/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _integralTerm_Controller_AttitudeController_H_
#define _integralTerm_Controller_AttitudeController_H_

#include "kcg_types.h"
#include "minMaxLimitation_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::integralTerm::iValue */ iValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_integralTerm_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::integralTerm */
extern void integralTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::integralTerm::Ki */kcg_real Ki,
  /* Controller::AttitudeController::integralTerm::differenceValue */kcg_real differenceValue,
  /* Controller::AttitudeController::integralTerm::integralStartValue */kcg_real integralStartValue,
  /* Controller::AttitudeController::integralTerm::motorsOnSignal */kcg_bool motorsOnSignal,
  outC_integralTerm_Controller_AttitudeController *outC);

extern void integralTerm_reset_Controller_AttitudeController(
  outC_integralTerm_Controller_AttitudeController *outC);

#endif /* _integralTerm_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** integralTerm_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

