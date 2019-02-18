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

/*
    Used mainly during training, but can be useful in the future.
    Drives the robot in a relatively straight line, using PID to angle - target is 0 degrees.

    (double) mag -> magnitude for Drive(mag, rot, squared) - See also "Drive.h".
*/

using namespace std;
class DriveStraight : public frc::Command
{
  public:
    DriveStraight(double mag);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

  private:
    double mag;
};
