#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

void testAuton(){
    double start = pros::millis();
    moveBot(30, 100);
    delay(1000);
    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void redPositive(){
}

void redNegative(){
    movePID(8, 1000);
    turnPID(0, 1000);
    turnPID(0, 1000);
    movePID(9, 1000);
    liftTarget = 16500;
    delay(1000);
    liftTarget = 0;
    movePID(-3.5, 800);
    turnPID(327, 1000);
    movePID(-25, 2000);
    moveBot(-14, 80);
    delay(1000);
    // movePID(-43, 2000, 0, 200);
    autoClamp(true);
    delay(300);
    turnPID(136, 1000);
    autoIntake(475);
    movePID(26, 2000);
    movePID(-10, 2000);
    turnPID(120, 1000);
    movePID(16, 1000);
    turnPID(120, 1000);
    movePID(-30, 2000);
    turnPID(87, 1000);
    movePID(23, 2000);
    turnPID(70, 1000);
    delay(2000);
    autoIntake(0);
    movePID(-34, 3000);
}

void redAWP(){}

void bluePositive(){}

void blueNegative(){
    movePID(8, 1000);
    turnPID(0, 1000);
    turnPID(0, 1000);
    movePID(9, 1000);
    liftTarget = 16500;
    delay(1000);
    liftTarget = 0;
    movePID(-3.5, 800);
    turnPID(33, 1000);
    movePID(-25, 2000);
    moveBot(-14, 80);
    delay(1000);
    // movePID(-43, 2000, 0, 200);
    autoClamp(true);
    delay(300);
    turnPID(224, 1000);
    autoIntake(475);
    movePID(26, 2000);
    movePID(-10, 2000);
    turnPID(240, 1000);
    movePID(16, 1000);
    turnPID(240, 1000);
    movePID(-30, 2000);
    turnPID(273, 1000);
    movePID(23, 2000);
    turnPID(290, 1000);
    delay(2000);
    autoIntake(0);
    movePID(-34, 3000);
}

void blueAWP(){}

void autonSkills(){
    //7.75 tile to left end

    double start = pros::millis();
    autoClamp(false);
    liftTarget = 17500;
    delay(1200);
    liftTarget = 0;
    movePID(-16, 2000);
    turnPID(92, 2000);
    
    movePID(-7.5, 3000);
    moveBot(-12.5, 80);
    delay(1000);
    autoClamp(true);
    delay(600);
    turnPID(125, 2000);
    autoIntake(550);
    movePID(-35, 5000);
    autoClamp(false);
    movePID(5, 1000);
    movePID(-8, 800);
     movePID(5, 1000);
    turnPID(135, 800);
    movePID(20, 2000);
    turnPID(268, 2000);
    turnPID(268, 2000);
    movePID(-43, 3000);
    moveBot(-8, 80);
    delay(1000);
    autoClamp(true);
    turnPID(245, 1000);
    turnPID(245, 1000);
    movePID(-30, 5000);
    autoClamp(false);
    movePID(5, 1000);
    movePID(-8, 800);
    movePID(10, 1000);
    turnPID(180, 1000);
    turnPID(180, 1000);
    movePID(80, 5000);
    turnPID(35, 1000);
    turnPID(35, 1000);
    movePID(-38, 3000);
    moveBot(-15, 80);
    delay(1000);
    autoClamp(true);
    turnPID(75, 1000);
    movePID(-70, 3000);
    autoClamp(false);
    movePID(5, 1000);
    movePID(-8, 800);
    movePID(13, 1000);
    turnPID(280, 1000);
    turnPID(280, 1000);
    movePID(-60, 5000);
    moveBot(-15, 80);
    delay(1200);
    autoClamp(true);
    movePID(-30, 3000);
    movePID(5, 1000);
    movePID(-8, 800);
    movePID(10, 1000);
    // movePID(24, 3000);
    // turnPID(270, 2000);
    // movePID(24.5, 3000);
    // turnPID(203, 2000);
    // movePID(30.5, 2000);
    // turnPID(355.2, 3000);
    // turnPID(355.2, 3000);
    // movePID(50, 4000);
    // turnPID(330, 2000);
    // movePID(-23, 3000);
    // turnPID(0, 3000);
    // movePID(19, 3000);
    // delay(500);
    // movePID(14.5, 3000);
    // delay(500);
    // movePID(-13, 1000);
    // turnPID(135, 1000);
    // movePID(-13, 1000);
    // autoClamp(false);
    // moveBot(8, 80);
    // delay(300);
    // movePID(-5, 300);
    // turnPID(135, 2000);
    // movePID(19, 3000);
    // turnPID(270, 2000);
    // turnPID(270, 2000);
    // movePID(-57, 4000);
    // moveBot(-11, 80);
    // delay(1000);
    // autoClamp(true);


    // turnPID(180.25, 2000);
    // autoIntake(550);
    // movePID(26, 3000);
    // turnPID(87.5, 2000);
    // movePID(25.5, 3000);
    // turnPID(156, 2000);
    // movePID(31, 2000);
    // turnPID(3.9, 3000);
    // turnPID(3.9, 3000);
    // movePID(50, 4000);
    // turnPID(30, 2000);
    // movePID(-23, 3000);
    // turnPID(0, 3000);
    // movePID(22, 3000);
    // delay(500);
    // movePID(14.5, 3000);
    // delay(500);
    // movePID(-5, 1000);
    // turnPID(235, 1000);
    // movePID(-15, 800);
    // autoClamp(false);
    // moveBot(8, 80);
    // delay(300);
    // movePID(-5, 800);
    // turnPID(225, 2000);
    // movePID(14, 3000);
    // turnPID(0, 2000);
    // turnPID(0, 2000);
    // movePID(-90, 5000);
    // turnPID(45, 2000);
    // moveBot(-30, 80);
    // delay(3000);
    // movePID(-80, 5000);
}

void noAuton(){}

void preRedPos(){}

void preBluePos(){}

void preRedNeg(){
    turnPID(270, 2000);
    movePID(-2.6, 800);
    turnPID(270, 2000);
}

void preBlueNeg(){
    turnPID(90, 2000);
    movePID(-2.6, 800);
    turnPID(90, 2000);
}

void preAuton(){
    switch (autonSelected){
        case 2:
        preRedPos();
        break;
        
        case 3:
        preRedNeg();
        break;

        case 5:
        preBluePos();
        break;

        case 6:
        preBlueNeg();
        break;

        default:
        break;
    }
}

#endif