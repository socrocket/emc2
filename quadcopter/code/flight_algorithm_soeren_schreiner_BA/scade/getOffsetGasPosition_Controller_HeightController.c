/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "getOffsetGasPosition_Controller_HeightController.h"

void getOffsetGasPosition_reset_Controller_HeightController(
  outC_getOffsetGasPosition_Controller_HeightController *outC)
{
  outC->init = kcg_true;
}

/* Controller::HeightController::getOffsetGasPosition */
void getOffsetGasPosition_Controller_HeightController(
  /* Controller::HeightController::getOffsetGasPosition::lostConnectionSignal */kcg_bool lostConnectionSignal,
  /* Controller::HeightController::getOffsetGasPosition::activeSignal */kcg_bool activeSignal,
  /* Controller::HeightController::getOffsetGasPosition::thrustValue */kcg_real thrustValue,
  outC_getOffsetGasPosition_Controller_HeightController *outC)
{
  kcg_real tmp;
  
  if (activeSignal) {
    if (outC->init) {
      outC->_L3 = 0.0;
    }
  }
  else {
    outC->_L3 = thrustValue;
  }
  if (lostConnectionSignal) {
    outC->setpointValue = LOST_CONNECTION_HC_SETPOINT_Main;
  }
  else {
    tmp = /* 1 */
      rcAdjustingReal_Functions(
        thrustValue - outC->_L3,
        SENSITIVITY_GAS_STICK_HC_Main);
    outC->setpointValue = tmp / SCALING_GAS_STICK_HC_Main;
  }
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** getOffsetGasPosition_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

