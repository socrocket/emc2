/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "driftCorrectionAngles_Controller_Signalprocessing.h"

void driftCorrectionAngles_reset_Controller_Signalprocessing(
  outC_driftCorrectionAngles_Controller_Signalprocessing *outC)
{
  outC->init = kcg_true;
}

/* Controller::Signalprocessing::driftCorrectionAngles */
void driftCorrectionAngles_Controller_Signalprocessing(
  /* Controller::Signalprocessing::driftCorrectionAngles::accelerationAngles */accelerationAngles_Main *accelerationAngles,
  /* Controller::Signalprocessing::driftCorrectionAngles::compassValue */kcg_real compassValue,
  /* Controller::Signalprocessing::driftCorrectionAngles::angleValues */angleValues_Main *angleValues,
  outC_driftCorrectionAngles_Controller_Signalprocessing *outC)
{
  /* Controller::Signalprocessing::driftCorrectionAngles::_L18 */ kcg_real _L18;
  /* Controller::Signalprocessing::driftCorrectionAngles::_L45 */ kcg_real _L45;
  /* Controller::Signalprocessing::driftCorrectionAngles::_L44 */ kcg_real _L44;
  
  if (0 <= (*angleValues).phi) {
    _L45 = (*angleValues).phi;
  }
  else {
    _L45 = - (*angleValues).phi;
  }
  if (0 <= (*angleValues).theta) {
    _L18 = (*angleValues).theta;
  }
  else {
    _L18 = - (*angleValues).theta;
  }
  /* 2 */
  kalmanFilter180_Functions(
    (*accelerationAngles).accPhi,
    (*angleValues).phi,
    KALMAN_THETA_PHI_MAX_Main - KALMAN_THETA_PHI_CONSTANT_Main * _L45,
    &outC->angleValuesFiltered.phi,
    &outC->diffValues.phi);
  if (outC->init) {
    _L44 = compassValue;
  }
  else {
    _L44 = (*angleValues).psi;
  }
  /* 3 */
  kalmanFilter180_Functions(
    compassValue,
    _L44,
    KALMAN_PSI_MAX_Main - KALMAN_PSI_CONSTANT_Main * (_L18 + _L45),
    &outC->angleValuesFiltered.psi,
    &outC->diffValues.psi);
  /* 1 */
  kalmanFilter90_Functions(
    (*accelerationAngles).accTheta,
    (*angleValues).theta,
    KALMAN_THETA_PHI_MAX_Main - KALMAN_THETA_PHI_CONSTANT_Main * _L18,
    &outC->angleValuesFiltered.theta,
    &outC->diffValues.theta);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** driftCorrectionAngles_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

