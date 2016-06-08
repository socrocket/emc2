/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calcAngleValues_Controller_Signalprocessing.h"

void calcAngleValues_reset_Controller_Signalprocessing(
  outC_calcAngleValues_Controller_Signalprocessing *outC)
{
  /* 1 */
  driftCorrectionAngles_reset_Controller_Signalprocessing(&outC->Context_1);
}

/* Controller::Signalprocessing::calcAngleValues */
void calcAngleValues_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcAngleValues::oldAngleValues */angleValues_Main *oldAngleValues,
  /* Controller::Signalprocessing::calcAngleValues::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::calcAngleValues::accelerations */accelerations_Main *accelerations,
  /* Controller::Signalprocessing::calcAngleValues::compassValue */kcg_real compassValue,
  /* Controller::Signalprocessing::calcAngleValues::angleSpeeds */angleValues_Main *angleSpeeds,
  /* Controller::Signalprocessing::calcAngleValues::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_calcAngleValues_Controller_Signalprocessing *outC)
{
  angleValues_Main tmp1;
  angleValues_Main tmp;
  
  /* 1 */
  accelerationAngles_Controller_Signalprocessing(
    accelerations,
    &outC->accelertionAngles);
  /* 1 */
  calcDiscreteAngleChanges_Controller_Signalprocessing(angleSpeeds, &tmp);
  /* 1 */
  angleTransformation_Controller_Signalprocessing(&tmp, sinCosValues, &tmp1);
  /* 1 */
  angleIntegration_Controller_Signalprocessing(&tmp1, oldAngleValues, &tmp);
  /* 1 */ angleLimitationBlock_Controller_Signalprocessing(&tmp, &tmp1);
  /* 1 */
  driftCorrectionAngles_Controller_Signalprocessing(
    &outC->accelertionAngles,
    compassValue,
    &tmp1,
    &outC->Context_1);
  kcg_copy_angleValues_Main(
    &outC->angleValues,
    &outC->Context_1.angleValuesFiltered);
  kcg_copy_angleValues_Main(&tmp, &outC->Context_1.diffValues);
  /* 1 */
  offsetCorrectionBlock_Controller_Signalprocessing(
    &outC->angleValues,
    &tmp,
    analogOffsetValues,
    &outC->analogCorrectedOffsetValues);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcAngleValues_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

