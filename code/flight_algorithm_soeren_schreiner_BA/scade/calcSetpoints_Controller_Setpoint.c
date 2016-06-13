/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calcSetpoints_Controller_Setpoint.h"

/* Controller::Setpoint::calcSetpoints */
void calcSetpoints_Controller_Setpoint(
  /* Controller::Setpoint::calcSetpoints::rcTransformedValues */rcValuesReal_Main *rcTransformedValues,
  /* Controller::Setpoint::calcSetpoints::rcNormalizedValues */rcValuesReal_Main *rcNormalizedValues)
{
  (*rcNormalizedValues).thrust = RC_MAX_VALUES_Main.thrust *
    (RC_NORMALIZING_Main.thrustMin + (*rcTransformedValues).thrust *
      RC_NORMALIZING_Main.thrust);
  (*rcNormalizedValues).yaw = RC_MAX_VALUES_Main.yaw *
    ((*rcTransformedValues).yaw * RC_NORMALIZING_Main.yaw);
  (*rcNormalizedValues).pitch = RC_MAX_VALUES_Main.pitch *
    ((*rcTransformedValues).pitch * RC_NORMALIZING_Main.pitch);
  (*rcNormalizedValues).roll = RC_MAX_VALUES_Main.roll *
    ((*rcTransformedValues).roll * RC_NORMALIZING_Main.roll);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcSetpoints_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

