/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _integralTermHC_Controller_HeightController_H_
#define _integralTermHC_Controller_HeightController_H_

#include "kcg_types.h"
#include "minMaxLimitation_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::HeightController::integralTermHC::iValue */ iValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Controller::HeightController::integralTermHC::activeSignal */ rem_activeSignal;
  kcg_real /* Controller::HeightController::integralTermHC::setpointValue */ rem_setpointValue;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_integralTermHC_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::integralTermHC */
extern void integralTermHC_Controller_HeightController(
  /* Controller::HeightController::integralTermHC::Ki */kcg_real Ki,
  /* Controller::HeightController::integralTermHC::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::integralTermHC::differenceValue */kcg_real differenceValue,
  /* Controller::HeightController::integralTermHC::integralStartValue */kcg_real integralStartValue,
  /* Controller::HeightController::integralTermHC::activeSignal */kcg_bool activeSignal,
  outC_integralTermHC_Controller_HeightController *outC);

extern void integralTermHC_reset_Controller_HeightController(
  outC_integralTermHC_Controller_HeightController *outC);

#endif /* _integralTermHC_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** integralTermHC_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

