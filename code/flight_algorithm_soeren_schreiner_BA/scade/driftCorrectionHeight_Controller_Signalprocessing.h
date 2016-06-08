/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _driftCorrectionHeight_Controller_Signalprocessing_H_
#define _driftCorrectionHeight_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "kalmanFilterHeight_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Controller::Signalprocessing::driftCorrectionHeight::heightValue */ heightValue;
  kcg_real /* Controller::Signalprocessing::driftCorrectionHeight::heightSpeedValue */ heightSpeedValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_real /* Controller::Signalprocessing::driftCorrectionHeight::heightValue */ rem_heightValue;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_driftCorrectionHeight_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::driftCorrectionHeight */
extern void driftCorrectionHeight_Controller_Signalprocessing(
  /* Controller::Signalprocessing::driftCorrectionHeight::heightBarometer */kcg_real heightBarometer,
  /* Controller::Signalprocessing::driftCorrectionHeight::speedGeoZ */kcg_real speedGeoZ,
  /* Controller::Signalprocessing::driftCorrectionHeight::heightGeoZ */kcg_real heightGeoZ,
  outC_driftCorrectionHeight_Controller_Signalprocessing *outC);

extern void driftCorrectionHeight_reset_Controller_Signalprocessing(
  outC_driftCorrectionHeight_Controller_Signalprocessing *outC);

#endif /* _driftCorrectionHeight_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** driftCorrectionHeight_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

