#ifndef CHASSIS_SETUP_HPP
#define CHASSIS_SETUP_HPP

#include "main.h"
#include "setup.hpp"

float kP = 12.7, kI = 0.0001, kD = 1.25;
float smallError = 0, largeError = 0; //range, in inches
float smallErrorTimeout = 0, largeErrorTimeout = 0; //milliseconds
float windupRange = 3, slew = 0; //slew: maximum acceleration

lemlib::ControllerSettings LateralPID (kP, kI, kD, windupRange,
                                        smallError, smallErrorTimeout, largeError, largeErrorTimeout,
                                        slew);

float rkP = 1.6, rkI = 0.0001, rkD = 0.6;
float rsmallError = 0, rlargeError = 0; //range, in degrees
float rsmallErrorTimeout = 0, rlargeErrorTimeout = 0; //milliseconds
float rwindupRange = 3, rslew = 0; //slew: maximum acceleration

lemlib::ControllerSettings AngularPID (rkP, rkI, rkD, rwindupRange,
                                        rsmallError, rsmallErrorTimeout, rlargeError, rlargeErrorTimeout,
                                        rslew);

//Chassis

lemlib::ExpoDriveCurve Throttle (5, 10, 1.013);
lemlib::ExpoDriveCurve Steer (5, 10, 1.013);

lemlib::Chassis Chassis(Drivetrain, LateralPID, AngularPID, DTsensors, &Throttle, &Steer);

#endif