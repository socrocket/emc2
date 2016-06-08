/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _getOffsetGasPosition_Controller_HeightController_H_
#define _getOffsetGasPosition_Controller_HeightController_H_

#include "kcg_types.h"
#include "rcAdjustingReal_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::HeightController::getOffsetGasPosition::setpointValue */ setpointValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_real /* Controller::HeightController::getOffsetGasPosition::_L3 */ _L3;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_getOffsetGasPosition_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::getOffsetGasPosition */
extern void getOffsetGasPosition_Controller_HeightController(
  /* Controller::HeightController::getOffsetGasPosition::lostConnectionSignal */kcg_bool lostConnectionSignal,
  /* Controller::HeightController::getOffsetGasPosition::activeSignal */kcg_bool activeSignal,
  /* Controller::HeightController::getOffsetGasPosition::thrustValue */kcg_real thrustValue,
  outC_getOffsetGasPosition_Controller_HeightController *outC);

extern void getOffsetGasPosition_reset_Controller_HeightController(
  outC_getOffsetGasPosition_Controller_HeightController *outC);

#endif /* _getOffsetGasPosition_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** getOffsetGasPosition_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

