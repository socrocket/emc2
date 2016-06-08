/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calculateMotorSpeed_Controller_CalculateMotorSpeed.h"

/* Controller::CalculateMotorSpeed::calculateMotorSpeed */
void calculateMotorSpeed_Controller_CalculateMotorSpeed(
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::psi */kcg_real psi,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::theta */kcg_real theta,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::phi */kcg_real phi,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::thrust */kcg_real thrust,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::motorValues */motorValues_Main *motorValues)
{
  kcg_int tmp2;
  kcg_int tmp1;
  kcg_int tmp;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L7 */ kcg_real _L7;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L10 */ kcg_real _L10;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L50 */ kcg_real _L50;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L52 */ kcg_real _L52;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L53 */ kcg_real _L53;
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::_L54 */ kcg_real _L54;
  
  _L54 = /* 5 */
    minMaxLimitation_Functions(MIN_AC_GAS_Main, MAX_AC_GAS_Main, psi);
  _L53 = /* 4 */
    minMaxLimitation_Functions(MIN_HC_GAS_Main, MAX_HC_GAS_Main, thrust);
  _L52 = /* 3 */
    minMaxLimitation_Functions(MIN_AC_GAS_Main, MAX_AC_GAS_Main, phi);
  _L50 = /* 1 */
    minMaxLimitation_Functions(MIN_AC_GAS_Main, MAX_AC_GAS_Main, theta);
  _L10 = _L53 + _L54;
  _L7 = _L53 - _L54;
  if ((*rcFlags).motorsOn) {
    (*motorValues).motorFront = /* 1 */
      motorLimitation_Functions(
        (kcg_int) (_L7 - _L50),
        MAX_GAS_Main,
        MIN_GAS_Main);
    tmp2 = /* 2 */
      motorLimitation_Functions(
        (kcg_int) (_L7 + _L50),
        MAX_GAS_Main,
        MIN_GAS_Main);
    tmp1 = /* 3 */
      motorLimitation_Functions(
        (kcg_int) (_L10 + _L52),
        MAX_GAS_Main,
        MIN_GAS_Main);
    tmp = /* 4 */
      motorLimitation_Functions(
        (kcg_int) (_L10 - _L52),
        MAX_GAS_Main,
        MIN_GAS_Main);
  }
  else {
    (*motorValues).motorFront = ZERO_Main;
    tmp2 = ZERO_Main;
    tmp1 = ZERO_Main;
    tmp = ZERO_Main;
  }
  (*motorValues).motorRear = tmp2;
  (*motorValues).motorLeft = tmp1;
  (*motorValues).motorRight = tmp;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calculateMotorSpeed_Controller_CalculateMotorSpeed.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

