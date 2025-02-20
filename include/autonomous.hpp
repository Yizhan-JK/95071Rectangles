#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

void testAuton(){
    double start = pros::millis();
    movePID(24, 1500);
    movePID(48, 1500);
    movePID(6, 1500);
    movePID(18, 1500);
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
    movePID(7.75, 1200, 0, 250);
    liftTarget = 16500;
    delay(900);
    movePID(-6, 800, 0, 350);
    liftTarget = 0;
    delay(100);
    turnPID(345.5, 300);
    movePID(-24, 2000, 100, 600);
    autoIntake(0);
    moveBot(-12, 90);
    delay(1000);
    autoClamp(true);
    delay(300);
    turnPID(112, 800);
    autoIntake(475);
    movePID(20.5, 2500, 100, 600);
    turnPID(96.25, 1000);
    autoIntake(-475);/////
    movePID(16, 2000, 100, 600);
    turnPID(115, 800);
    movePID(-20, 2000, 100, 600);
    autoIntake(475);
    turnPID(55, 800);
    movePID(16, 1200, 100, 600);
    delay(300);
    
    
    turnPID(308, 800);
    autoIntake(-475);

    movePID(37, 3000, 200, 600);
    turnPID(280, 800);
    movePID(37, 3000, 200, 600);


    // turnPID(280, 800);
    // autoIntake(0);
    // movePID(33, 2000, 50, 550);
    // movePID(7, 2000, 50, 300);
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
    movePID(7, 1000, 70, 350);
    liftTarget = 16500;
    delay(900);
    movePID(-3, 800, 70, 350);
    liftTarget = 0;
    turnPID(18, 800);
    movePID(-23, 2000, 80, 400);
    autoIntake(0);
    moveBot(-12, 85);
    delay(1000);
    autoClamp(true);
    delay(350);
    turnPID(234, 800);
    turnPID(234, 800);
    autoIntake(475);
    movePID(21.2, 2000, 100, 600);
    turnPID(262, 1000);
    autoIntake(-475);/////
    movePID(15, 1200, 100, 600);
    turnPID(240, 800);
    movePID(-22, 1200, 100, 600);
    autoIntake(475);
    turnPID(296, 800);
    movePID(13, 1200, 100, 600);
    delay(300);
    ///////
    turnPID(38, 800);
    autoIntake(-475);

    movePID(42, 3000, 200, 600);
    turnPID(80, 800);
    movePID(37, 3000, 200, 600);


    // turnPID(70, 800);
    // movePID(37, 2500, 70, 550);
    // movePID(8, 2000, 0, 300);
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

    delay(10000);
    movePID(-8, 2000);
}

void autonSkills(){
    autoClamp(false);
    liftTarget = 16500;
    delay(1000);
    movePID(-9.75, 1000, 0, 300);
    liftTarget = 0;
    movePID(-9.5, 800, 0, 300);
    autoClamp(true);
    delay(300);
    autoIntake(475);
    turnPID(165.3, 800);
    movePID(28, 1200);
    turnPID(256, 800);
    movePID(25, 1200);
    turnPID(208, 800);
    turnPID(208, 800);
    movePID(28, 2000);
    turnPID(346.5, 800);
    turnPID(346.5, 1000);
    movePID(44, 2000);
    turnPID(315, 1000);
    movePID(-18.5, 1500);
    turnPID(356, 3000);
    movePID(18, 1000);
    delay(500);
    movePID(12, 1000);
    delay(500);
    movePID(-8, 1000, 0, 400);
    turnPID(115, 1000);
    autoIntake(0);
    movePID(-8, 1000);
    autoClamp(false);
    moveBot(8, 80);
    delay(300);
    movePID(-5, 300);
    turnPID(135, 800);
    movePID(16, 1500, 0, 300);
    turnPID(265, 800);
    turnPID(265, 1000);
    movePID(-50.5, 4000, 80, 550);
    moveBot(-12, 90);
    delay(1000);
    autoClamp(true);

    turnPID(179, 1000);
    autoIntake(550);
    movePID(28, 1500);
    turnPID(88.5, 2000);
    movePID(25.5, 3000);
    turnPID(152, 2000);
    movePID(28, 2000);
    turnPID(9.2, 800);
    turnPID(9.2, 1000);
    movePID(42, 2500);
    turnPID(45, 1000);
    movePID(-5, 800);
    turnPID(45, 800);
    movePID(-18, 3000);
    turnPID(0, 3000);
    movePID(18, 1000);
    delay(500);
    movePID(12, 1000);
    delay(500);
    movePID(-8, 1000, 0, 400);
    turnPID(245, 1000);
    autoIntake(0);
    movePID(-13, 800);
    autoClamp(false);
    movePID(8, 800, 0, 300);
    movePID(-9, 800, 0, 350);
    turnPID(315, 2000);
    movePID(12, 3000);
    turnPID(352, 2000);
    turnPID(352, 2000);
    movePID(-82, 5000, 80, 500);
    turnPID(61, 2000);
    movePID(-37.5, 1500);
    moveBot(-12, 90);
    delay(1000);
    // autoClamp(true);
    delay(300);
    turnPID(65, 800);
    movePID(-59, 3000, 80, 550);
    // autoClamp(false);
    delay(500);
    // movePID(8, 5000, 50, 300);
    // movePID(-10, 5000, 50, 200);
    turnPID(45, 800);
    turnPID(45, 800);
    movePID(10, 1000);
    turnPID(95, 800);
    movePID(5*24 + 5, 3000, 200, 600);
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
    movePID(-10, 1000, 0, 300);
    turnPID(325, 1000);
    movePID(9, 1000, 0, 300);
    turnPID(332.75, 1000);
}

void preBlueNeg(){
    movePID(-10, 1000, 0, 300);
    turnPID(35, 1000);
    movePID(9, 1000, 0, 300);
    turnPID(27.25, 1000);
}

void preSkills(){
    //0.75, 1
    turnPID(53, 800);
    turnPID(53, 800);
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