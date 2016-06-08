/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "derivativeTermHC_Controller_HeightController.h"

void derivativeTermHC_reset_Controller_HeightController(
  outC_derivativeTermHC_Controller_HeightController *outC)
{
  outC->init = kcg_true;
}

/* Controller::HeightController::derivativeTermHC */
void derivativeTermHC_Controller_HeightController(
  /* Controller::HeightController::derivativeTermHC::Kd */kcg_real Kd,
  /* Controller::HeightController::derivativeTermHC::differenceValue */kcg_real differenceValue,
  outC_derivativeTermHC_Controller_HeightController *outC)
{
  kcg_real tmp;
  
  if (outC->init) {
    tmp = 0.0;
  }
  else {
    tmp = outC->rem_differenceValue;
  }
  outC->dValue = Kd * (differenceValue - tmp);
  outC->rem_differenceValue = differenceValue;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** derivativeTermHC_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

