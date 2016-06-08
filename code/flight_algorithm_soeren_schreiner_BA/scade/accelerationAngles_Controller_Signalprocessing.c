/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accelerationAngles_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::accelerationAngles */
void accelerationAngles_Controller_Signalprocessing(
  /* Controller::Signalprocessing::accelerationAngles::accelerations */accelerations_Main *accelerations,
  /* Controller::Signalprocessing::accelerationAngles::accelerationAngles */accelerationAngles_Main *accelerationAngles)
{
  kcg_real tmp;
  
  tmp = /* 1 */
    accelerationAngleTheta_Controller_Signalprocessing((*accelerations).accX);
  (*accelerationAngles).accTheta = /* 1 */ radian2degree_Functions(tmp);
  (*accelerationAngles).accPhi = /* 1 */
    accAnglePhiCorrection_Functions(
      /* 2 */
      radian2degree_Functions(
        /* 1 */
        accelerationAnglePhi_Controller_Signalprocessing(
          tmp,
          (*accelerations).accY)),
      (*accelerations).accZ);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accelerationAngles_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

