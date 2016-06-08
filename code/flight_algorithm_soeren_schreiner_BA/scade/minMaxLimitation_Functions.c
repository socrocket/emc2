/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "minMaxLimitation_Functions.h"

/* Functions::minMaxLimitation */
kcg_real minMaxLimitation_Functions(
  /* Functions::minMaxLimitation::min */kcg_real min,
  /* Functions::minMaxLimitation::max */kcg_real max,
  /* Functions::minMaxLimitation::value */kcg_real value)
{
  /* Functions::minMaxLimitation::valueLimited */ kcg_real valueLimited;
  
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
** minMaxLimitation_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

