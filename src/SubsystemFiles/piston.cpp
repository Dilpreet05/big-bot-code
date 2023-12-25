#include "main.h"

bool isRightWingExtended = false;
bool waitingOnReleaseB = false;

bool isLeftWingExtended = false;
bool waitingOnReleaseDOWN = false;

bool isGrabberExtended = false;
bool waitingOnReleaseR2 = false;

pros::ADIDigitalOut WingPistonLeft('A');
pros::ADIDigitalOut WingPistonRight('B');
pros::ADIDigitalOut GrabberPiston1('C');
pros:: ADIDigitalOut GrabberPiston2('D');




void UpdatePistons(){
    ////////////////////////////
    //LEFT WING PISTON CONTROLS
    ////////////////////////////
    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1)&& (isLeftWingExtended == false) && (waitingOnReleaseDOWN == false) ) {
       WingPistonLeft.set_value(true);  // Deploy the piston
       isLeftWingExtended = true;   // Indicate it's set
       waitingOnReleaseDOWN = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1) && (isLeftWingExtended == true) && (waitingOnReleaseDOWN == false) ) {
       WingPistonLeft.set_value(false);  // Retract the piston
       isLeftWingExtended = false;  // Indicate it's not set
       waitingOnReleaseDOWN = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 0 )) {
       waitingOnReleaseDOWN = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }

    ////////////////////////////
    //RIGHT WING PISTON CONTROLS
    ////////////////////////////

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1)&& (isRightWingExtended == false) && (waitingOnReleaseB == false) ) {
       WingPistonRight.set_value(true);  // Deploy the piston
       isRightWingExtended = true;   // Indicate it's set
       waitingOnReleaseB = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) && (isRightWingExtended == true) && (waitingOnReleaseB == false) ) {
       WingPistonRight.set_value(false);  // Retract the piston
       isRightWingExtended = false;  // Indicate it's not set
       waitingOnReleaseB = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 0 )) {
       waitingOnReleaseB = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }


    ////////////////////////////
    //GRABBER PISTON CONTROLS
    ////////////////////////////

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1)&& (isGrabberExtended == false) && (waitingOnReleaseR2 == false) ) {
       GrabberPiston1.set_value(true);  // Deploy the piston
       GrabberPiston2.set_value(true);
       isGrabberExtended = true;   // Indicate it's set
       waitingOnReleaseR2 = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) && (isGrabberExtended == true) && (waitingOnReleaseR2 == false) ) {
       GrabberPiston1.set_value(false);  // Retract the piston
       GrabberPiston2.set_value(false);
       isGrabberExtended = false;  // Indicate it's not set
       waitingOnReleaseR2 = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 0 )) {
       waitingOnReleaseR2 = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }

     pros::delay(20);

}