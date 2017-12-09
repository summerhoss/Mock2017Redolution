#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
#include "WVPIDController.h"

class Turn : public CommandBase {
public:
	Turn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double angle;
	WVPIDController* anglePID;
};

#endif  // Turn_H
