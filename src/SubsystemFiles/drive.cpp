#include "main.h"

bool isForward = true;

void updateDrive(){

    if(updateDirection()){

        chassis.tank();

    }else {
        reversedChassis.tank();
    }

}


bool updateDirection(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) != 1 && isForward){
        isForward = true;
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && !isForward){
        isForward = false;
    };

    return isForward;
}