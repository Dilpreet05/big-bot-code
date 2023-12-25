#include "main.h"

extern bool isRightWingExtended;
extern bool waitingOnReleaseB;

extern bool isLeftWingExtended;
extern bool waitingOnReleaseDOWN;

extern bool isGrabberExtended;
extern bool waitingOnReleaseR2;

extern pros::ADIDigitalOut WingPistonLeft;
extern pros::ADIDigitalOut WingPistonRight;
extern pros::ADIDigitalOut GrabberPiston1;
extern pros:: ADIDigitalOut GrabberPiston2;

void UpdatePistons();