/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
using namespace frc;
#include <frc/WPILib.h>
#include "../RobotMap.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "../commands/Vision/GetData.h"
#include "ctre/Phoenix.h"

#include "PID/VisionAngleOutput.h"
#include "PID/VisionAngleSource.h"

class Vision : public frc::Subsystem
{
  private:
    NetworkTable *table;
    double distance, alpha;

    PIDController *anglePID;
    PIDSource *angle_source;
    PIDOutput *angle_output;
    double angle;

  public:
    Vision();
    void InitDefaultCommand() override;

    double GetDistance();
    double GetAlpha();
    void SetValues(double distance, double alpha);

    void SetAngleOutput(double angle);
    double GetAngleOutput();
    PIDController *GetAnglePIDMode(int mode);
    void SetAnglePIDMode(int mode);
    PIDController *GetAnglePID();
};