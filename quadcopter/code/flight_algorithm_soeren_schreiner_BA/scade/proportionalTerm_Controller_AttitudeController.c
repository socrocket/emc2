/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "proportionalTerm_Controller_AttitudeController.h"

/* Controller::AttitudeController::proportionalTerm */
kcg_real proportionalTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::proportionalTerm::Kp */kcg_real Kp,
  /* Controller::AttitudeController::proportionalTerm::differenceValue */kcg_real differenceValue)
{
  /* Controller::AttitudeController::proportionalTerm::pValue */ kcg_real pValue;
  
  pValue = differenceValue * Kp;
  return pValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** proportionalTerm_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

