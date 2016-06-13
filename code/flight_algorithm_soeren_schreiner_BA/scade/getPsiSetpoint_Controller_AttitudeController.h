/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _getPsiSetpoint_Controller_AttitudeController_H_
#define _getPsiSetpoint_Controller_AttitudeController_H_

#include "kcg_types.h"
#include "angleLimitation180_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::getPsiSetpoint::psiSetpointValue */ psiSetpointValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_real /* Controller::AttitudeController::getPsiSetpoint::_L3 */ _L3;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_getPsiSetpoint_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::getPsiSetpoint */
extern void getPsiSetpoint_Controller_AttitudeController(
  /* Controller::AttitudeController::getPsiSetpoint::setpointThrust */kcg_real setpointThrust,
  /* Controller::AttitudeController::getPsiSetpoint::setpointYaw */kcg_real setpointYaw,
  /* Controller::AttitudeController::getPsiSetpoint::anglePsi */kcg_real anglePsi,
  /* Controller::AttitudeController::getPsiSetpoint::motorsOn */kcg_bool motorsOn,
  outC_getPsiSetpoint_Controller_AttitudeController *outC);

extern void getPsiSetpoint_reset_Controller_AttitudeController(
  outC_getPsiSetpoint_Controller_AttitudeController *outC);

#endif /* _getPsiSetpoint_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** getPsiSetpoint_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

