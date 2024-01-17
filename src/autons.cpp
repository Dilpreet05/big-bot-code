#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 101; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



// . . .
// Make your own autonomous functions here!
// . . .

void skills(){

  startOfSkills();
  reset();

  spinFW();
  intakeSpin();
  grabberDown();

  pros::delay(500);

  chassis.set_drive_pid(-12,DRIVE_SPEED);
  chassis.wait_drive();
  

  chassis.set_drive_pid(10,DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(150);

  

  for(int k = 0; k < 22; k++){
    skillsCycle();
  }

  // endOfSkills();

}



void skillsCycle(){

  pros::delay(500);

  chassis.set_drive_pid(-10,DRIVE_SPEED);
  chassis.wait_drive();
  

  chassis.set_drive_pid(10,DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(250);


}

void startOfSkills(){
  chassis.set_drive_pid(-9,DRIVE_SPEED,true);
  chassis.wait_drive();

  chassis.set_drive_pid(20,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,45,SWING_SPEED);
  chassis.wait_drive();
}

// void endOfSkills(){

//   chassis.reset_pid_targets(); // Resets PID targets to 0
//   chassis.reset_gyro(); // Reset gyro position to 0
//   chassis.reset_drive_sensor(); // Reset drive sensors to 0

//   chassis.set_drive_pid(-27,DRIVE_SPEED,true);
//   chassis.wait_drive();

//   chassis.set_swing_pid(ez::LEFT_SWING,45,TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-35,127,true);
//   chassis.wait_drive();

//   chassis.set_turn_pid(90,TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(12,DRIVE_SPEED);
//   chassis.wait_drive();

//   chassis.set_turn_pid(-90,TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-35,DRIVE_SPEED,true);
//   chassis.wait_drive();

// }


void match(){

  winPoint();

  for(int k = 0; k < 3; k++){
    cycle();
  }

  touchHang();

  

  

}

void touchHang(){

  reset();

  chassis.set_drive_pid(-35,DRIVE_SPEED,true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, -90,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(25,DRIVE_SPEED,true);
  chassis.wait_drive();

  grabberDown();
  stopFW();
  

}

void winPoint(){
  spinFW();
  pros::delay(1000);

  intakeSpin();
  pros::delay(750);
  stopIntake();
  chassis.set_drive_pid(19,DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::RIGHT_SWING,-45,TURN_SPEED);
  chassis.wait_drive();

  reset();

  grabberDown();
  pros::delay(250);

  chassis.set_drive_pid(-62,60,true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 45, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(1000);
  grabberUp();
  // pros::delay(500);




  chassis.set_drive_pid(35,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();

  chassis.set_drive_pid(-15,DRIVE_SPEED,true);
  chassis.wait_drive();



  chassis.set_turn_pid(180,50);
  chassis.wait_drive();

  chassis.set_drive_pid(-20,127,true);
  chassis.wait_drive();

  chassis.set_drive_pid(18,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();

  chassis.set_turn_pid(180,50);
  chassis.wait_drive();

  chassis.set_drive_pid(-17,DRIVE_SPEED,true);
  chassis.wait_drive();

  // chassis.set_swing_pid(ez::LEFT_SWING, 45, 50);
  // chassis.wait_drive();

  reset();
  
  chassis.set_swing_pid(ez::RIGHT_SWING, -53, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(54,DRIVE_SPEED,true);
  chassis.wait_drive();
}


void cycle(){ // grab from corner and shoot cycle 

  reset();

  grabberDown();
  pros::delay(500);
  chassis.set_drive_pid(-28,DRIVE_SPEED,true);
  chassis.wait_drive();


  chassis.set_swing_pid(ez::LEFT_SWING,45,TURN_SPEED/2);
  // chassis.set_turn_pid(45,TURN_SPEED/2);
  chassis.wait_drive();

  chassis.set_drive_pid(-15,90);
  chassis.wait_drive();
  
  grabberUp();
  intakeSpin();
  pros::delay(250);

  // chassis.set_drive_pid(15,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-15,DRIVE_SPEED,true);
  // chassis.wait_drive();

  chassis.set_drive_pid(15,DRIVE_SPEED);
  chassis.wait_drive();
  stopIntake();


  reset();

  chassis.set_swing_pid(ez::LEFT_SWING,-45,TURN_SPEED);
  // chassis.set_turn_pid(-45,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(30,DRIVE_SPEED,true);
  chassis.wait_drive();




}



void spinFW(){
  flywheel1 = 127;
  flywheel2 = -127;
}

void stopFW(){
  flywheel1 = 0;
  flywheel2 = 0;
}

void intakeSpin(){
  intakeMotor = 127;
}

void outtake(){
  intakeMotor = -127;
}

void stopIntake(){
  intakeMotor = 0;
}

void grabberDown(){
  GrabberPiston1.set_value(true);  // Deploy the piston
  GrabberPiston2.set_value(true);
}

void grabberUp(){
  GrabberPiston1.set_value(false);  // Deploy the piston
  GrabberPiston2.set_value(false);
}

void reset(){
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0

}
