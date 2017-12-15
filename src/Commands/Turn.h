#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
#include "WVPIDController.h"

class Turn : public CommandBase {
public:
	Turn(double turnAngle);
	~Turn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double angle;

private:
	WVPIDController* anglePID;
};

#endif  // Turn_H
