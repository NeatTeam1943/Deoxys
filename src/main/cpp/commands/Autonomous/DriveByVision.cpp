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
    // if (Robot::m_vision.GetAlpha() == -999)
    // {
    //     return;
    // }
    // // Change PID Mode
    // int angle_mode = 0;
    // double difference_angle = 0 - Robot::m_vision.GetAlpha();
    // if (difference_angle < 0)
    // {
    //     difference_angle = -1 * difference_angle;
    // }

    // if (difference_angle >= 20)
    // {
    //     Robot::m_vision.SetAnglePIDMode(20);
    //     angle_mode = 20;
    // }
    // else if (difference_angle >= 5)
    // {
    //     Robot::m_vision.SetAnglePIDMode(5);
    //     angle_mode = 5;
    // }
    // else
    // {
    //     Robot::m_vision.SetAnglePIDMode(2);
    //     angle_mode = 2;
    // }

    // if (difference_angle <= 2)
    // {
    //     Robot::m_vision.SetAnglePIDMode(2);
    //     angle_mode = 2;
    // }

    // else
    // {
    //     if (difference_angle <= 5)
    //     {
    //         Robot::m_vision.SetAnglePIDMode(5);
    //         angle_mode = 5;
    //     }
    //     else
    //     {
    //         Robot::m_vision.SetAnglePIDMode(20);
    //         angle_mode = 20;
    //     }
    // }

    //cout << "Angle PID Mode set to " << angle_mode << ". " << endl;

    // if (Robot::m_vision.GetDistance() <= this->distance)
    //     Robot::m_chassis.Drive(0, -Robot::m_vision.GetAngleOutput(), false);

    // else
    Robot::m_chassis.Drive(0, -Robot::m_vision.GetAngleOutput(), false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByVision::IsFinished()
{
    return false;
    //return (Robot::m_vision.GetAnglePID()->OnTarget()) || (Robot::m_vision.GetAlpha() == -999);
}

// Called once after isFinished returns true
void DriveByVision::End()
{
    cout << "LAST ANGLE: " << Robot::m_vision.GetAlpha() << endl;
    cout << "Rotated to angle 0." << endl;
    Robot::m_chassis.Drive(0, 0, false);
    Robot::m_vision.GetAnglePID()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByVision::Interrupted()
{
    End();
}
