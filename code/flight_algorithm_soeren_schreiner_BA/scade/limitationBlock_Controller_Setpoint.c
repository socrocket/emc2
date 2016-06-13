/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "limitationBlock_Controller_Setpoint.h"

/* Controller::Setpoint::limitationBlock */
void limitationBlock_Controller_Setpoint(
  /* Controller::Setpoint::limitationBlock::rcNormalizedValues */rcValuesReal_Main *rcNormalizedValues,
  /* Controller::Setpoint::limitationBlock::setpointValues */rcValuesReal_Main *setpointValues)
{
  (*setpointValues).thrust = /* 1 */
    minMaxLimitation_Functions(
      MIN_GAS_REAL_Main,
      RC_MAX_VALUES_Main.thrust,
      (*rcNormalizedValues).thrust);
  (*setpointValues).yaw = /* 2 */
    minMaxLimitation_Functions(
      - RC_MAX_VALUES_Main.yaw,
      RC_MAX_VALUES_Main.yaw,
      (*rcNormalizedValues).yaw);
  (*setpointValues).pitch = /* 3 */
    minMaxLimitation_Functions(
      - RC_MAX_VALUES_Main.pitch,
      RC_MAX_VALUES_Main.pitch,
      (*rcNormalizedValues).pitch);
  (*setpointValues).roll = /* 4 */
    minMaxLimitation_Functions(
      - RC_MAX_VALUES_Main.roll,
      RC_MAX_VALUES_Main.roll,
      (*rcNormalizedValues).roll);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** limitationBlock_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

