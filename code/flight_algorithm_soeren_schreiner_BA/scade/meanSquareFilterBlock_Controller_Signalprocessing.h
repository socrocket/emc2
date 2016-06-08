/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _meanSquareFilterBlock_Controller_Signalprocessing_H_
#define _meanSquareFilterBlock_Controller_Signalprocessing_H_

#include "kcg_types.h"
#include "meanSquareFilter_Functions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  analogValuesReal_Main /* Controller::Signalprocessing::meanSquareFilterBlock::analogValuesFiltered */ analogValuesFiltered;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_meanSquareFilter_Functions /* 1 */ Context_1;
  outC_meanSquareFilter_Functions /* 2 */ Context_2;
  outC_meanSquareFilter_Functions /* 3 */ Context_3;
  outC_meanSquareFilter_Functions /* 4 */ Context_4;
  outC_meanSquareFilter_Functions /* 5 */ Context_5;
  outC_meanSquareFilter_Functions /* 6 */ Context_6;
  outC_meanSquareFilter_Functions /* 7 */ Context_7;
  /* ----------------- no clocks of observable data ------------------ */
} outC_meanSquareFilterBlock_Controller_Signalprocessing;

/* ===========  node initialization and cycle functions  =========== */
/* Controller::Signalprocessing::meanSquareFilterBlock */
extern void meanSquareFilterBlock_Controller_Signalprocessing(
  /* Controller::Signalprocessing::meanSquareFilterBlock::analogAdjustedValues */analogValuesReal_Main *analogAdjustedValues,
  outC_meanSquareFilterBlock_Controller_Signalprocessing *outC);

extern void meanSquareFilterBlock_reset_Controller_Signalprocessing(
  outC_meanSquareFilterBlock_Controller_Signalprocessing *outC);

#endif /* _meanSquareFilterBlock_Controller_Signalprocessing_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** meanSquareFilterBlock_Controller_Signalprocessing.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

