/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

using namespace frc;
#include <frc/WPILib.h>
#include "../RobotMap.h"

/*
    For functions' documentation, see also "Climber.cpp".

    (DoubleSolenoid*) ds      -> Controls the air in the pistons.
    (bool)            is_open -> Is the piston opened.
*/

class Climber : public frc::Subsystem
{
  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    Compressor *comp;
    DoubleSolenoid *ds;
    bool is_open;
    bool is_enabled;

  public:
    Climber();
    void ChangeState();
    void Close();
    void ChangeCompressor();
    void InitDefaultCommand() override;
    bool GetIsOpen();
};
