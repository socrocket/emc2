/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "getHeightSetpoint_Controller_HeightController.h"

void getHeightSetpoint_reset_Controller_HeightController(
  outC_getHeightSetpoint_Controller_HeightController *outC)
{
  outC->init = kcg_true;
}

/* Controller::HeightController::getHeightSetpoint */
void getHeightSetpoint_Controller_HeightController(
  /* Controller::HeightController::getHeightSetpoint::activeSignal */kcg_bool activeSignal,
  /* Controller::HeightController::getHeightSetpoint::setpointValue */kcg_real setpointValue,
  /* Controller::HeightController::getHeightSetpoint::heightValue */kcg_real heightValue,
  outC_getHeightSetpoint_Controller_HeightController *outC)
{
  if (activeSignal & (ZERO_REAL_Main == setpointValue)) {
    if (outC->init) {
      outC->heightSetpointValue = 0.0;
    }
  }
  else {
    outC->heightSetpointValue = setpointValue + heightValue;
  }
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** getHeightSetpoint_Controller_HeightController.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

