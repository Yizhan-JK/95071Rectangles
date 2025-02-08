#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

void testAuton(){
    // double start = pros::millis();

    // Chassis.moveToPoint(15, 15, 4000);
}

void redPositive(){
    // //5.25 (towards alliance stake), 11.5
    // autoClamp(false);
    // movePID(39.8, 1600);
    // autoArm(true);
    // moveBot(-13.1, 80);
    // delay(900);
    // turnPID(330, 800);
    // autoArm(false);
    // turnPID(310, 800);
    // delay(300);
    // turnPID(90, 800);
    // moveBot(-16, 90);
    // delay(1100);
    // autoClamp(true);
    // delay(300);
    // autoIntake(475);
    // turnPID(85, 800);
    // movePID(35, 1500);
    // delay(300);
    // turnPID(350, 800);
    // movePID(-30, 1000);
    // autoClamp(false);
    // delay(300);
    // movePID(20, 1000);
    // turnPID(135, 800);
    // // movePID(-10, 800);
    // moveBot(-16, 90);
    // delay(1000);
    // autoClamp(true);
    // delay(300);
    // turnPID(208, 800);
    // autoIntake(-475);
    // delay(300);
    // autoIntake(475);
    // movePID(48, 1500);
    // turnPID(320, 800);
    // movePID(15, 800);
    // moveBot(12, 90);
    // delay(2000);


    // // movePID(8, 800);
    // // turnPID(0, 800);
    // // // turnPID(0, 1000);
    // // movePID(9, 700);
    // // liftTarget = 16500;
    // // delay(1000);
    // // liftTarget = 0;
    // // movePID(-3.5, 500);
    // // turnPID(27, 800);
    // // movePID(-25.8, 1000);
    // // moveBot(-15, 90);
    // // delay(800);
    // // autoClamp(true);
    // // delay(300);
    // // turnPID(263, 800);
    // // autoIntake(475);
    // // movePID(30, 1200);

    // // delay(1200);
    // // autoIntake(-475);
    // // delay(50);
    // // autoIntake(475);
    // // turnPID(150, 1000);
    // // delay(800);
    // // autoClamp(false);
    
}

void redNegative(){
    Chassis.moveToPoint(-8, 15, 4000, {.earlyExitRange = 0.6});
    liftTarget = 15000;
    pros::delay(1000);
    liftTarget = 0;
    // autoIntake(-475);
    // movePID(8.8, 800);
    // turnPID(0, 800);
    // // turnPID(0, 1000);
    // movePID(9, 700);
    // autoIntake(0);
    // liftTarget = 16500;
    // delay(1000);
    // liftTarget = 0;
    // movePID(-3.5, 500);
    // turnPID(325.5, 800);
    // movePID(-27.2, 1000);
    // moveBot(-15, 90);
    // delay(800);
    // autoClamp(true);
    // delay(300);
    // turnPID(97, 800);
    // autoIntake(475);
    // movePID(30.5, 1200);
    // turnPID(175, 800);
    // autoIntake(-475);
    // delay(30);
    // autoIntake(475);
    // movePID(14.5, 1000);
    // delay(300);
    // movePID(-11, 800);
    // turnPID(198, 800);
    // movePID(10, 800);
    // delay(100);
    // movePID(-6, 800);
    // turnPID(280, 800);

    // autoIntake(-475);
    // delay(100);
    // autoIntake(475);
    // movePID(30, 1000);
    // turnPID(135, 800);
    // movePID(-15, 1000);
    // turnPID(90, 800);
    // // movePID(34.5, 1000);
    // // autoIntake(-475);
    // // delay(30);
    // // autoIntake(475);
    // // moveBot(10, 90);
    // // delay(800);
    // delay(2000);
}

void redAWP(){
    // delay(10000);
    // movePID(-11, 2000);
}

void bluePositive(){
//     autoClamp(false);
//     delay(3000);
//     movePID(7.5, 800);
//     turnPID(0, 800);
//     // turnPID(0, 1000);
//     movePID(9, 700);
//     liftTarget = 16500;
//     delay(1000);
//     liftTarget = 0;
//     movePID(-3.5, 500);
//     turnPID(323, 800);
//     movePID(-26, 1000);
//     moveBot(-15, 90);
//     delay(800);
//     autoClamp(true);
//     delay(300);
//     turnPID(97, 800);
//     autoIntake(475);
//     movePID(30, 1200);

//     delay(1200);
//     autoIntake(-475);
//     delay(50);
//     autoIntake(475);
//     turnPID(210, 1000);
//     delay(800);
//     autoClamp(false);
   }

   void blueNegative(){
//     autoIntake(-475);
//     movePID(9.5, 800);
//     turnPID(0, 800);
//     // turnPID(0, 1000);
//     movePID(9, 700);
//      autoIntake(0);
//     liftTarget = 16500;
//     delay(1000);
//     liftTarget = 0;
//     movePID(-3.5, 500);
//     turnPID(30, 800);
//     movePID(-26.2, 1000);
//     moveBot(-15, 90);
//     delay(800);
//     autoClamp(true);
//     delay(300);
//     turnPID(263, 800);
//     autoIntake(475);
//     movePID(30, 1200);
//     turnPID(185, 800);
//     autoIntake(-475);
//     delay(30);
//     autoIntake(475);
//     movePID(12.75, 1000);
//     delay(300);
//     movePID(-8, 800);
//     turnPID(160, 800);
//     autoIntake(-475);
//     delay(100);
//     autoIntake(475);
//     movePID(10, 800);
//     delay(100);
//     movePID(-6, 800);
//     turnPID(80, 800);
//     movePID(34.5, 1000);
//     moveBot(10, 90);
//     delay(800);
//     delay(2000);
}

void blueAWP(){
//     delay(10000);
//     movePID(-11, 2000);
   }

void autonSkills(){
    // //7.75 tile to left end

    // double start = pros::millis();
    // autoClamp(false);
    // liftTarget = 22500;
    // delay(1000);
    // movePID(-8, 2000);
    // turnPID(90, 2000);
    // liftTarget = 0;
    // movePID(-12, 3000);
    // moveBot(-6.5, 80);
    // delay(1000);
    // autoClamp(true);
    // turnPID(182, 2000);
    // autoIntake(550);
    // movePID(24, 3000);
    // turnPID(265, 2000);
    // movePID(24.5, 3000);
    // turnPID(203, 2000);
    // movePID(30.5, 2000);
    // turnPID(355.2, 3000);
    // turnPID(355.2, 3000);
    // movePID(50, 4000);
    // turnPID(330, 2000);
    // movePID(-23, 3000);
    // turnPID(0, 3000);
    // movePID(18, 3000);
    // delay(500);
    // movePID(15.5, 3000);
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
    // turnPID(259.5, 2000);
    // turnPID(259.5, 2000);
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

void preRedPos(){
    // turnPID(6.2, 800);
    // turnPID(6.2, 800);
    turnPID(90, 2000);
    movePID(-2.6, 800);
    turnPID(90, 2000);
}

void preBluePos(){
    // turnPID(353.8, 800);
    // turnPID(353.8, 800);
    turnPID(270, 2000);
    movePID(-2.6, 800);
    turnPID(270, 2000);
}

void preRedNeg(){
    Chassis.moveToPoint(-6.5, 13, 4000, {.earlyExitRange = 0.6});
    Chassis.waitUntilDone();
    // pros::delay(1000);
    turnPID(335, 800);
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