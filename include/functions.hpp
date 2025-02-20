#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "setup.hpp"

void moveDT(){
    double power, turn;
    
    power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 
}

const double intakeVelocity = 450; 

void moveIntake(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        IntakeBMotor.move_velocity(intakeVelocity);
        IntakeFMotor.move_velocity(200);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        IntakeBMotor.move_velocity(-intakeVelocity);
        IntakeFMotor.move_velocity(-200);
    }
    else {IntakeBMotor.move_velocity(0);
      IntakeFMotor.move_velocity(0);
    };

}

void togglePneumatics(){
    if(master.get_digital_new_press(DIGITAL_A)) ClampPiston.toggle();
    if(master.get_digital_new_press(DIGITAL_DOWN)) DoinkerPiston.toggle();
}

bool liftAuto = true;
int liftMode = 0;

void moveLift(){
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && liftAuto)
        liftMode = (liftMode + 1) % 3;
    else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && liftAuto)
        liftMode = 1;

    switch(liftMode){
        
        case 0:
            liftTarget = 0;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            break;
        case 1:
            liftTarget = 2700;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
        case 2:
            liftTarget = 15000;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
    }
}

void liftManuel(){
    if (!liftAuto){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) LiftMotor.move(70);
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) LiftMotor.move(-70);
        else LiftMotor.move(0);
    }
}

bool colorSense = false;
int colorMode = 1;

void colorModeSwitch(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
        pros::delay(300);
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
            colorSense = !colorSense;
            ColorPiston.extend();
            master.rumble(".");
        }
    }
}

void liftModeSwitch(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
        pros::delay(400);
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
            liftAuto = !liftAuto;
            master.rumble("-");
        }
    }
}

#endif