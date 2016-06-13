/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "setOffsets_Controller_Setpoint.h"

/* Controller::Setpoint::setOffsets */
void setOffsets_Controller_Setpoint(
  /* Controller::Setpoint::setOffsets::rcValues */rcValues_Main *rcValues,
  /* Controller::Setpoint::setOffsets::rcOffsetValues */rcValues_Main *rcOffsetValues,
  /* Controller::Setpoint::setOffsets::rcAdjustedValues */rcValues_Main *rcAdjustedValues)
{
  (*rcAdjustedValues).thrust = (*rcValues).thrust - (*rcOffsetValues).thrust;
  (*rcAdjustedValues).yaw = - /* 1 */
    rcAdjusting_Functions(
      (*rcValues).yaw - (*rcOffsetValues).yaw,
      SENSITIVITY_STICKS_SP_Main);
  (*rcAdjustedValues).pitch = /* 2 */
    rcAdjusting_Functions(
      (*rcValues).pitch - (*rcOffsetValues).pitch,
      SENSITIVITY_STICKS_SP_Main);
  (*rcAdjustedValues).roll = - /* 3 */
    rcAdjusting_Functions(
      (*rcValues).roll - (*rcOffsetValues).roll,
      SENSITIVITY_STICKS_SP_Main);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** setOffsets_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

