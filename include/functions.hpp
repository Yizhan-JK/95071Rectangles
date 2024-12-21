#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "setup.hpp"

int liftMode = 0;

void moveLift(){
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
        liftMode = (liftMode + 1) % 3;

    switch(liftMode){
        
        case 0:
            liftTarget = 33150;
            break;
        case 1:
            liftTarget = 11800;
            break;
        case 2:
            liftTarget = 35700;
            break;

        default:
            break;
    }
}

#endif