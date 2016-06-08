/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "rcAdjustingReal_Functions.h"

/* Functions::rcAdjustingReal */
kcg_real rcAdjustingReal_Functions(
  /* Functions::rcAdjustingReal::rcValue */kcg_real rcValue,
  /* Functions::rcAdjustingReal::adjustingValue */kcg_real adjustingValue)
{
  /* Functions::rcAdjustingReal::rcValueAdjusted */ kcg_real rcValueAdjusted;
  
  if (rcValue > adjustingValue) {
    rcValueAdjusted = rcValue - adjustingValue;
  }
  else if (rcValue < - adjustingValue) {
    rcValueAdjusted = rcValue + adjustingValue;
  }
  else {
    rcValueAdjusted = ZERO_REAL_Main;
  }
  return rcValueAdjusted;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** rcAdjustingReal_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

