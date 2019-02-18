/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonomous/Load.h"

Load::Load()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_conveyor);
    Requires(&Robot::m_intake);
}

// Called just before this Command runs the first time
void Load::Initialize()
{
    Robot::m_conveyor.SetLauncher1(0);
    Robot::m_conveyor.SetLauncher2(0);
    Robot::m_intake.SetRoller(0);
}

// Called repeatedly when this Command is scheduled to run
void Load::Execute()
{
    Robot::m_conveyor.SetLauncher1(-0.2);
    Robot::m_conveyor.SetLauncher2(-0.2);
    Robot::m_intake.SetRoller(-0.4);

    if (Robot::m_conveyor.IsLoaded())
        frc::Scheduler::GetInstance()->AddCommand(new Vibrate());
}

// Make this return true when this Command no longer needs to run execute()
bool Load::IsFinished() { return Robot::m_conveyor.IsLoaded(); }

// Called once after isFinished returns true
void Load::End()
{
    Robot::m_conveyor.SetLauncher1(0);
    Robot::m_conveyor.SetLauncher2(0);
    Robot::m_intake.SetRoller(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Load::Interrupted()
{
    End();
}
