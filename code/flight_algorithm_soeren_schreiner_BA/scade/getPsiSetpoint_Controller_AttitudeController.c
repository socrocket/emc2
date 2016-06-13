/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "getPsiSetpoint_Controller_AttitudeController.h"

void getPsiSetpoint_reset_Controller_AttitudeController(
  outC_getPsiSetpoint_Controller_AttitudeController *outC)
{
  outC->init = kcg_true;
}

/* Controller::AttitudeController::getPsiSetpoint */
void getPsiSetpoint_Controller_AttitudeController(
  /* Controller::AttitudeController::getPsiSetpoint::setpointThrust */kcg_real setpointThrust,
  /* Controller::AttitudeController::getPsiSetpoint::setpointYaw */kcg_real setpointYaw,
  /* Controller::AttitudeController::getPsiSetpoint::anglePsi */kcg_real anglePsi,
  /* Controller::AttitudeController::getPsiSetpoint::motorsOn */kcg_bool motorsOn,
  outC_getPsiSetpoint_Controller_AttitudeController *outC)
{
  /* Controller::AttitudeController::getPsiSetpoint::_L14 */ kcg_real _L14;
  
  if (setpointThrust < STOP_GIER_Main) {
    _L14 = ZERO_REAL_Main;
  }
  else {
    _L14 = setpointYaw;
  }
  if (motorsOn & (ZERO_REAL_Main == _L14)) {
    if (outC->init) {
      outC->_L3 = 0.0;
    }
  }
  else {
    outC->_L3 = _L14 + anglePsi;
  }
  outC->psiSetpointValue = /* 1 */ angleLimitation180_Functions(outC->_L3);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** getPsiSetpoint_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

