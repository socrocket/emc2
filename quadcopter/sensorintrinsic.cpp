#include "core/base/systemc.h"
#include "core/sr_iss/intrinsics/platformintrinsic.h"
#include "core/common/sr_registry.h"
#include "core/common/sr_report.h"

#include <map>
#include <string>
#include <vector>

using namespace trap;

static const int values[] = {
 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
};

template<class wordSize>
class SensorIntrinsic : public PlatformIntrinsic<wordSize> {
  public:
    SensorIntrinsic(sc_core::sc_module_name mn) : PlatformIntrinsic<wordSize>(mn) {}
    bool operator()() {
      this->m_processor->pre_call();
      // Lets get the system call arguments
      std::vector<wordSize> callArgs = this->m_processor->read_args();

      // Assign value from array
      int value = (int)readValue();

      this->m_processor->set_return_value(value);
      this->m_processor->return_from_call();
      this->m_processor->post_call();

      if (this->latency.to_double() > 0) {
        wait(this->latency);
      }

      return true;
    }

    static unsigned int readValue() {
       sc_time current_time = sc_time_stamp();
       double magnitude = current_time.to_default_time_units();
       uint64_t value = *reinterpret_cast<uint64_t*>(&magnitude);
       return static_cast<uint32_t>((value & 0xFFFFFFFF) | ((value >>32)));
    }
};

typedef SensorIntrinsic<unsigned int> SensorIntrinsic32;
SR_HAS_INTRINSIC(SensorIntrinsic32);
