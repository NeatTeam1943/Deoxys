/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "../../Robot.h"

using namespace frc;
#include <frc/WPILib.h>

/*
    Controlls Robot's chassis with a joystick.

    (Joystick*) stick -> surprise surprise - it is the god damn joystick.
*/

class DriveByJoystick : public frc::Command
{
  private:
    Joystick *stick;

  public:
    DriveByJoystick();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
