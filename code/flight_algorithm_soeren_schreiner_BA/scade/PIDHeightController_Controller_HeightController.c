/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PIDHeightController_Controller_HeightController.h"

void PIDHeightController_reset_Controller_HeightController(
  outC_PIDHeightController_Controller_HeightController *outC)
{
  /* 1 */ derivativeTermHC_reset_Controller_HeightController(&outC->Context_1);
  /* 1 */ integralTermHC_reset_Controller_HeightController(&outC->_1_Context_1);
}

/* Controller::HeightController::PIDHeightController */
void PIDHeightController_Controller_HeightController(
  /* Controller::HeightController::PIDHeightController::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::PIDHeightController::actualValue */kcg_real actualValue,
  /* Controller::HeightController::PIDHeightController::settingValues */controllerSettings_Main *settingValues,
  /* Controller::HeightController::PIDHeightController::speedValue */kcg_real speedValue,
  /* Controller::HeightController::PIDHeightController::integralStartValue */kcg_real integralStartValue,
  /* Controller::HeightController::PIDHeightController::activeSignal */kcg_bool activeSignal,
  outC_PIDHeightController_Controller_HeightController *outC)
{
  /* Controller::HeightController::PIDHeightController::_L51 */ kcg_real _L51;
  /* Controller::HeightController::PIDHeightController::_L53 */ kcg_real _L53;
  
  _L51 = setpointValue - actualValue;
  _L53 = /* 1 */
    proportionalTermHC_Controller_HeightController((*settingValues).Kp, _L51);
  outC->controllerParts.Kp = _L53;
  /* 1 */
  integralTermHC_Controller_HeightController(
    (*settingValues).Ki,
    setpointValue,
    _L51,
    integralStartValue,
    activeSignal,
    &outC->_1_Context_1);
  outC->controllerParts.Ki = outC->_1_Context_1.iValue;
  /* 1 */
  derivativeTermHC_Controller_HeightController(
    (*settingValues).Kd,
    _L51,
    &outC->Context_1);
  outC->controllerParts.Kd = outC->Context_1.dValue;
  _L51 = /* 1 */
    dampingTermHC_Controller_HeightController((*settingValues).Ks, speedValue);
  outC->controllerParts.Ks = _L51;
  outC->motorValue = _L53 + outC->_1_Context_1.iValue + outC->Context_1.dValue -
    _L51;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** PIDHeightController_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

