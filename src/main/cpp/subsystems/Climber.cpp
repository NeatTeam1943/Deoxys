/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"

Climber::Climber() : Subsystem("ExampleSubsystem")
{
    this->comp = new Compressor(0);
    this->comp->SetClosedLoopControl(false);
    this->ds = new DoubleSolenoid(OPEN_PISTON, CLOSE_PISTON);
    this->ds->Set(frc::DoubleSolenoid::Value::kOff);
    this->is_open = false;
    this->is_enabled = false;
}

void Climber::InitDefaultCommand()
{
    // No init default command for now.
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Climber::ChangeState()
{
    /*
    Changes the state of the piston.
    */

    if (is_open)
        this->ds->Set(DoubleSolenoid::Value::kForward);
    else
        this->ds->Set(DoubleSolenoid::Value::kReverse);
    this->is_open = !this->is_open;
}

bool Climber::GetIsOpen()
{
    return this->is_open;
}

void Climber::Close()
{
    /*
    Sets piston's state to off.
    */

    this->ds->Set(DoubleSolenoid::Value::kOff);
}

void Climber::ChangeCompressor()
{
    this->comp->SetClosedLoopControl(!this->is_enabled);
    this->is_enabled = !this->is_enabled;
}