/* $*************** KCG Version 6.1.2 (build i5) ****************
** Command: s2c612 -config D:/Bachelor-SVN/Programmcode/scade/KCG\kcg_s2c_config.txt
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#define KCG_MAPW_CPY

#include "./my_macros.h"

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif /* kcg_real */

#ifndef kcg_char
#define kcg_char kcg_char
typedef unsigned char kcg_char;
#endif /* kcg_char */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* truthtables::TruthTableValues */
typedef enum {
  T_truthtables,
  F_truthtables,
  X_truthtables
} TruthTableValues_truthtables;
typedef struct { kcg_real accTheta; kcg_real accPhi; } struct__8352;

/* Main::accelerationAngles */
typedef struct__8352 accelerationAngles_Main;

typedef struct { kcg_real accX; kcg_real accY; kcg_real accZ; } struct__8357;

/* Main::accelerations */
typedef struct__8357 accelerations_Main;

typedef struct {
  kcg_real accX;
  kcg_real accY;
  kcg_real accZ;
  kcg_real gyroPitch;
  kcg_real gyroRoll;
  kcg_real gyroYaw;
  kcg_real barometer;
} struct__8363;

/* Main::analogOffsetValues */
typedef struct__8363 analogOffsetValues_Main;

typedef struct { kcg_real theta; kcg_real phi; kcg_real psi; } struct__8373;

/* Main::angleValues */
typedef struct__8373 angleValues_Main;

typedef struct {
  kcg_real sinTheta;
  kcg_real cosTheta;
  kcg_real sinPhi;
  kcg_real cosPhi;
  kcg_real sinPsi;
  kcg_real cosPsi;
} struct__8379;

/* Main::sinCosValues */
typedef struct__8379 sinCosValues_Main;

typedef struct {
  kcg_real accX;
  kcg_real accY;
  kcg_real accZ;
  kcg_real gyroPitch;
  kcg_real gyroRoll;
  kcg_real gyroYaw;
  kcg_real barometer;
  kcg_real compass;
} struct__8388;

/* Main::analogValuesReal */
typedef struct__8388 analogValuesReal_Main;

typedef struct {
  kcg_int accX;
  kcg_int accY;
  kcg_int accZ;
  kcg_int gyroPitch;
  kcg_int gyroRoll;
  kcg_int gyroYaw;
  kcg_int barometer;
  kcg_real compass;
} struct__8399;

/* Main::analogValues */
typedef struct__8399 analogValues_Main;

typedef struct {
  kcg_real thrustMin;
  kcg_real thrust;
  kcg_real yaw;
  kcg_real pitch;
  kcg_real roll;
} struct__8410;

/* Main::rcNormalizingValues */
typedef struct__8410 rcNormalizingValues_Main;

typedef struct {
  kcg_real thrust;
  kcg_real yaw;
  kcg_real pitch;
  kcg_real roll;
} struct__8418;

/* Main::rcValuesReal */
typedef struct__8418 rcValuesReal_Main;

typedef struct {
  kcg_int thrust;
  kcg_int yaw;
  kcg_int pitch;
  kcg_int roll;
} struct__8425;

/* Main::rcValues */
typedef struct__8425 rcValues_Main;

typedef struct {
  kcg_bool motorsOn;
  kcg_bool heightControl;
  kcg_bool lostConnection;
} struct__8432;

/* Main::rcFlags */
typedef struct__8432 rcFlags_Main;

typedef struct {
  kcg_int motorFront;
  kcg_int motorRear;
  kcg_int motorLeft;
  kcg_int motorRight;
} struct__8438;

/* Main::motorValues */
typedef struct__8438 motorValues_Main;

typedef struct {
  kcg_real Kp;
  kcg_real Ki;
  kcg_real Kd;
  kcg_real Ks;
} struct__8445;

/* Main::controllerSettings */
typedef struct__8445 controllerSettings_Main;

typedef struct {
  controllerSettings_Main theta;
  kcg_real thetaFinal;
  controllerSettings_Main phi;
  kcg_real phiFinal;
  controllerSettings_Main psi;
  kcg_real psiFinal;
} struct__8452;

/* Main::attitudeController */
typedef struct__8452 attitudeController_Main;

typedef struct {
  controllerSettings_Main thrust;
  kcg_real thrustFinal;
  kcg_real setpoint;
  kcg_bool activated;
} struct__8461;

/* Main::heightController */
typedef struct__8461 heightController_Main;

