#include "MoveArm.h"

MoveArm::MoveArm() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {
	arm->resetArm();
	arm->moveArm();
}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveArm::End() {
	arm->resetArm();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {

}
