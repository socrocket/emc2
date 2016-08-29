/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "setOffsets_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::setOffsets */
void setOffsets_Controller_Signalprocessing(
  /* Controller::Signalprocessing::setOffsets::analogValues */analogValues_Main *analogValues,
  /* Controller::Signalprocessing::setOffsets::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  /* Controller::Signalprocessing::setOffsets::analogAdjustedValues */analogValuesReal_Main *analogAdjustedValues)
{
  (*analogAdjustedValues).accX = (kcg_real) (*analogValues).accX -
    (*analogOffsetValues).accX;
  (*analogAdjustedValues).accY = (kcg_real) (*analogValues).accY -
    (*analogOffsetValues).accY;
  (*analogAdjustedValues).accZ = (kcg_real) (*analogValues).accZ -
    (*analogOffsetValues).accZ;
  (*analogAdjustedValues).gyroPitch = (kcg_real) (*analogValues).gyroPitch -
    (*analogOffsetValues).gyroPitch;
  (*analogAdjustedValues).gyroRoll = (kcg_real) (*analogValues).gyroRoll -
    (*analogOffsetValues).gyroRoll;
  (*analogAdjustedValues).gyroYaw = (kcg_real) (*analogValues).gyroYaw -
    (*analogOffsetValues).gyroYaw;
  (*analogAdjustedValues).barometer = (kcg_real) (*analogValues).barometer -
    (*analogOffsetValues).barometer;
  (*analogAdjustedValues).compass = (*analogValues).compass;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** setOffsets_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

