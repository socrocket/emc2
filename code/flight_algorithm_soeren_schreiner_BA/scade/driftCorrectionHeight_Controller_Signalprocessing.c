/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "driftCorrectionHeight_Controller_Signalprocessing.h"

void driftCorrectionHeight_reset_Controller_Signalprocessing(
  outC_driftCorrectionHeight_Controller_Signalprocessing *outC)
{
  outC->init = kcg_true;
}

/* Controller::Signalprocessing::driftCorrectionHeight */
void driftCorrectionHeight_Controller_Signalprocessing(
  /* Controller::Signalprocessing::driftCorrectionHeight::heightBarometer */kcg_real heightBarometer,
  /* Controller::Signalprocessing::driftCorrectionHeight::speedGeoZ */kcg_real speedGeoZ,
  /* Controller::Signalprocessing::driftCorrectionHeight::heightGeoZ */kcg_real heightGeoZ,
  outC_driftCorrectionHeight_Controller_Signalprocessing *outC)
{
  kcg_real tmp;
  
  outC->heightValue = /* 1 */
    kalmanFilterHeight_Functions(
      heightBarometer,
      heightGeoZ,
      KALMAN_HEIGHT_Main);
  if (outC->init) {
    tmp = 0.0;
  }
  else {
    tmp = outC->rem_heightValue;
  }
  outC->heightSpeedValue = /* 2 */
    kalmanFilterHeight_Functions(
      (outC->heightValue - tmp) * TIMERCYCLES_Main,
      speedGeoZ,
      KALMAN_HEIGHT_SPEED_Main);
  outC->rem_heightValue = outC->heightValue;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** driftCorrectionHeight_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

