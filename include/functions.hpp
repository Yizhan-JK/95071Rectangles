#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "setup.hpp"
#include "chassis_setup.hpp"

void moveDT(){
    double power, turn;
    
    power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 

    //Chassis.arcade(power, turn, false, 0.5);
    Chassis.curvature(power, turn, false);
}

const double intakeVelocity = 475; 

void moveIntake(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        IntakeBMotor.move_velocity(intakeVelocity);
        IntakeFMotor.move_velocity(200);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        IntakeBMotor.move_velocity(-intakeVelocity);
        IntakeFMotor.move_velocity(-200);
    }
    else {
      IntakeFMotor.move_velocity(0);
      IntakeBMotor.move_velocity(0);
    }

}

void togglePneumatics(){
    if(master.get_digital_new_press(DIGITAL_A)) {
        ClampPiston.toggle();
    }
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
            liftTarget = 2300;
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
            colorPiston.extend();
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

void autonLift(){
    int position = LiftRotation.get_position();

    while (fabs(liftTarget - position) < 150){
        position = LiftRotation.get_position();

        LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/140 + 20)), 100), -100));
        pros::delay(10);
    }
}


// void autonLift(double target){
//     double position = LiftRotation.get_position();

//     while (fabs(target - position) < 150){
//         position = LiftRotation.get_position();

//         LiftMotor.move_velocity(fmax(fmin((((target - position)/150)), 100), -100));
//         pros::delay(10);
//     }
// }

void autoIntake(double intakeVelocity){
    if(intakeVelocity > 0){
        IntakeFMotor.move_velocity(200);
    } else if(intakeVelocity < 0){
        IntakeFMotor.move_velocity(-200);
    } else{
        IntakeFMotor.move_velocity(0);
    }
    IntakeBMotor.move_velocity(intakeVelocity);
}

void autoB(double intakeVelocity){
    IntakeBMotor.move_velocity(intakeVelocity);
}

void autoF(double intakeVelocity){
    if(intakeVelocity > 0){
        IntakeFMotor.move_velocity(200);
    } else if(intakeVelocity < 0){
        IntakeFMotor.move_velocity(-200);
    } else{
        IntakeFMotor.move_velocity(0);
    }
}

void autoClamp(bool out){
    if(out){
        ClampPiston.extend();
    } else{
        ClampPiston.retract();
    }
}

void autoArm(bool out){
    if(out){
        DoinkerPiston.extend();
    } else{
        DoinkerPiston.retract();
    }
}

const double wheelCircumference = 3.25 * 3.14159265358979;

//inches to ticks
double dToT(double inches){
  double ticks = inches;
  ticks /= wheelCircumference;
  ticks *= 360;
  return ticks;
}

const double deg = 3;

void moveBot(double dist, double vel){
    double ticks = dToT(dist);

    LeftDT.move_relative(ticks, vel);
    RightDT.move_relative(ticks, vel);
}

void turnBot(double dist, double vel){

    LeftDT.move_relative(dist * deg, vel);
    RightDT.move_relative(-dist * deg, vel);
}

#endif