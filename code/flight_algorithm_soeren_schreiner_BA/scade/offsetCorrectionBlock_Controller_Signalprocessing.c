/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "offsetCorrectionBlock_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::offsetCorrectionBlock */
void offsetCorrectionBlock_Controller_Signalprocessing(
  /* Controller::Signalprocessing::offsetCorrectionBlock::angleValues */angleValues_Main *angleValues,
  /* Controller::Signalprocessing::offsetCorrectionBlock::diffValues */angleValues_Main *diffValues,
  /* Controller::Signalprocessing::offsetCorrectionBlock::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  /* Controller::Signalprocessing::offsetCorrectionBlock::analogCorrectedOffsetValues */analogOffsetValues_Main *analogCorrectedOffsetValues)
{
  kcg_real tmp1;
  kcg_real tmp;
  
  if (0 <= (*angleValues).theta) {
    tmp1 = (*angleValues).theta;
  }
  else {
    tmp1 = - (*angleValues).theta;
  }
  if (0 <= (*angleValues).phi) {
    tmp = (*angleValues).phi;
  }
  else {
    tmp = - (*angleValues).phi;
  }
  if ((tmp1 > DEACTIVATE_OFFSET_CORRECTION_Main) | (tmp >
      DEACTIVATE_OFFSET_CORRECTION_Main)) {
    kcg_copy_analogOffsetValues_Main(
      analogCorrectedOffsetValues,
      analogOffsetValues);
  }
  else {
    (*analogCorrectedOffsetValues).accX = (*analogOffsetValues).accX;
    (*analogCorrectedOffsetValues).accY = (*analogOffsetValues).accY;
    (*analogCorrectedOffsetValues).accZ = (*analogOffsetValues).accZ;
    (*analogCorrectedOffsetValues).barometer = (*analogOffsetValues).barometer;
    (*analogCorrectedOffsetValues).gyroPitch = /* 1 */
      offsetCorrection_Functions(
        (*analogOffsetValues).gyroPitch,
        (*diffValues).theta,
        GYRO_CORRECTION_Main);
    (*analogCorrectedOffsetValues).gyroRoll = /* 2 */
      offsetCorrection_Functions(
        (*analogOffsetValues).gyroRoll,
        (*diffValues).phi,
        GYRO_CORRECTION_Main);
    (*analogCorrectedOffsetValues).gyroYaw = /* 3 */
      offsetCorrection_Functions(
        (*analogOffsetValues).gyroYaw,
        (*diffValues).psi,
        GYRO_CORRECTION_Main);
  }
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** offsetCorrectionBlock_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

