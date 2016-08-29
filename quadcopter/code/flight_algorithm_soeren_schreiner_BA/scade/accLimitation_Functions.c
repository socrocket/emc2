/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accLimitation_Functions.h"

/* Functions::accLimitation */
kcg_real accLimitation_Functions(
  /* Functions::accLimitation::value */kcg_real value)
{
  /* Functions::accLimitation::valueLimited */ kcg_real valueLimited;
  
  if (value < ONE_N_REAL_Main) {
    valueLimited = ONE_N_REAL_Main;
  }
  else if (value > ONE_REAL_Main) {
    valueLimited = ONE_REAL_Main;
  }
  else {
    valueLimited = value;
  }
  return valueLimited;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accLimitation_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

