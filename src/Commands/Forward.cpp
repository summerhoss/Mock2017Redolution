#include "Forward.h"

//based off of last year's code
Forward::Forward() : distancePID(new WVPIDController(1, 0, 0, 10, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void Forward::Initialize() {
	drive->resetEncoders();
	drive->setSpeedLeft(WVPIDController::Tick(drive->getDistance()));
	drive->setSpeedRight(WVPIDController::Tick(drive->getDistance()));
}

// Called repeatedly when this Command is scheduled to run
void Forward::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Forward::IsFinished() {
	if(drive->getDistance() <= 12) //change number later
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void Forward::End() {
	drive->setSpeedLeft(0);
	drive->setSpeedRight(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Forward::Interrupted() {

}
