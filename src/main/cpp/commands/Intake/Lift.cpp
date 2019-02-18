/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/Lift.h"

Lift::Lift(double power)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_intake);

    // As Lift() runs all the time, there's no need for Requires().
    this->power = power;
}

// Called just before this Command runs the first time
void Lift::Initialize()
{
    Robot::m_intake.SetLift(0);
}

// Called repeatedly when this Command is scheduled to run
void Lift::Execute()
{
    Robot::m_intake.SetLift(this->power);
}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void Lift::End()
{
    Robot::m_intake.SetLift(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted()
{
    End();
}
