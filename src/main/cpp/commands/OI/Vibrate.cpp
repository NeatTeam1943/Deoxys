/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/OI/Vibrate.h"

Vibrate::Vibrate()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Vibrate::Initialize()
{
    Robot::m_oi.GetStick()->SetRumble(Robot::m_oi.GetStick()->kRightRumble, 1);
    Robot::m_oi.GetStick()->SetRumble(Robot::m_oi.GetStick()->kLeftRumble, 1);
    SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void Vibrate::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Vibrate::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void Vibrate::End()
{
    Robot::m_oi.GetStick()->SetRumble(Robot::m_oi.GetStick()->kRightRumble, 0);
    Robot::m_oi.GetStick()->SetRumble(Robot::m_oi.GetStick()->kLeftRumble, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Vibrate::Interrupted()
{
    End();
}
