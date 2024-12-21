#ifndef TASKS_HPP
#define TASKS_HPP

#include "setup.hpp"

const int k_lift = 0.02;

void liftTask(){
    if ((LiftRotation.get_position() - liftTarget) < -250)
        LiftMotor.move(k_lift * (liftTarget - LiftRotation.get_position()));
    else if ((LiftRotation.get_position() - liftTarget) > 250)
        LiftMotor.move(k_lift * (liftTarget - LiftRotation.get_position()));

    else LiftMotor.move(0);

        pros::delay(10);
}

pros::Task lift_task(liftTask);

#endif