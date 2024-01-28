#include "main.h"

extern bool isBlockerExtended;
extern bool waitingOnReleaseB;

extern bool isHangExtended;
extern bool waitingOnReleaseDOWN;

extern bool isGrabberExtended;
extern bool waitingOnReleaseR2;


extern pros::ADIDigitalOut hangPiston;
extern pros::ADIDigitalOut BlockerPiston2;
extern pros::ADIDigitalOut BlockerPiston1;
extern pros::ADIDigitalOut GrabberPiston1;
extern pros:: ADIDigitalOut GrabberPiston2;

void UpdatePistons();