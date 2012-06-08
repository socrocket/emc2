using namespace std;
using namespace sc_core;
using namespace tlm;

// Destructor (unregisters callbacks)
template<class BASE>
AHBMaster<BASE>::~AHBMaster() {
}

// TLM non-blocking backward transport function
template<class BASE>
tlm::tlm_sync_enum AHBMaster<BASE>::nb_transport_bw(tlm::tlm_generic_payload &trans, tlm::tlm_phase &phase, sc_core::sc_time &delay) {

  v::debug << this->name() << "nb_transport_bw received transaction " << hex << &trans << " with phase " << phase << v::endl;

  if (phase == tlm::END_REQ) {

    // END_REQ marks the time at which the address or the last address of a burst is sampled by the slave.
    // Let the ahbread function know that END_REQ came in.
    m_EndRequestEvent.notify(delay);
    delay=SC_ZERO_TIME;

  } else if (phase == tlm::BEGIN_RESP) {

    // BEGIN_RESP indicates that the data is ready (begin of AHB data phase)
    // Send the transaction to the thread for response processing;

    uint32_t data_phase_base;

    // Calculate length of data phase
    if (trans.get_data_length() < 4) {

      data_phase_base = 1;

    } else {

      data_phase_base = (trans.get_data_length() >> 2);    

    }

    delay += data_phase_base * get_clock();
    m_ResponsePEQ.notify(trans, delay);
    delay=SC_ZERO_TIME;

  } else {

    v::error << this->name() << "Invalid phase in call to nb_transport_bw!" << v::endl;
    trans.set_response_status(tlm::TLM_COMMAND_ERROR_RESPONSE);
    assert(-1);

  }

  // Return arrow for msc
  msclogger::return_forward(this, &ahb, &trans, tlm::TLM_ACCEPTED, delay);
  return tlm::TLM_ACCEPTED;

}

template<class BASE>
void AHBMaster<BASE>::ahbread(uint32_t addr, unsigned char * data, uint32_t length) {

  bool cacheable;
  tlm::tlm_response_status response;
  sc_core::sc_time delay = SC_ZERO_TIME;

  ahbread(addr, data, length, delay, cacheable, response);

}

template<class BASE>
void AHBMaster<BASE>::ahbread(uint32_t addr, unsigned char * data, uint32_t length, sc_core::sc_time &delay, bool &cacheable, tlm::tlm_response_status &response) {

  ahbread(addr, data, length, delay, cacheable, false, response);

}

template<class BASE>
void AHBMaster<BASE>::ahbwrite(uint32_t addr, unsigned char * data, uint32_t length) {

  sc_core::sc_time delay = SC_ZERO_TIME;
  tlm::tlm_response_status response;

  ahbwrite(addr, data, length, delay, response);

}

template<class BASE>
void AHBMaster<BASE>::ahbwrite(uint32_t addr, unsigned char * data, uint32_t length, sc_core::sc_time &delay, tlm::tlm_response_status &response) {

  ahbwrite(addr, data, length, delay, false, response);

}

