/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _main_Main_H_
#define _main_Main_H_

#include "kcg_types.h"
#include "controller_Controller.h"

/* ========================  input structure  ====================== */
typedef struct {
  rcFlags_Main /* Main::main::rcFlags */ rcFlags;
  rcValues_Main /* Main::main::rcValues */ rcValues;
  analogValues_Main /* Main::main::analogValues */ analogValues;
  analogOffsetValues_Main /* Main::main::analogOffsetValues */ analogOffsetValues;
} inC_main_Main;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  motorValues_Main /* Main::main::motorValues */ motorValues;
  angleValues_Main /* Main::main::anlgeValues */ anlgeValues;
  angleValues_Main /* Main::main::anlgeSpeedValues */ anlgeSpeedValues;
  kcg_real /* Main::main::heightValue */ heightValue;
  kcg_real /* Main::main::heightSpeedValue */ heightSpeedValue;
  analogOffsetValues_Main /* Main::main::analogCorrectedOffsetValues */ analogCorrectedOffsetValues;
  rcValuesReal_Main /* Main::main::setpointValues */ setpointValues;
  attitudeController_Main /* Main::main::attitudeControllerValues */ attitudeControllerValues;
  heightController_Main /* Main::main::heightControllerValues */ heightControllerValues;
  accelerationAngles_Main /* Main::main::accelerationAngleValues */ accelerationAngleValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_controller_Controller /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_main_Main;

/* ===========  node initialization and cycle functions  =========== */
/* Main::main */
extern void main_Main(inC_main_Main *inC, outC_main_Main *outC);

extern void main_reset_Main(outC_main_Main *outC);

#endif /* _main_Main_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** main_Main.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

