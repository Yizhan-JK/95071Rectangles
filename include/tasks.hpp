#ifndef TASKS_HPP
#define TASKS_HPP

#include "setup.hpp"

const int k_lift = 0.02;

void liftTask(){
    while (true){

        if ((LiftRotation.get_position() - liftTarget) < -250)
            LiftMotor.move(k_lift * (liftTarget - LiftRotation.get_position()));
        else if ((LiftRotation.get_position() - liftTarget) > 250)
            LiftMotor.move(k_lift * (liftTarget - LiftRotation.get_position()));

        else LiftMotor.move(0);

            pros::delay(10);
    }
}

pros::Clock::time_point start;

void headerFileTask(){
    while (true){
        pros::Clock::time_point time = pros::Clock::now();
        pros::lcd::print(9, "hi im header file task! its %d o' clock", (time - start));
        pros::delay(25);
    }
}

pros::Task lift_task(liftTask, "lift task");
pros::Task header_file_task(headerFileTask, "header file task");

#endif