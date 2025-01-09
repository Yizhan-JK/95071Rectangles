#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "setup.hpp"
#include "chassis_setup.hpp"

void moveDT(){
    double power, turn;
    
    power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 

    Chassis.arcade(power, turn, false, 0.5);
    //chassis.curvature(power, turn, false);
}

const double intakeVelocity = 450; 

void moveIntake(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) IntakeMotor.move_velocity(intakeVelocity);
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) IntakeMotor.move_velocity(-intakeVelocity);
    else IntakeMotor.move_velocity(0);

}

void togglePneumatics(){
    if(master.get_digital_new_press(DIGITAL_A)) ClampPiston.toggle();
    if(master.get_digital_new_press(DIGITAL_X)) DoinkerPiston.toggle();
}

bool liftAuto = true;
int liftMode = 0;

void moveLift(){
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && liftAuto)
        liftMode = (liftMode + 1) % 3;

    switch(liftMode){
        
        case 0:
            liftTarget = 0;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            break;
        case 1:
            liftTarget = 3400;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
        case 2:
            liftTarget = 13000;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
    }
}

void liftManuel(){
    if (!liftAuto){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) LiftMotor.move(70);
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) LiftMotor.move(-50);
        else LiftMotor.move(0);
    }
}

bool colorSense = false;
int colorMode = 1;

void colorModeSwitch(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
        pros::delay(70);
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
            colorSense = !colorSense;
            colorPiston.retract();
        }
    }
}

void liftModeSwitch(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        pros::delay(500);
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            liftAuto = !liftAuto;
            master.rumble("-");
        }
    }
}

int autonSelected = 0;

std::vector<std::string> autons {"Test", "None", "RedPositve", "RedNegative", "RedAWP",
                                    "BluePositive", "BlueNegative", "BlueAWP", "Skills"};

void autonSelect(){
    
    while(true){
        master.clear();
        pros::delay(100);

        master.print(1, 2, autons[autonSelected].c_str());
        pros::delay(100);

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
            autonSelected = (autonSelected + 1 + autons.size()) % autons.size();
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
            autonSelected = (autonSelected - 1 + autons.size()) % autons.size();
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
            pros::delay(100);
            if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
                master.clear();
                break;
            }
       }

       pros::delay(10);
    }
}

#endif