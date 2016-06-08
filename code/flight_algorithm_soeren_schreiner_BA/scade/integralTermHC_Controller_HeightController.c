/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "integralTermHC_Controller_HeightController.h"

void integralTermHC_reset_Controller_HeightController(
  outC_integralTermHC_Controller_HeightController *outC)
{
  outC->init = kcg_true;
}

/* Controller::HeightController::integralTermHC */
void integralTermHC_Controller_HeightController(
  /* Controller::HeightController::integralTermHC::Ki */kcg_real Ki,
  /* Controller::HeightController::integralTermHC::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::integralTermHC::differenceValue */kcg_real differenceValue,
  /* Controller::HeightController::integralTermHC::integralStartValue */kcg_real integralStartValue,
  /* Controller::HeightController::integralTermHC::activeSignal */kcg_bool activeSignal,
  outC_integralTermHC_Controller_HeightController *outC)
{
  kcg_real tmp1;
  kcg_real tmp;
  /* Controller::HeightController::integralTermHC::_L28 */ kcg_bool _L28;
  
  if (outC->init) {
    _L28 = kcg_false;
    tmp = setpointValue;
  }
  else {
    _L28 = outC->rem_activeSignal;
    tmp = outC->rem_setpointValue;
  }
  if (setpointValue != tmp) {
    tmp1 = ZERO_REAL_Main;
  }
  else if (_L28) {
    tmp1 = differenceValue * Ki;
  }
  else {
    tmp1 = integralStartValue;
  }
  if (_L28) {
    if (outC->init) {
      tmp = 0.0;
    }
    else {
      tmp = outC->iValue;
    }
  }
  else {
    tmp = ZERO_REAL_Main;
  }
  outC->iValue = /* 1 */
    minMaxLimitation_Functions(
      I_LIMITATION_MIN_HC_Main,
      I_LIMITATION_MAX_HC_Main,
      tmp1 + tmp);
  outC->rem_setpointValue = setpointValue;
  outC->rem_activeSignal = activeSignal;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** integralTermHC_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

