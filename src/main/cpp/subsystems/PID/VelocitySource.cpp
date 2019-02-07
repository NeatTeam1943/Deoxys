/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PID/VelocitySource.h"

VelocitySource::VelocitySource() {
}

double VelocitySource::PIDGet() {
    return Robot::m_chassis.GetNavxVelocity();
}

void VelocitySource::SetPIDSourceType(PIDSourceType pidSource) {
    this->m_pidSource = pidSource;
}

PIDSourceType VelocitySource::GetPIDSourceType() const {
    return this->m_pidSource;
}