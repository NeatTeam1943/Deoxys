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
#include "RobotMap.h"
#include "ctre/Phoenix.h"

/*
    For functions' documentation, see also "Conveyor.cpp".

    (VictorSP*) launcher1
                launcher2 -> launches / shoots / ejects / conveys / whatever Cargo.
*/

class Conveyor : public frc::Subsystem
{
  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    WPI_VictorSPX *launcher1;
    WPI_VictorSPX *launcher2;
    DigitalInput *loadingSwitch;

  public:
    Conveyor();
    void InitDefaultCommand() override;
    void SetLauncher1(double power);
    void SetLauncher2(double power);
    bool IsLoaded();
};