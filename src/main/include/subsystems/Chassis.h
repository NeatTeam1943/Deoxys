/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

using namespace frc;
#include <frc/WPILib.h> // must come after another include
#include "commands/Chassis/DriveByJoystick.h"

#include "AHRS.h"

#include "PID/AngleOutput.h"
#include "PID/AngleSource.h"
#include "PID/VelocityOutput.h"
#include "PID/VelocitySource.h"

/*
    For functions' documentation, see also "Chassis.cpp".

    (VictorSP*)             right_front
                            right_rear
                            left_front
                            left_rear
    (SpeedControllerGroup*) right
                            left
    (DifferentialDrive*)    drive           -> You do know what they do, right?
    (AHRS*)                 navx            -> An almost-perfect gyro, and a pretty-awful accelerometer.
    
    (PIDController*)        anglePID
                            velocityPID     -> PID Controllers for 2 parameters (note that velocity might change to accel.)
    (PIDSource*)            angle_source
                            velocity_source -> Source for PID input.
    (PIDOutput*)            angle_output
                            velocity_output -> Destination for PID output.
    (double)                angle
                            velocity        -> Keeps the cur value, controlled by PID Loop.
*/

class Chassis : public frc::Subsystem {
  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    VictorSP* right_front;
    VictorSP* right_rear;
    VictorSP* left_front;
    VictorSP* left_rear;
    SpeedControllerGroup* right;
    SpeedControllerGroup* left;
    DifferentialDrive* drive;

    AHRS* navx;

    PIDController* anglePID;
    PIDSource* angle_source;
    PIDOutput* angle_output;
    double angle;

    PIDController* velocityPID;
    PIDSource* velocity_source;
    PIDOutput* velocity_output;
    double velocity;

    // temporary
    DigitalInput *forwardLimitSwitch;


  public:
    Chassis();
    void InitDefaultCommand() override;
    void Drive(double mag, double rot, bool squared);
    void Drive(Joystick* stick);

    AHRS* GetNavx();

    double GetNavxAngle();
    void SetAngleOutput(double angle);
    double GetAngleOutput();
    PIDController* GetAnglePIDMode(int mode);
    void SetAnglePIDMode(int mode);
    PIDController* GetAnglePID();
    
    double GetNavxVelocityX();
    double GetNavxVelocityY();
    double GetNavxVelocity();
    void SetVelocityOutput(double velocity);
    double GetVelocityOutput();
    PIDController* GetVelocityPID();
    
    // temp
    bool GetSwitchPressed();
};
