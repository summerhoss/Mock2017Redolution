#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() : Subsystem("Arm"), servo(new Servo(ARM_PORT)) {

}

Arm::~Arm()
{
	delete servo;
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm());
}

void Arm::moveArm()
{
	servo->SetAngle(90);
}

void Arm::resetArm()
{
	servo->SetAngle(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
