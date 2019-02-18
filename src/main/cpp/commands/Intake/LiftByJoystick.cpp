/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/LiftByJoystick.h"

LiftByJoystick::LiftByJoystick()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_intake);
    this->stick = Robot::m_oi.GetStick();
}

// Called just before this Command runs the first time
void LiftByJoystick::Initialize()
{
    Robot::m_intake.SetLift(0);
}

// Called repeatedly when this Command is scheduled to run
void LiftByJoystick::Execute()
{
    double power = this->stick->GetRawAxis(AXIS_RIGHT_TRIGGER) - this->stick->GetRawAxis(AXIS_LEFT_TRIGGER);
    if (power < 0)
        Robot::m_intake.SetLift(-1 * power * power);
    else
        Robot::m_intake.SetLift(power * power);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftByJoystick::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void LiftByJoystick::End()
{
    Robot::m_intake.SetLift(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftByJoystick::Interrupted()
{
    End();
}
