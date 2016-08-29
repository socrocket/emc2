/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _calcAngleValues_Controller_Signalprocessing_H_
#define _calcAngleValues_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "angleTransformation_Controller_Signalprocessing.h"
#include "calcDiscreteAngleChanges_Controller_Signalprocessing.h"
#include "angleIntegration_Controller_Signalprocessing.h"
#include "angleLimitationBlock_Controller_Signalprocessing.h"
#include "offsetCorrectionBlock_Controller_Signalprocessing.h"
#include "accelerationAngles_Controller_Signalprocessing.h"
#include "driftCorrectionAngles_Controller_Signalprocessing.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  accelerationAngles_Main /* Controller::Signalprocessing::calcAngleValues::accelertionAngles */ accelertionAngles;
  analogOffsetValues_Main /* Controller::Signalprocessing::calcAngleValues::analogCorrectedOffsetValues */ analogCorrectedOffsetValues;
  angleValues_Main /* Controller::Signalprocessing::calcAngleValues::angleValues */ angleValues;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_driftCorrectionAngles_Controller_Signalprocessing /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_calcAngleValues_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::calcAngleValues */
extern void calcAngleValues_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcAngleValues::oldAngleValues */angleValues_Main *oldAngleValues,
  /* Controller::Signalprocessing::calcAngleValues::sinCosValues */sinCosValues_Main *sinCosValues,
  /* Controller::Signalprocessing::calcAngleValues::accelerations */accelerations_Main *accelerations,
  /* Controller::Signalprocessing::calcAngleValues::compassValue */kcg_real compassValue,
  /* Controller::Signalprocessing::calcAngleValues::angleSpeeds */angleValues_Main *angleSpeeds,
  /* Controller::Signalprocessing::calcAngleValues::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_calcAngleValues_Controller_Signalprocessing *outC);

extern void calcAngleValues_reset_Controller_Signalprocessing(
  outC_calcAngleValues_Controller_Signalprocessing *outC);

#endif /* _calcAngleValues_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcAngleValues_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

