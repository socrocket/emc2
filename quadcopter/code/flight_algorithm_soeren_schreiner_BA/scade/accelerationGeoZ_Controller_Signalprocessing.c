/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accelerationGeoZ_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::accelerationGeoZ */
kcg_real accelerationGeoZ_Controller_Signalprocessing(
  /* Controller::Signalprocessing::accelerationGeoZ::accelerations */accelerations_Main *accelerations,
  /* Controller::Signalprocessing::accelerationGeoZ::sincosValues */sinCosValues_Main *sincosValues)
{
  /* Controller::Signalprocessing::accelerationGeoZ::accelerationGeoZ */ kcg_real accelerationGeoZ;
  
  accelerationGeoZ = - (*accelerations).accX * (*sincosValues).sinTheta +
    ((*accelerations).accY * (*sincosValues).sinPhi + (*accelerations).accZ *
      (*sincosValues).cosPhi) * (*sincosValues).cosTheta;
  return accelerationGeoZ;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accelerationGeoZ_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

