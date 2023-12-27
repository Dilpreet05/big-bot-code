#include "main.h"

pros::Motor flywheel1(8, MOTOR_GEARSET_06,false);
pros::Motor flywheel2(9,MOTOR_GEARSET_06,false);
bool contBool = false;
bool brakeBool = false;

void setFlywheelBrake(){
        flywheel1.set_brake_mode(MOTOR_BRAKE_COAST);
        flywheel2.set_brake_mode(MOTOR_BRAKE_COAST);
}

void spinFlywheel(){
        if(((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) || contBool) && !brakeBool){
                flywheel1 = 127;
                flywheel2 = -127;
                contBool = true;
        }

        pros::delay(20);

}

void eBrake(){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1){
                // brakeBool = true;
                contBool=false;
                flywheel1 = 0;
                flywheel2 = 0;
        }
}