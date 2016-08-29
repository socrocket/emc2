/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _calculateMotorSpeed_Controller_CalculateMotorSpeed_H_
#define _calculateMotorSpeed_Controller_CalculateMotorSpeed_H_

#include "kcg_types.h"
#include "minMaxLimitation_Functions.h"
#include "motorLimitation_Functions.h"

/* =====================  no input structure  ====================== */


/* Controller::CalculateMotorSpeed::calculateMotorSpeed */
extern void calculateMotorSpeed_Controller_CalculateMotorSpeed(
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::psi */kcg_real psi,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::theta */kcg_real theta,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::phi */kcg_real phi,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::thrust */kcg_real thrust,
  /* Controller::CalculateMotorSpeed::calculateMotorSpeed::motorValues */motorValues_Main *motorValues);

#endif /* _calculateMotorSpeed_Controller_CalculateMotorSpeed_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** calculateMotorSpeed_Controller_CalculateMotorSpeed.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

