/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calcUnitsFromAnalog_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::calcUnitsFromAnalog */
void calcUnitsFromAnalog_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcUnitsFromAnalog::analogValuesFIltered */analogValuesReal_Main *analogValuesFIltered,
  /* Controller::Signalprocessing::calcUnitsFromAnalog::heightBarometer */kcg_real *heightBarometer,
  /* Controller::Signalprocessing::calcUnitsFromAnalog::accelerations */accelerations_Main *accelerations,
  /* Controller::Signalprocessing::calcUnitsFromAnalog::compass */kcg_real *compass,
  /* Controller::Signalprocessing::calcUnitsFromAnalog::angleSpeeds */angleValues_Main *angleSpeeds)
{
  (*angleSpeeds).theta = - (*analogValuesFIltered).gyroPitch *
    GYRO_CONSTANT_Main;
  (*angleSpeeds).phi = - (*analogValuesFIltered).gyroRoll * GYRO_CONSTANT_Main;
  (*angleSpeeds).psi = - (*analogValuesFIltered).gyroYaw * GYRO_CONSTANT_Main;
  (*accelerations).accX = - (*analogValuesFIltered).accX * ACC_CONSTANT_Main;
  (*accelerations).accY = (*analogValuesFIltered).accY * ACC_CONSTANT_Main;
  (*accelerations).accZ = - (*analogValuesFIltered).accZ * ACC_CONSTANT_Main;
  *heightBarometer = - ((*analogValuesFIltered).barometer *
      BAROMETER_CONSTANT_Main);
  *compass = (*analogValuesFIltered).compass;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcUnitsFromAnalog_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

