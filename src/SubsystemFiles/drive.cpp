#include "main.h"

bool isForward = true;

Drive reversedChassis {
  
  {-20,-19,-18} // left ports
  
  ,{13,12,11} // right ports
  
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

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1){
        isForward = !isForward;
    }
    // else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && !isForward){
    //     isForward = true;
    // };

    return isForward;
}