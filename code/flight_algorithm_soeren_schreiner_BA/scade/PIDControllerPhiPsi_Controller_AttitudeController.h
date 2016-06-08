/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _PIDControllerPhiPsi_Controller_AttitudeController_H_
#define _PIDControllerPhiPsi_Controller_AttitudeController_H_

#include "kcg_types.h"
#include "proportionalTerm_Controller_AttitudeController.h"
#include "dampingTerm_Controller_AttitudeController.h"
#include "angleLimitation180_Functions.h"
#include "integralTerm_Controller_AttitudeController.h"
#include "derivativeTerm_Controller_AttitudeController.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::PIDControllerPhiPsi::motorValue */ motorValue;
  controllerSettings_Main /* Controller::AttitudeController::PIDControllerPhiPsi::controllerParts */ controllerParts;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_integralTerm_Controller_AttitudeController /* 1 */ _1_Context_1;
  outC_derivativeTerm_Controller_AttitudeController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_PIDControllerPhiPsi_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::PIDControllerPhiPsi */
extern void PIDControllerPhiPsi_Controller_AttitudeController(
  /* Controller::AttitudeController::PIDControllerPhiPsi::setpointValue */kcg_real setpointValue,
  /* Controller::AttitudeController::PIDControllerPhiPsi::actualValue */kcg_real actualValue,
  /* Controller::AttitudeController::PIDControllerPhiPsi::settingValues */controllerSettings_Main *settingValues,
  /* Controller::AttitudeController::PIDControllerPhiPsi::angleSpeedValue */kcg_real angleSpeedValue,
  /* Controller::AttitudeController::PIDControllerPhiPsi::integralStartValue */kcg_real integralStartValue,
  /* Controller::AttitudeController::PIDControllerPhiPsi::motorsOnSignal */kcg_bool motorsOnSignal,
  outC_PIDControllerPhiPsi_Controller_AttitudeController *outC);

extern void PIDControllerPhiPsi_reset_Controller_AttitudeController(
  outC_PIDControllerPhiPsi_Controller_AttitudeController *outC);

#endif /* _PIDControllerPhiPsi_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** PIDControllerPhiPsi_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

