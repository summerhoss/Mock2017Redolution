#ifndef Forward_H
#define Forward_H

#include "../CommandBase.h"
#include "WVPIDController.h"

class Forward : public CommandBase {
public:
	Forward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	WVPIDController* distancePID;
};

#endif  // Forward_H
