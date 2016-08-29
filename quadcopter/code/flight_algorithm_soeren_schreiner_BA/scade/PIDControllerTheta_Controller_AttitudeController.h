/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _PIDControllerTheta_Controller_AttitudeController_H_
#define _PIDControllerTheta_Controller_AttitudeController_H_

#include "kcg_types.h"
#include "proportionalTerm_Controller_AttitudeController.h"
#include "dampingTerm_Controller_AttitudeController.h"
#include "angleLimitation90_Functions.h"
#include "integralTerm_Controller_AttitudeController.h"
#include "derivativeTerm_Controller_AttitudeController.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::PIDControllerTheta::motorValue */ motorValue;
  controllerSettings_Main /* Controller::AttitudeController::PIDControllerTheta::controllerParts */ controllerParts;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_integralTerm_Controller_AttitudeController /* 1 */ _1_Context_1;
  outC_derivativeTerm_Controller_AttitudeController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_PIDControllerTheta_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::PIDControllerTheta */
extern void PIDControllerTheta_Controller_AttitudeController(
  /* Controller::AttitudeController::PIDControllerTheta::setpointValue */kcg_real setpointValue,
  /* Controller::AttitudeController::PIDControllerTheta::actualValue */kcg_real actualValue,
  /* Controller::AttitudeController::PIDControllerTheta::settingValues */controllerSettings_Main *settingValues,
  /* Controller::AttitudeController::PIDControllerTheta::angleSpeedValue */kcg_real angleSpeedValue,
  /* Controller::AttitudeController::PIDControllerTheta::integralStartValue */kcg_real integralStartValue,
  /* Controller::AttitudeController::PIDControllerTheta::motorsOnSignal */kcg_bool motorsOnSignal,
  outC_PIDControllerTheta_Controller_AttitudeController *outC);

extern void PIDControllerTheta_reset_Controller_AttitudeController(
  outC_PIDControllerTheta_Controller_AttitudeController *outC);

#endif /* _PIDControllerTheta_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** PIDControllerTheta_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

