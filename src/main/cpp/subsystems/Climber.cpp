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
    this->comp->SetClosedLoopControl(true);
    this->ds = new DoubleSolenoid(OPEN_PISTON, CLOSE_PISTON);
    this->saver = new Solenoid(SAVER);
    this->ds->Set(frc::DoubleSolenoid::Value::kOff);
    this->saver->Set(false);
    this->mode = 0;
    this->is_enabled = true;
}

void Climber::InitDefaultCommand()
{
    // No init default command for now.
}

int Climber::GetMode()
{
    return this->mode;
}

void Climber::NextMode()
{
    this->mode = (this->mode + 1) % 3;
    if (this->mode == 0)
    {
        this->SetSaverMode(false);
        this->SetDoubleMode(frc::DoubleSolenoid::Value::kOff);
    }
    else if (this->mode == 1)
    {
        this->SetSaverMode(true);
        this->SetDoubleMode(frc::DoubleSolenoid::Value::kForward);
    }
    else
    {
        this->SetSaverMode(true);
        this->SetDoubleMode(frc::DoubleSolenoid::Value::kReverse);
    }
}

frc::DoubleSolenoid::Value Climber::GetDoubleMode()
{
    return this->ds->Get();
}

void Climber::SetDoubleMode(frc::DoubleSolenoid::Value mode)
{
    this->ds->Set(mode);
}

bool Climber::GetSaverMode()
{
    return this->saver->Get();
}

void Climber::SetSaverMode(bool mode)
{
    this->saver->Set(mode);
}

void Climber::ChangeCompressor()
{
    this->comp->SetClosedLoopControl(!this->is_enabled);
    this->is_enabled = !this->is_enabled;
}

bool Climber::GetEnabled()
{
    return this->is_enabled;
}