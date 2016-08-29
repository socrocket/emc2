/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "kalmanFilter180_Functions.h"

/* Functions::kalmanFilter180 */
void kalmanFilter180_Functions(
  /* Functions::kalmanFilter180::refValue */kcg_real refValue,
  /* Functions::kalmanFilter180::value */kcg_real value,
  /* Functions::kalmanFilter180::kalmanValue */kcg_real kalmanValue,
  /* Functions::kalmanFilter180::filterValue */kcg_real *filterValue,
  /* Functions::kalmanFilter180::diffValue */kcg_real *diffValue)
{
  *diffValue = /* 1 */ angleLimitation180_Functions(refValue - value);
  *filterValue = *diffValue * kalmanValue + value;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** kalmanFilter180_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

