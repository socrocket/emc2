/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "meanSquareFilterBlock_Controller_Signalprocessing.h"

void meanSquareFilterBlock_reset_Controller_Signalprocessing(
  outC_meanSquareFilterBlock_Controller_Signalprocessing *outC)
{
  /* 7 */ meanSquareFilter_reset_Functions(&outC->Context_7);
  /* 6 */ meanSquareFilter_reset_Functions(&outC->Context_6);
  /* 5 */ meanSquareFilter_reset_Functions(&outC->Context_5);
  /* 4 */ meanSquareFilter_reset_Functions(&outC->Context_4);
  /* 3 */ meanSquareFilter_reset_Functions(&outC->Context_3);
  /* 2 */ meanSquareFilter_reset_Functions(&outC->Context_2);
  /* 1 */ meanSquareFilter_reset_Functions(&outC->Context_1);
}

/* Controller::Signalprocessing::meanSquareFilterBlock */
void meanSquareFilterBlock_Controller_Signalprocessing(
  /* Controller::Signalprocessing::meanSquareFilterBlock::analogAdjustedValues */analogValuesReal_Main *analogAdjustedValues,
  outC_meanSquareFilterBlock_Controller_Signalprocessing *outC)
{
  outC->analogValuesFiltered.compass = (*analogAdjustedValues).compass;
  /* 1 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).accX,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_1);
  outC->analogValuesFiltered.accX = outC->Context_1.filterValue;
  /* 2 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).accY,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_2);
  outC->analogValuesFiltered.accY = outC->Context_2.filterValue;
  /* 3 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).accZ,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_3);
  outC->analogValuesFiltered.accZ = outC->Context_3.filterValue;
  /* 4 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).gyroPitch,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_4);
  outC->analogValuesFiltered.gyroPitch = outC->Context_4.filterValue;
  /* 5 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).gyroRoll,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_5);
  outC->analogValuesFiltered.gyroRoll = outC->Context_5.filterValue;
  /* 6 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).gyroYaw,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_6);
  outC->analogValuesFiltered.gyroYaw = outC->Context_6.filterValue;
  /* 7 */
  meanSquareFilter_Functions(
    (*analogAdjustedValues).barometer,
    WEIGHT_NEW_VALUE_Main,
    &outC->Context_7);
  outC->analogValuesFiltered.barometer = outC->Context_7.filterValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** meanSquareFilterBlock_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

