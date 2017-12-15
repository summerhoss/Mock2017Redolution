#ifndef Autonomous_H
#define Autonomous_H

#include <Commands/CommandGroup.h>
#include <WPILib.h>
#include "DriveUntilTarget.h"
#include "DriveUntilWall.h"
#include "Forward.h"
#include "Park.h"
#include "TankDrive.h"
#include "Turn.h"

using namespace frc;

class Autonomous : public CommandGroup {
public:
	Autonomous();
};

#endif  // Autonomous_H
