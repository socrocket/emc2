/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleLimitation90_Functions.h"

/* Functions::angleLimitation90 */
kcg_real angleLimitation90_Functions(
  /* Functions::angleLimitation90::angle */kcg_real angle)
{
  /* Functions::angleLimitation90::angleLimited */ kcg_real angleLimited;
  
  if (angle > ANGLE_90_REAL_Main) {
    angleLimited = ANGLE_180_REAL_Main - angle;
  }
  else if (angle < ANGLE_N90_REAL_Main) {
    angleLimited = ANGLE_N180_Real_Main - angle;
  }
  else {
    angleLimited = angle;
  }
  return angleLimited;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleLimitation90_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

