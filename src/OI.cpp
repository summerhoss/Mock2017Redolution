#include "OI.h"

#include <WPILib.h>

using namespace frc;

OI::OI() : leftStick(new Joystick(2)), rightStick(new Joystick(1))  {
	activateArm = new JoystickButton(rightStick, 2);
	activateArm->WhenPressed(new MoveArm());
}

OI::~OI()
{
	delete rightStick;
	delete leftStick;
}

Joystick* OI::getDriveStickLeft() {
	return leftStick;
}

Joystick* OI::getDriveStickRight() {
	return rightStick;
}
