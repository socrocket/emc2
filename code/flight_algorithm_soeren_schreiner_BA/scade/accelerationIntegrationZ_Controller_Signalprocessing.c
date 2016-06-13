/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accelerationIntegrationZ_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::accelerationIntegrationZ */
void accelerationIntegrationZ_Controller_Signalprocessing(
  /* Controller::Signalprocessing::accelerationIntegrationZ::accelerationGeoZ */kcg_real accelerationGeoZ,
  /* Controller::Signalprocessing::accelerationIntegrationZ::oldHeightGeoZ */kcg_real oldHeightGeoZ,
  /* Controller::Signalprocessing::accelerationIntegrationZ::oldSpeedGeoZ */kcg_real oldSpeedGeoZ,
  /* Controller::Signalprocessing::accelerationIntegrationZ::speedGeoZ */kcg_real *speedGeoZ,
  /* Controller::Signalprocessing::accelerationIntegrationZ::heightGeoZ */kcg_real *heightGeoZ)
{
  *speedGeoZ = (accelerationGeoZ - GRAVITY_Main) * TIMERPERIOD_Main +
    oldSpeedGeoZ;
  *heightGeoZ = *speedGeoZ * TIMERPERIOD_Main + oldHeightGeoZ;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accelerationIntegrationZ_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

