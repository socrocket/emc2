//**********************************************************************************
//*
//*   Autor: Soeren Schreiner
//* 
//*   scade.h
//*
//**********************************************************************************

#ifndef _SCADE_H
#define _SCADE_H

//**********************************************************************************

typedef struct
{
  volatile float theta;
  volatile float phi;
  volatile float psi;
} __attribute__((packed)) angles;

typedef struct
{
  volatile float thrust;
  volatile float yaw;
  volatile float pitch;
  volatile float roll;
} __attribute__((packed)) setpoints;

typedef struct
{
  volatile float Kp;
  volatile float Ki;
  volatile float Kd;
  volatile float Ks;
} __attribute__((packed)) pidControllerParts;

typedef struct
{
  volatile float accTheta; 
  volatile float accPhi;
} __attribute__((packed)) accAngles;

typedef struct
{
  volatile pidControllerParts theta;
  volatile float thetaFinal;
  volatile pidControllerParts phi;
  volatile float phiFinal;
  volatile pidControllerParts psi;
  volatile float psiFinal;
  volatile pidControllerParts thrust;
  volatile float thrustFinal;
  volatile float setpoint;
  bool active;
} __attribute__((packed)) controllerInfos;

void calcSCADEModel(void);


#endif
