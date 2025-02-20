#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "functions.hpp"
#include "tasks.hpp"

/* params:
 *
 * bool stop
 *
 * double (pidName).minVelocity, (pidName).maxVelocity
 * bool boomerang, double lead
 * bool forwards
 *
 * int liftTarget
 * bool colorSense, int colorMode (1 = red, 2 = blue)
 *
 */

void testAuton(){
    double start = pros::millis();
    
    master.clear();
    master.print(1, 1, "Time: %.0f", (pros::millis() - start));
}

void redPositive(){
}

void redNegative(){
}

void redAWP(){
}

void bluePositive(){
}

void blueNegative(){
}

void blueAWP(){
}

void autonSkills(){
}

void noAuton(){}

void preRedPos(){
}

void preBluePos(){
}

void preRedNeg(){
}

void preBlueNeg(){
}

void preSkills(){
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