/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _getHeightSetpoint_Controller_HeightController_H_
#define _getHeightSetpoint_Controller_HeightController_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::HeightController::getHeightSetpoint::heightSetpointValue */ heightSetpointValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_getHeightSetpoint_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::getHeightSetpoint */
extern void getHeightSetpoint_Controller_HeightController(
  /* Controller::HeightController::getHeightSetpoint::activeSignal */kcg_bool activeSignal,
  /* Controller::HeightController::getHeightSetpoint::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::getHeightSetpoint::heightValue */kcg_real heightValue,
  outC_getHeightSetpoint_Controller_HeightController *outC);

extern void getHeightSetpoint_reset_Controller_HeightController(
  outC_getHeightSetpoint_Controller_HeightController *outC);

#endif /* _getHeightSetpoint_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** getHeightSetpoint_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

