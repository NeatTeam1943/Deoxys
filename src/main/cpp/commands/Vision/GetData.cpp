/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Vision/GetData.h"

GetData::GetData()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_vision);
}

// Called just before this Command runs the first time
void GetData::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void GetData::Execute()
{
    this->distanceEntry = Robot::table->GetEntry("distance"); // distance entry
    this->alphaEntry = Robot::table->GetEntry("alpha");       // alpha entry

    double curDistance = this->distanceEntry.GetDouble(0), // distance from reflector (returns 0 by default)
        curAlpha = this->alphaEntry.GetDouble(0);          // angle from reflector (returns 0 by default)
    Robot::m_vision.SetValues(curDistance, curAlpha);      // distance from reflector (returns 0 by default)
}

// Make this return true when this Command no longer needs to run execute()
bool GetData::IsFinished() { return false; }

// Called once after isFinished returns true
void GetData::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetData::Interrupted() { End(); }
