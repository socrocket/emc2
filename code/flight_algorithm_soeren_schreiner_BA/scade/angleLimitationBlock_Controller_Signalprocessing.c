/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleLimitationBlock_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::angleLimitationBlock */
void angleLimitationBlock_Controller_Signalprocessing(
  /* Controller::Signalprocessing::angleLimitationBlock::angleValues */angleValues_Main *angleValues,
  /* Controller::Signalprocessing::angleLimitationBlock::angleValuesLimited */angleValues_Main *angleValuesLimited)
{
  (*angleValuesLimited).theta = /* 1 */
    angleLimitation90_Functions((*angleValues).theta);
  (*angleValuesLimited).phi = /* 2 */
    angleLimitation180_Functions((*angleValues).phi);
  (*angleValuesLimited).psi = /* 3 */
    angleLimitation180_Functions((*angleValues).psi);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleLimitationBlock_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

