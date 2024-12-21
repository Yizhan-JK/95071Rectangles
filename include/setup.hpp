#ifndef SETUP_HPP
#define SETUP_HPP

#include "main.h"

// const int FL_PORT;
// const int ML_PORT;
// const int BL_PORT;
// const int FR_PORT;
// const int MR_PORT;
// const int BR_PORT;

// const int ODOM_PORT;

// const int INT_PORT;

const int LIFT_PORT = 8;
const int LIFTROT_PORT = 10;

// const char CLAMP_PORT;
// const char DOINKER_PORT;

pros::Controller master(pros::E_CONTROLLER_MASTER);

int liftTarget;

pros::Motor LiftMotor(LIFT_PORT, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
pros::Rotation LiftRotation(LIFTROT_PORT);

#endif