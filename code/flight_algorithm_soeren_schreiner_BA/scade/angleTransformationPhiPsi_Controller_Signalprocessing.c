/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleTransformationPhiPsi_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::angleTransformationPhiPsi */
void angleTransformationPhiPsi_Controller_Signalprocessing(
  /* Controller::Signalprocessing::angleTransformationPhiPsi::angleSteps */angleValues_Main *angleSteps,
  /* Controller::Signalprocessing::angleTransformationPhiPsi::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::angleTransformationPhiPsi::angleStepsTransformedPhiPsi */angleValues_Main *angleStepsTransformedPhiPsi)
{
  /* Controller::Signalprocessing::angleTransformationPhiPsi::_L14 */ kcg_real _L14;
  
  (*angleStepsTransformedPhiPsi).theta = (*angleSteps).theta;
  _L14 = (*angleSteps).theta * (*sinCosValues).sinPhi + (*angleSteps).psi *
    (*sinCosValues).cosPhi;
  (*angleStepsTransformedPhiPsi).phi = (*angleSteps).phi + _L14 *
    ((*sinCosValues).sinTheta / (*sinCosValues).cosTheta);
  (*angleStepsTransformedPhiPsi).psi = _L14 / (*sinCosValues).cosTheta;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleTransformationPhiPsi_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

