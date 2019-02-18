/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "../../Robot.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Drive in auto mode. PID + spline stuff are involved.

    (ifstream) file -> A file, created via py file "AutonomicMovement1943", with 
                       bilions of lines, each one represents a point in the spline
                       with the following values:
                        * alpha (relative to the beginning - starts at 0) - in degrees
                        * accel (sqrt(x2+y2)) - in m/s2
                        * time (start at 0) - in sec
    (int)      time -> helps us with file loop. DO NOT TOUCH!
*/

class DriveAutonomous : public frc::Command
{
  private:
    ifstream file;
    int count;

  public:
    DriveAutonomous();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
