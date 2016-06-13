/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "integralTerm_Controller_AttitudeController.h"

void integralTerm_reset_Controller_AttitudeController(
  outC_integralTerm_Controller_AttitudeController *outC)
{
  outC->init = kcg_true;
}

/* Controller::AttitudeController::integralTerm */
void integralTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::integralTerm::Ki */kcg_real Ki,
  /* Controller::AttitudeController::integralTerm::differenceValue */kcg_real differenceValue,
  /* Controller::AttitudeController::integralTerm::integralStartValue */kcg_real integralStartValue,
  /* Controller::AttitudeController::integralTerm::motorsOnSignal */kcg_bool motorsOnSignal,
  outC_integralTerm_Controller_AttitudeController *outC)
{
  kcg_real tmp1;
  kcg_real tmp;
  
  if (motorsOnSignal) {
    tmp1 = differenceValue * Ki;
    if (outC->init) {
      tmp = 0.0;
    }
    else {
      tmp = outC->iValue;
    }
  }
  else {
    tmp1 = integralStartValue;
    tmp = integralStartValue;
  }
  outC->iValue = /* 1 */
    minMaxLimitation_Functions(
      I_LIMITATION_MIN_Main,
      I_LIMITATION_MAX_Main,
      tmp1 + tmp);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** integralTerm_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

