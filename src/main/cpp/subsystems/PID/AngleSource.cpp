/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PID/AngleSource.h"

AngleSource::AngleSource()
{
}

double AngleSource::PIDGet()
{
    return Robot::m_chassis.GetNavx()->GetYaw();
    //return Robot::table->GetEntry("alpha").GetDouble(0);
}

void AngleSource::SetPIDSourceType(PIDSourceType pidSource)
{
    this->m_pidSource = pidSource;
}

PIDSourceType AngleSource::GetPIDSourceType() const
{
    return this->m_pidSource;
}