#ifndef CHASSIS_SETUP_HPP
#define CHASSIS_SETUP_HPP

#include "main.h"
#include "setup.hpp"

float kP = 13.5, kI = 0.002, kD = 15;
float smallError = 0.2, largeError = 1.5; //range, in inches
float smallErrorTimeout = 200, largeErrorTimeout = 800; //milliseconds
float windupRange = 3, slew = 200; //slew: maximum acceleration

lemlib::ControllerSettings LateralPID (kP, kI, kD, windupRange,
                                        smallError, smallErrorTimeout, largeError, largeErrorTimeout,
                                        slew);


//6, 0, 45, 3, 1
float rkP = 5.7, rkI = 0.001, rkD = 45;
// float rkP = 3.5, rkI = 0.001, rkD = 20;
//float rkP = 1.383, rkI = 0.001, rkD = 5.4;
float rsmallError = 1, rlargeError = 3; //range, in degrees
float rsmallErrorTimeout = 200, rlargeErrorTimeout = 500; //milliseconds
float rwindupRange = 3, rslew = 200; //slew: maximum acceleration

lemlib::ControllerSettings AngularPID (rkP, rkI, rkD, rwindupRange,
                                        rsmallError, rsmallErrorTimeout, rlargeError, rlargeErrorTimeout,
                                        rslew);

//Chassis

lemlib::ExpoDriveCurve Throttle (5, 10, 1.013);
lemlib::ExpoDriveCurve Steer (5, 10, 1.013);

lemlib::Chassis Chassis(Drivetrain, LateralPID, AngularPID, DTsensors, &Throttle, &Steer);

#endif