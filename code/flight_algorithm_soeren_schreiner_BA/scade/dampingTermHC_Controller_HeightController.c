/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "dampingTermHC_Controller_HeightController.h"

/* Controller::HeightController::dampingTermHC */
kcg_real dampingTermHC_Controller_HeightController(
  /* Controller::HeightController::dampingTermHC::Ks */kcg_real Ks,
  /* Controller::HeightController::dampingTermHC::speedValue */kcg_real speedValue)
{
  /* Controller::HeightController::dampingTermHC::dampingValue */ kcg_real dampingValue;
  
  dampingValue = speedValue * Ks;
  return dampingValue;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** dampingTermHC_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

