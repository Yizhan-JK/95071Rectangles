#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

    // LiftRotation.set_position(3850);
    // autoClamp(false);
    // pros::delay(50);
    // liftTarget = 21500;
    // pros::delay(800);
    // Chassis.moveToPoint(0, -4, 1500, {.forwards = false, .minSpeed = 50}, false);
    // // Chassis.turnToHeading(90, 800);
    // liftTarget = 0;
    // // Chassis.moveToPose(-12, -7, 90, 1500, {.forwards = false, .maxSpeed = 100});
    // Chassis.moveToPose(-18, -7, 90, 1500, {.forwards = false, .maxSpeed = 100}, false);
    // autoClamp(true);
    // pros::delay(300);
    // Chassis.waitUntilDone();
    // // Chassis.setPose(18.4,7, 90);  
    // autoIntake(500);
    // pros::delay(50);
    // pros::delay(2000); 
    // Chassis.turnToPoint(-26, 24, -1500, {.maxSpeed = 90}, false);
    // Chassis.waitUntilDone();
    // Chassis.moveToPoint(-26, -24, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    // // Chassis.turnToPoint(-50, -90, 1000, {}, false);
    // // Chassis.moveToPoint(-50, -93, 3000, {.forwards = true, .minSpeed = 60}, false);
    // Chassis.moveToPose(-45, -60, 180, 1200, {.forwards = true, .minSpeed = 70}, false);
    // Chassis.moveToPose(-53, -90, 250, 1500, {.forwards = true}, false);

