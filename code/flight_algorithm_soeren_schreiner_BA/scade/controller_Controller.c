/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "controller_Controller.h"

void controller_reset_Controller(outC_controller_Controller *outC)
{
  /* 1 */
  attitudeController_reset_Controller_AttitudeController(&outC->Context_1);
  /* 1 */
  heightController_reset_Controller_HeightController(&outC->_1_Context_1);
  /* 1 */ setpoints_reset_Controller_Setpoint(&outC->_2_Context_1);
  /* 1 */
  signalprocessing_reset_Controller_Signalprocessing(&outC->_3_Context_1);
}

/* Controller::controller */
void controller_Controller(
  /* Controller::controller::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::controller::rcValues */rcValues_Main *rcValues,
  /* Controller::controller::analogValues */analogValues_Main *analogValues,
  /* Controller::controller::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_controller_Controller *outC)
{
  /* Controller::controller::_L11 */ kcg_real _L11;
  /* Controller::controller::_L12 */ kcg_real _L12;
  /* Controller::controller::_L13 */ kcg_real _L13;
  /* Controller::controller::_L14 */ kcg_real _L14;
  
  /* 1 */
  signalprocessing_Controller_Signalprocessing(
    analogValues,
    analogOffsetValues,
    &outC->_3_Context_1);
  kcg_copy_angleValues_Main(
    &outC->anlgeValues,
    &outC->_3_Context_1.angleValues);
  kcg_copy_angleValues_Main(
    &outC->angleSpeedValues,
    &outC->_3_Context_1.angleSpeedValues);
  outC->heightValue = outC->_3_Context_1.heightValue;
  outC->heightSpeedValue = outC->_3_Context_1.heightSpeedValue;
  kcg_copy_analogOffsetValues_Main(
    &outC->analogCorrectedOffsetValues,
    &outC->_3_Context_1.analogCorrectedOffsetValues);
  kcg_copy_accelerationAngles_Main(
    &outC->accelerationAngleValues,
    &outC->_3_Context_1.accelertionAngles);
  /* 1 */
  setpoints_Controller_Setpoint(
    rcFlags,
    rcValues,
    &outC->anlgeValues,
    &outC->_2_Context_1);
  kcg_copy_rcValuesReal_Main(
    &outC->setpointValues,
    &outC->_2_Context_1.setpointValues);
  /* 1 */
  heightController_Controller_HeightController(
    rcFlags,
    &outC->setpointValues,
    outC->heightValue,
    outC->heightSpeedValue,
    &outC->_1_Context_1);
  _L11 = outC->_1_Context_1.thrust;
  kcg_copy_heightController_Main(
    &outC->heightControllerValues,
    &outC->_1_Context_1.heightControllerValues);
  /* 1 */
  attitudeController_Controller_AttitudeController(
    rcFlags,
    &outC->setpointValues,
    &outC->anlgeValues,
    &outC->angleSpeedValues,
    &outC->Context_1);
  _L12 = outC->Context_1.psi;
  _L13 = outC->Context_1.theta;
  _L14 = outC->Context_1.phi;
  kcg_copy_attitudeController_Main(
    &outC->attitudeControllerValues,
    &outC->Context_1.attitudeControllerValues);
  /* 1 */
  calculateMotorSpeed_Controller_CalculateMotorSpeed(
    rcFlags,
    _L12,
    _L13,
    _L14,
    _L11,
    &outC->motorValues);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** controller_Controller.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

