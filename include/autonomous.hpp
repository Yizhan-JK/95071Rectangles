#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "pid.hpp"
#include "tasks.hpp"

using namespace pros;

/*double start = pros::millis();

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
    master.print(2, 1, "Time: %.0f", (pros::millis() - start));*/


void testAuton(){
    double start = pros::millis();

// ////// part 1

    Chassis.setPose(0, 0, 180);

    LiftRotation.set_position(3850);
    autoClamp(false);
    pros::delay(50);
    liftTarget = 21500;
    pros::delay(800);
    Chassis.moveToPoint(0, 4, 1500, {.forwards = false, .minSpeed = 50}, false);
    liftTarget = 0;
    Chassis.moveToPose(18, 7, 270, 1500, {.forwards = false, .maxSpeed = 100}, false);
    autoClamp(true);
    delay(300);
    Chassis.setPose(18, 7, 270);
    Chassis.waitUntilDone();  
    autoIntake(500);
    delay(50); 
    // Chassis.turnToPoint(-23.5, -25, 1000, {}, false);
    // Chassis.moveToPoint(-23.5, -25, 1500, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    // Chassis.turnToPoint(-50, -80, 1000, {}, false);
    // Chassis.moveToPoint(-50, -80, 3000, {.forwards = true, .minSpeed = 60}, false);
    // Chassis.turnToPoint(-55, -80, 1000, {}, false);
    // Chassis.moveToPoint(-55, -80, 3000, {.forwards = true, .maxSpeed = 100, .minSpeed = 50}, false);
    // Chassis.moveToPose(-45, -60, 180, 1200, {.forwards = true, .minSpeed = 70}, false);
    // Chassis.moveToPose(-53, -90, 250, 1500, {.forwards = true}, false);

    delay(350);
    Chassis.waitUntilDone();
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
    LiftRotation.set_position(3850);
    autoClamp(false);
    // autoIntake(-475);
    movePID(4.7, 600, 150, 450);
    liftTarget = 21500;
    delay(850);
    movePID(-5, 500, 150, 450);
    liftTarget = 0;
    Chassis.turnToHeading(335, 800, {}, false);
    movePID(-23, 1000, 300, 600);
    // autoIntake(0);
    movePID(-9, 1000, 100, 400);
    //delay(1000);
    autoClamp(true);
    delay(300);
    autoIntake(500);
    Chassis.turnToHeading(360-229, 800, {}, false);
    movePID(12.5 , 3000, 250, 600);
    Chassis.turnToHeading(360-275, 800, {}, false);
    //autoIntake(-475);/////
    movePID(8, 1000, 250, 600);
    autoB(0);
    turnPID(360-260, 800);
    Chassis.turnToHeading(360-260, 800, {}, false);
    movePID(-5, 1000, 300, 600);
    turnPID(150, 800);
    autoIntake(500);
    movePID(-13.5, 1000, 300, 600);
    //autoIntake(475);
    turnPID(360-292, 800);
    movePID(12, 1000, 300, 600);
    delay(300);
    ///////
    // turnPID(360-38, 800);
    // autoIntake(-475);

    // movePID(42, 3000, 200, 600);
    // turnPID(360-80, 800);
    // movePID(37, 3000, 200, 600);

///////
    turnPID(275, 800);
    movePID(34, 2500, 70, 550);
    movePID(8, 2000, 0, 300);
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
    LiftRotation.set_position(3850);
    autoClamp(false);
    // autoIntake(-475);
    movePID(6.2, 600, 150, 450);
    liftTarget = 21500;
    delay(850);
    movePID(-5, 500, 150, 450);
    liftTarget = 0;
    Chassis.turnToHeading(20, 800, {}, false);
    movePID(-23, 1000, 300, 600);
    // autoIntake(0);
    movePID(-9, 1000, 100, 400);
    //delay(1000);
    autoClamp(true);
    delay(300);
    autoIntake(500);
    Chassis.turnToHeading(229, 800, {}, false);
    movePID(13.8 , 3000, 250, 600);
    Chassis.turnToHeading(273, 800, {}, false);
    autoB(0);
    //autoIntake(-475);/////
    movePID(8, 1000, 250, 600);
    turnPID(263, 800);
    Chassis.turnToHeading(263, 800, {}, false);
    movePID(-5, 1000, 300, 600);
    turnPID(210, 800);
    autoIntake(500);
    movePID(-13.5, 1000, 300, 600);
    //autoIntake(475);
    turnPID(292, 800);
    movePID(12, 1000, 300, 600);
    delay(300);
    ///////
    // turnPID(38, 800);
    // autoIntake(-475);

    // movePID(42, 3000, 200, 600);
    // turnPID(80, 800);
    // movePID(37, 3000, 200, 600);

///////
    turnPID(90, 800);
    movePID(33, 2500, 70, 550);
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
    movePID(-20, 1000, 0, 300);
    turnPID(326.9, 1000);
    Chassis.turnToHeading(326.9, 800, {}, false);
    movePID(14.5, 1000, 0, 300);
    turnPID(326.9, 1000);
    Chassis.turnToHeading(326.9, 800, {}, false);
}

void preBlueNeg(){
    movePID(-20, 1000, 0, 300);
    turnPID(35, 1000);
    Chassis.turnToHeading(35, 800, {}, false);
    movePID(14.5, 1000, 0, 300);
    turnPID(35, 1000);
    Chassis.turnToHeading(35, 800, {}, false);
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