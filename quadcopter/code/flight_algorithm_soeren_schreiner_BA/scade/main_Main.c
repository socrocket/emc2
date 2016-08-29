/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "main_Main.h"

void main_reset_Main(outC_main_Main *outC)
{
  /* 1 */ controller_reset_Controller(&outC->Context_1);
}

/* Main::main */
void main_Main(inC_main_Main *inC, outC_main_Main *outC)
{
  /* 1 */
  controller_Controller(
    &inC->rcFlags,
    &inC->rcValues,
    &inC->analogValues,
    &inC->analogOffsetValues,
    &outC->Context_1);
  kcg_copy_motorValues_Main(&outC->motorValues, &outC->Context_1.motorValues);
  kcg_copy_analogOffsetValues_Main(
    &outC->analogCorrectedOffsetValues,
    &outC->Context_1.analogCorrectedOffsetValues);
  kcg_copy_angleValues_Main(&outC->anlgeValues, &outC->Context_1.anlgeValues);
  kcg_copy_angleValues_Main(
    &outC->anlgeSpeedValues,
    &outC->Context_1.angleSpeedValues);
  outC->heightValue = outC->Context_1.heightValue;
  outC->heightSpeedValue = outC->Context_1.heightSpeedValue;
  kcg_copy_rcValuesReal_Main(
    &outC->setpointValues,
    &outC->Context_1.setpointValues);
  kcg_copy_attitudeController_Main(
    &outC->attitudeControllerValues,
    &outC->Context_1.attitudeControllerValues);
  kcg_copy_heightController_Main(
    &outC->heightControllerValues,
    &outC->Context_1.heightControllerValues);
  kcg_copy_accelerationAngles_Main(
    &outC->accelerationAngleValues,
    &outC->Context_1.accelerationAngleValues);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** main_Main.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

