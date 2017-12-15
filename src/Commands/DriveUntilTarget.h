#ifndef DriveUntilTarget_H
#define DriveUntilTarget_H

using namespace std;

#include "../CommandBase.h"
#include "Utilities/NetworkTablesInterface.h"
#include "DriveTrain.h"
#include "WVPIDController.h"

class DriveUntilTarget : public CommandBase {
public:
	DriveUntilTarget();
	void Initialize();
	bool TargetFound();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	string CVOrientation = NetworkTablesInterface::getOrientation();
	double CVAzimuth = NetworkTablesInterface::getAzimuth();
	WVPIDController* distancePID;
};

#endif  // DriveUntilTarget_H
