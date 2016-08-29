/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _attitudeController_Controller_AttitudeController_H_
#define _attitudeController_Controller_AttitudeController_H_

#include "kcg_types.h"
#include "PIDControllerPhiPsi_Controller_AttitudeController.h"
#include "getPsiSetpoint_Controller_AttitudeController.h"
#include "PIDControllerTheta_Controller_AttitudeController.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::attitudeController::psi */ psi;
  kcg_real /* Controller::AttitudeController::attitudeController::theta */ theta;
  kcg_real /* Controller::AttitudeController::attitudeController::phi */ phi;
  attitudeController_Main /* Controller::AttitudeController::attitudeController::attitudeControllerValues */ attitudeControllerValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_getPsiSetpoint_Controller_AttitudeController /* 1 */ _1_Context_1;
  outC_PIDControllerPhiPsi_Controller_AttitudeController /* 3 */ Context_3;
  outC_PIDControllerPhiPsi_Controller_AttitudeController /* 2 */ Context_2;
  outC_PIDControllerTheta_Controller_AttitudeController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_attitudeController_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::attitudeController */
extern void attitudeController_Controller_AttitudeController(
  /* Controller::AttitudeController::attitudeController::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::AttitudeController::attitudeController::setpointValues */rcValuesReal_Main *setpointValues,
  /* Controller::AttitudeController::attitudeController::angleValues */angleValues_Main *angleValues,
  /* Controller::AttitudeController::attitudeController::angleSpeedValues */angleValues_Main *angleSpeedValues,
  outC_attitudeController_Controller_AttitudeController *outC);

extern void attitudeController_reset_Controller_AttitudeController(
  outC_attitudeController_Controller_AttitudeController *outC);

#endif /* _attitudeController_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** attitudeController_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

