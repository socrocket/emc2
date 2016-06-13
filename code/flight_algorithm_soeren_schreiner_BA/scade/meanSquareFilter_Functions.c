/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "meanSquareFilter_Functions.h"

void meanSquareFilter_reset_Functions(outC_meanSquareFilter_Functions *outC)
{
  outC->init = kcg_true;
}

/* Functions::meanSquareFilter */
void meanSquareFilter_Functions(
  /* Functions::meanSquareFilter::newValue */kcg_real newValue,
  /* Functions::meanSquareFilter::weightNewValue */kcg_real weightNewValue,
  outC_meanSquareFilter_Functions *outC)
{
  kcg_real tmp;
  
  if (outC->init) {
    tmp = 0.0;
  }
  else {
    tmp = outC->filterValue;
  }
  outC->filterValue = newValue * weightNewValue + (ONE_REAL_Main -
      weightNewValue) * tmp;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** meanSquareFilter_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