void testAuton(){
    double start = pros::millis();
    turnPID(90, 1000);
    delay(1000);
    turnPID(180, 1000);
    delay(1000);
    turnPID(270, 1000);
    delay(1000);
    turnPID(0, 1000);

// ////// part 1

//     Chassis.setPose(0, 0, 180);

//     LiftRotation.set_position(3850);
//     autoClamp(false);
//     pros::delay(50);
//     liftTarget = 21500;
//     pros::delay(800);
//     Chassis.moveToPoint(0, 4, 1500, {.forwards = false, .minSpeed = 50}, false);
//     liftTarget = 0;
//     Chassis.moveToPose(18, 7, 270, 1500, {.forwards = false, .maxSpeed = 100}, false);
//     autoClamp(true);
//     delay(300);
//     Chassis.setPose(18, 7, 270);
//     Chassis.waitUntilDone();  
//     autoIntake(500);
//     delay(50); 
//     // Chassis.turnToPoint(-23.5, -25, 1000, {}, false);
//     // Chassis.moveToPoint(-23.5, -25, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     // Chassis.turnToPoint(-50, -80, 1000, {}, false);
//     // Chassis.moveToPoint(-50, -80, 3000, {.forwards = true, .minSpeed = 60}, false);
//     // Chassis.turnToPoint(-55, -80, 1000, {}, false);
//     // Chassis.moveToPoint(-55, -80, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     // Chassis.moveToPose(-45, -60, 180, 1200, {.forwards = true, .minSpeed = 70}, false);
//     // Chassis.moveToPose(-53, -90, 250, 1500, {.forwards = true}, false);

//     delay(350);
//     Chassis.waitUntilDone();
//////////////////////////////////////////////////////////////////////////////////
    // autoB(0);
    // liftTarget = 3700;
    // Chassis.moveToPose(-28, -57.75, 270, 3000, {.forwards = false, .minSpeed = 50}, false);
    // Chassis.turnToHeading(270, 800);
    // Chassis.waitUntilDone();
    // autoB(500);


//     Chassis.moveToPose(-40, -57.75, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
//     autoB(0);
//     liftTarget = 16500;
//     delay(650);
//     liftTarget = 3700;
//     delay(500);
//     autoB(500);
//     delay(500);
//     autoB(0);
//     liftTarget = 16500;
//     delay(650);
//     Chassis.moveToPose(-35, -57.75, 270, 3000, {.forwards = false, .minSpeed = 50}, false);
//     liftTarget = 0;
//     Chassis.turnToHeading(0, 800);
//     autoB(500);
//     Chassis.moveToPose(-35, -33, 0, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.moveToPose(-35, 5, 0, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     Chassis.turnToHeading(226, 800);
//     Chassis.moveToPose(-42, -7, 226, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     delay(300);
//     Chassis.turnToHeading(163, 800);
//     Chassis.moveToPose(-44, 5.5, 163, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
//     autoClamp(false);
//     autoIntake(-500);

//     Chassis.moveToPose(5, -7, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
//     Chassis.turnToHeading(270, 800);
//     Chassis.moveToPose(18, -7, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
    
// ///////// part 2


//     autoClamp(true);
//     delay(300);
//     Chassis.waitUntilDone();  
//     autoIntake(500);
//     // delay(50); 
//     Chassis.turnToPoint(24, -25.5, 1000, {}, false);
//     Chassis.moveToPoint(24, -25.5, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.turnToPoint(50.5, -80, 1000, {}, false);
//     Chassis.moveToPoint(50.5, -80, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     delay(350);
//     Chassis.waitUntilDone();
//     autoB(0);
//     liftTarget = 3700;
//     Chassis.moveToPose(28.5, -57.75, 90, 3000, {.forwards = false, .minSpeed = 50}, false);
//     Chassis.turnToHeading(90, 800);
//     Chassis.waitUntilDone();
//     autoB(500);

//     Chassis.moveToPose(40.5, -57.75, 90, 3000, {.forwards = true, .minSpeed = 50}, false);
//     autoB(0);
//     liftTarget = 16500;
//     delay(650);
//     liftTarget = 3700;
//     delay(500);
//     autoB(500);
//     delay(500);
//     autoB(0);
//     liftTarget = 16500;
//     delay(650);
//     Chassis.moveToPose(35.5, -57.75, 90, 3000, {.forwards = false, .minSpeed = 50}, false);
//     liftTarget = 0;
//     Chassis.turnToHeading(0, 800);
//     autoB(500);
//     Chassis.moveToPose(35.5, -33, 0, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.moveToPose(35.5, 5, 0, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     Chassis.turnToHeading(135, 800);
//     Chassis.moveToPose(42.5, -7, 135, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     delay(300);
//     Chassis.turnToHeading(195, 800);
//     Chassis.moveToPose(44.5, 5.5, 195, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
//     autoClamp(false);
//     autoIntake(-500);
    
// //////// part 3

//     Chassis.moveToPose(-23.5, -70, 225, 3000, {.forwards = true, .maxSpeed = 70, .minSpeed = 50}, false);
//     Chassis.waitUntil(77);
//     autoIntake(500);
//     Chassis.waitUntil(85);
//     autoB(0);
//     liftTarget = 3700;
//     Chassis.moveToPose(-15, -83, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
//     Chassis.turnToHeading(270, 800);
//     autoIntake(500);
//     Chassis.moveToPose(-6, -83, 270, 3000, {.forwards = false, .maxSpeed = 100, .minSpeed = 50}, false);
//     autoClamp(true);
//     delay(300);
//     autoB(0);
//     Chassis.moveToPose(1, -86, 180, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.turnToHeading(180, 800);
//     liftTarget = 21500;
//     delay(850);
//     Chassis.moveToPoint(1, -82, 1500, {.forwards = false, .minSpeed = 50}, false);
//     liftTarget = 0;
//     liftMode = 0;
//     // Chassis.turnToHeading(270, 800);
//     Chassis.moveToPose(-35, -82, 270, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     Chassis.waitUntil(10);
//     autoIntake(500);
//     Chassis.moveToPose(-35, -85.5, 180, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
//     Chassis.turnToHeading(73, 800);
//     Chassis.moveToPose(0, -78, 73, 3000, {.forwards = true, .minSpeed = 50}, false);
//     Chassis.turnToHeading(55, 800);
//     Chassis.moveToPose(24, -70, 55, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.moveToPose(35.5, -80, 135, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.moveToPose(35.5, -83, 180, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
//     Chassis.turnToHeading(280, 800);
//     Chassis.moveToPose(37, -85, 280, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
//     autoClamp(false);
//     autoIntake(-500);

// //////// part 4

//     Chassis.moveToPose(24, -78, 255, 3000, {.forwards = true, .minSpeed = 50}, false);
//     autoIntake(0);
//     Chassis.moveToPose(-24, -83, 255, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
//     Chassis.turnToHeading(275, 800);
//     Chassis.moveToPose(-38, -86, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
//     Chassis.moveToPose(-31, -82, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
//     Chassis.moveToPose(-39, -87, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
//     master.print(2, 1, "Time: %.0f", (pros::millis() - start));
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
    delay(2000);
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
    Chassis.turnToHeading(110, 800);
    //turnPID(110, 800);
    autoIntake(475);
    movePID(23, 2500, 100, 600);
    Chassis.turnToHeading(97, 800);
    // turnPID(97, 1000);
    //autoIntake(-475);/////
    movePID(16.5, 2000, 100, 600);
    Chassis.turnToHeading(115, 800);
    //turnPID(115, 800);
    movePID(-20, 2000, 100, 600);
    //autoIntake(475);
    Chassis.turnToHeading(55, 800);
    //turnPID(55, 800);
    movePID(14.5, 1200, 100, 600);
    delay(300);
    /////
    
    // turnPID(308, 800);
    // autoIntake(-475);

    // movePID(37, 3000, 200, 600);
    // turnPID(280, 800);
    // movePID(37, 3000, 200, 600);

//////
    Chassis.turnToHeading(280, 800);
    // turnPID(280, 800);
    movePID(33, 2000, 50, 550);
    movePID(7, 2000, 50, 300);
    delay(2000);

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
    Chassis.turnToHeading(15.2, 800);
    // turnPID(15.2, 800);
    // turnPID(15.2, 800);
    movePID(-23, 1000, 150, 600);
    autoIntake(0);
    moveBot(-12, 85);
    delay(1000);
    autoClamp(true);
    delay(300);
    Chassis.turnToHeading(238, 800);
    // turnPID(238, 800);
    // turnPID(238, 800);
    autoIntake(475);
    movePID(18, 1000, 150, 600);
    Chassis.turnToHeading(263, 800);
    // turnPID(263, 1000);
    //autoIntake(-475);/////
    movePID(15, 1000, 150, 600);
    Chassis.turnToHeading(239.8, 800);
    // turnPID(239.8, 800);
    movePID(-22, 1000, 150, 600);
    //autoIntake(475);
    Chassis.turnToHeading(296, 800);
    // turnPID(296, 800);
    movePID(12, 1000, 150, 600);
    delay(300);
    ///////
    // turnPID(38, 800);
    // autoIntake(-475);

    // movePID(42, 3000, 200, 600);
    // turnPID(80, 800);
    // movePID(37, 3000, 200, 600);

///////
    Chassis.turnToHeading(75, 800);
    // turnPID(75, 800);
    movePID(31.75, 2500, 70, 550);
    movePID(8, 2000, 0, 300);
    delay(2000);
    ///////////

    master.print(2, 1, "Time: %.0f", (pros::millis() - start));
}

