#include "main.h"

bool isForward = true;

Drive reversedChassis {
  
  {13,12,11} // left ports
  
  ,{-20,-19,-18} // right ports
  
  ,15 // imu
  
  ,3.5
  
  ,600
  
  ,1.666
};

Drive chassis (

  {-13,-12, -11} // ports for left motors

  ,{20,19, 18} // ports for right motors

  ,15

  ,3.5

  ,600

  ,1.666

);


void updateDrive(){

    if(isForward){

        chassis.tank();

    }else {
        reversedChassis.tank();
    }

}


bool updateDirection(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && isForward){
        isForward = false;
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && !isForward){
        isForward = true;
    };

    return isForward;
}