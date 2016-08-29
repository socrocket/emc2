/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _signalprocessing_Controller_Signalprocessing_H_
#define _signalprocessing_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "sinCosValues_Controller_Signalprocessing.h"
#include "setOffsets_Controller_Signalprocessing.h"
#include "calcUnitsFromAnalog_Controller_Signalprocessing.h"
#include "meanSquareFilterBlock_Controller_Signalprocessing.h"
#include "calcHeightValues_Controller_Signalprocessing.h"
#include "calcAngleValues_Controller_Signalprocessing.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  angleValues_Main /* Controller::Signalprocessing::signalprocessing::angleValues */ angleValues;
  angleValues_Main /* Controller::Signalprocessing::signalprocessing::angleSpeedValues */ angleSpeedValues;
  kcg_real /* Controller::Signalprocessing::signalprocessing::heightValue */ heightValue;
  kcg_real /* Controller::Signalprocessing::signalprocessing::heightSpeedValue */ heightSpeedValue;
  analogOffsetValues_Main /* Controller::Signalprocessing::signalprocessing::analogCorrectedOffsetValues */ analogCorrectedOffsetValues;
  accelerationAngles_Main /* Controller::Signalprocessing::signalprocessing::accelertionAngles */ accelertionAngles;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_meanSquareFilterBlock_Controller_Signalprocessing /* 1 */ _2_Context_1;
  outC_calcHeightValues_Controller_Signalprocessing /* 1 */ _1_Context_1;
  outC_calcAngleValues_Controller_Signalprocessing /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_signalprocessing_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::signalprocessing */
extern void signalprocessing_Controller_Signalprocessing(
  /* Controller::Signalprocessing::signalprocessing::analogValues */analogValues_Main *analogValues,
  /* Controller::Signalprocessing::signalprocessing::analogOffsetValues */analogOffsetValues_Main *analogOffsetValues,
  outC_signalprocessing_Controller_Signalprocessing *outC);

extern void signalprocessing_reset_Controller_Signalprocessing(
  outC_signalprocessing_Controller_Signalprocessing *outC);

#endif /* _signalprocessing_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** signalprocessing_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

