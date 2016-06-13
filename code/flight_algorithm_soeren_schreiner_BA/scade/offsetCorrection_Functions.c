/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "offsetCorrection_Functions.h"

/* Functions::offsetCorrection */
kcg_real offsetCorrection_Functions(
  /* Functions::offsetCorrection::analogOffsetValue */kcg_real analogOffsetValue,
  /* Functions::offsetCorrection::diffValue */kcg_real diffValue,
  /* Functions::offsetCorrection::influence */kcg_real influence)
{
  /* Functions::offsetCorrection::_L8 */ kcg_real _L8;
  /* Functions::offsetCorrection::analogCorrectedOffsetValue */ kcg_real analogCorrectedOffsetValue;
  
  if (diffValue < - GYRO_CORRECTION_DIFF_Main) {
    _L8 = analogOffsetValue - influence;
  }
  else {
    _L8 = analogOffsetValue;
  }
  if (diffValue > GYRO_CORRECTION_DIFF_Main) {
    analogCorrectedOffsetValue = influence + _L8;
  }
  else {
    analogCorrectedOffsetValue = _L8;
  }
  return analogCorrectedOffsetValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** offsetCorrection_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

