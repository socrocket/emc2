/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "proportionalTermHC_Controller_HeightController.h"

/* Controller::HeightController::proportionalTermHC */
kcg_real proportionalTermHC_Controller_HeightController(
  /* Controller::HeightController::proportionalTermHC::Kp */kcg_real Kp,
  /* Controller::HeightController::proportionalTermHC::differenceValue */kcg_real differenceValue)
{
  /* Controller::HeightController::proportionalTermHC::pValue */ kcg_real pValue;
  
  pValue = differenceValue * Kp;
  return pValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** proportionalTermHC_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

