/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Chassis/DriveStraight.h"

DriveStraight::DriveStraight(double mag)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_chassis);
    this->mag = mag;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
    Robot::m_chassis.GetNavx()->ZeroYaw();
    Robot::m_chassis.GetAnglePID()->SetSetpoint(0);
    Robot::m_chassis.GetAnglePID()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
    Robot::m_chassis.Drive(0.3, Robot::m_chassis.GetAngleOutput(), false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveStraight::End()
{
    Robot::m_chassis.GetAnglePID()->Disable();
    cout << "Drive straight over." << endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{
    End();
}
