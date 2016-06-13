/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "getPsiStartValue_Controller_Setpoint.h"

void getPsiStartValue_reset_Controller_Setpoint(
  outC_getPsiStartValue_Controller_Setpoint *outC)
{
  outC->init = kcg_true;
}

/* Controller::Setpoint::getPsiStartValue */
void getPsiStartValue_Controller_Setpoint(
  /* Controller::Setpoint::getPsiStartValue::anglePsi */kcg_real anglePsi,
  /* Controller::Setpoint::getPsiStartValue::motorsOn */kcg_bool motorsOn,
  outC_getPsiStartValue_Controller_Setpoint *outC)
{
  if (motorsOn) {
    if (outC->init) {
      outC->psiStartValue = 0.0;
    }
  }
  else {
    outC->psiStartValue = anglePsi;
  }
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** getPsiStartValue_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

