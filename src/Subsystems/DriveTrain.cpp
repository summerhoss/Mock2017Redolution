#include "DriveTrain.h"
#include "../RobotMap.h"
#include <math.h>

#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/TankDrive.h"
//#include "../Commands/TankDriveReverse.h"

#include "DriveTrain.h"

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain"),
		left(new CANTalon(LEFT_MOTOR_PORT)),
		right(new CANTalon(RIGHT_MOTOR_PORT)),
		mult(1.0),
		ticksToDistance(114),
		leftEncoder(new Encoder(ENCODER_LEFT_1,ENCODER_LEFT_2)),
		rightEncoder(new Encoder(ENCODER_RIGHT_1,ENCODER_RIGHT_2)),
		gyro(new ADXRS450_Gyro())
{ // 112 < ticksToDistance < 117

	//left->SetInverted(true);
	//right->SetInverted(true);
}

DriveTrain::~DriveTrain() {
	delete left;
	delete right;
	delete leftEncoder;
	delete rightEncoder;
}

void DriveTrain::reverseDrive(){
	left->SetInverted(!left->GetInverted());
	right->SetInverted(!right->GetInverted());
}

void DriveTrain::setMult(float m) {
	mult = m;
}

int DriveTrain::getMult() {
	return mult;
}

void DriveTrain::arcadeDrive(float moveValue, float rotateValue) {
	float leftMotorOutput;
	float rightMotorOutput;

	moveValue = DriveTrain::Limit(moveValue, 1);
	rotateValue = DriveTrain::Limit(rotateValue, 1);

	// Standard ArcadeDriveTrain algorithm from Google
	if (moveValue > 0.0) {
		if (rotateValue > 0.0) {
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = max(moveValue, rotateValue);
		} else {
			leftMotorOutput = max(moveValue, -rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		}
	} else {
		if (rotateValue > 0.0) {
			leftMotorOutput = -max(-moveValue, rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		} else {
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = -max(-moveValue, -rotateValue);
		}
	}

	float limitedL = DriveTrain::Limit(leftMotorOutput, 1.0);
	float limitedR = -DriveTrain::Limit(rightMotorOutput, 1.0);

	left->Set(-limitedL);
	right->Set(-limitedR); //removed negatives
}

void DriveTrain::tankDrive(float moveValueLeft, float moveValueRight) {
	//float leftMotorOutput;
	//float rightMotorOutput;

	moveValueLeft = DriveTrain::Limit(moveValueLeft, 1.0);
	moveValueRight = -DriveTrain::Limit(moveValueRight, 1.0);

	//std::cout << "LeftRaw: " << limitedL<< "\n";
	//std::cout << "RightRaw: " << limitedR << "\n";
	// TODO: mult should never be 0, but robot wasn't driving for some reason
	if (mult != 0) {
		left->Set(-moveValueLeft);
		right->Set(-moveValueRight);
	} else {
		left->Set(-moveValueLeft);
		right->Set(-moveValueRight);
	}
}

float DriveTrain::Limit(float num, float max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

 //Return distance in feet
double DriveTrain::getDistance() {
	//code from last year
	return ((double) ((leftEncoder->GetDistance()) / ticksToDistance)
				- (double) ((rightEncoder->GetDistance()) / ticksToDistance)) / 2.0;
	std::cout<<"Distance = "<<getDistance()<<std::endl;
}

void DriveTrain::InitDefaultCommand() {
	//std::cout<<"pushpush"<<std::endl;
	SetDefaultCommand(new TankDrive());
}

double DriveTrain::getRightEncoderDistance()
{
	return rightEncoder->GetDistance();
}

double DriveTrain::getLeftEncoderDistance()
{
	return leftEncoder->GetDistance();
}

void DriveTrain::setSpeedLeft(double speed) {
	left->Set(speed * mult);
}

void DriveTrain::setSpeedRight(double speed) {
	right->Set(speed * mult);
}

void DriveTrain::resetEncoders()
{
	left->Reset();
	right->Reset();
}

ADXRS450_Gyro* DriveTrain::getGyro()
{
	return gyro;
}
