/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _calcHeightValues_Controller_Signalprocessing_H_
#define _calcHeightValues_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "accelerationGeoZ_Controller_Signalprocessing.h"
#include "accelerationIntegrationZ_Controller_Signalprocessing.h"
#include "driftCorrectionHeight_Controller_Signalprocessing.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::Signalprocessing::calcHeightValues::heightSpeedValue */ heightSpeedValue;
  kcg_real /* Controller::Signalprocessing::calcHeightValues::heightValue */ heightValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_driftCorrectionHeight_Controller_Signalprocessing /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_calcHeightValues_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::calcHeightValues */
extern void calcHeightValues_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcHeightValues::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::calcHeightValues::heightBarometer */kcg_real heightBarometer,
  /* Controller::Signalprocessing::calcHeightValues::accelerations */accelerations_Main *accelerations,
  outC_calcHeightValues_Controller_Signalprocessing *outC);

extern void calcHeightValues_reset_Controller_Signalprocessing(
  outC_calcHeightValues_Controller_Signalprocessing *outC);

#endif /* _calcHeightValues_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcHeightValues_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

