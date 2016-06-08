/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "dampingTerm_Controller_AttitudeController.h"

/* Controller::AttitudeController::dampingTerm */
kcg_real dampingTerm_Controller_AttitudeController(
  /* Controller::AttitudeController::dampingTerm::Ks */kcg_real Ks,
  /* Controller::AttitudeController::dampingTerm::angleSpeedValue */kcg_real angleSpeedValue)
{
  /* Controller::AttitudeController::dampingTerm::dampingValue */ kcg_real dampingValue;
  
  dampingValue = angleSpeedValue * Ks;
  return dampingValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** dampingTerm_Controller_AttitudeController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

