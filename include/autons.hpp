#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;
// extern Drive reversedChassis;
extern bool isReversed;

void drive_example();
void turn_example();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void combining_movements();
void interfered_example();
void default_constants();

void skills();
void match();

void spinFW();
void stopFW();
void intakeSpin();
void outtake();
void stopIntake();
void grabberDown();
void grabberUp();

void cycle();
void skillsCycle();
void winPoint();
void touchHang();

// // my functions //
// void moveForward(int d);
// void turnRight(int d);
// void turnLeft(int d);
// void swingRight(int d);
// void swingLeft(int d);