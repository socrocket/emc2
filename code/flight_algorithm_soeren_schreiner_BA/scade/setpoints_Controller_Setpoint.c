/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "setpoints_Controller_Setpoint.h"

void setpoints_reset_Controller_Setpoint(
  outC_setpoints_Controller_Setpoint *outC)
{
  /* 1 */ getPsiStartValue_reset_Controller_Setpoint(&outC->Context_1);
}

/* Controller::Setpoint::setpoints */
void setpoints_Controller_Setpoint(
  /* Controller::Setpoint::setpoints::rcFlags */rcFlags_Main *rcFlags,
  /* Controller::Setpoint::setpoints::rcValues */rcValues_Main *rcValues,
  /* Controller::Setpoint::setpoints::angleValues */angleValues_Main *angleValues,
  outC_setpoints_Controller_Setpoint *outC)
{
  rcValuesReal_Main tmp2;
  rcValuesReal_Main tmp1;
  rcValues_Main tmp;
  
  /* 1 */
  getPsiStartValue_Controller_Setpoint(
    (*angleValues).psi,
    (*rcFlags).motorsOn,
    &outC->Context_1);
  /* 1 */
  setOffsets_Controller_Setpoint(
    rcValues,
    (rcValues_Main *) &RC_OFFSET_VALUES_Main,
    &tmp);
  /* 1 */
  rotationMatrix_Controller_Setpoint(
    (*angleValues).psi,
    outC->Context_1.psiStartValue,
    &tmp,
    &tmp1);
  /* 1 */ calcSetpoints_Controller_Setpoint(&tmp1, &tmp2);
  /* 1 */ limitationBlock_Controller_Setpoint(&tmp2, &outC->setpointValues);
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** setpoints_Controller_Setpoint.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

