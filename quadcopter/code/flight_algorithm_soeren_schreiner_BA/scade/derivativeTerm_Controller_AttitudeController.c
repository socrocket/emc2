/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "derivativeTerm_Controller_AttitudeController.h"

void derivativeTerm_reset_Controller_AttitudeController(
  outC_derivativeTerm_Controller_AttitudeController *outC)
{
  outC->init = kcg_true;
}

/* Controller::AttitudeController::derivativeTerm */
void derivativeTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::derivativeTerm::Kd */kcg_real Kd,
  /* Controller::AttitudeController::derivativeTerm::differenceValue */kcg_real differenceValue,
  outC_derivativeTerm_Controller_AttitudeController *outC)
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
** derivativeTerm_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

