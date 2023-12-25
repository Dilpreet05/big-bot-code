#include "main.h"

bool isForward = true;

Drive reversedChassis {
  
  {17,16,15} // left ports
  
  ,{-7,-6,-5} // right ports
  
  ,21 // imu
  
  ,3.5
  
  ,600
  
  ,1.666
};

Drive chassis (

  {-17,-15, -16} // ports for left motors

  ,{7,6, 5} // ports for right motors

  ,21

  ,3.5

  ,600

  ,1.666

);


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