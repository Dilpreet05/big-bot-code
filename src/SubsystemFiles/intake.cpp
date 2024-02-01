#include "main.h"

pros::Motor intakeMotor(2,MOTOR_GEARSET_06,false);

void setIntakeBrakes(){
        intakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
}

void spinIntake(){

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) != 1)){
        intakeMotor = 127;
    }
    else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) != 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1)){
        intakeMotor = -127;
    }
    else{
        intakeMotor.brake();
    }

    pros::delay(20);

}

