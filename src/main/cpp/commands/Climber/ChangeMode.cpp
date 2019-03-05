/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climber/ChangeMode.h"

ChangeMode::ChangeMode()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_climber);
}

// Called just before this Command runs the first time
void ChangeMode::Initialize()
{
    Robot::m_climber.NextMode();
    if (Robot::m_climber.GetMode() == 2)
        SetTimeout(1.5);
    // if (Robot::m_climber.GetMode() == 1)
    // {
    //     Robot::m_climber.SetSaverMode(false);
    //     Robot::m_climber.SetDoubleMode(frc::DoubleSolenoid::Value::kOff);
    // }
    // else if (Robot::m_climber.GetMode() == 2)
    // {
    //     Robot::m_climber.SetSaverMode(true);
    //     Robot::m_climber.SetDoubleMode(frc::DoubleSolenoid::Value::kForward);
    // }
    // else
    // {
    //     Robot::m_climber.SetSaverMode(true);
    //     Robot::m_climber.SetDoubleMode(frc::DoubleSolenoid::Value::kReverse);
    //     SetTimeout(1.5);
    // }
}

// Called repeatedly when this Command is scheduled to run
void ChangeMode::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ChangeMode::IsFinished()
{
    if (Robot::m_climber.GetMode() == 2)
    {
        if (IsTimedOut())
            Robot::m_climber.NextMode();
        else
            return false;
    }
    return true;
}

// Called once after isFinished returns true
void ChangeMode::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeMode::Interrupted()
{
    End();
}
