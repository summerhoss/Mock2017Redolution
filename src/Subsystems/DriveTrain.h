#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

#include <WPILib.h>
#include "ctrlib/CANTalon.h"
#include "Commands/Subsystem.h"

class DriveTrain: public Subsystem {
private:

	CANTalon* left;
	CANTalon* right;
	int ticksToDistance;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	ADXRS450_Gyro* gyro;

public:

	DriveTrain();
	~DriveTrain();

	static float Limit(float num, float max);

	void setMult(float m);
	void reverseDrive();
	int getMult();
	void arcadeDrive(float move, float rotate);
	void tankDrive(float moveValueLeft, float moveValueRight);

	double getDistance();

	void setSpeedLeft(double speed);
	void setSpeedRight(double speed);
	void resetEncoders();
	double getRightEncoderDistance();
	double getLeftEncoderDistance();

	void InitDefaultCommand();
	ADXRS450_Gyro* getGyro();

	//void SetReverse();
	float mult;
};

#endif

