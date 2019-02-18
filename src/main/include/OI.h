/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Robot.h"
using namespace frc;
#include <frc/WPILib.h>
#include "RobotMap.h"

#include "commands/Chassis/Drive.h"
#include "commands/Chassis/DriveByJoystick.h"
#include "commands/Autonomous/DriveAutonomous.h"
#include "commands/Chassis/ResetNavX.h"
#include "commands/Chassis/DriveStraight.h"
#include "commands/Intake/Lift.h"
#include "commands/Intake/Roll.h"
#include "commands/Conveyor/Launch.h"
#include "commands/Climber/Climb.h"
#include "commands/Vision/GetData.h"
#include "commands/Autonomous/Rotate.h"
#include "commands/Autonomous/Load.h"
#include "commands/Climber/ChangeCompressor.h"

class OI
{
  private:
    Joystick *stick;
    JoystickButton *buttons[10];

  public:
    OI();
    Joystick *GetStick();
};
