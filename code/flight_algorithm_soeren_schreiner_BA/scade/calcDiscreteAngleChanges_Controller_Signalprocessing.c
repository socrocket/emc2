/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "calcDiscreteAngleChanges_Controller_Signalprocessing.h"

/* Controller::Signalprocessing::calcDiscreteAngleChanges */
void calcDiscreteAngleChanges_Controller_Signalprocessing(
  /* Controller::Signalprocessing::calcDiscreteAngleChanges::angleSpeeds */angleValues_Main *angleSpeeds,
  /* Controller::Signalprocessing::calcDiscreteAngleChanges::angleSteps */angleValues_Main *angleSteps)
{
  (*angleSteps).theta = (*angleSpeeds).theta * TIMERPERIOD_Main;
  (*angleSteps).phi = (*angleSpeeds).phi * TIMERPERIOD_Main;
  (*angleSteps).psi = (*angleSpeeds).psi * TIMERPERIOD_Main;
}

/* $*************** KCG Version 6.1.2 (build i5) ****************
** calcDiscreteAngleChanges_Controller_Signalprocessing.c
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

