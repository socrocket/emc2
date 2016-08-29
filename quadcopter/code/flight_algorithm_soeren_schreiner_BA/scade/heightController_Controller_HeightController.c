/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "heightController_Controller_HeightController.h"

void heightController_reset_Controller_HeightController(
  outC_heightController_Controller_HeightController *outC)
{
  /* 1 */
  PIDHeightController_reset_Controller_HeightController(&outC->Context_1);
  /* 1 */
  getHeightSetpoint_reset_Controller_HeightController(&outC->_1_Context_1);
  /* 1 */
  getOffsetGasPosition_reset_Controller_HeightController(&outC->_2_Context_1);
}

/* Controller::HeightController::heightController */
void heightController_Controller_HeightController(
  /* Controller::HeightController::heightController::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::HeightController::heightController::setpointValues */rcValuesReal_Main *setpointValues,
  /* Controller::HeightController::heightController::heightValue */kcg_real heightValue,
  /* Controller::HeightController::heightController::heightSpeedValue */kcg_real heightSpeedValue,
  outC_heightController_Controller_HeightController *outC)
{
  /* Controller::HeightController::heightController::_L38 */ kcg_bool _L38;
  
  _L38 = (*rcFlags).motorsOn & ((*rcFlags).heightControl |
      (*rcFlags).lostConnection);
  outC->heightControllerValues.activated = _L38;
  /* 1 */
  getOffsetGasPosition_Controller_HeightController(
    (*rcFlags).lostConnection,
    _L38,
    (*setpointValues).thrust,
    &outC->_2_Context_1);
  outC->heightControllerValues.setpoint = outC->_2_Context_1.setpointValue;
  /* 1 */
  getHeightSetpoint_Controller_HeightController(
    _L38,
    outC->_2_Context_1.setpointValue,
    heightValue,
    &outC->_1_Context_1);
  /* 1 */
  PIDHeightController_Controller_HeightController(
    outC->_1_Context_1.heightSetpointValue,
    heightValue,
    (controllerSettings_Main *) &CONTROLLER_HEIGHT_SETTINGS_Main,
    heightSpeedValue,
    (*setpointValues).thrust,
    _L38,
    &outC->Context_1);
  kcg_copy_controllerSettings_Main(
    &outC->heightControllerValues.thrust,
    &outC->Context_1.controllerParts);
  outC->heightControllerValues.thrustFinal = outC->Context_1.motorValue;
  if (_L38) {
    outC->thrust = outC->Context_1.motorValue;
  }
  else {
    outC->thrust = (*setpointValues).thrust;
  }
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** heightController_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

