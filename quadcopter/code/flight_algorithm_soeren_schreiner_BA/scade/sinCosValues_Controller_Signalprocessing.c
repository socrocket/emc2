/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "sinCosValues_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::sinCosValues */
void sinCosValues_Controller_Signalprocessing(
  /* Controller::Signalprocessing::sinCosValues::angleValues */angleValues_Main *angleValues,
  /* Controller::Signalprocessing::sinCosValues::sinCosValues */sinCosValues_Main *sinCosValues)
{
  kcg_real tmp1;
  kcg_real tmp;
  /* Controller::Signalprocessing::sinCosValues::_L7 */ kcg_real _L7;
  
  tmp1 = /* 1 */ degree2radian_Functions((*angleValues).theta);
  tmp = /* 2 */ degree2radian_Functions((*angleValues).phi);
  _L7 = /* 3 */ degree2radian_Functions((*angleValues).psi);
  (*sinCosValues).sinTheta = /* 1 */ SinR_mathext(tmp1);
  (*sinCosValues).cosTheta = /* 1 */ CosR_mathext(tmp1);
  (*sinCosValues).sinPhi = /* 2 */ SinR_mathext(tmp);
  (*sinCosValues).cosPhi = /* 2 */ CosR_mathext(tmp);
  (*sinCosValues).sinPsi = /* 3 */ SinR_mathext(_L7);
  (*sinCosValues).cosPsi = /* 3 */ CosR_mathext(_L7);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** sinCosValues_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

