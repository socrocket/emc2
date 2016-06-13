/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "kalmanFilter90_Functions.h"

/* Functions::kalmanFilter90 */
void kalmanFilter90_Functions(
  /* Functions::kalmanFilter90::refValue */kcg_real refValue,
  /* Functions::kalmanFilter90::value */kcg_real value,
  /* Functions::kalmanFilter90::kalmanValue */kcg_real kalmanValue,
  /* Functions::kalmanFilter90::filterValue */kcg_real *filterValue,
  /* Functions::kalmanFilter90::diffValue */kcg_real *diffValue)
{
  *diffValue = /* 1 */ angleLimitation90_Functions(refValue - value);
  *filterValue = *diffValue * kalmanValue + value;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** kalmanFilter90_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

