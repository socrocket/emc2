//**********************************************************************************
//*
//*   Autor: Soeren Schreiner
//* 
//*   scade.c
//*
//**********************************************************************************

#include "scade.h"
#include "main_Main.h"

//**********************************************************************************
// Inputs
//**********************************************************************************
extern ADCData ADCRawData; // struct all float
extern ADCOffset ADCOffsetData; // struct all float

extern RCData RCReadyData; // struct all float
extern RCEvents RCEventList; // struct all uint8_t

inC_main_Main inputs;
//**********************************************************************************
// Outputs
//**********************************************************************************
extern uint16_t i2c1Speed[4]; // motor outputs

angles angleValues = {0.0, 0.0, 0.0};
angles angleSpeedValues = {0.0, 0.0, 0.0};
setpoints setpointValues = {0.0, 0.0, 0.0, 0.0};
controllerInfos controllerInfoValues;
accAngles accAngleValues = {0.0, 0.0};
float heightValue = 0.0;
float heightSpeedValue = 0.0;

outC_main_Main outputs;

//**********************************************************************************

void calcSCADEModel()
{
  //************************************************************
  inputs.rcFlags.motorsOn = RCEventList.motorsOn;
  inputs.rcFlags.heightControl = RCEventList.heightControl;
  inputs.rcFlags.lostConnection = RCEventList.lostConnection;
  //************************************************************
  inputs.rcValues.thrust = RCReadyData.thrust;
  inputs.rcValues.yaw = RCReadyData.yaw;
  inputs.rcValues.pitch = RCReadyData.pitch;
  inputs.rcValues.roll = RCReadyData.roll;
  //************************************************************
  inputs.analogValues.accX = ADCRawData.accX;
  inputs.analogValues.accY = ADCRawData.accY;
  inputs.analogValues.accZ = ADCRawData.accZ;
  inputs.analogValues.gyroPitch = ADCRawData.gyroP;
  inputs.analogValues.gyroRoll = ADCRawData.gyroR;
  inputs.analogValues.gyroYaw = ADCRawData.gyroY;
  inputs.analogValues.barometer = ADCRawData.baro;
  inputs.analogValues.compass = ADCRawData.compass;
  //************************************************************
  inputs.analogOffsetValues.accX = ADCOffsetData.accX;
  inputs.analogOffsetValues.accY = ADCOffsetData.accY;
  inputs.analogOffsetValues.accZ = ADCOffsetData.accZ;
  inputs.analogOffsetValues.gyroPitch = ADCOffsetData.gyroP;
  inputs.analogOffsetValues.gyroRoll = ADCOffsetData.gyroR;
  inputs.analogOffsetValues.gyroYaw = ADCOffsetData.gyroY;
  inputs.analogOffsetValues.barometer = ADCOffsetData.baro;
  //************************************************************

  main_Main(&inputs, &outputs); // call model

  //************************************************************
  i2c1Speed[0] = outputs.motorValues.motorFront;
  i2c1Speed[1] = outputs.motorValues.motorRear;
  i2c1Speed[2] = outputs.motorValues.motorRight;
  i2c1Speed[3] = outputs.motorValues.motorLeft;
  //************************************************************
  angleValues.theta = outputs.anlgeValues.theta;
  angleValues.phi = outputs.anlgeValues.phi;
  angleValues.psi = outputs.anlgeValues.psi;
  //************************************************************
  angleSpeedValues.theta = outputs.anlgeSpeedValues.theta;
  angleSpeedValues.phi = outputs.anlgeSpeedValues.phi;
  angleSpeedValues.psi = outputs.anlgeSpeedValues.psi;
  //************************************************************
  ADCOffsetData.gyroP = outputs.analogCorrectedOffsetValues.gyroPitch;
  ADCOffsetData.gyroR = outputs.analogCorrectedOffsetValues.gyroRoll;
  ADCOffsetData.gyroY = outputs.analogCorrectedOffsetValues.gyroYaw;
  //************************************************************
  heightValue = outputs.heightValue;
  heightSpeedValue = outputs.heightSpeedValue;
  //************************************************************
  setpointValues.thrust = outputs.setpointValues.thrust;
  setpointValues.yaw = outputs.setpointValues.yaw;
  setpointValues.pitch = outputs.setpointValues.pitch;
  setpointValues.roll = outputs.setpointValues.roll;
  //************************************************************
  controllerInfoValues.theta.Kp = outputs.attitudeControllerValues.theta.Kp;
  controllerInfoValues.theta.Ki = outputs.attitudeControllerValues.theta.Ki;
  controllerInfoValues.theta.Kd = outputs.attitudeControllerValues.theta.Kd;
  controllerInfoValues.theta.Ks = outputs.attitudeControllerValues.theta.Ks;
  controllerInfoValues.thetaFinal = outputs.attitudeControllerValues.thetaFinal;
  //************************************************************
  controllerInfoValues.phi.Kp = outputs.attitudeControllerValues.phi.Kp;
  controllerInfoValues.phi.Ki = outputs.attitudeControllerValues.phi.Ki;
  controllerInfoValues.phi.Kd = outputs.attitudeControllerValues.phi.Kd;
  controllerInfoValues.phi.Ks = outputs.attitudeControllerValues.phi.Ks;
  controllerInfoValues.phiFinal = outputs.attitudeControllerValues.phiFinal;
  //************************************************************
  controllerInfoValues.psi.Kp = outputs.attitudeControllerValues.psi.Kp;
  controllerInfoValues.psi.Ki = outputs.attitudeControllerValues.psi.Ki;
  controllerInfoValues.psi.Kd = outputs.attitudeControllerValues.psi.Kd;
  controllerInfoValues.psi.Ks = outputs.attitudeControllerValues.psi.Ks;
  controllerInfoValues.psiFinal = outputs.attitudeControllerValues.psiFinal;
  //************************************************************
  controllerInfoValues.thrust.Kp = outputs.heightControllerValues.thrust.Kp;
  controllerInfoValues.thrust.Ki = outputs.heightControllerValues.thrust.Ki;
  controllerInfoValues.thrust.Kd = outputs.heightControllerValues.thrust.Kd;
  controllerInfoValues.thrust.Ks = outputs.heightControllerValues.thrust.Ks;
  controllerInfoValues.thrustFinal = outputs.heightControllerValues.thrustFinal;
  controllerInfoValues.setpoint = outputs.heightControllerValues.setpoint;
  controllerInfoValues.active = outputs.heightControllerValues.activated;
  //************************************************************
  accAngleValues.accTheta = outputs.accelerationAngleValues.accTheta;
  accAngleValues.accPhi = outputs.accelerationAngleValues.accPhi;
  //************************************************************
}
