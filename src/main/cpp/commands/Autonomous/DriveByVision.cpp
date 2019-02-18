/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonomous/DriveByVision.h"

DriveByVision::DriveByVision(double distance)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_chassis);
    Requires(&Robot::m_vision);

    this->distance = distance;
}

// Called just before this Command runs the first time
void DriveByVision::Initialize()
{
    Robot::m_vision.SetAnglePIDMode(2);
    Robot::m_vision.GetAnglePID()->SetSetpoint(0);
    Robot::m_vision.GetAnglePID()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveByVision::Execute()
{
    // Change PID Mode
    int angle_mode = 0;
    double difference_angle = 0 - Robot::m_vision.GetAlpha();
    if (difference_angle < 0)
    {
        difference_angle = -1 * difference_angle;
    }

    if (difference_angle <= 2)
    {
        Robot::m_vision.SetAnglePIDMode(2);
        angle_mode = 2;
    }

    else
    {
        if (difference_angle <= 5)
        {
            Robot::m_vision.SetAnglePIDMode(5);
            angle_mode = 5;
        }
        else
        {
            Robot::m_vision.SetAnglePIDMode(20);
            angle_mode = 20;
        }
    }

    cout << "Angle PID Mode set to " << angle_mode << ". " << endl;

    Robot::m_chassis.Drive(0.3, Robot::m_vision.GetAngleOutput(), false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByVision::IsFinished()
{
    return (Robot::m_vision.GetDistance() < this->distance);
}

// Called once after isFinished returns true
void DriveByVision::End()
{
    cout << "Rotated to angle 0." << endl;
    Robot::m_vision.GetAnglePID()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByVision::Interrupted()
{
    End();
}
