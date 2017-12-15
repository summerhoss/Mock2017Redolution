#ifndef DriveUntilWall_H
#define DriveUntilWall_H

#include "../CommandBase.h"

class DriveUntilWall : public CommandBase {
public:
	DriveUntilWall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Ultrasonic* ultra;
};

#endif  // DriveUntilWall_H
