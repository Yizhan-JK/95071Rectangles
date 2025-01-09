#ifndef TASKS_HPP
#define TASKS_HPP

#include "setup.hpp"
#include "functions.hpp"

void liftTask(){
    
    while (true){

        if (liftAuto){
        int position = LiftRotation.get_position();

        if ((liftTarget - position) > 150)
            LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/140 + 20)), 100), -100));

        else if ((liftTarget - position) < 150)
            LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/160)), 100), -100));

        else LiftMotor.move_velocity(0);
        }

        pros::delay(10);
    }
}

int tempMax = 0;
std::vector<std::string> motorNames{"FL", "ML", "BL", "FR", "MR", "BR", "INT", "LFT"}; 

// void printTemp(){
//     while (true){
    
//         std::vector<double> motorTemps{};

//         motorTemps.push_back(LeftDT.get_temperature(0));
//         motorTemps.push_back(LeftDT.get_temperature(1));
//         motorTemps.push_back(LeftDT.get_temperature(2));
//         motorTemps.push_back(RightDT.get_temperature(0));
//         motorTemps.push_back(RightDT.get_temperature(1));
//         motorTemps.push_back(RightDT.get_temperature(2));
//         motorTemps.push_back(IntakeMotor.get_temperature());
//         motorTemps.push_back(LiftMotor.get_temperature());

//         for(int i = 0; i < motorTemps.size(); i++)
//             if(motorTemps[i] > motorTemps[tempMax]) tempMax = i;

//         master.print(0, 0, "max temp: %.1f, %s", motorTemps[tempMax], motorNames[tempMax].c_str());

//         pros::delay(55);

//     }
// }

// void printPos(){
//     while (true){
    
//         master.print(1, 0, "X: %f, Y: %f, a: %f", Chassis.getPose().x, Chassis.getPose().y, Chassis.getPose().theta);

//         pros::delay(55);

//     }
// }

// void printLift(){
//     while (true){
    
//         master.print(3, 0, "lift auto: %s", liftAuto ? "on" : "off");

//         pros::delay(55);
//     }
// }

// void printColor(){
//     while (true){
//     master.print(2, 0, "color sense: %s, %s", colorSense ? "on" : "off", colorMode == 1 ? "red" : "blue");

//     pros::delay(55);
//     }
// }

void colorTask(){
    while (true) {
        if (colorSense){
            int proximity = OpticalSensor.get_proximity();
            double hue = OpticalSensor.get_hue();
            
            if (colorMode == 1 && proximity > 250 && hue < 14){
                pros::delay(20);
                colorPiston.extend(); //reverse
                pros::delay(500);

            }else if (colorMode == 1){
                colorPiston.retract();

            }else if (colorMode == 2 && proximity > 250 && hue > 185){
                pros::delay(150);
                colorPiston.extend();

            }else if (colorMode == 2){
                colorPiston.retract();
            }
        }
        pros::delay(10);
    }
}

pros::Task lift_task(liftTask, "lift task");
pros::Task color_task(colorTask, "color task");
// pros::Task print_temp_task(printTemp, "temp task");
// pros::Task print_pos_task(printPos, "pos task");
// pros::Task print_lift_task(printLift, "lift task");
// pros::Task print_color_task(printColor, "color task");

#endif