/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/PIDSubsystem.h>

using namespace frc;
#include <frc/WPILib.h> // must come after another include
#include "commands/Chassis/DriveByJoystick.h"

#include "AHRS.h"
#include "ctre/Phoenix.h"

#include "PID/AngleOutput.h"
#include "PID/AngleSource.h"

class ChassisPID : public frc::PIDSubsystem
{
  private:
    WPI_TalonSRX *right_front;
    WPI_TalonSRX *right_rear;
    WPI_TalonSRX *left_front;
    WPI_TalonSRX *left_rear;
    SpeedControllerGroup *right;
    SpeedControllerGroup *left;
    DifferentialDrive *drive;

    AHRS *navx;

    PIDController *anglePID;
    PIDSource *angle_source;
    PIDOutput *angle_output;
    double angle;

  public:
    ChassisPID();
    void InitDefaultCommand() override;
    void Drive(double mag, double rot, bool squared);
    void Drive(Joystick *stick);
    double ReturnPIDInput();
    void UsePIDOutput(double output);
    AHRS *GetNavx();
    double GetNavxAngle();
    void SetAngleOutput(double angle);
    double GetAngleOutput();
    PIDController *GetAnglePIDMode(int mode);
    void SetAnglePIDMode(int mode);
    PIDController *GetAnglePID();
};
