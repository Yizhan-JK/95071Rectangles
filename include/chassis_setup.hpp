#ifndef CHASSIS_SETUP_HPP
#define CHASSIS_SETUP_HPP

#include "main.h"
#include "setup.hpp"

float kP = 6.5, kI = 0.00025, kD = 2;
float smallError = 0.5, largeError = 0; //range, in inches
float smallErrorTimeout = 400, largeErrorTimeout = 0; //milliseconds
float windupRange = 3, slew = 20; //slew: maximum acceleration

lemlib::ControllerSettings LateralPID (kP, kI, kD, windupRange,
                                        smallError, smallErrorTimeout, largeError, largeErrorTimeout,
                                        slew);

float rkP = 0.98, rkI = 0.0019, rkD = 0.6;
float rsmallError = 0, rlargeError = 0; //range, in degrees
float rsmallErrorTimeout = 300, rlargeErrorTimeout = 0; //milliseconds
float rwindupRange = 2, rslew = 40; //slew: maximum acceleration

lemlib::ControllerSettings AngularPID (rkP, rkI, rkD, rwindupRange,
                                        rsmallError, rsmallErrorTimeout, rlargeError, rlargeErrorTimeout,
                                        rslew);

//Chassis

lemlib::ExpoDriveCurve Throttle (5, 10, 1.013);
lemlib::ExpoDriveCurve Steer (5, 10, 1.013);

lemlib::Chassis Chassis(Drivetrain, LateralPID, AngularPID, DTsensors, &Throttle, &Steer);

#endif