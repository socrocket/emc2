/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _meanSquareFilter_Functions_H_
#define _meanSquareFilter_Functions_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* Functions::meanSquareFilter::filterValue */ filterValue;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_meanSquareFilter_Functions;

/* ===========  node initialization and cycle functions  =========== */
/* Functions::meanSquareFilter */
extern void meanSquareFilter_Functions(
  /* Functions::meanSquareFilter::newValue */kcg_real newValue,
  /* Functions::meanSquareFilter::weightNewValue */kcg_real weightNewValue,
  outC_meanSquareFilter_Functions *outC);

extern void meanSquareFilter_reset_Functions(
  outC_meanSquareFilter_Functions *outC);

#endif /* _meanSquareFilter_Functions_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** meanSquareFilter_Functions.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

