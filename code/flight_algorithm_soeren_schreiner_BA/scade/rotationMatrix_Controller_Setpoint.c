/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "rotationMatrix_Controller_Setpoint.h"

/* Controller::Setpoint::rotationMatrix */
void rotationMatrix_Controller_Setpoint(
  /* Controller::Setpoint::rotationMatrix::anglePsi */kcg_real anglePsi,
  /* Controller::Setpoint::rotationMatrix::psiStartValue */kcg_real psiStartValue,
  /* Controller::Setpoint::rotationMatrix::rcAdjustedValues */rcValues_Main *rcAdjustedValues,
  /* Controller::Setpoint::rotationMatrix::rcTransformedValues */rcValuesReal_Main *rcTransformedValues)
{
  /* Controller::Setpoint::rotationMatrix::_L11 */ kcg_real _L11;
  /* Controller::Setpoint::rotationMatrix::_L12 */ kcg_real _L12;
  /* Controller::Setpoint::rotationMatrix::_L26 */ kcg_real _L26;
  /* Controller::Setpoint::rotationMatrix::_L27 */ kcg_real _L27;
  /* Controller::Setpoint::rotationMatrix::_L29 */ kcg_real _L29;
  
  (*rcTransformedValues).thrust = (kcg_real) (*rcAdjustedValues).thrust;
  (*rcTransformedValues).yaw = (kcg_real) (*rcAdjustedValues).yaw;
  _L26 = (kcg_real) (*rcAdjustedValues).pitch;
  _L29 = /* 1 */
    degree2radian_Functions(
      /* 1 */ angleLimitation180_Functions(psiStartValue - anglePsi));
  _L11 = /* 1 */ CosR_mathext(_L29);
  _L27 = (kcg_real) (*rcAdjustedValues).roll;
  _L12 = /* 1 */ SinR_mathext(_L29);
  (*rcTransformedValues).pitch = _L26 * _L11 - _L27 * _L12;
  (*rcTransformedValues).roll = _L27 * _L11 + _L26 * _L12;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** rotationMatrix_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

