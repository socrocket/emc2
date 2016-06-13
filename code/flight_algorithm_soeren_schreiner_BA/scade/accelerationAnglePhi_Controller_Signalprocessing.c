/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accelerationAnglePhi_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::accelerationAnglePhi */
kcg_real accelerationAnglePhi_Controller_Signalprocessing(
  /* Controller::Signalprocessing::accelerationAnglePhi::thetaRadian */kcg_real thetaRadian,
  /* Controller::Signalprocessing::accelerationAnglePhi::accY */kcg_real accY)
{
  kcg_real tmp1;
  kcg_real tmp;
  /* Controller::Signalprocessing::accelerationAnglePhi::_L14 */ kcg_real _L14;
  /* Controller::Signalprocessing::accelerationAnglePhi::_L8 */ kcg_bool _L8;
  /* Controller::Signalprocessing::accelerationAnglePhi::phiRadian */ kcg_real phiRadian;
  
  tmp1 = /* 1 */ CosR_mathext(thetaRadian);
  _L8 = ZERO_REAL_Main != tmp1;
  _L14 = /* 2 */ accLimitation_Functions(accY / GRAVITY_Main);
  if (_L8) {
    tmp = _L14 / tmp1;
  }
  else if (_L14 > ZERO_REAL_Main) {
    tmp = ONE_REAL_Main;
  }
  else {
    tmp = ONE_N_REAL_Main;
  }
  tmp1 = /* 1 */ accLimitation_Functions(tmp);
  phiRadian = /* 1 */ AsinR_mathext(tmp1);
  return phiRadian;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accelerationAnglePhi_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

