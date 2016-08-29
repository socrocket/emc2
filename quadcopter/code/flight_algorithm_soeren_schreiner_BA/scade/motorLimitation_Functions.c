/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "motorLimitation_Functions.h"

/* Functions::motorLimitation */
kcg_int motorLimitation_Functions(
  /* Functions::motorLimitation::value */kcg_int value,
  /* Functions::motorLimitation::max */kcg_int max,
  /* Functions::motorLimitation::min */kcg_int min)
{
  /* Functions::motorLimitation::valueLimited */ kcg_int valueLimited;
  
  if (value > max) {
    valueLimited = max;
  }
  else if (value < min) {
    valueLimited = min;
  }
  else {
    valueLimited = value;
  }
  return valueLimited;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** motorLimitation_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

