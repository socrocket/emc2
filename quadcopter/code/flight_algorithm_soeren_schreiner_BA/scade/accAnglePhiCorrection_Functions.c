/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accAnglePhiCorrection_Functions.h"

/* Functions::accAnglePhiCorrection */
kcg_real accAnglePhiCorrection_Functions(
  /* Functions::accAnglePhiCorrection::accPhi */kcg_real accPhi,
  /* Functions::accAnglePhiCorrection::accZ */kcg_real accZ)
{
  /* Functions::accAnglePhiCorrection::accPhiCorrected */ kcg_real accPhiCorrected;
  
  if (accZ < ZERO_REAL_Main) {
    if (accPhi > ZERO_REAL_Main) {
      accPhiCorrected = ANGLE_180_REAL_Main - accPhi;
    }
    else {
      accPhiCorrected = ANGLE_N180_Real_Main - accPhi;
    }
  }
  else {
    accPhiCorrected = accPhi;
  }
  return accPhiCorrected;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** accAnglePhiCorrection_Functions.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

