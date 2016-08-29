/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "degree2radian_Functions.h"

/* Functions::degree2radian */
kcg_real degree2radian_Functions(
  /* Functions::degree2radian::degree */kcg_real degree)
{
  /* Functions::degree2radian::radian */ kcg_real radian;
  
  radian = degree * PI180_Main;
  return radian;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** degree2radian_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

