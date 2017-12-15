#include "DriveUntilWall.h"

DriveUntilWall::DriveUntilWall() : ultra(new Ultrasonic*) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	//the ultrasonic sensor will be in DriveTrain
}

// Called just before this Command runs the first time
void DriveUntilWall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveUntilWall::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilWall::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveUntilWall::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilWall::Interrupted() {

}
