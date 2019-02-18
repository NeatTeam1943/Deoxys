/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "../../Robot.h" // <> for a library file, "" for my own

/*
    Controlls Chassis, moves, drives, whatever.

    (double) mag     -> magnitude (-1 < mag < 1)
    (double) rot     -> rotation (-1 < rot < 1)
    (bool)   squared -> is Squared - drive slower (true/false)
*/

class Drive : public frc::Command
{
  private:
    double mag;
    double rot;
    bool squared;

  public:
    Drive(double mag, double rot, bool squared);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
