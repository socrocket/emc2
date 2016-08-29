/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleTransformation_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::angleTransformation */
void angleTransformation_Controller_Signalprocessing(
  /* Controller::Signalprocessing::angleTransformation::angleSteps */angleValues_Main *angleSteps,
  /* Controller::Signalprocessing::angleTransformation::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::angleTransformation::angleStepsTransformed */angleValues_Main *angleStepsTransformed)
{
  /* Controller::Signalprocessing::angleTransformation::_L16 */ kcg_bool _L16;
  /* Controller::Signalprocessing::angleTransformation::_L18 */ angleValues_Main _L18;
  
  (*angleStepsTransformed).theta = (*angleSteps).theta *
    (*sinCosValues).cosPhi - (*angleSteps).psi * (*sinCosValues).sinPhi;
  _L16 = (*sinCosValues).cosTheta != ZERO_REAL_Main;
  if (_L16) {
    /* 1 */
    angleTransformationPhiPsi_Controller_Signalprocessing(
      angleSteps,
      sinCosValues,
      &_L18);
  }
  else {
    kcg_copy_angleValues_Main(&_L18, angleSteps);
  }
  (*angleStepsTransformed).phi = _L18.phi;
  (*angleStepsTransformed).psi = _L18.psi;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleTransformation_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

