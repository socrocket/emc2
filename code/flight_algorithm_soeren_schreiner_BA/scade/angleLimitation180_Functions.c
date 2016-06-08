/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleLimitation180_Functions.h"

/* Functions::angleLimitation180 */
kcg_real angleLimitation180_Functions(
  /* Functions::angleLimitation180::angle */kcg_real angle)
{
  /* Functions::angleLimitation180::angleLimited */ kcg_real angleLimited;
  
  if (angle >= ANGLE_180_REAL_Main) {
    angleLimited = angle - ANGLE_360_REAL_Main;
  }
  else if (angle < ANGLE_N180_Real_Main) {
    angleLimited = angle + ANGLE_360_REAL_Main;
  }
  else {
    angleLimited = angle;
  }
  return angleLimited;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleLimitation180_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

