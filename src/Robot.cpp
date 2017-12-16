#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/TankDrive.h"
#include <WPILib.h>
#include "CommandBase.h"

class Robot: public frc::IterativeRobot {
private:
	frc::SendableChooser<frc::Command*> chooser;

public:
	void RobotInit() override {
		CommandBase::initialize();
		chooser.AddDefault("DriveTrain", new TankDrive());
		// chooser.AddObject("My Auto", new MyAutoCommand());
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		frc::SmartDashboard::PutString("CVOrientationFound", NetworkTablesInterface::getOrientation());
		frc::SmartDashboard::PutNumber("CVAzimuthFound", NetworkTablesInterface::getAzimuth());
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
			if (autonomousCommand != nullptr) {
					autonomousCommand->Start();
			}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
					autonomousCommand->Cancel();
				}
		CommandBase::drive->Disable();
		//why is this not working?

	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		//This is copied from last year's code because we don't have the CV values yet
		frc::SmartDashboard::PutString("CVOrientationFound", NetworkTablesInterface::getOrientation());
		frc::SmartDashboard::PutNumber("CVAzimuthFound", NetworkTablesInterface::getAzimuth());

	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();

		//This is copied from last year's code because we don't have the CV values yet
		frc::SmartDashboard::PutString("CVOrientationFound", NetworkTablesInterface::getOrientation());
		frc::SmartDashboard::PutNumber("CVAzimuthFound", NetworkTablesInterface::getAzimuth());
	}

private:
	CommandGroup* autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;

};

START_ROBOT_CLASS(Robot)
;
