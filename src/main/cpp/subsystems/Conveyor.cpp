/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyor.h"

Conveyor::Conveyor() : Subsystem("ExampleSubsystem")
{
    this->launcher1 = new WPI_VictorSPX(CONVEYOR_FIRST);
    this->launcher2 = new WPI_VictorSPX(CONVEYOR_SECOND);
    this->loadingSwitch = new DigitalInput(LOADING_SWITCH);
}

void Conveyor::InitDefaultCommand()
{
    // No init default command for now.
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Conveyor::SetLauncher1(double power)
{
    /*
    Sets power for Launcher1.

    (double) power -> power for launcher1.
  */
    this->launcher1->Set(power);
}

void Conveyor::SetLauncher2(double power)
{
    /*
    Sets power for Launcher2.

    (double) power -> power for launcher2.
  */
    this->launcher2->Set(power);
}

bool Conveyor::IsLoaded()
{
    return this->loadingSwitch->Get();
}