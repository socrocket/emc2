/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "rcAdjusting_Functions.h"

/* Functions::rcAdjusting */
kcg_int rcAdjusting_Functions(
  /* Functions::rcAdjusting::rcValue */kcg_int rcValue,
  /* Functions::rcAdjusting::adjustingValue */kcg_int adjustingValue)
{
  /* Functions::rcAdjusting::rcValueAdjusted */ kcg_int rcValueAdjusted;
  
  if (rcValue > adjustingValue) {
    rcValueAdjusted = rcValue - adjustingValue;
  }
  else if (rcValue < - adjustingValue) {
    rcValueAdjusted = rcValue + adjustingValue;
  }
  else {
    rcValueAdjusted = 0;
  }
  return rcValueAdjusted;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** rcAdjusting_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

