#include "Park.h"

Park::Park() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void Park::Initialize() {
	drive->setSpeedLeft(0);
	drive->setSpeedRight(0);
}

// Called repeatedly when this Command is scheduled to run
void Park::Execute() {
	drive->setSpeedLeft(0);
	drive->setSpeedRight(0);
}

// Make this return true when this Command no longer needs to run execute()
bool Park::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Park::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Park::Interrupted() {
	End();
	//why is this needed?
}
