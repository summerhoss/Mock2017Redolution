#include "DriveUntilTarget.h"

DriveUntilTarget::DriveUntilTarget() : distancePID(new WVPIDController(1, 0, 0, 10, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

bool DriveUntilTarget::TargetFound()
{
	if(CVOrientation.compare("VERTICAL") == 0 && CVAzimuth == 90) //fix the azimuth value probably
	{
		return true;
	}
	else
		return false;
}

// Called just before this Command runs the first time
void DriveUntilTarget::Initialize() {
	drive->resetEncoders();
	drive->setSpeedLeft(distancePID->Tick(drive->getDistance()));
	drive->setSpeedRight(distancePID->Tick(drive->getDistance()));
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilTarget::Execute() {
	while(TargetFound() == false)
	{
		drive->setSpeedLeft(distancePID->Tick(drive->getDistance()));
		drive->setSpeedRight(distancePID->Tick(drive->getDistance()));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilTarget::IsFinished() {

	return DriveUntilTarget::TargetFound();
}

// Called once after isFinished returns true
void DriveUntilTarget::End() {
	//parks
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilTarget::Interrupted() {

}
