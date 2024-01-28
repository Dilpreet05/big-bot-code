#include "main.h"

bool isBlockerExtended = false;
bool waitingOnReleaseB = false;

bool isHangExtended = false;
bool waitingOnReleaseDOWN = false;

bool isGrabberExtended = false;
bool waitingOnReleaseR2 = false;

pros::ADIDigitalOut hangPiston('C');
pros::ADIDigitalOut BlockerPiston2('D');
pros::ADIDigitalOut BlockerPiston1('E');
pros::ADIDigitalOut GrabberPiston1('A');
pros:: ADIDigitalOut GrabberPiston2('B');




void UpdatePistons(){
    ////////////////////////////
    // HANG PISTON CONTROLS
    ////////////////////////////
    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1)&& (isHangExtended == false) && (waitingOnReleaseDOWN == false) ) {
       hangPiston.set_value(true);  // Deploy the piston
       isHangExtended = true;   // Indicate it's set
       waitingOnReleaseDOWN = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1) && (isHangExtended == true) && (waitingOnReleaseDOWN == false) ) {
       hangPiston.set_value(false);  // Retract the piston
       isHangExtended = false;  // Indicate it's not set
       waitingOnReleaseDOWN = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 0 )) {
       waitingOnReleaseDOWN = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }

    // //////////////////////////
    // BLOCKER PISTON CONTROLS
    // //////////////////////////

    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1)&& (isBlockerExtended == false) && (waitingOnReleaseB == false) ) {
       BlockerPiston2.set_value(true);  // Deploy the pistons
       BlockerPiston1.set_value(true);
       isBlockerExtended = true;   // Indicate it's set
       waitingOnReleaseB = true;  // Flag to wait for button release
     }
     else if( (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) && (isBlockerExtended == true) && (waitingOnReleaseB == false) ) {
       BlockerPiston2.set_value(false);  // Deploy the pistons
       BlockerPiston1.set_value(false);
       isBlockerExtended = false;  // Indicate it's not set
       waitingOnReleaseB = true;  // Flag to wait for button release
     }
     else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 0 )) {
       waitingOnReleaseB = false;  // Flag that button has been released, so next press will toggle to the opposite state
     }


    ////////////////////////////
    // GRABBER PISTON CONTROLS
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