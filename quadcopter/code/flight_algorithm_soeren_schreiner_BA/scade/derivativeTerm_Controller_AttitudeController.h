/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _derivativeTerm_Controller_AttitudeController_H_
#define _derivativeTerm_Controller_AttitudeController_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::AttitudeController::derivativeTerm::dValue */ dValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_real /* Controller::AttitudeController::derivativeTerm::differenceValue */ rem_differenceValue;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_derivativeTerm_Controller_AttitudeController;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::AttitudeController::derivativeTerm */
extern void derivativeTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::derivativeTerm::Kd */kcg_real Kd,
  /* Controller::AttitudeController::derivativeTerm::differenceValue */kcg_real differenceValue,
  outC_derivativeTerm_Controller_AttitudeController *outC);

extern void derivativeTerm_reset_Controller_AttitudeController(
  outC_derivativeTerm_Controller_AttitudeController *outC);

#endif /* _derivativeTerm_Controller_AttitudeController_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** derivativeTerm_Controller_AttitudeController.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

