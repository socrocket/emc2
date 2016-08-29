/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _setpoints_Controller_Setpoint_H_
#define _setpoints_Controller_Setpoint_H_

#include "kcg_types.h"
#include "setOffsets_Controller_Setpoint.h"
#include "rotationMatrix_Controller_Setpoint.h"
#include "limitationBlock_Controller_Setpoint.h"
#include "calcSetpoints_Controller_Setpoint.h"
#include "getPsiStartValue_Controller_Setpoint.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  rcValuesReal_Main /* Controller::Setpoint::setpoints::setpointValues */ setpointValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_getPsiStartValue_Controller_Setpoint /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_setpoints_Controller_Setpoint;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Setpoint::setpoints */
extern void setpoints_Controller_Setpoint(
  /* Controller::Setpoint::setpoints::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::Setpoint::setpoints::rcValues */rcValues_Main *rcValues,
  /* Controller::Setpoint::setpoints::angleValues */angleValues_Main *angleValues,
  outC_setpoints_Controller_Setpoint *outC);

extern void setpoints_reset_Controller_Setpoint(
  outC_setpoints_Controller_Setpoint *outC);

#endif /* _setpoints_Controller_Setpoint_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** setpoints_Controller_Setpoint.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

