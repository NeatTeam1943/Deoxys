/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Chassis/DriveSlow.h"

DriveSlow::DriveSlow()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_chassis);
    this->stick = Robot::m_oi.GetStick();
    this->x = 0;
    this->y = 0;
}

// Called just before this Command runs the first time
void DriveSlow::Initialize()
{
    Robot::m_chassis.Drive(0, 0, false);
}

// Called repeatedly when this Command is scheduled to run
void DriveSlow::Execute()
{
    this->x = this->stick->GetX();
    this->y = this->stick->GetY();
    Robot::m_chassis.Drive(this->y * 0.35, this->x * 0.35, false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSlow::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveSlow::End()
{
    Robot::m_chassis.Drive(0, 0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSlow::Interrupted()
{
    End();
}
