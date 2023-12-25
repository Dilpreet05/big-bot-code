#include "main.h"

pros::Motor intake(20,MOTOR_GEARSET_06,false);

void setIntakeBrakes(){
        intake.set_brake_mode(MOTOR_BRAKE_COAST);
}

void spinIntake(){

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) != 1)){
        intake = 127;
    }
    else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) != 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1)){
        intake = -127;
    }
    else{
        intake.brake();
    }

    pros::delay(20);

}