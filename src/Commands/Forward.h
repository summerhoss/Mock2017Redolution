#ifndef Forward_H
#define Forward_H

#include "../CommandBase.h"
#include "Utilities/WVPIDController.h"

class Forward : public CommandBase {
public:
	Forward(double myDistance);
	~Forward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double distance;

private:
	WVPIDController* distancePID;
};

#endif  // Forward_H
