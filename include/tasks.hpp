#ifndef TASKS_HPP
#define TASKS_HPP

#include "setup.hpp"
#include "functions.hpp"
#include "pid.hpp"

#include <math.h>

#define RAD_DEG 180/M_PI
#define CIRCUMFERENCE 2 * 2.125 * M_PI

// double lkP = 1.5, lkI = 0.01, lkD = 3;

// double liftError;
// double liftLastError = 0;

// double liftIntegral = 0;
// double liftDerivative = 0;

// double liftMinVelocity = 0;
// double liftMaxVelocity = 200;

// double liftIntLimit = 200;

// double liftExit = 0.2;

// bool liftPidReset = false;

// double liftPid(double in){

//     if (liftPidReset){
//         liftIntegral = 0;
//         liftDerivative = 0;
//         liftLastError = 0;
//         liftPidReset = false;
//     }

//     liftError = in;

//     if (fabs(liftIntegral) < liftIntLimit) liftIntegral += liftError;
//     else liftIntegral = sign(liftIntegral) * liftIntLimit; 

//     if (fabs(liftError) < 1) liftIntegral = 0;

//     liftDerivative = liftError - liftLastError;
//     liftLastError = liftError;

//     double out = lkP * liftError + lkI * liftIntegral + lkD * liftDerivative;

//     if (fabs(out) > liftMaxVelocity) out = sign(out) * liftMaxVelocity;
//     if (fabs(out) < liftMinVelocity) out = sign(out) * liftMinVelocity;

//     if (fabs(out) < liftExit) out = 0;

//     return out;
// }

// void liftTask(){

//     while (true){
//     if (liftAuto){
//         int position = LiftRotation.get_position();

//         if (fabs(liftTarget - position) < 250)
//             LiftMotor.move_voltage(liftPid((liftTarget - position)/100) * 20);
//         else{
//             LiftMotor.move_velocity(0);
//             liftPidReset = true;
//         }
//     }
//         pros::delay(10);
//     }
// }

bool opControl = false;

void liftTask(){

    while (true){
        if (liftAuto){
        int position = LiftRotation.get_position();

        if ((liftTarget - position) > 250)
            LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/32)), 200), -200));

        else if ((liftTarget - position) < -250)
            LiftMotor.move_velocity(fmax(fmin(((liftTarget - position)/20), 200), -200));

        else{
            LiftMotor.move_velocity(0);
            if (opControl) liftAuto = false;}
        }else{

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) LiftMotor.move_velocity(150);
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) LiftMotor.move_velocity(-150);
        else LiftMotor.move(0);
        }
        pros::delay(10);
    }

    // while (true) {
    // if ((liftTarget - LiftRotation.get_position()) < -250) LiftMotor.move_velocity(200 * (liftTarget - LiftRotation.get_position()) / 36000*2);
    // else if ((liftTarget - LiftRotation.get_position()) > 250) LiftMotor.move_velocity(100 * (liftTarget - LiftRotation.get_position()) / 36000*2);
    // else LiftMotor.move_velocity(0);

	// 	pros::delay(10);
    
}

int tempMax = 0;
std::vector<std::string> motorNames{"FL", "ML", "BL", "FR", "MR", "BR", "INTF", "INTB", "LFT"}; 

void printTemp(){
        std::vector<double> motorTemps{};

        motorTemps.push_back(LeftDT.get_temperature(0));
        motorTemps.push_back(LeftDT.get_temperature(1));
        motorTemps.push_back(LeftDT.get_temperature(2));
        motorTemps.push_back(RightDT.get_temperature(0));
        motorTemps.push_back(RightDT.get_temperature(1));
        motorTemps.push_back(RightDT.get_temperature(2));
        motorTemps.push_back(IntakeFMotor.get_temperature());
        motorTemps.push_back(IntakeBMotor.get_temperature());
        motorTemps.push_back(LiftMotor.get_temperature());

        for(int i = 0; i < motorTemps.size(); i++)
            if(motorTemps[i] > motorTemps[tempMax]) tempMax = i;

        master.clear_line(0);

        std::string s = motorNames[tempMax];
        master.print(0, 0, "max temp: %.1f, %s", motorTemps[tempMax], motorNames[tempMax]);

}

void printPos0(){
    master.clear_line(0);
    master.print(0, 0, "X: %f", Chassis.getPose().x);
}

void printPos1(){
    master.clear_line(1);
    master.print(1, 0, "Y: %f", Chassis.getPose().y);
}

void printPos2(){
    master.clear_line(2);
    master.print(2, 0, "a: %f", Chassis.getPose().theta);
}

void printBrain(){
    while(true){
    pros::lcd::print(0, "X: %f", Chassis.getPose().x);
    pros::lcd::print(1, "Y: %f", Chassis.getPose().y);
    pros::lcd::print(2, "a: %f", Chassis.getPose().theta);

    pros::delay(100);
    }
}

void printLift(){
    master.clear_line(2);
    master.print(2, 0, "lift auto: %s", liftAuto ? "on" : "off");
}

void printColor(){
    master.clear_line(1);
    master.print(1, 0, "color sense: %s, %s", colorSense ? "on" : "off", colorMode == 1 ? "red" : "blue");
}



// void printAuton(){
//     int printCount = 0;
//     while (true){

//         switch(printCount){
//             case 0:
//                 printPos0();
//                 break;
//             case 1:
//                 printPos1();
//                 break;
//             case 2:
//                 printPos2();
//                 break;
//         }

//         pros::delay(150);
        
//         printCount = (printCount + 1) % 3;
//     }
// }



// void printDrive(){
//     int printCountDrive = 0;
//     while (true){
//         switch (printCountDrive){
//             case 0:
//                 printTemp();
//                 break;
//             case 1:
//                 printColor();
//                 // printPos();
//                 break;
//             case 2:
//                 printLift();
//                 break;
//         }

//         pros::delay(100);

//         printCountDrive = (printCountDrive + 1) % 3;
//     }
// }

void colorTask(){
    while (true) {
        if (colorSense){
            int proximity = OpticalSensor.get_proximity();
            double hue = OpticalSensor.get_hue();
            
            if (colorMode == 1 && (proximity > 250 && hue > 185)){
                pros::delay(170);
                colorPiston.extend();
                pros::delay(800);

            }else if (colorMode == 1){
                colorPiston.retract();

            }else if (colorMode == 2 && (proximity > 250 && hue < 17)){
                pros::delay(170);
                colorPiston.extend(); 
                pros::delay(800);

            }else if (colorMode == 2){
                colorPiston.retract();
            }
        }
        pros::delay(10);
    }
}

pros::Task lift_task(liftTask, "lift task");
pros::Task color_task(colorTask, "color task");

// pros::Task print_task_auton(printAuton, "auton task");
// pros::Task print_task_drive(printDrive, "drive task");

pros::Task print_task_brain(printBrain, "brain task");

#endif