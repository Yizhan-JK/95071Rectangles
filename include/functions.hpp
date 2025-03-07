#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "setup.hpp"
#include "chassis_setup.hpp"

double leftVelocity = 0;
double rightVelocity = 0;
double powerVelocity = 0;
double turnVelocity = 0;
bool holdDrive = false;
// https://www.desmos.com/calculator/8dizsra4fi
// double driveCurve(double input, double k1 = 1, double k2 = 1) {
// 	if (fabs(input < 3)) return 0;
// 	else if (fabs(input < 80)) return input/k1;
// 	else return (pow(M_E, -k2/10) + pow(M_E, (fabs(input)-127)/5) * (1-pow(M_E, -k2/10))) * input;
// }

void moveDT(){
    double power1 = master.get_analog(ANALOG_LEFT_Y);
	double turn2 = master.get_analog(ANALOG_RIGHT_X) * 0.925;

    if (fabs(power1) < 5) power1 = 0;
	if (fabs(turn2) < 20) turn2 = 0;
	
    double p = 1;
	double t = 7;
	power1 = (pow(M_E, -p/10) + pow(M_E, (fabs(power1)-127)/10) * (1-pow(M_E, -p/10))) * power1;
	// turn2 = (pow(M_E, -t/10) + pow(M_E, (fabs(turn2)-127)/10) * (1-pow(M_E, -t/10))) * turn2; 

	// double turn = turn2;
	// double power = power1;
    
    // double power = driveCurve(power1, 4, 7);
	// double turn = driveCurve(turn2, 4, 7);

    // leftVelocity = (1 * power1 + 0.75 * turn2) * 600 / 127;
	// rightVelocity = (1 * power1 - 0.75 * turn2) * 600 / 127;

    LeftDT.move_velocity(leftVelocity);
	RightDT.move_velocity(rightVelocity);

    // //Chassis.arcade(power, turn, false, 0.5);
    // Chassis.curvature(power, turn, false);
}

const double intakeVelocity = 500; 

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

bool liftAuto = false;
int liftMode = 0;

void moveLift(){
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) // && liftAuto
        liftMode = (liftMode + 1) % 3;
    else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) // && liftAuto
        liftMode = 1;

    switch(liftMode){
        
        case 0:
            liftTarget = 0;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            break;
        case 1:
            liftTarget = 3700;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
        case 2:
            liftTarget = 16500;
            LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            break;
    }
}

void liftManuel(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        LiftMotor.move(100);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        LiftMotor.move(-100);
    }
    else {
        LiftMotor.move(0);
    }

}

bool colorSense = false;
int colorMode = 1;

void colorModeSwitch(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
        pros::delay(300);
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
            colorSense = !colorSense;
            colorPiston.retract();
            master.rumble(".");
        }
    }
}


// void liftModeSwitch(){
//     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
//         pros::delay(400);
//         if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
//             liftAuto = !liftAuto;
//             master.rumble("-");
//         }
//     }
// }

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
        ClampPiston.retract();
    } else{
        ClampPiston.extend();
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