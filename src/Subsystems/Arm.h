#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>

class Arm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Arm();
	void InitDefaultCommand();
};

#endif  // Arm_H
