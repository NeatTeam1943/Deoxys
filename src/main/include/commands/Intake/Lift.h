/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

#include "../../Robot.h"

/*
    Controlls Robot's Intake subsystem, using Joystick's Triggers (Rotfus' idea, god knows why).

    (Joystick*) stick -> A stick that contains joy.
*/

class Lift : public frc::Command
{
  private:
    double power;

  public:
    Lift(double power);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
