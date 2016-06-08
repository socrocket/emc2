/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accelerationAngleTheta_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::accelerationAngleTheta */
kcg_real accelerationAngleTheta_Controller_Signalprocessing(
  /* Controller::Signalprocessing::accelerationAngleTheta::accX */kcg_real accX)
{
  kcg_real tmp;
  /* Controller::Signalprocessing::accelerationAngleTheta::thetaRadian */ kcg_real thetaRadian;
  
  tmp = /* 1 */ accLimitation_Functions(accX / GRAVITY_Main);
  thetaRadian = /* 1 */ AsinR_mathext(tmp);
  return thetaRadian;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accelerationAngleTheta_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

