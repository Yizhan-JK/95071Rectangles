#ifndef CHASSIS_SETUP_HPP
#define CHASSIS_SETUP_HPP

#include "main.h"
#include "setup.hpp"

float kP = 5, kI = 0, kD = 0;
float smallError = 0, largeError = 0; //range, in inches
float smallErrorTimeout = 0, largeErrorTimeout = 0; //milliseconds
float windupRange = 0, slew = 0; //slew: maximum acceleration

lemlib::ControllerSettings LateralPID (kP, kI, kD, windupRange,
                                        smallError, smallErrorTimeout, largeError, largeErrorTimeout,
                                        slew);

float rkP = 1, rkI = 0, rkD = 0;
float rsmallError = 0, rlargeError = 0; //range, in degrees
float rsmallErrorTimeout = 0, rlargeErrorTimeout = 0; //milliseconds
float rwindupRange = 0, rslew = 0; //slew: maximum acceleration

lemlib::ControllerSettings AngularPID (rkP, rkI, rkD, rwindupRange,
                                        rsmallError, rsmallErrorTimeout, rlargeError, rlargeErrorTimeout,
                                        rslew);

//Chassis

lemlib::ExpoDriveCurve Throttle (5, 10, 1.013);
lemlib::ExpoDriveCurve Steer (5, 10, 1.013);

lemlib::Chassis Chassis(Drivetrain, LateralPID, AngularPID, DTsensors, &Throttle, &Steer);

#endif