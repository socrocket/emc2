/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "signalprocessing_Controller_Signalprocessing.h"

void signalprocessing_reset_Controller_Signalprocessing(
  outC_signalprocessing_Controller_Signalprocessing *outC)
{
  outC->init = kcg_true;
  /* 1 */ calcAngleValues_reset_Controller_Signalprocessing(&outC->Context_1);
  /* 1 */
  calcHeightValues_reset_Controller_Signalprocessing(&outC->_1_Context_1);
  /* 1 */
  meanSquareFilterBlock_reset_Controller_Signalprocessing(&outC->_2_Context_1);
}

/* Controller::Signalprocessing::signalprocessing */
void signalprocessing_Controller_Signalprocessing(
  /* Controller::Signalprocessing::signalprocessing::analogValues */analogValues_Main *analogValues,
  /* Controller::Signalprocessing::signalprocessing::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_signalprocessing_Controller_Signalprocessing *outC)
{
  analogValuesReal_Main tmp;
  /* Controller::Signalprocessing::signalprocessing::_L25 */ sinCosValues_Main _L25;
  /* Controller::Signalprocessing::signalprocessing::_L30 */ kcg_real _L30;
  /* Controller::Signalprocessing::signalprocessing::_L49 */ angleValues_Main _L49;
  /* Controller::Signalprocessing::signalprocessing::_L31 */ kcg_real _L31;
  /* Controller::Signalprocessing::signalprocessing::_L29 */ accelerations_Main _L29;
  
  if (outC->init) {
    kcg_copy_angleValues_Main(&_L49, (angleValues_Main *) &ANGLES_INIT_Main);
  }
  else {
    kcg_copy_angleValues_Main(&_L49, &outC->angleValues);
  }
  /* 1 */ sinCosValues_Controller_Signalprocessing(&_L49, &_L25);
  /* 1 */
  setOffsets_Controller_Signalprocessing(
    analogValues,
    analogOffsetValues,
    &tmp);
  /* 1 */
  meanSquareFilterBlock_Controller_Signalprocessing(&tmp, &outC->_2_Context_1);
  /* 1 */
  calcUnitsFromAnalog_Controller_Signalprocessing(
    &outC->_2_Context_1.analogValuesFiltered,
    &_L30,
    &_L29,
    &_L31,
    &outC->angleSpeedValues);
  /* 1 */
  calcHeightValues_Controller_Signalprocessing(
    &_L25,
    _L30,
    &_L29,
    &outC->_1_Context_1);
  outC->heightSpeedValue = outC->_1_Context_1.heightSpeedValue;
  outC->heightValue = outC->_1_Context_1.heightValue;
  /* 1 */
  calcAngleValues_Controller_Signalprocessing(
    &_L49,
    &_L25,
    &_L29,
    _L31,
    &outC->angleSpeedValues,
    analogOffsetValues,
    &outC->Context_1);
  kcg_copy_accelerationAngles_Main(
    &outC->accelertionAngles,
    &outC->Context_1.accelertionAngles);
  kcg_copy_analogOffsetValues_Main(
    &outC->analogCorrectedOffsetValues,
    &outC->Context_1.analogCorrectedOffsetValues);
  kcg_copy_angleValues_Main(&outC->angleValues, &outC->Context_1.angleValues);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** signalprocessing_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

