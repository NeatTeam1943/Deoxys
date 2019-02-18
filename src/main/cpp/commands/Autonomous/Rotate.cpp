/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonomous/Rotate.h"

Rotate::Rotate(double target)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_chassis);
    this->curAlpha = 0;
}

// Called just before this Command runs the first time
void Rotate::Initialize()
{
    Robot::m_chassis.SetAnglePIDMode(2);
    Robot::m_chassis.GetAnglePID()->SetSetpoint(this->target);
    Robot::m_chassis.GetAnglePID()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void Rotate::Execute()
{
    // Change PID Mode
    int angle_mode = 0;
    double difference_angle = this->target - Robot::m_chassis.GetNavx()->GetYaw();
    if (difference_angle < 0)
    {
        difference_angle = -1 * difference_angle;
    }

    if (difference_angle <= 2)
    {
        Robot::m_chassis.SetAnglePIDMode(2);
        angle_mode = 2;
    }

    else
    {
        if (difference_angle <= 5)
        {
            Robot::m_chassis.SetAnglePIDMode(5);
            angle_mode = 5;
        }
        else
        {
            Robot::m_chassis.SetAnglePIDMode(20);
            angle_mode = 20;
        }
    }

    cout << "Angle PID Mode set to " << angle_mode << ". " << endl;

    //if (Robot::m_chassis.GetAngleOutput() != -1 && Robot::m_chassis.GetAngleOutput() != 0)
    Robot::m_chassis.Drive(0, Robot::m_chassis.GetAngleOutput(), false);
    //Robot::m_chassis.GetAnglePID()->SetSetpoint(this->curAlpha);
}

// Make this return true when this Command no longer needs to run execute()
bool Rotate::IsFinished() { return Robot::m_chassis.GetAnglePID()->OnTarget(); }

// Called once after isFinished returns true
void Rotate::End()
{
    cout << "Rotated to angle " << this->target << "." << endl;
    Robot::m_chassis.GetAnglePID()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rotate::Interrupted()
{
    End();
}