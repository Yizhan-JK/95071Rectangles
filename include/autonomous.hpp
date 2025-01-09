#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"

void testAuton(){
    double start = pros::millis();
    
    master.clear();
    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void redPositive(){
}

void redNegative(){
}

void redAWP(){}

void bluePositive(){}

void blueNegative(){}

void blueAWP(){}

void autonSkills(){}

void noAuton(){}

#endif