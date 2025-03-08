#ifndef SETUP_HPP
#define SETUP_HPP

#include "main.h"
#include "lemlib/api.hpp"

const int FL_PORT = -6;
const int ML_PORT = -5;
const int BL_PORT = -4;
const int FR_PORT = 3;
const int MR_PORT = 2;
const int BR_PORT = 1;

const int INTB_PORT = 8;
const int INTF_PORT = -21;

const int LIFT_PORT = 7;
const int LIFTROT_PORT = -11;

const int OPTICAL_PORT = 12;

const char CLAMP_PORT = 'C';
const char DOINKER_PORT = 'B';
const char COLOR_PORT = 'D';

const int IMU_PORT = 13;

const int VERT_ODOM_PORT = 14;
const int HORIZ_ODOM_PORT = -15;


/*measurementss*/

const float TRACK_WIDTH = 12.1875;
const float LEFT_DT_OFFSET = -6.09375;
const float RIGHT_DT_OFFSET = 6.09375;
const float HORIZ_ODOM_OFFSET = 3.98;
const float VERT_ODOM_OFFSET = 0.73;

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

pros::adi::Pneumatics ClampPiston(CLAMP_PORT, false);
pros::adi::Pneumatics DoinkerPiston(DOINKER_PORT, false);
pros::adi::Pneumatics colorPiston(COLOR_PORT, false);

/*

LEMLIB

*/

pros::Imu ImuSensor(IMU_PORT);
pros::Rotation HorizontalRotation(HORIZ_ODOM_PORT);
pros::Rotation VerticalRotation(VERT_ODOM_PORT);

const float DT_WHEEL_DIAMETER = 3.25;//lemlib::Omniwheel::NEW_325;
const float TRACKING_WHEEL_DIAMETER = 2.00/*lemlib::Omniwheel::NEW_2*/;

const float DT_RPM = 450;
const float DT_DRIFT = 8;

// lemlib::TrackingWheel LeftDTtracking(&LeftDT, DT_WHEEL_DIAMETER, LEFT_DT_OFFSET, DT_RPM);
// lemlib::TrackingWheel RightDTtracking(&RightDT, DT_WHEEL_DIAMETER, LEFT_DT_OFFSET, DT_RPM);

//tracking gear ratio = 1
lemlib::TrackingWheel HorizontalTracking(&HorizontalRotation, TRACKING_WHEEL_DIAMETER, HORIZ_ODOM_OFFSET, 1);
lemlib::TrackingWheel VerticalTracking(&VerticalRotation, TRACKING_WHEEL_DIAMETER, VERT_ODOM_OFFSET, 1);

lemlib::Drivetrain Drivetrain(&LeftDT, &RightDT, TRACK_WIDTH, DT_WHEEL_DIAMETER, DT_RPM, DT_DRIFT);

lemlib::OdomSensors DTsensors(&VerticalTracking, nullptr, &HorizontalTracking, nullptr, &ImuSensor);

#endif