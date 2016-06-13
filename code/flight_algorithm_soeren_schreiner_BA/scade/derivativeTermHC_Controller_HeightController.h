/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _derivativeTermHC_Controller_HeightController_H_
#define _derivativeTermHC_Controller_HeightController_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::HeightController::derivativeTermHC::dValue */ dValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_real /* Controller::HeightController::derivativeTermHC::differenceValue */ rem_differenceValue;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_derivativeTermHC_Controller_HeightController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::HeightController::derivativeTermHC */
extern void derivativeTermHC_Controller_HeightController(
  /* Controller::HeightController::derivativeTermHC::Kd */kcg_real Kd,
  /* Controller::HeightController::derivativeTermHC::differenceValue */kcg_real differenceValue,
  outC_derivativeTermHC_Controller_HeightController *outC);

extern void derivativeTermHC_reset_Controller_HeightController(
  outC_derivativeTermHC_Controller_HeightController *outC);

#endif /* _derivativeTermHC_Controller_HeightController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** derivativeTermHC_Controller_HeightController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

