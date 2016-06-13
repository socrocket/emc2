/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _driftCorrectionAngles_Controller_Signalprocessing_H_
#define _driftCorrectionAngles_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "kalmanFilter180_Functions.h"
#include "kalmanFilter90_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  angleValues_Main /* Controller::Signalprocessing::driftCorrectionAngles::angleValuesFiltered */ angleValuesFiltered;
  angleValues_Main /* Controller::Signalprocessing::driftCorrectionAngles::diffValues */ diffValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_driftCorrectionAngles_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::driftCorrectionAngles */
extern void driftCorrectionAngles_Controller_Signalprocessing(
  /* Controller::Signalprocessing::driftCorrectionAngles::accelerationAngles */accelerationAngles_Main *accelerationAngles,
  /* Controller::Signalprocessing::driftCorrectionAngles::compassValue */kcg_real compassValue,
  /* Controller::Signalprocessing::driftCorrectionAngles::angleValues */angleValues_Main *angleValues,
  outC_driftCorrectionAngles_Controller_Signalprocessing *outC);

extern void driftCorrectionAngles_reset_Controller_Signalprocessing(
  outC_driftCorrectionAngles_Controller_Signalprocessing *outC);

#endif /* _driftCorrectionAngles_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** driftCorrectionAngles_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

