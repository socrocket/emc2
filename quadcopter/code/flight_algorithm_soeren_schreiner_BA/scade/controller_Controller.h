/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _controller_Controller_H_
#define _controller_Controller_H_

#include "kcg_types.h"
#include "calculateMotorSpeed_Controller_CalculateMotorSpeed.h"
#include "heightController_Controller_HeightController.h"
#include "attitudeController_Controller_AttitudeController.h"
#include "setpoints_Controller_Setpoint.h"
#include "signalprocessing_Controller_Signalprocessing.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  motorValues_Main /* Controller::controller::motorValues */ motorValues;
  analogOffsetValues_Main /* Controller::controller::analogCorrectedOffsetValues */ analogCorrectedOffsetValues;
  angleValues_Main /* Controller::controller::anlgeValues */ anlgeValues;
  angleValues_Main /* Controller::controller::angleSpeedValues */ angleSpeedValues;
  kcg_real /* Controller::controller::heightValue */ heightValue;
  kcg_real /* Controller::controller::heightSpeedValue */ heightSpeedValue;
  rcValuesReal_Main /* Controller::controller::setpointValues */ setpointValues;
  attitudeController_Main /* Controller::controller::attitudeControllerValues */ attitudeControllerValues;
  heightController_Main /* Controller::controller::heightControllerValues */ heightControllerValues;
  accelerationAngles_Main /* Controller::controller::accelerationAngleValues */ accelerationAngleValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_signalprocessing_Controller_Signalprocessing /* 1 */ _3_Context_1;
  outC_setpoints_Controller_Setpoint /* 1 */ _2_Context_1;
  outC_heightController_Controller_HeightController /* 1 */ _1_Context_1;
  outC_attitudeController_Controller_AttitudeController /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_controller_Controller;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::controller */
extern void controller_Controller(
  /* Controller::controller::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::controller::rcValues */rcValues_Main *rcValues,
  /* Controller::controller::analogValues */analogValues_Main *analogValues,
  /* Controller::controller::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_controller_Controller *outC);

extern void controller_reset_Controller(outC_controller_Controller *outC);

#endif /* _controller_Controller_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** controller_Controller.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

