#include "Turn.h"

Turn::Turn(double turnAngle) : anglePID(new WVPIDController(0.15,0,0,90,false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	angle = turnAngle;
	//not sure about the inAngle part... that needs to be fixed
}

Turn::~Turn()
{
	delete anglePID;
}

// Called just before this Command runs the first time
void Turn::Initialize() {
	drive->resetEncoders();
	drive->getGyro()->Reset();
	anglePID->SetSetPoint(angle);
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	//code from last year that needs to be fixed with the gyro
	double current_angle = drive->getGyro()->GetAngle();
	double rotateVal = anglePID->Tick(current_angle);
	drive->arcadeDrive(0, rotateVal);
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() {
	bool finished = (fabs(anglePID->GetError()) < 1);

		return finished;

		//return finished || forceFinish || IsTimedOut();
}

// Called once after isFinished returns true
void Turn::End() {
	drive->arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
