/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _rotationMatrix_Controller_Setpoint_H_
#define _rotationMatrix_Controller_Setpoint_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"
#include "degree2radian_Functions.h"
#include "angleLimitation180_Functions.h"

/* =====================  no input structure  ====================== */


/* Controller::Setpoint::rotationMatrix */
extern void rotationMatrix_Controller_Setpoint(
  /* Controller::Setpoint::rotationMatrix::anglePsi */kcg_real anglePsi,
  /* Controller::Setpoint::rotationMatrix::psiStartValue */kcg_real psiStartValue,
  /* Controller::Setpoint::rotationMatrix::rcAdjustedValues */rcValues_Main *rcAdjustedValues,
  /* Controller::Setpoint::rotationMatrix::rcTransformedValues */rcValuesReal_Main *rcTransformedValues);

#endif /* _rotationMatrix_Controller_Setpoint_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** rotationMatrix_Controller_Setpoint.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

