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
#include "../commands/Intake/Lift.h"
#include "../commands/Intake/LiftByJoystick.h"

class Intake : public frc::Subsystem
{
  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    WPI_TalonSRX *roller; // Might change to Talon SRX
    WPI_TalonSRX *lift;
    Counter *counter;

  public:
    Intake();
    void InitDefaultCommand() override;
    void SetRoller(double power);
    void SetLift(double power);
    Counter *GetCounter();
};
