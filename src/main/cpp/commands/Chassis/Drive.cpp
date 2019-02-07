/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Chassis/Drive.h"

Drive::Drive(double mag, double rot, bool squared) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  this->mag = mag;
  this->rot = rot;
  this->squared = squared;
}

// Called just before this Command runs the first time
void Drive::Initialize() {
  Robot::m_chassis.Drive(0, 0, false);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
  Robot::m_chassis.Drive(this->mag, this->rot, this->squared);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() { return false; }

// Called once after isFinished returns true
void Drive::End() {
    Robot::m_chassis.Drive(0, 0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
  End();
}