typedef struct { kcg_int k; kcg_real f; } struct__8468;

/* lut::LutIndex */
typedef struct__8468 LutIndex_lut;

#ifndef kcg_copy_struct__8352
#define kcg_copy_struct__8352(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8352)))
#endif /* kcg_copy_struct__8352 */

#ifndef kcg_copy_struct__8357
#define kcg_copy_struct__8357(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8357)))
#endif /* kcg_copy_struct__8357 */

#ifndef kcg_copy_struct__8363
#define kcg_copy_struct__8363(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8363)))
#endif /* kcg_copy_struct__8363 */

#ifndef kcg_copy_struct__8373
#define kcg_copy_struct__8373(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8373)))
#endif /* kcg_copy_struct__8373 */

#ifndef kcg_copy_struct__8379
#define kcg_copy_struct__8379(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8379)))
#endif /* kcg_copy_struct__8379 */

#ifndef kcg_copy_struct__8388
#define kcg_copy_struct__8388(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8388)))
#endif /* kcg_copy_struct__8388 */

#ifndef kcg_copy_struct__8399
#define kcg_copy_struct__8399(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8399)))
#endif /* kcg_copy_struct__8399 */

#ifndef kcg_copy_struct__8410
#define kcg_copy_struct__8410(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8410)))
#endif /* kcg_copy_struct__8410 */

#ifndef kcg_copy_struct__8418
#define kcg_copy_struct__8418(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8418)))
#endif /* kcg_copy_struct__8418 */

#ifndef kcg_copy_struct__8425
#define kcg_copy_struct__8425(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8425)))
#endif /* kcg_copy_struct__8425 */

#ifndef kcg_copy_struct__8432
#define kcg_copy_struct__8432(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8432)))
#endif /* kcg_copy_struct__8432 */

#ifndef kcg_copy_struct__8438
#define kcg_copy_struct__8438(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8438)))
#endif /* kcg_copy_struct__8438 */

#ifndef kcg_copy_struct__8445
#define kcg_copy_struct__8445(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8445)))
#endif /* kcg_copy_struct__8445 */

#ifndef kcg_copy_struct__8452
#define kcg_copy_struct__8452(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8452)))
#endif /* kcg_copy_struct__8452 */

#ifndef kcg_copy_struct__8461
#define kcg_copy_struct__8461(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8461)))
#endif /* kcg_copy_struct__8461 */

#ifndef kcg_copy_struct__8468
#define kcg_copy_struct__8468(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__8468)))
#endif /* kcg_copy_struct__8468 */

#ifndef kcg_comp_struct__8352
extern kcg_bool kcg_comp_struct__8352(
  struct__8352 *kcg_c1,
  struct__8352 *kcg_c2);
#endif /* kcg_comp_struct__8352 */

#ifndef kcg_comp_struct__8357
extern kcg_bool kcg_comp_struct__8357(
  struct__8357 *kcg_c1,
  struct__8357 *kcg_c2);
#endif /* kcg_comp_struct__8357 */

#ifndef kcg_comp_struct__8363
extern kcg_bool kcg_comp_struct__8363(
  struct__8363 *kcg_c1,
  struct__8363 *kcg_c2);
#endif /* kcg_comp_struct__8363 */

#ifndef kcg_comp_struct__8373
extern kcg_bool kcg_comp_struct__8373(
  struct__8373 *kcg_c1,
  struct__8373 *kcg_c2);
#endif /* kcg_comp_struct__8373 */

#ifndef kcg_comp_struct__8379
extern kcg_bool kcg_comp_struct__8379(
  struct__8379 *kcg_c1,
  struct__8379 *kcg_c2);
#endif /* kcg_comp_struct__8379 */

#ifndef kcg_comp_struct__8388
extern kcg_bool kcg_comp_struct__8388(
  struct__8388 *kcg_c1,
  struct__8388 *kcg_c2);
#endif /* kcg_comp_struct__8388 */

#ifndef kcg_comp_struct__8399
extern kcg_bool kcg_comp_struct__8399(
  struct__8399 *kcg_c1,
  struct__8399 *kcg_c2);
#endif /* kcg_comp_struct__8399 */

#ifndef kcg_comp_struct__8410
extern kcg_bool kcg_comp_struct__8410(
  struct__8410 *kcg_c1,
  struct__8410 *kcg_c2);
#endif /* kcg_comp_struct__8410 */

