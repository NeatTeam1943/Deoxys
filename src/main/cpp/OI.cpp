/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"

using namespace frc;
#include <frc/WPILib.h>

OI::OI() {
  // Process operator interface input here.
  this->stick = new Joystick(0); // Todo: a non-issue, to be fixed in the near future.

  for (int i = 0; i < 10; i++)
  {
    this->buttons[i] = new JoystickButton(this->stick, i+1);
  }

  // Buttons
  this->buttons[BTN_X]->WhileHeld(new DriveStraight(1));
}

Joystick* OI::GetStick() {
  return this->stick;
}