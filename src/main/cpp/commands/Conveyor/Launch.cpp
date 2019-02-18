/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Conveyor/Launch.h"

Launch::Launch(double power)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_conveyor);
    this->power = power;
}

// Called just before this Command runs the first time
void Launch::Initialize()
{
    Robot::m_conveyor.SetLauncher1(0);
    Robot::m_conveyor.SetLauncher2(0);
}

// Called repeatedly when this Command is scheduled to run
void Launch::Execute()
{
    Robot::m_conveyor.SetLauncher1(this->power);
    Robot::m_conveyor.SetLauncher2(this->power);
}

// Make this return true when this Command no longer needs to run execute()
bool Launch::IsFinished() { return false; }

// Called once after isFinished returns true
void Launch::End()
{
    Robot::m_conveyor.SetLauncher1(0);
    Robot::m_conveyor.SetLauncher2(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Launch::Interrupted()
{
    End();
}