// Function for read access to AHB master socket
template<class BASE>
void AHBMaster<BASE>::ahbread(uint32_t addr, unsigned char * data, uint32_t length, sc_core::sc_time &delay, bool &cacheable, bool is_lock, tlm::tlm_response_status &response) {

  tlm::tlm_phase phase;
  tlm::tlm_sync_enum status;

  // Allocate new transactin (reference counter = 1
  tlm::tlm_generic_payload *trans = ahb.get_transaction();

  v::debug << this->name() << "Allocate new transaction: " << hex << trans << "Acquire / Ref-Count = " << trans->get_ref_count() << v::endl;

  // Initialize transaction
  trans->set_command(tlm::TLM_READ_COMMAND);
  trans->set_address(addr);
  trans->set_data_length(length);
  trans->set_data_ptr(data);
  trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

  if (m_ambaLayer == amba::amba_LT) {

    // Forward arrow for msc
    msclogger::forward(this, &ahb, trans, tlm::BEGIN_REQ);

    v::debug << this->name() << "Transaction " << hex << trans << " call to b_transport" << v::endl;

    // Blocking transport
    ahb->b_transport(*trans, delay);

    // Check the data
    response_callback(trans);

    // Consume transfer delay
    wait(delay);
    delay = SC_ZERO_TIME;

    cacheable = (ahb.get_extension<amba::amba_cacheable>(*trans)) ? true : false;

    response = trans->get_response_status();

    // Decrement reference counter
    trans->release();

  } else {

    // Initial phase for AT
    phase = tlm::BEGIN_REQ;

    // Simulated master->bus path delay
    delay = SC_ZERO_TIME;

    // Forward arrow for msc
    msclogger::forward(this, &ahb, trans, phase, delay);

    v::debug << this->name() << "Transaction " << hex << trans << " call to nb_transport_fw with phase " << phase << v::endl;

    status = ahb->nb_transport_fw(*trans, phase, delay);

    // By sending BEGIN_REQ the master starts a bus request.
    // The slave is expected to send END_REQ and BEGIN_RESP.
    //
    // END_REQ - Time at which slave samples address of single transfer
    // or last address of burst. After END_REQ the master may issue the
    // next transaction.
    //
    // BEGIN_RESP - Indicates that the data is ready.
    // Marks the begin of the data phase for single transfers and bursts.
    // Slave may insert wait states before BEGIN_RESP.
    //
    // ! For bursts BEGIN_RESP comes before END_REQ, because
    // the AHB data phase starts before the last address
    // has been sampled !

    assert((status==tlm::TLM_ACCEPTED)||(status==tlm::TLM_UPDATED));

    if (phase == tlm::BEGIN_REQ) {

      // Wait for END_REQ to come in on backward path
      wait(m_EndRequestEvent);

    } else if (phase == tlm::END_REQ) {

      // The bus has send END_REQ on the return path
      wait(delay);
      delay=SC_ZERO_TIME;

    } else {

      // Forbidden phase
      v::error << this->name() << "Invalid phase in return path (from call to nb_transport_fw)!" << v::endl;
      trans->set_response_status(tlm::TLM_COMMAND_ERROR_RESPONSE);
      assert(-1);

    }

    response = trans->get_response_status();
    cacheable = (ahb.get_extension<amba::amba_cacheable>(*trans)) ? true : false;

  }
}

// Function for write access to AHB master socket
template<class BASE>
void AHBMaster<BASE>::ahbwrite(uint32_t addr, unsigned char * data, uint32_t length, sc_core::sc_time &delay, bool is_lock, tlm::tlm_response_status &response) {

  tlm::tlm_phase phase;
  tlm::tlm_sync_enum status;

  // Allocate new transactin (reference counter = 1)
  tlm::tlm_generic_payload *trans = ahb.get_transaction();

  v::debug << this->name() << "Allocate new transaction " << hex << trans << "Acquire / Ref-Count = " << trans->get_ref_count() << v::endl;

  // Initialize transaction
  trans->set_command(tlm::TLM_WRITE_COMMAND);
  trans->set_address(addr);
  trans->set_data_length(length);
  trans->set_data_ptr(data);
  trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

  if (is_lock) {

    ahb.template validate_extension<amba::amba_lock>(*trans);

  }
    
  if (m_ambaLayer == amba::amba_LT) {

    // Forward arrow for msc
    msclogger::forward(this, &ahb, trans, tlm::BEGIN_REQ);
    ahb->b_transport(*trans, delay);

    // Consume transfer delay
    wait(delay);
    delay = SC_ZERO_TIME;

    response = trans->get_response_status();

    // Decrement reference counter
    trans->release();

  } else {

    // Initial phase for AT
    phase = tlm::BEGIN_REQ;

    // Forward arrow for msc
    msclogger::forward(this, &ahb, trans, phase, delay);

    v::debug << this->name() << "Transaction " << hex << trans << " call to nb_transport_fw with phase " << phase << v::endl;

    status = ahb->nb_transport_fw(*trans, phase, delay);

    // By sending BEGIN_REQ the master starts a bus request.
    // The slave is expected to send END_REQ and BEGIN_RESP.
    //
    // END_REQ - Time at which slave samples address of single transfer
    // or last address of burst. After END_REQ the master may issue the
    // next transaction.
    //
    // BEGIN_RESP - Indicates that the data is ready.
    // Marks the begin of the data phase for single transfers and bursts.
    // Slave may insert wait states before BEGIN_RESP.
    //
    // ! For bursts BEGIN_RESP comes before END_REQ, because
    // the AHB data phase starts before the last address
    // has been sampled !

    assert((status==tlm::TLM_ACCEPTED)||(status==tlm::TLM_UPDATED));

    if (phase == tlm::BEGIN_REQ) {

      // Wait for END_REQ to come in on backward path
      wait(m_EndRequestEvent);

    } else if (phase == tlm::END_REQ) {

      // The bus has send END_REQ on the return path
      wait(delay);
      delay=SC_ZERO_TIME;

    } else {

      // Forbidden phase
      v::error << this->name() << "Invalid phase in return path (from call to nb_transport_fw)!" << v::endl;
      trans->set_response_status(tlm::TLM_COMMAND_ERROR_RESPONSE);
      assert(-1);

    }

    response = trans->get_response_status();

  }
}

