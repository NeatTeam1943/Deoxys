/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Chassis/DriveByJoystick.h"

DriveByJoystick::DriveByJoystick()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_chassis);
    this->stick = Robot::m_oi.GetStick();
}

// Called just before this Command runs the first time
void DriveByJoystick::Initialize()
{
    Robot::m_chassis.Drive(0, 0, false);
}

// Called repeatedly when this Command is scheduled to run
void DriveByJoystick::Execute()
{
    Robot::m_chassis.Drive(this->stick);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveByJoystick::End()
{
    Robot::m_chassis.Drive(0, 0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByJoystick::Interrupted()
{
    End();
}
