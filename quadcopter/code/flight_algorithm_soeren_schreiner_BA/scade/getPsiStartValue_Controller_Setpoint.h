/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _getPsiStartValue_Controller_Setpoint_H_
#define _getPsiStartValue_Controller_Setpoint_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::Setpoint::getPsiStartValue::psiStartValue */ psiStartValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_getPsiStartValue_Controller_Setpoint;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Setpoint::getPsiStartValue */
extern void getPsiStartValue_Controller_Setpoint(
  /* Controller::Setpoint::getPsiStartValue::anglePsi */kcg_real anglePsi,
  /* Controller::Setpoint::getPsiStartValue::motorsOn */kcg_bool motorsOn,
  outC_getPsiStartValue_Controller_Setpoint *outC);

extern void getPsiStartValue_reset_Controller_Setpoint(
  outC_getPsiStartValue_Controller_Setpoint *outC);

#endif /* _getPsiStartValue_Controller_Setpoint_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** getPsiStartValue_Controller_Setpoint.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

