/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _PIDHeightController_Controller_HeightController_H_
#define _PIDHeightController_Controller_HeightController_H_

#include "kcg_types.h"
#include "dampingTermHC_Controller_HeightController.h"
#include "proportionalTermHC_Controller_HeightController.h"
#include "integralTermHC_Controller_HeightController.h"
#include "derivativeTermHC_Controller_HeightController.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  controllerSettings_Main /* Controller::HeightController::PIDHeightController::controllerParts */ controllerParts;
  kcg_real /* Controller::HeightController::PIDHeightController::motorValue */ motorValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_integralTermHC_Controller_HeightController /* 1 */ _1_Context_1;
  outC_derivativeTermHC_Controller_HeightController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_PIDHeightController_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::PIDHeightController */
extern void PIDHeightController_Controller_HeightController(
  /* Controller::HeightController::PIDHeightController::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::PIDHeightController::actualValue */kcg_real actualValue,
  /* Controller::HeightController::PIDHeightController::settingValues */controllerSettings_Main *settingValues,
  /* Controller::HeightController::PIDHeightController::speedValue */kcg_real speedValue,
  /* Controller::HeightController::PIDHeightController::integralStartValue */kcg_real integralStartValue,
  /* Controller::HeightController::PIDHeightController::activeSignal */kcg_bool activeSignal,
  outC_PIDHeightController_Controller_HeightController *outC);

extern void PIDHeightController_reset_Controller_HeightController(
  outC_PIDHeightController_Controller_HeightController *outC);

#endif /* _PIDHeightController_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** PIDHeightController_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

