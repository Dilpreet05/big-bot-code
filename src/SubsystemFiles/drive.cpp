#include "main.h"

bool isArcade = false;
bool isMotorAvailable = true;

Drive chassis {
  
  {-20,-19,-18} // left ports

  ,{13,12,11}
  
  ,15 // imu
  
  ,3.5
  
  ,600
  
  ,1.666
};




void updateDrive(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1){
      isArcade = !isArcade;
    }
    if( isMotorAvailable == true){
        if(!isArcade){
             chassis.tank();
    }   else{
             chassis.arcade_standard(ez::SPLIT);
    }
    }
    
    pros::delay(50);

}
