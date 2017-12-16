#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <WPILib.h>


class Arm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo* servo;

public:
	Arm();
	~Arm();
	void InitDefaultCommand();
	void moveArm();
	void resetArm();
};

#endif  // Arm_H
