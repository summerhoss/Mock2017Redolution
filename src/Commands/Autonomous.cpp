#include "Autonomous.h"

Autonomous::Autonomous() {
	// Add Commands here:

	AddSequential(new Forward());
	AddSequential(new Turn(90));
	AddSequential(new DriveUntilTarget());
	AddSequential(new Turn(-90));
	// I need to fix the turn values
	AddSequential(new Forward());
	AddSequential(new Park());
	AddSequential(new DriveUntilWall());
	AddSequential(new PushTarget());
	//autonomous stops after this


	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
