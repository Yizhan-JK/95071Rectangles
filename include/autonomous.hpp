#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

void testAuton(){
    Chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    double start = pros::millis();
    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void redPositive(){
    autoClamp(false);
    movePID(-15, 1000, 0, 150);
    moveBot(-10, 90);
    delay(1300);
    autoClamp(true);
    delay(300);
    turnPID(295, 800);
    autoIntake(475);
    movePID(23, 1500, 0, 300);
    delay(1500);
    turnPID(165, 800);
    // double start = pros::millis();
    // autoClamp(false);
    // delay(2000);
    // autoIntake(-475);
    // movePID(7, 1000, 0, 350);
    // moveBot(1.5, 80);
    // delay(300);
    // liftTarget = 16500;
    // delay(1000);
    // movePID(-3, 800, 0, 350);
    // liftTarget = 0;
    // turnPID(20, 800);
    // movePID(-21.75, 1200, 0, 550);
    // autoIntake(0);
    // moveBot(-8.9, 100);
    // delay(800);
    // autoClamp(true);
    // delay(300);

    // turnPID(283, 800);
    // autoIntake(475);
    // movePID(25, 1200);
    // delay(1200);
    // turnPID(150, 1000);
    // delay(800);
}

void redNegative(){
    double start = pros::millis();
    autoClamp(false);
    autoIntake(-475);
    movePID(6.75, 1200, 0, 250);
    liftTarget = 16500;
    delay(1000);
    movePID(-3, 800, 0, 300);
    liftTarget = 0;
    turnPID(332.75, 300);
    movePID(-21.8, 2000, 0, 550);
    autoIntake(0);
    moveBot(-10, 100);
    delay(900);
    autoClamp(true);
    delay(300);
    turnPID(126, 800);
    autoIntake(475);
    movePID(16, 2500, 50, 550);
    turnPID(100, 1000);
    movePID(13, 2000, 50, 550);
    turnPID(115, 800);
    movePID(-20, 2000, 50, 550);
    turnPID(75, 800);
    movePID(13, 1200, 50, 550);
    turnPID(308, 800);

    // autoIntake(475);


    movePID(37, 3000, 50, 550);
    turnPID(280, 800);
    movePID(37, 3000, 50, 550);


    // turnPID(275, 800);
    // movePID(24, 2000, 50, 550);
    // moveBot(15, 110);
    // delay(2000);


    // movePID(37, 3000, 50, 550);
    // autoArm(true);
    // movePID(-12, 800, 50, 300);
    // autoArm(false);
    // turnPID(315, 800);
    // movePID(12, 800, 50, 550);
    // turnPID(215, 800);
    // moveBot(10, 110);
    // delay(800);

    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void redAWP(){
    delay(10000);
    movePID(-11, 2000);
}

void bluePositive(){
    autoClamp(false);
    movePID(-15, 1000, 0, 150);
    moveBot(-10, 90);
    delay(1300);
    autoClamp(true);
    delay(300);
    turnPID(65, 800);
    autoIntake(475);
    movePID(23, 1500, 0, 300);
    delay(1500);
    turnPID(195, 800);

    // double start = pros::millis();
    // autoClamp(false);
    // pros::delay(2000);
    // autoIntake(-475);
    // movePID(6.75, 1200, 0, 250);
    // liftTarget = 16500;
    // delay(1000);
    // movePID(-3, 800, 0, 300);
    // liftTarget = 0;
    // turnPID(332.75, 300);
    // movePID(-21.8, 2000, 0, 550);
    // autoIntake(0);
    // moveBot(-12, 100);
    // delay(900);
    // autoClamp(true);
    // delay(300);
    // turnPID(77, 800);
    // autoIntake(475);
    // movePID(25, 1200);
    // delay(1200);
    // turnPID(210, 1000);
    // delay(800);
}

void blueNegative(){
    double start = pros::millis();
    autoClamp(false);
    autoIntake(-475);
    movePID(7, 1000, 0, 350);
    liftTarget = 16500;
    delay(1000);
    movePID(-3, 800, 0, 350);
    liftTarget = 0;
    turnPID(20, 800);
    movePID(-21.75, 1200, 0, 550);
    autoIntake(0);
    moveBot(-8.9, 100);
    delay(800);
    autoClamp(true);
    delay(300);
    turnPID(234, 800);
    autoIntake(475);
    movePID(17, 1200, 70, 550);
    turnPID(263, 1000);
    movePID(14, 1200, 70, 550);
    turnPID(240, 800);
    movePID(-20, 1200, 70, 550);
    turnPID(290, 800);
    movePID(13, 1200, 70, 550);
    turnPID(38, 800);
    autoIntake(475);

    movePID(42, 3000, 50, 550);
    turnPID(80, 800);
    movePID(37, 3000, 50, 550);


    // turnPID(83, 800);
    // movePID(29, 2000, 70, 550);
    // moveBot(10, 110);
    // delay(2000);


    // movePID(42, 2000, 70, 550);
    // autoArm(true);
    // movePID(-12, 800, 50, 300);
    // autoArm(false);
    // turnPID(65, 800);
    // movePID(12, 800, 80, 550);
    // turnPID(145, 800);
    // moveBot(10, 115);
    // delay(800);

    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void blueAWP(){

    // delay(10000);
    // movePID(-11, 2000);
}

void autonSkills(){
    autoClamp(false);
    liftTarget = 16500;
    delay(1000);
    movePID(-8, 800, 0, 200);
    liftTarget = 0;
    moveBot(-8, 90);
    delay(800);
    autoClamp(true);
    delay(300);
    autoIntake(475);
    turnPID(167.5, 800);
    movePID(25, 1200);
    turnPID(260, 800);
    movePID(25, 1200);
    turnPID(205, 2000);
    movePID(28, 2000);
    turnPID(350, 3000);
    turnPID(350, 3000);
    movePID(52, 4000);
    turnPID(330, 2000);
    movePID(-21, 3000);
    turnPID(356, 3000);
    movePID(20, 3000);
    delay(500);
    movePID(12, 1000);
    delay(500);
    movePID(-13, 1000);
    turnPID(135, 1000);
    movePID(-13, 1000);
    autoClamp(false);
    moveBot(8, 80);
    delay(300);
    movePID(-5, 300);
    turnPID(135, 2000);
    movePID(13.25, 3000);
    turnPID(259.5, 2000);
    turnPID(259.5, 2000);
    movePID(-52, 4000, 80, 550);
    moveBot(-12, 90);
    delay(1000);
    autoClamp(true);

    turnPID(180.25, 2000);
    autoIntake(550);
    movePID(23, 3000);
    turnPID(87.5, 2000);
    movePID(25.5, 3000);
    turnPID(156, 2000);
    movePID(28, 2000);
    turnPID(10, 3000);
    turnPID(10, 3000);
    movePID(52, 4000);
    turnPID(30, 2000);
    movePID(-21, 3000);
    turnPID(4, 3000);
    movePID(20, 1000);
    delay(500);
    movePID(14.5, 1000);
    delay(500);
    movePID(-5, 1000);
    turnPID(243, 1000);
    movePID(-15, 800);
    autoClamp(false);
    moveBot(8, 80);
    delay(300);
    movePID(-5, 800);
    turnPID(45, 2000);
    movePID(-12, 3000);
    turnPID(356, 2000);
    turnPID(356, 2000);
    movePID(-65, 5000, 80, 400);
    turnPID(60, 2000);
    movePID(-36, 1500);
    moveBot(-12, 90);
    delay(1000);
    autoClamp(true);
    delay(300);
    turnPID(75, 800);
    movePID(-65, 5000, 80, 300);
    autoClamp(false);
    delay(500);
    movePID(8, 5000, 50, 300);
    movePID(-10, 5000, 50, 200);
}

void noAuton(){}

void preRedPos(){
    // movePID(-10, 4000, 0, 300);
    // turnPID(27.25, 1000);
    // movePID(8, 4000, 0, 300);
    // turnPID(27.25, 1000);
}

void preBluePos(){
    // movePID(-10, 4000, 0, 300);
    // turnPID(332.75, 1000);
    // movePID(8, 4000, 0, 300);
    // turnPID(332.75, 1000);
}

void preRedNeg(){
    movePID(-10, 4000, 0, 300);
    turnPID(332.75, 1000);
    movePID(8, 4000, 0, 300);
    turnPID(332.75, 1000);
}

void preBlueNeg(){
    movePID(-10, 4000, 0, 300);
    turnPID(27.25, 1000);
    movePID(8, 4000, 0, 300);
    turnPID(27.25, 1000);
}

void preSkills(){
    //0.75, 1
    turnPID(60, 800);
    turnPID(60, 800);
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

        case 8:
        preSkills();
        break;

        default:
        break;
    }
}

#endif