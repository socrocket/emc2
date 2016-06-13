/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "attitudeController_Controller_AttitudeController.h"

void attitudeController_reset_Controller_AttitudeController(
  outC_attitudeController_Controller_AttitudeController *outC)
{
  /* 1 */
  PIDControllerTheta_reset_Controller_AttitudeController(&outC->Context_1);
  /* 2 */
  PIDControllerPhiPsi_reset_Controller_AttitudeController(&outC->Context_2);
  /* 3 */
  PIDControllerPhiPsi_reset_Controller_AttitudeController(&outC->Context_3);
  /* 1 */
  getPsiSetpoint_reset_Controller_AttitudeController(&outC->_1_Context_1);
}

/* Controller::AttitudeController::attitudeController */
void attitudeController_Controller_AttitudeController(
  /* Controller::AttitudeController::attitudeController::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::AttitudeController::attitudeController::setpointValues */rcValuesReal_Main *setpointValues,
  /* Controller::AttitudeController::attitudeController::angleValues */angleValues_Main *angleValues,
  /* Controller::AttitudeController::attitudeController::angleSpeedValues */angleValues_Main *angleSpeedValues,
  outC_attitudeController_Controller_AttitudeController *outC)
{
  /* Controller::AttitudeController::attitudeController::_L58 */ rcValuesReal_Main _L58;
  
  if ((*rcFlags).lostConnection) {
    _L58.thrust = (*setpointValues).thrust;
    _L58.yaw = ZERO_REAL_Main;
    _L58.pitch = ZERO_REAL_Main;
    _L58.roll = ZERO_REAL_Main;
  }
  else {
    kcg_copy_rcValuesReal_Main(&_L58, setpointValues);
  }
  /* 1 */
  getPsiSetpoint_Controller_AttitudeController(
    _L58.thrust,
    _L58.yaw,
    (*angleValues).psi,
    (*rcFlags).motorsOn,
    &outC->_1_Context_1);
  /* 3 */
  PIDControllerPhiPsi_Controller_AttitudeController(
    outC->_1_Context_1.psiSetpointValue,
    (*angleValues).psi,
    (controllerSettings_Main *) &CONTROLLER_PSI_SETTINGS_Main,
    (*angleSpeedValues).psi,
    ZERO_REAL_Main,
    (*rcFlags).motorsOn,
    &outC->Context_3);
  kcg_copy_controllerSettings_Main(
    &outC->attitudeControllerValues.psi,
    &outC->Context_3.controllerParts);
  outC->psi = outC->Context_3.motorValue;
  outC->attitudeControllerValues.psiFinal = outC->psi;
  /* 2 */
  PIDControllerPhiPsi_Controller_AttitudeController(
    _L58.roll,
    (*angleValues).phi,
    (controllerSettings_Main *) &CONTROLLER_THETA_PHI_SETTINGS_Main,
    (*angleSpeedValues).phi,
    ZERO_REAL_Main,
    (*rcFlags).motorsOn,
    &outC->Context_2);
  kcg_copy_controllerSettings_Main(
    &outC->attitudeControllerValues.phi,
    &outC->Context_2.controllerParts);
  outC->phi = outC->Context_2.motorValue;
  outC->attitudeControllerValues.phiFinal = outC->phi;
  /* 1 */
  PIDControllerTheta_Controller_AttitudeController(
    _L58.pitch,
    (*angleValues).theta,
    (controllerSettings_Main *) &CONTROLLER_THETA_PHI_SETTINGS_Main,
    (*angleSpeedValues).theta,
    ZERO_REAL_Main,
    (*rcFlags).motorsOn,
    &outC->Context_1);
  kcg_copy_controllerSettings_Main(
    &outC->attitudeControllerValues.theta,
    &outC->Context_1.controllerParts);
  outC->theta = outC->Context_1.motorValue;
  outC->attitudeControllerValues.thetaFinal = outC->theta;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** attitudeController_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

