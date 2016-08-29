/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "angleIntegration_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::angleIntegration */
void angleIntegration_Controller_Signalprocessing(
  /* Controller::Signalprocessing::angleIntegration::angleStepsTransformed */angleValues_Main *angleStepsTransformed,
  /* Controller::Signalprocessing::angleIntegration::angleValues */angleValues_Main *angleValues,
  /* Controller::Signalprocessing::angleIntegration::angleValuesNew */angleValues_Main *angleValuesNew)
{
  (*angleValuesNew).theta = (*angleStepsTransformed).theta +
    (*angleValues).theta;
  (*angleValuesNew).phi = (*angleStepsTransformed).phi + (*angleValues).phi;
  (*angleValuesNew).psi = (*angleStepsTransformed).psi + (*angleValues).psi;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** angleIntegration_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