// Perform AHB debug read
template<class BASE>
uint32_t AHBMaster<BASE>::ahbread_dbg(uint32_t addr, unsigned char * data, unsigned int length) {

  uint32_t length_dbg;

  // Allocate new transaction (reference counter = 1
  tlm::tlm_generic_payload *trans = ahb.get_transaction();

  v::debug << this->name() << "Allocate new transaction " << hex << trans << v::endl;

  // Initialize transaction
  trans->set_command(tlm::TLM_READ_COMMAND);
  trans->set_address(addr);
  trans->set_data_length(length);
  trans->set_data_ptr(data);
  trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);  

  // Debug transport
  length_dbg = ahb->transport_dbg(*trans);
  
  // Decrement reference count
  trans->release();

  return length_dbg;

}

// Perform AHB debug write
template<class BASE>
uint32_t AHBMaster<BASE>::ahbwrite_dbg(uint32_t addr, unsigned char * data, unsigned int length) {

  uint32_t length_dbg;

  // Allocate new transactin (reference counter = 1)
  tlm::tlm_generic_payload *trans = ahb.get_transaction();

  v::debug << this->name() << "Allocate new transaction " << hex << trans << v::endl;

  // Initialize transaction
  trans->set_command(tlm::TLM_WRITE_COMMAND);
  trans->set_address(addr);
  trans->set_data_length(length);
  trans->set_data_ptr(data);
  trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE); 

  // Debug transport
  length_dbg = ahb->transport_dbg(*trans);
  
  // Decrement reference count
  trans->release();

  return length_dbg;

}
   
// Thread for response synchronization (sync and send END_RESP)
template<class BASE>
void AHBMaster<BASE>::ResponseThread() {

  tlm::tlm_generic_payload* trans;
  tlm::tlm_phase phase;
  sc_core::sc_time delay;
  tlm::tlm_sync_enum status;

  uint32_t data_phase_base;

  while(1) {

    // Wait for response from slave
    wait(m_ResponsePEQ.get_event());

    // Get transaction from PEQ
    trans = m_ResponsePEQ.get_next_transaction();

    // Check result
    response_callback(trans);

    // END_RESP marks the end of the data phase
    phase = tlm::END_RESP;
    delay = sc_core::SC_ZERO_TIME;

    v::debug << this->name() << "Transaction " << hex << trans << " call to nb_transport_fw with phase " << phase << v::endl;

    // Forward arrow for msc
    msclogger::forward(this, &ahb, trans, phase, delay);

    // Call to nb_transport_fw
    status = ahb->nb_transport_fw(*trans, phase, delay);

    // Return value must be TLM_COMPLETED or TLM_ACCEPTED
    assert((status==tlm::TLM_COMPLETED)||(status==tlm::TLM_ACCEPTED));

    v::debug << name() << "Release " << trans << " Ref-Count before calling release " << trans->get_ref_count() << v::endl; 

    // Decrement reference count
    trans->release();

  }
}