void blueAWP(){

    delay(10000);
    movePID(-8, 2000);
}

void autonSkills(){
    ////// part 1

    LiftRotation.set_position(3850);
    autoClamp(false);
    delay(50);
    liftTarget = 21500;
    delay(850);
    Chassis.moveToPoint(0, -4, 1500, {.forwards = false, .minSpeed = 50}, false);
    // Chassis.turnToHeading(90, 800);
    liftTarget = 0;
    liftMode = 0;
    Chassis.moveToPose(-18, -7, 90, 1500, {.forwards = false, .maxSpeed = 100}, false);
    autoClamp(true);
    delay(300);
    Chassis.waitUntilDone();  
    autoIntake(500);
    // delay(50); 
    Chassis.turnToPoint(-23.5, -25, 1000, {}, false);
    Chassis.moveToPoint(-23.5, -25, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.turnToPoint(-50, -80, 1000, {}, false);
    Chassis.moveToPoint(-50, -80, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    delay(350);
    Chassis.waitUntilDone();
    autoB(0);
    liftTarget = 3700;
    Chassis.moveToPose(-28, -57.75, 270, 3000, {.forwards = false, .minSpeed = 50}, false);
    Chassis.turnToHeading(270, 800);
    Chassis.waitUntilDone();
    autoB(500);


    Chassis.moveToPose(-40, -57.75, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
    autoB(0);
    liftTarget = 16500;
    delay(650);
    liftTarget = 3700;
    delay(500);
    autoB(500);
    delay(500);
    autoB(0);
    liftTarget = 16500;
    delay(650);
    Chassis.moveToPose(-35, -57.75, 270, 3000, {.forwards = false, .minSpeed = 50}, false);
    liftTarget = 0;
    Chassis.turnToHeading(0, 800);
    autoB(500);
    Chassis.moveToPose(-35, -33, 0, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.moveToPose(-35, 5, 0, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    Chassis.turnToHeading(226, 800);
    Chassis.moveToPose(-42, -7, 226, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    delay(300);
    Chassis.turnToHeading(163, 800);
    Chassis.moveToPose(-44, 5.5, 163, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
    autoClamp(false);
    autoIntake(-500);

    Chassis.moveToPose(5, -7, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
    Chassis.turnToHeading(270, 800);
    Chassis.moveToPose(18, -7, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
    
///////// part 2


    autoClamp(true);
    delay(300);
    Chassis.waitUntilDone();  
    autoIntake(500);
    // delay(50); 
    Chassis.turnToPoint(24, -25.5, 1000, {}, false);
    Chassis.moveToPoint(24, -25.5, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.turnToPoint(50.5, -80, 1000, {}, false);
    Chassis.moveToPoint(50.5, -80, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    delay(350);
    Chassis.waitUntilDone();
    autoB(0);
    liftTarget = 3700;
    Chassis.moveToPose(28.5, -57.75, 90, 3000, {.forwards = false, .minSpeed = 50}, false);
    Chassis.turnToHeading(90, 800);
    Chassis.waitUntilDone();
    autoB(500);

    Chassis.moveToPose(40.5, -57.75, 90, 3000, {.forwards = true, .minSpeed = 50}, false);
    autoB(0);
    liftTarget = 16500;
    delay(650);
    liftTarget = 3700;
    delay(500);
    autoB(500);
    delay(500);
    autoB(0);
    liftTarget = 16500;
    delay(650);
    Chassis.moveToPose(35.5, -57.75, 90, 3000, {.forwards = false, .minSpeed = 50}, false);
    liftTarget = 0;
    Chassis.turnToHeading(0, 800);
    autoB(500);
    Chassis.moveToPose(35.5, -33, 0, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.moveToPose(35.5, 5, 0, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    Chassis.turnToHeading(135, 800);
    Chassis.moveToPose(42.5, -7, 135, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    delay(300);
    Chassis.turnToHeading(195, 800);
    Chassis.moveToPose(44.5, 5.5, 195, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
    autoClamp(false);
    autoIntake(-500);
    
//////// part 3

    Chassis.moveToPose(-23.5, -70, 225, 3000, {.forwards = true, .maxSpeed = 70, .minSpeed = 50}, false);
    Chassis.waitUntil(77);
    autoIntake(500);
    Chassis.waitUntil(85);
    autoB(0);
    liftTarget = 3700;
    Chassis.moveToPose(-15, -83, 270, 3000, {.forwards = true, .minSpeed = 50}, false);
    Chassis.turnToHeading(270, 800);
    autoIntake(500);
    Chassis.moveToPose(-6, -83, 270, 3000, {.forwards = false, .maxSpeed = 100, .minSpeed = 50}, false);
    autoClamp(true);
    delay(300);
    autoB(0);
    Chassis.moveToPose(1, -86, 180, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.turnToHeading(180, 800);
    liftTarget = 21500;
    delay(850);
    Chassis.moveToPoint(1, -82, 1500, {.forwards = false, .minSpeed = 50}, false);
    liftTarget = 0;
    liftMode = 0;
    // Chassis.turnToHeading(270, 800);
    Chassis.moveToPose(-35, -82, 270, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    Chassis.waitUntil(10);
    autoIntake(500);
    Chassis.moveToPose(-35, -85.5, 180, 3000, {.forwards = true, .maxSpeed = 95, .minSpeed = 50}, false);
    Chassis.turnToHeading(73, 800);
    Chassis.moveToPose(0, -78, 73, 3000, {.forwards = true, .minSpeed = 50}, false);
    Chassis.turnToHeading(55, 800);
    Chassis.moveToPose(24, -70, 55, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.moveToPose(35.5, -80, 135, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.moveToPose(35.5, -83, 180, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    Chassis.turnToHeading(280, 800);
    Chassis.moveToPose(37, -85, 280, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50}, false);
    autoClamp(false);
    autoIntake(-500);

//////// part 4

    Chassis.moveToPose(24, -78, 255, 3000, {.forwards = true, .minSpeed = 50}, false);
    autoIntake(0);
    Chassis.moveToPose(-24, -83, 255, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
    Chassis.turnToHeading(275, 800);
    Chassis.moveToPose(-38, -86, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
    Chassis.moveToPose(-31, -82, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
    Chassis.moveToPose(-39, -87, 275, 3000, {.forwards = true, .maxSpeed = 85, .minSpeed = 50}, false);
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
    // //0.75, 1
    // liftTarget = 3800;
    // liftMode = 1;
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