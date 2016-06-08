/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calcHeightValues_Controller_Signalprocessing.h"

void calcHeightValues_reset_Controller_Signalprocessing(
  outC_calcHeightValues_Controller_Signalprocessing *outC)
{
  outC->init = kcg_true;
  /* 1 */
  driftCorrectionHeight_reset_Controller_Signalprocessing(&outC->Context_1);
}

/* Controller::Signalprocessing::calcHeightValues */
void calcHeightValues_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcHeightValues::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::calcHeightValues::heightBarometer */kcg_real heightBarometer,
  /* Controller::Signalprocessing::calcHeightValues::accelerations */accelerations_Main *accelerations,
  outC_calcHeightValues_Controller_Signalprocessing *outC)
{
  kcg_real tmp2;
  kcg_real tmp1;
  kcg_real tmp;
  /* Controller::Signalprocessing::calcHeightValues::_L4 */ kcg_real _L4;
  /* Controller::Signalprocessing::calcHeightValues::_L5 */ kcg_real _L5;
  
  tmp2 = /* 1 */
    accelerationGeoZ_Controller_Signalprocessing(accelerations, sinCosValues);
  if (outC->init) {
    tmp1 = 0.0;
    tmp = 0.0;
  }
  else {
    tmp1 = outC->heightValue;
    tmp = outC->heightSpeedValue;
  }
  /* 1 */
  accelerationIntegrationZ_Controller_Signalprocessing(
    tmp2,
    tmp1,
    tmp,
    &_L4,
    &_L5);
  /* 1 */
  driftCorrectionHeight_Controller_Signalprocessing(
    heightBarometer,
    _L4,
    _L5,
    &outC->Context_1);
  outC->heightValue = outC->Context_1.heightValue;
  outC->heightSpeedValue = outC->Context_1.heightSpeedValue;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcHeightValues_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

