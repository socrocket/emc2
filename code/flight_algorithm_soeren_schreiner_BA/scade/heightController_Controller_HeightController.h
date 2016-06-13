/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _heightController_Controller_HeightController_H_
#define _heightController_Controller_HeightController_H_

#include "kcg_types.h"
#include "PIDHeightController_Controller_HeightController.h"
#include "getOffsetGasPosition_Controller_HeightController.h"
#include "getHeightSetpoint_Controller_HeightController.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::HeightController::heightController::thrust */ thrust;
  heightController_Main /* Controller::HeightController::heightController::heightControllerValues */ heightControllerValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_getOffsetGasPosition_Controller_HeightController /* 1 */ _2_Context_1;
  outC_getHeightSetpoint_Controller_HeightController /* 1 */ _1_Context_1;
  outC_PIDHeightController_Controller_HeightController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_heightController_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::heightController */
extern void heightController_Controller_HeightController(
  /* Controller::HeightController::heightController::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::HeightController::heightController::setpointValues */rcValuesReal_Main *setpointValues,
  /* Controller::HeightController::heightController::heightValue */kcg_real heightValue,
  /* Controller::HeightController::heightController::heightSpeedValue */kcg_real heightSpeedValue,
  outC_heightController_Controller_HeightController *outC);

extern void heightController_reset_Controller_HeightController(
  outC_heightController_Controller_HeightController *outC);

#endif /* _heightController_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** heightController_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

