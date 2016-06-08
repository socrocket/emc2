/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PIDControllerTheta_Controller_AttitudeController.h"

void PIDControllerTheta_reset_Controller_AttitudeController(
  outC_PIDControllerTheta_Controller_AttitudeController *outC)
{
  /* 1 */ derivativeTerm_reset_Controller_AttitudeController(&outC->Context_1);
  /* 1 */ integralTerm_reset_Controller_AttitudeController(&outC->_1_Context_1);
}

/* Controller::AttitudeController::PIDControllerTheta */
void PIDControllerTheta_Controller_AttitudeController(
  /* Controller::AttitudeController::PIDControllerTheta::setpointValue */kcg_real setpointValue,
  /* Controller::AttitudeController::PIDControllerTheta::actualValue */kcg_real actualValue,
  /* Controller::AttitudeController::PIDControllerTheta::settingValues */controllerSettings_Main *settingValues,
  /* Controller::AttitudeController::PIDControllerTheta::angleSpeedValue */kcg_real angleSpeedValue,
  /* Controller::AttitudeController::PIDControllerTheta::integralStartValue */kcg_real integralStartValue,
  /* Controller::AttitudeController::PIDControllerTheta::motorsOnSignal */kcg_bool motorsOnSignal,
  outC_PIDControllerTheta_Controller_AttitudeController *outC)
{
  /* Controller::AttitudeController::PIDControllerTheta::_L37 */ kcg_real _L37;
  /* Controller::AttitudeController::PIDControllerTheta::_L40 */ kcg_real _L40;
  
  _L40 = /* 1 */ angleLimitation90_Functions(setpointValue - actualValue);
  _L37 = /* 1 */
    proportionalTerm_Controller_AttitudeController((*settingValues).Kp, _L40);
  outC->controllerParts.Kp = _L37;
  /* 1 */
  integralTerm_Controller_AttitudeController(
    (*settingValues).Ki,
    _L40,
    integralStartValue,
    motorsOnSignal,
    &outC->_1_Context_1);
  outC->controllerParts.Ki = outC->_1_Context_1.iValue;
  /* 1 */
  derivativeTerm_Controller_AttitudeController(
    (*settingValues).Kd,
    _L40,
    &outC->Context_1);
  outC->controllerParts.Kd = outC->Context_1.dValue;
  _L40 = /* 1 */
    dampingTerm_Controller_AttitudeController(
      (*settingValues).Ks,
      angleSpeedValue);
  outC->controllerParts.Ks = _L40;
  outC->motorValue = _L37 + outC->_1_Context_1.iValue + outC->Context_1.dValue -
    _L40;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** PIDControllerTheta_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

