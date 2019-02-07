/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() : Subsystem("ExampleSubsystem") {
  this->roller = new VictorSP(INTAKE_ROLLER);
  this->lift = new VictorSP(INTAKE_LIFT);
}

void Intake::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
    //SetDefaultCommand(new Lift());
  //cout << "init command" << endl;
  //SetDefaultCommand(new Lift());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::SetRoller(double power)
{
  this->roller->Set(power);
}

void Intake::SetLift(double power)
{
  this->lift->Set(power);
}