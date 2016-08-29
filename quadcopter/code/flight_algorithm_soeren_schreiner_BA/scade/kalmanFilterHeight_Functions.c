/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "kalmanFilterHeight_Functions.h"

/* Functions::kalmanFilterHeight */
kcg_real kalmanFilterHeight_Functions(
  /* Functions::kalmanFilterHeight::refValue */kcg_real refValue,
  /* Functions::kalmanFilterHeight::value */kcg_real value,
  /* Functions::kalmanFilterHeight::kalmanValue */kcg_real kalmanValue)
{
  /* Functions::kalmanFilterHeight::filterValue */ kcg_real filterValue;
  
  filterValue = (refValue - value) * kalmanValue + value;
  return filterValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** kalmanFilterHeight_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

