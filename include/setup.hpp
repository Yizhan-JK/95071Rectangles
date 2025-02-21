#ifndef SETUP_HPP
#define SETUP_HPP

#include "main.h"

#include <math.h>

#define DEG_RAD M_PI/180

const int FL_PORT = -20;
const int ML_PORT = -17;
const int BL_PORT = -5;
const int FR_PORT = 13;
const int MR_PORT = 14;
const int BR_PORT = 15;

const int INTB_PORT = 7;
const int INTF_PORT = -9;

const int LIFT_PORT = 18;
const int LIFTROT_PORT = -8;

const int OPTICAL_PORT = 3;

const char CLAMP_PORT = 'A';
const char DOINKER_PORT = 'B';
const char COLOR_PORT = 'E';

const int IMU_PORT = 16;

const int VERT_ODOM_PORT = 2;
const int HORIZ_ODOM_PORT = 1;


/*measurementss*/

// const float TRACK_WIDTH = 11.875;
// const float LEFT_DT_OFFSET = -5.9375;
// const float RIGHT_DT_OFFSET = 5.9375;
const float HORIZ_ODOM_OFFSET = 7.5000;
const float VERT_ODOM_OFFSET = 1.1875;

/**************/

const float DT_WHEEL_CIRCUMFERENCE = 3.25 * M_PI;
const float TRACKING_WHEEL_CIRCUMFERENCE = 2 * M_PI;

const float DT_RPM = 450;

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
pros::adi::Pneumatics ColorPiston(COLOR_PORT, false);

pros::Imu Imu(IMU_PORT);
pros::Rotation HorizontalRotation(HORIZ_ODOM_PORT);
pros::Rotation VerticalRotation(VERT_ODOM_PORT);

int sign (double in){
    return (in > 0) - (in < 0);
}

#endif