#ifndef OI_H
#define OI_H

#include <WPILib.h>

class OI {
public:
	OI();
	~OI();
	Joystick* getDriveStickRight();
	Joystick* getDriveStickLeft();

private:
	Button* activateArm;
	Joystick* leftStick;
    Joystick* rightStick;
};

#endif  // OI_H