#ifndef kcg_comp_struct__8418
extern kcg_bool kcg_comp_struct__8418(
  struct__8418 *kcg_c1,
  struct__8418 *kcg_c2);
#endif /* kcg_comp_struct__8418 */

#ifndef kcg_comp_struct__8425
extern kcg_bool kcg_comp_struct__8425(
  struct__8425 *kcg_c1,
  struct__8425 *kcg_c2);
#endif /* kcg_comp_struct__8425 */

#ifndef kcg_comp_struct__8432
extern kcg_bool kcg_comp_struct__8432(
  struct__8432 *kcg_c1,
  struct__8432 *kcg_c2);
#endif /* kcg_comp_struct__8432 */

#ifndef kcg_comp_struct__8438
extern kcg_bool kcg_comp_struct__8438(
  struct__8438 *kcg_c1,
  struct__8438 *kcg_c2);
#endif /* kcg_comp_struct__8438 */

#ifndef kcg_comp_struct__8445
extern kcg_bool kcg_comp_struct__8445(
  struct__8445 *kcg_c1,
  struct__8445 *kcg_c2);
#endif /* kcg_comp_struct__8445 */

#ifndef kcg_comp_struct__8452
extern kcg_bool kcg_comp_struct__8452(
  struct__8452 *kcg_c1,
  struct__8452 *kcg_c2);
#endif /* kcg_comp_struct__8452 */

#ifndef kcg_comp_struct__8461
extern kcg_bool kcg_comp_struct__8461(
  struct__8461 *kcg_c1,
  struct__8461 *kcg_c2);
#endif /* kcg_comp_struct__8461 */

#ifndef kcg_comp_struct__8468
extern kcg_bool kcg_comp_struct__8468(
  struct__8468 *kcg_c1,
  struct__8468 *kcg_c2);
#endif /* kcg_comp_struct__8468 */

#define kcg_comp_LutIndex_lut kcg_comp_struct__8468

#define kcg_copy_LutIndex_lut kcg_copy_struct__8468

#define kcg_comp_heightController_Main kcg_comp_struct__8461

#define kcg_copy_heightController_Main kcg_copy_struct__8461

#define kcg_comp_attitudeController_Main kcg_comp_struct__8452

#define kcg_copy_attitudeController_Main kcg_copy_struct__8452

#define kcg_comp_controllerSettings_Main kcg_comp_struct__8445

#define kcg_copy_controllerSettings_Main kcg_copy_struct__8445

#define kcg_comp_rcNormalizingValues_Main kcg_comp_struct__8410

#define kcg_copy_rcNormalizingValues_Main kcg_copy_struct__8410

#define kcg_comp_rcFlags_Main kcg_comp_struct__8432

#define kcg_copy_rcFlags_Main kcg_copy_struct__8432

#define kcg_comp_rcValuesReal_Main kcg_comp_struct__8418

#define kcg_copy_rcValuesReal_Main kcg_copy_struct__8418

#define kcg_comp_rcValues_Main kcg_comp_struct__8425

#define kcg_copy_rcValues_Main kcg_copy_struct__8425

#define kcg_comp_accelerationAngles_Main kcg_comp_struct__8352

#define kcg_copy_accelerationAngles_Main kcg_copy_struct__8352

#define kcg_comp_accelerations_Main kcg_comp_struct__8357

#define kcg_copy_accelerations_Main kcg_copy_struct__8357

#define kcg_comp_sinCosValues_Main kcg_comp_struct__8379

#define kcg_copy_sinCosValues_Main kcg_copy_struct__8379

#define kcg_comp_analogValuesReal_Main kcg_comp_struct__8388

#define kcg_copy_analogValuesReal_Main kcg_copy_struct__8388

#define kcg_comp_analogOffsetValues_Main kcg_comp_struct__8363

#define kcg_copy_analogOffsetValues_Main kcg_copy_struct__8363

#define kcg_comp_analogValues_Main kcg_comp_struct__8399

#define kcg_copy_analogValues_Main kcg_copy_struct__8399

#define kcg_comp_angleValues_Main kcg_comp_struct__8373

#define kcg_copy_angleValues_Main kcg_copy_struct__8373

#define kcg_comp_motorValues_Main kcg_comp_struct__8438

#define kcg_copy_motorValues_Main kcg_copy_struct__8438

#endif /* _KCG_TYPES_H_ */
/* $*************** KCG Version 6.1.2 (build i5) ****************
** kcg_types.h
** Generation date: 2011-03-07T21:45:05
*************************************************************$ */

