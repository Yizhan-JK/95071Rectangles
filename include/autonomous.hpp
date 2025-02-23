#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

void testAuton(){
    double start = pros::millis();
    // turnPID(90, 1000);
    // delay(1000);
    // turnPID(180, 1000);
    // delay(1000);
    // turnPID(270, 1000);
    // delay(1000);
    // turnPID(0, 1000);
    movePID(24, 4000);
    delay(1000);
    movePID(48, 4000);
    movePID(6, 4000);
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
    movePID(7.75, 1000, 0, 250);
    liftTarget = 16500;
    delay(900);
    movePID(-6, 800, 0, 350);
    liftTarget = 0;
    delay(100);
    turnPID(346, 300);
    movePID(-24, 2000, 250, 600);
    autoIntake(0);
    movePID(-11, 2000, 100, 400);
    autoClamp(true);
    delay(300);
    turnPID(110, 800);
    autoIntake(475);
    movePID(23, 2500, 100, 600);
    turnPID(97, 1000);
    //autoIntake(-475);/////
    movePID(16.5, 2000, 100, 600);
    turnPID(115, 800);
    movePID(-20, 2000, 100, 600);
    //autoIntake(475);
    turnPID(55, 800);
    movePID(14.5, 1200, 100, 600);
    delay(300);
    /////
    
    // turnPID(308, 800);
    // autoIntake(-475);

    // movePID(37, 3000, 200, 600);
    // turnPID(280, 800);
    // movePID(37, 3000, 200, 600);

//////
    turnPID(280, 800);
    movePID(33, 2000, 50, 550);
    movePID(7, 2000, 50, 300);
    delay(2000);


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
    movePID(7, 600, 100, 450);
    liftTarget = 16500;
    delay(900);
    movePID(-6, 500, 100, 450);
    liftTarget = 0;
    turnPID(15.2, 800);
    turnPID(15.2, 800);
    movePID(-23, 1000, 150, 600);
    autoIntake(0);
    moveBot(-12, 85);
    delay(1000);
    autoClamp(true);
    delay(300);
    turnPID(238, 800);
    turnPID(238, 800);
    autoIntake(475);
    movePID(18, 1000, 150, 600);
    turnPID(263, 1000);
    //autoIntake(-475);/////
    movePID(15, 1000, 150, 600);
    turnPID(239.8, 800);
    movePID(-22, 1000, 150, 600);
    //autoIntake(475);
    turnPID(296, 800);
    movePID(12, 1000, 150, 600);
    delay(300);
    ///////
    // turnPID(38, 800);
    // autoIntake(-475);

    // movePID(42, 3000, 200, 600);
    // turnPID(80, 800);
    // movePID(37, 3000, 200, 600);

///////
    turnPID(75, 800);
    movePID(31.75, 2500, 70, 550);
    movePID(8, 2000, 0, 300);
    delay(2000);


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
    delay(900);
    liftTarget = 0;
    movePID(-13, 800, 300, 600);
    turnPID(90, 800);
    movePID(-17, 900, 250, 600);
    movePID(-10, 900, 100, 300);
    autoClamp(true);
    delay(300);
    autoIntake(475);
    turnPID(161, 800);
    movePID(25, 1500, 250, 600);
    turnPID(208, 800);
    autoIntake(-500);
    delay(80);
    autoIntake(475);
    movePID(49, 3000, 300, 600);

delay(500);
    
    //////
    turnPID(193, 1000);
    turnPID(193, 800);

    movePID(-28.25, 4000, 300, 600);
    liftTarget = 2300;
    
    turnPID(254, 1000);
    turnPID(254, 800);
    autoIntake(475);
    movePID(16, 1000, 200, 450);
    delay(1500);
    autoB(-500);
    delay(80);
    autoB(0);

    liftTarget = 15000;
    delay(900);
    liftTarget = 0;
    delay(200);
    movePID(-14, 1000, 200, 550);
    autoIntake(-475);
    turnBot(83.7, 110);
    delay(950);
    turnPID(358, 800);

    autoIntake(475);
    movePID(59, 4000, 150, 400);

    turnPID(250, 800);
    movePID(9, 1000, 250, 500);
    turnPID(155, 800);
    movePID(-11, 800, 200, 400);
    autoClamp(false);
    autoIntake(-475);
    turnPID(135, 800);
    autoIntake(0);
    movePID(7.25, 1000, 200, 600);
    turnPID(262, 800);
    turnPID(262, 1000);

    movePID(-52.5, 4000, 80, 550);
    movePID(-20, 1500, 150, 400);
    autoClamp(true);
    delay(300);
    turnPID(173, 1000);
    autoIntake(475);
    movePID(28, 1500);
    
    
    turnPID(156, 800);
////////

    autoIntake(-500);
    delay(80);
    autoIntake(475);
    movePID(53, 3000, 300, 600);

delay(500);
    
    turnPID(165, 1000);
    turnPID(165, 800);

    movePID(-36, 4000, 300, 600);
    liftTarget = 2300;
    
    turnPID(100, 1000);
    turnPID(100, 800);
    autoIntake(475);
    movePID(19, 1000, 200, 450);
    delay(1500);
    autoB(-500);
    delay(80);
    autoB(0);

    liftTarget = 15000;
    delay(900);
    liftTarget = 0;
    delay(200);
    movePID(-15.5, 1000, 200, 550);
    autoIntake(-475);
    turnBot(-83.7, 110);
    delay(950);
    turnPID(2, 800);

    autoIntake(475);
    movePID(56.5, 4000, 150, 400);

    turnPID(110, 800);
    movePID(9, 1000, 250, 500);
    turnPID(205, 800);
    movePID(-11, 800, 200, 400);
    autoClamp(false);
    autoIntake(-475);    
    turnPID(225, 800);
    movePID(10, 800, 300, 600);
    
    //////

    turnPID(175, 1000);
    turnPID(175, 800);

    movePID(72, 4000, 300, 600);
    turnPID(60, 1000);
    turnPID(60, 800);

    movePID(-48, 3000, 300, 600);
    movePID(-12, 1500, 150, 400);
    autoClamp(true);
    delay(300);
    autoIntake(475);
    turnPID(325, 800);
    movePID(25, 1000, 150, 550);
    turnPID(265, 800);
    turnPID(265, 800);
    movePID(20, 1000, 150, 550);
    turnPID(175, 800);
    movePID(33, 1000, 150, 400);
    turnPID(310, 1500);
    movePID(9, 1000);
    turnPID(45, 800);
    movePID(-8, 1000);
    autoClamp(false);
    autoIntake(-475);
    movePID(7.5, 1000);
    turnPID(105, 800);
    turnPID(105, 800);
    movePID(25, 1500, 300, 600);
    movePID(10, 1000, 200, 450);
    movePID(72, 4000, 250, 600);
    /////

//     movePID(66, 3000, 300, 600);

// delay(550);
//     liftTarget = 2300;
// delay(100);
    
//     //////
//     turnPID(225, 800);
//     movePID(-10, 1000, 300, 550);
//     autoB(0);
//     turnPID(185, 1000);
//     turnPID(185, 800);

//     movePID(-42, 3000, 300, 600);
    
//     turnPID(256, 1000);
//     turnPID(256, 800);
//     autoB(-500);
//     delay(80);
//     autoB(0);
//     movePID(20, 1000, 200, 450);

//     liftTarget = 15000;
//     delay(900);
//     liftTarget = 2300;
//     delay(650);
//     autoIntake(475);
//     delay(800);
//     autoB(-500);
//     delay(80);
//     autoB(0);

//     liftTarget = 15000;
//     delay(900);
//     liftTarget = 0;
//     delay(200);
//     movePID(-19, 1000, 200, 550);
//     autoIntake(-475);
//     turnPID(337, 1000);
//     turnPID(337, 800);

//     autoIntake(475);
//     movePID(50, 3000, 250, 550);

// delay(1500);

//     turnPID(230, 800);
//     movePID(7, 1000, 250, 500);
//     turnPID(155, 800);
//     movePID(-11, 800, 200, 400);
//     autoClamp(false);
//     autoIntake(-475);
//     turnPID(135, 800);
//     autoIntake(0);
//     movePID(10, 1000, 200, 600);
//     turnPID(265, 800);
//     turnPID(265, 1000);

// delay(1500);

//     movePID(-50.5, 4000, 80, 550);

// delay(1500);

//     movePID(-12, 800, 150, 400);
//     autoClamp(true);
//     delay(300);
//     turnPID(179, 1000);
//     autoIntake(475);
//     movePID(26, 1500);
//     turnPID(152.5, 800);

// delay(1500); 

//     autoIntake(-500);
//     delay(80);
//     autoIntake(475);
//     movePID(63, 5000, 300, 600);
//     autoB(0);

// delay(1500);

//     //////
//     movePID(-26, 5000, 300, 600);
//     turnPID(180, 800, 0, 350);
//     turnPID(180, 800);
//     movePID(-24, 5000, 300, 600);
//     liftTarget = 2300;
//     autoB(475);
//     turnPID(90, 800);
//     turnPID(90, 800);
//     autoB(-500);
//     delay(80);
//     autoB(0);
//     movePID(26, 1000, 200, 450);

// delay(1500);

//     liftTarget = 15000;
//     delay(900);
//     autoIntake(475);
//     liftTarget = 2300;
//     delay(800);
//     autoB(-500);
//     delay(80);
//     autoB(0);

// delay(1500);

//     liftTarget = 15000;
//     delay(900);
//     liftTarget = 0;
//     delay(200);
//     movePID(-13, 800, 200, 550);
//     autoIntake(-475);
//     turnPID(0, 800);
//     turnPID(0, 800);

// delay(1500);

//     autoIntake(475);
//     movePID(50, 3000, 250, 550);

// delay(1500);

//     turnPID(135, 800);
//     movePID(18, 1000, 250, 500);
//     turnPID(205, 800);
//     movePID(-12, 800, 200, 400);
//     autoClamp(false);
//     turnPID(225, 800);    

//     /////


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
    liftTarget = 2300;
    liftMode = 1;
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