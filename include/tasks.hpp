#ifndef TASKS_HPP
#define TASKS_HPP

#include "setup.hpp"
#include "functions.hpp"

void liftTask(){
    
    while (true){

        if (liftAuto){
        int position = LiftRotation.get_position();

        if ((liftTarget - position) > 150)
            LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/140 + 20)), 200), -200));

        else if ((liftTarget - position) < 150)
            LiftMotor.move_velocity(fmax(fmin((((liftTarget - position)/160)), 200), -200));

        else LiftMotor.move_velocity(0);
        }

        pros::delay(10);
    }
}

int tempMax = 0;
std::vector<std::string> motorNames{"FL", "ML", "BL", "FR", "MR", "BR", "INT", "LFT"}; 

void printTemp(){
        std::vector<double> motorTemps{};

        motorTemps.push_back(LeftDT.get_temperature(0));
        motorTemps.push_back(LeftDT.get_temperature(1));
        motorTemps.push_back(LeftDT.get_temperature(2));
        motorTemps.push_back(RightDT.get_temperature(0));
        motorTemps.push_back(RightDT.get_temperature(1));
        motorTemps.push_back(RightDT.get_temperature(2));
        motorTemps.push_back(IntakeFMotor.get_temperature());
        motorTemps.push_back(LiftMotor.get_temperature());

        for(int i = 0; i < motorTemps.size(); i++)
            if(motorTemps[i] > motorTemps[tempMax]) tempMax = i;

        master.clear_line(0);

        std::string s = motorNames[tempMax];
        master.print(0, 0, "max temp: %.1f, %s", motorTemps[tempMax], motorNames[tempMax]);

}

void printPos(){
    master.clear_line(1);
    // master.print();
}

void printLift(){
    master.clear_line(2);
    master.print(2, 0, "lift auto: %s", liftAuto ? "on" : "off");
}

void printColor(){
    master.clear_line(1);
    master.print(1, 0, "color sense: %s, %s", colorSense ? "on" : "off", colorMode == 1 ? "red" : "blue");
}



void printAuton(){
    int printCount = 0;
    while (true){

        switch(printCount){
            case 0:
                printTemp();
                break;
            case 1:
                printPos();
                break;
        }

        pros::delay(150);
        
        printCount = (printCount + 1) % 2;
    }
}



void printDrive(){
    int printCountDrive = 0;
    while (true){
        switch (printCountDrive){
            case 0:
                printTemp();
                break;
            case 1:
                printColor();
                // printPos();
                break;
            case 2:
                printLift();
                break;
        }

        pros::delay(100);

        printCountDrive = (printCountDrive + 1) % 3;
    }
}

void colorTask(){
    while (true) {
        if (colorSense){
            int proximity = OpticalSensor.get_proximity();
            double hue = OpticalSensor.get_hue();
            
            if (colorMode == 1 && (proximity > 250 && hue > 185)){
                pros::delay(50);
                colorPiston.retract(); //reverse
                pros::delay(800);

            }else if (colorMode == 1){
                colorPiston.extend();

            }else if (colorMode == 2 && (proximity > 250 && hue < 14)){
                pros::delay(50);
                colorPiston.retract(); 
                pros::delay(800);

            }else if (colorMode == 2){
                colorPiston.extend();
            }
        }
        pros::delay(10);
    }
}

pros::Task lift_task(liftTask, "lift task");
pros::Task color_task(colorTask, "color task");

pros::Task print_task_auton(printAuton, "auton task");
pros::Task print_task_drive(printDrive, "drive task");

#endif