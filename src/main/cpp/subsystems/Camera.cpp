/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Camera.h"

Camera::Camera() : Subsystem("ExampleSubsystem")
{
    this->vertical = new Servo(CAMERA_VERTICAL_SERVO);
    this->horizontal = new Servo(CAMERA_HORIZONTAL_SERVO);
}

void Camera::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new Look());
}

void Camera::MoveCamera()
{
    double ver = -Robot::m_oi.GetStick()->GetRawAxis(AXIS_RIGHT_Y);
    double hor = Robot::m_oi.GetStick()->GetRawAxis(AXIS_RIGHT_X);

    this->horizontal->SetAngle(horizontal_middle + (hor * horizontal_middle));
    this->vertical->SetAngle(vertical_middle + (ver * vertical_middle));
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
double Camera::GetHorizotal()
{
    return this->horizontal->GetAngle();
}

double Camera::GetVertical()
{
    return this->vertical->GetAngle();
}