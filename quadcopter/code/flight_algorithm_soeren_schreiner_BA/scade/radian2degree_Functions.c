/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "radian2degree_Functions.h"

/* Functions::radian2degree */
kcg_real radian2degree_Functions(
  /* Functions::radian2degree::radian */kcg_real radian)
{
  /* Functions::radian2degree::degree */ kcg_real degree;
  
  degree = radian / PI180_Main;
  return degree;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** radian2degree_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

