/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PID/AngleOutput.h"

AngleOutput::AngleOutput()
{
}

void AngleOutput::PIDWrite(double output)
{
    Robot::m_chassis.SetAngleOutput(output);
}
