/*******************************************************************************
*
*
*
*
*
* This file is part of MICROBLAZE.
*
* MICROBLAZE is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#ifndef MICROBLAZE_CORE_FUNC_LT_INSTRUCTIONS_HPP
#define MICROBLAZE_CORE_FUNC_LT_INSTRUCTIONS_HPP

#include "microblaze/intunit/registers.hpp"
#include "microblaze/intunit/memory.hpp"
#include "microblaze/intunit/alias.hpp"

#include <instructionBase.hpp>
#include <utils/customExceptions.hpp>
#include <utils/trap_utils.hpp>

#include <string>
#include <sstream>


#define FUNC_MODEL
#define LT_IF
namespace core_microblaze_lt {

  /** @brief    Instruction Class
  *   @details
  *   All individual instructions derive from this class.
  */
  class Instruction : public InstructionBase {
    public:
    Instruction(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    virtual unsigned int behavior() = 0;
    virtual Instruction * replicate() const throw() = 0;
    virtual void setParams(const unsigned int & bitString) throw() = 0;
    void printTrace();
    virtual std::string getInstructionName() const throw() = 0;
    virtual std::string getMnemonic() const throw() = 0;
    virtual unsigned int getId() const throw() = 0;
    inline void annull() {
      throw annull_exception();
    } // annull()

    inline void flush() {

    } // flush()

    inline void stall(const unsigned int & numCycles) {
      this->totalInstrCycles += numCycles;
    } // stall()

    unsigned int SignExtend(
        unsigned int bitSeq, unsigned int bitSeq_length);
    void handleMemoryException(
        unsigned int W_value, unsigned int S_value, unsigned int rd_bit_value,
        unsigned int addr);
    void handleUserPermissionException();
    unsigned int totalInstrCycles;
    virtual ~Instruction();

    protected:
    Reg32_0 & PC;
    Reg32_1 & MSR;
    Reg32_0 & EAR;
    Reg32_2 & ESR;
    Reg32_0 & BTR;
    Reg32_3 & FSR;
    Reg32_0 & EDR;
    Reg32_0 & PID;
    Reg32_0 & ZPR;
    Reg32_0 & TLBLO;
    Reg32_0 & TLBHI;
    Reg32_0 & TLBX;
    Reg32_0 & TLBSX;
    Reg32_0 & IMMREG;
    Reg32_0 & TARGET;
    Reg1_0 & DSFLAG;
    Reg32_0 * GPR;
    Reg32_0 * PVR;
    MemoryInterface & dataMem;
    unsigned int & totalCycles;

  }; // class Instruction

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class IMM_reset_op : public virtual Instruction {
    public:
    IMM_reset_op(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    virtual ~IMM_reset_op();

    protected:
    inline void IMM_reset() {

      IMMREG &= 0x7fffffff;
    } // IMM_reset()


  }; // class IMM_reset_op

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class IMM_handler_op : public virtual Instruction {
    public:
    IMM_handler_op(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    virtual ~IMM_handler_op();

    protected:
    inline void IMM_handler(
        unsigned int & imm, unsigned int & imm_value) {

      if ( IMMREG & 0x80000000 ) {  /* IMM instruction */
      imm_value = ((int)imm & 0x0000ffff) + (int)(IMMREG << 16);
      IMMREG &= 0x7fffffff;
    } else {  /* No IMM instruction */
    imm_value = (int)SignExtend(imm,16);
  }
} // IMM_handler()


}; // class IMM_handler_op

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class InvalidInstr : public Instruction {
    public:
    InvalidInstr(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getInstructionName() const throw();
    std::string getMnemonic() const throw();
    unsigned int getId() const throw();
    virtual ~InvalidInstr();

  }; // class InvalidInstr

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class WDC : public IMM_reset_op {
    public:
    WDC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~WDC();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class WDC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGE : public IMM_reset_op {
    public:
    BGE(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGE();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BGE

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGEID : public IMM_handler_op {
    public:
    BGEID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGEID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BGEID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSLL : public IMM_reset_op {
    public:
    BSLL(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSLL();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BSLL

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGT : public IMM_reset_op {
    public:
    BGT(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGT();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BGT

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BR : public IMM_reset_op {
    public:
    BR(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BR();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BR

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BNED : public IMM_reset_op {
    public:
    BNED(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BNED();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BNED

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BNEI : public IMM_handler_op {
    public:
    BNEI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BNEI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BNEI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LBU : public IMM_reset_op {
    public:
    LBU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LBU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class LBU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUB : public IMM_reset_op {
    public:
    RSUB(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUB();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class RSUB

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSRLI : public IMM_handler_op {
    public:
    BSRLI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSRLI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BSRLI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FDIV : public IMM_reset_op {
    public:
    FDIV(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FDIV();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class FDIV

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FADD : public IMM_reset_op {
    public:
    FADD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FADD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class FADD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MULHU : public IMM_reset_op {
    public:
    MULHU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MULHU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class MULHU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGTD : public IMM_reset_op {
    public:
    BGTD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGTD();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BGTD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGTI : public IMM_handler_op {
    public:
    BGTI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGTI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BGTI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SEXT8 : public IMM_reset_op {
    public:
    SEXT8(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SEXT8();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class SEXT8

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LHU : public IMM_reset_op {
    public:
    LHU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LHU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class LHU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BNE : public IMM_reset_op {
    public:
    BNE(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BNE();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BNE

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRLD : public IMM_reset_op {
    public:
    BRLD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRLD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRLD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRKI : public IMM_handler_op {
    public:
    BRKI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRKI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRKI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDIKC : public IMM_handler_op {
    public:
    ADDIKC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDIKC();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ADDIKC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class IDIV : public IMM_reset_op {
    public:
    IDIV(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~IDIV();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class IDIV

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDC : public IMM_reset_op {
    public:
    ADDC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDC();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class ADDC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LBUI : public IMM_handler_op {
    public:
    LBUI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LBUI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class LBUI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDK : public IMM_reset_op {
    public:
    ADDK(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDK();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class ADDK

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class OR : public IMM_reset_op {
    public:
    OR(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~OR();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class OR

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDI : public IMM_handler_op {
    public:
    ADDI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ADDI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BEQID : public IMM_handler_op {
    public:
    BEQID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BEQID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BEQID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class CMPU : public IMM_reset_op {
    public:
    CMPU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~CMPU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class CMPU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FINT : public Instruction {
    public:
    FINT(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FINT();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class FINT

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSRL : public IMM_reset_op {
    public:
    BSRL(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSRL();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BSRL

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLTI : public IMM_handler_op {
    public:
    BLTI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLTI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BLTI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class PCMPEQ : public IMM_reset_op {
    public:
    PCMPEQ(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~PCMPEQ();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class PCMPEQ

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class XOR : public IMM_reset_op {
    public:
    XOR(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~XOR();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class XOR

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BEQ : public IMM_reset_op {
    public:
    BEQ(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BEQ();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BEQ

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLTD : public IMM_reset_op {
    public:
    BLTD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLTD();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BLTD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class CMP : public IMM_reset_op {
    public:
    CMP(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~CMP();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class CMP

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRALID : public IMM_handler_op {
    public:
    BRALID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRALID();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRALID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RTBD : public IMM_handler_op {
    public:
    RTBD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RTBD();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RTBD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MFS : public IMM_reset_op {
    public:
    MFS(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MFS();

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int rs;

  }; // class MFS

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLT : public IMM_reset_op {
    public:
    BLT(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLT();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BLT

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRLID : public IMM_handler_op {
    public:
    BRLID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRLID();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRLID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SB : public IMM_reset_op {
    public:
    SB(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SB();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class SB

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLE : public IMM_reset_op {
    public:
    BLE(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLE();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BLE

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SHI : public IMM_handler_op {
    public:
    SHI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SHI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class SHI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class AND : public IMM_reset_op {
    public:
    AND(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~AND();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class AND

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBIC : public IMM_handler_op {
    public:
    RSUBIC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBIC();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RSUBIC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SBI : public IMM_handler_op {
    public:
    SBI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SBI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class SBI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RTED : public IMM_handler_op {
    public:
    RTED(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RTED();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RTED

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBIK : public IMM_handler_op {
    public:
    RSUBIK(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBIK();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RSUBIK

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRALD : public IMM_reset_op {
    public:
    BRALD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRALD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRALD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRA : public IMM_reset_op {
    public:
    BRA(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRA();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRA

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FSQRT : public Instruction {
    public:
    FSQRT(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FSQRT();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class FSQRT

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SEXT16 : public IMM_reset_op {
    public:
    SEXT16(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SEXT16();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class SEXT16

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SWI : public IMM_handler_op {
    public:
    SWI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SWI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class SWI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLEID : public IMM_handler_op {
    public:
    BLEID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLEID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BLEID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSRA : public IMM_reset_op {
    public:
    BSRA(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSRA();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BSRA

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLED : public IMM_reset_op {
    public:
    BLED(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLED();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BLED

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MULI : public IMM_handler_op {
    public:
    MULI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MULI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class MULI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MSRSET : public IMM_reset_op {
    public:
    MSRSET(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MSRSET();

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm15;

  }; // class MSRSET

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MUL : public IMM_reset_op {
    public:
    MUL(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MUL();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class MUL

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLEI : public IMM_handler_op {
    public:
    BLEI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLEI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BLEI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RTSD : public IMM_handler_op {
    public:
    RTSD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RTSD();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RTSD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ANDN : public IMM_reset_op {
    public:
    ANDN(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ANDN();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class ANDN

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ANDI : public IMM_handler_op {
    public:
    ANDI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ANDI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ANDI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDKC : public IMM_reset_op {
    public:
    ADDKC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDKC();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class ADDKC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MSRCLR : public IMM_reset_op {
    public:
    MSRCLR(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MSRCLR();

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm15;

  }; // class MSRCLR

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSLLI : public IMM_handler_op {
    public:
    BSLLI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSLLI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BSLLI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGEI : public IMM_handler_op {
    public:
    BGEI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGEI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BGEI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SRC : public IMM_reset_op {
    public:
    SRC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SRC();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class SRC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SRA : public IMM_reset_op {
    public:
    SRA(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SRA();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class SRA

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class IMM : public IMM_reset_op {
    public:
    IMM(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~IMM();

    private:
    unsigned int imm;

  }; // class IMM

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SRL : public IMM_reset_op {
    public:
    SRL(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SRL();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class SRL

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FLT : public IMM_reset_op {
    public:
    FLT(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FLT();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;

  }; // class FLT

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MULHSU : public IMM_reset_op {
    public:
    MULHSU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MULHSU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class MULHSU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADD : public IMM_reset_op {
    public:
    ADD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class ADD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class XORI : public IMM_handler_op {
    public:
    XORI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~XORI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class XORI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class PCMPNE : public IMM_reset_op {
    public:
    PCMPNE(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~PCMPNE();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class PCMPNE

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BSRAI : public IMM_handler_op {
    public:
    BSRAI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BSRAI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BSRAI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRAID : public IMM_handler_op {
    public:
    BRAID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRAID();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRAID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class WIC : public IMM_reset_op {
    public:
    WIC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~WIC();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class WIC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBKC : public IMM_reset_op {
    public:
    RSUBKC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBKC();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class RSUBKC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SW : public IMM_reset_op {
    public:
    SW(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SW();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class SW

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FCMP : public Instruction {
    public:
    FCMP(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FCMP();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;
    unsigned int opsel;

  }; // class FCMP

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class SH : public IMM_reset_op {
    public:
    SH(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~SH();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class SH

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRK : public IMM_reset_op {
    public:
    BRK(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRK();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRK

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRI : public IMM_handler_op {
    public:
    BRI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ORI : public IMM_handler_op {
    public:
    ORI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ORI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ORI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ANDNI : public IMM_handler_op {
    public:
    ANDNI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ANDNI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ANDNI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRD : public IMM_reset_op {
    public:
    BRD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LHUI : public IMM_handler_op {
    public:
    LHUI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LHUI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class LHUI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBIKC : public IMM_handler_op {
    public:
    RSUBIKC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBIKC();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RSUBIKC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MULH : public IMM_reset_op {
    public:
    MULH(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MULH();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class MULH

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FRSUB : public IMM_reset_op {
    public:
    FRSUB(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FRSUB();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class FRSUB

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BEQI : public IMM_handler_op {
    public:
    BEQI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BEQI();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BEQI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BEQD : public IMM_reset_op {
    public:
    BEQD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BEQD();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BEQD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RTID : public IMM_handler_op {
    public:
    RTID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RTID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RTID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class FMUL : public IMM_reset_op {
    public:
    FMUL(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~FMUL();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class FMUL

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LWI : public IMM_handler_op {
    public:
    LWI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LWI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class LWI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BNEID : public IMM_handler_op {
    public:
    BNEID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BNEID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BNEID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDIK : public IMM_handler_op {
    public:
    ADDIK(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDIK();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ADDIK

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGTID : public IMM_handler_op {
    public:
    BGTID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGTID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BGTID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class ADDIC : public IMM_handler_op {
    public:
    ADDIC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~ADDIC();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class ADDIC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class LW : public IMM_reset_op {
    public:
    LW(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~LW();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class LW

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBC : public IMM_reset_op {
    public:
    RSUBC(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBC();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class RSUBC

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BLTID : public IMM_handler_op {
    public:
    BLTID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BLTID();

    protected:
    unsigned int imm_value;

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class BLTID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBI : public IMM_handler_op {
    public:
    RSUBI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    unsigned int imm;

  }; // class RSUBI

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class MTS : public IMM_reset_op {
    public:
    MTS(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~MTS();

    private:
    Alias ra;
    unsigned int ra_bit;
    unsigned int rs;

  }; // class MTS

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class RSUBK : public IMM_reset_op {
    public:
    RSUBK(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~RSUBK();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class RSUBK

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BGED : public IMM_reset_op {
    public:
    BGED(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BGED();

    private:
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BGED

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRID : public IMM_handler_op {
    public:
    BRID(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRID();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRID

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class PCMPBF : public IMM_reset_op {
    public:
    PCMPBF(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~PCMPBF();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class PCMPBF

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class IDIVU : public IMM_reset_op {
    public:
    IDIVU(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~IDIVU();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias ra;
    unsigned int ra_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class IDIVU

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRAD : public IMM_reset_op {
    public:
    BRAD(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRAD();

    private:
    Alias rd;
    unsigned int rd_bit;
    Alias rb;
    unsigned int rb_bit;

  }; // class BRAD

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class BRAI : public IMM_handler_op {
    public:
    BRAI(
        Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
        Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 &
        TLBLO, Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 &
        IMMREG, Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR,
        MemoryInterface & dataMem, unsigned int & totalCycles);
    unsigned int behavior();
    Instruction * replicate() const throw();
    std::string getInstructionName() const throw();
    unsigned int getId() const throw();
    void setParams(const unsigned int & bitString) throw();
    std::string getMnemonic() const throw();
    virtual ~BRAI();

    protected:
    unsigned int imm_value;

    private:
    Alias rd;
    unsigned int rd_bit;
    unsigned int imm;

  }; // class BRAI

} // namespace core_microblaze_lt



#endif
