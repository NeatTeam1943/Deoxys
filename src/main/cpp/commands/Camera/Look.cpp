/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Camera/Look.h"

Look::Look()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_camera);
}

// Called just before this Command runs the first time
void Look::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Look::Execute()
{
    Robot::m_camera.MoveCamera();
}

// Make this return true when this Command no longer needs to run execute()
bool Look::IsFinished() { return false; }

// Called once after isFinished returns true
void Look::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Look::Interrupted() { End(); }
