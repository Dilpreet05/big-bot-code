#include "main.h"

extern bool isForward;
extern Drive chassis;
extern Drive reversedChassis;

void updateDrive();
void driveForwardBack();
bool updateDirection();
extern bool isMotorAvailable;