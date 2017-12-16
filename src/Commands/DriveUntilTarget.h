#ifndef DriveUntilTarget_H
#define DriveUntilTarget_H

using namespace std;

#include "../CommandBase.h"
#include "Utilities/NetworkTablesInterface.h"
#include "../Subsystems/DriveTrain.h"
#include "WVPIDController.h"

class DriveUntilTarget : public CommandBase {
public:
	DriveUntilTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	string CVOrientation;
	double CVAzimuth;
	WVPIDController* distancePID;
};

#endif  // DriveUntilTarget_H
