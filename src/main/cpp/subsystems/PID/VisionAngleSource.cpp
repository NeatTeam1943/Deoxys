/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PID/VisionAngleSource.h"

VisionAngleSource::VisionAngleSource()
{
}

double VisionAngleSource::PIDGet()
{
    return Robot::m_vision.GetAlpha();
}

void VisionAngleSource::SetPIDSourceType(PIDSourceType pidSource)
{
    this->m_pidSource = pidSource;
}

PIDSourceType VisionAngleSource::GetPIDSourceType() const
{
    return this->m_pidSource;
}