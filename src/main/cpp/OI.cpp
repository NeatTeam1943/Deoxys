/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

using namespace frc;
#include <frc/WPILib.h>

OI::OI()
{
    // Process operator interface input here.
    this->stick = new Joystick(JOYTICK_PORT);

    for (int i = 0; i < 10; i++)
        this->buttons[i] = new JoystickButton(this->stick, i + 1);

    // Buttons
    //this->buttons[BTN_X]->WhileHeld(new DriveStraight(1));

    this->buttons[BTN_B]->WhileHeld(new Launch(-1));
    this->buttons[BTN_A]->WhileHeld(new Launch(-0.25));
    this->buttons[BTN_X]->WhileHeld(new Launch(0.2));

    this->buttons[BTN_BUMPER_R]->WhileHeld(new Load());
    this->buttons[BTN_BUMPER_L]->WhileHeld(new Roll(0.4));
    //this->buttons[BTN_BUMPER_L]->WhileHeld(new Roll(-0.4));

    this->buttons[BTN_START]->WhenPressed(new Climb());
    this->buttons[BTN_SELECT]->WhenPressed(new ChangeCompressor());

    //this->buttons[BTN_Y]->WhileHeld(new DriveStraight(-0.35));

    // temp. exper.
    // this->buttons[BTN_Y]->WhenPressed(new Rotate(0));
}

Joystick *OI::GetStick()
{
    return this->stick;
}