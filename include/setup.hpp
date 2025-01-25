#ifndef SETUP_HPP
#define SETUP_HPP

#include "main.h"
#include "lemlib/api.hpp"

const int FL_PORT = -19;
const int ML_PORT = -18;
const int BL_PORT = -17;
const int FR_PORT = 16;
const int MR_PORT = 15;
const int BR_PORT = 14;

const int INTB_PORT = 9;
const int INTF_PORT = -10;

const int LIFT_PORT = 7;
const int LIFTROT_PORT = 5;

const int OPTICAL_PORT = 8;

const char CLAMP_PORT = 'C';
const char DOINKER_PORT = 'D';
const char COLOR_PORT = 'B';

const int IMU_PORT = 1;

// const int VERT_ODOM_PORT;
//const int HORIZ_ODOM_PORT = 17;


/*measurementss*/

const float TRACK_WIDTH = 11.875;
const float LEFT_DT_OFFSET = -5.9375;
const float RIGHT_DT_OFFSET = 5.9375;
const float HORIZ_ODOM_OFFSET = 4.5000;

/**************/


pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup LeftDT({FL_PORT, ML_PORT, BL_PORT}, pros::v5::MotorGears::blue);
pros::MotorGroup RightDT({FR_PORT, MR_PORT, BR_PORT}, pros::v5::MotorGears::blue);

pros::Motor IntakeFMotor(INTF_PORT, pros::v5::MotorGears::green);

pros::Motor IntakeBMotor(INTB_PORT, pros::v5::MotorGears::blue);

int liftTarget;

pros::Motor LiftMotor(LIFT_PORT, pros::v5::MotorGears::green);  

pros::Rotation LiftRotation(LIFTROT_PORT);

pros::Optical OpticalSensor(OPTICAL_PORT);

pros::adi::Pneumatics ClampPiston(CLAMP_PORT, true);
pros::adi::Pneumatics DoinkerPiston(DOINKER_PORT, false);
pros::adi::Pneumatics colorPiston(COLOR_PORT, false);

/*

LEMLIB

*/

pros::Imu Imu(IMU_PORT);
// pros::Rotation HorizontalRotation(HORIZ_ODOM_PORT);

const float DT_WHEEL_DIAMETER = lemlib::Omniwheel::NEW_325;
const float TRACKING_WHEEL_DIAMETER = lemlib::Omniwheel::NEW_2;

const float DT_RPM = 450;
const float DT_DRIFT = 8;

lemlib::TrackingWheel LeftDTtracking(&LeftDT, DT_WHEEL_DIAMETER, LEFT_DT_OFFSET, DT_RPM);
lemlib::TrackingWheel RightDTtracking(&RightDT, DT_WHEEL_DIAMETER, LEFT_DT_OFFSET, DT_RPM);

//tracking gear ratio = 1
//lemlib::TrackingWheel HorizontalTracking(&HorizontalRotation, TRACKING_WHEEL_DIAMETER, HORIZ_ODOM_OFFSET, 1);

lemlib::Drivetrain Drivetrain(&LeftDT, &RightDT, TRACK_WIDTH, DT_WHEEL_DIAMETER, DT_RPM, DT_DRIFT);

lemlib::OdomSensors DTsensors(&LeftDTtracking, &RightDTtracking, nullptr/*&HorizontalTracking*/, nullptr, &Imu);

#endif