/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PID/VelocityOutput.h"

VelocityOutput::VelocityOutput() {

}

void VelocityOutput::PIDWrite(double output) {
    Robot::m_chassis.SetVelocityOutput(output);
}
