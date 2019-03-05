/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/subsystems/Vision.h"

Vision::Vision() : Subsystem("ExampleSubsystem")
{
    // PID angle
    this->angle_source = new VisionAngleSource();
    this->angle_output = new VisionAngleOutput();

    this->anglePID = Robot::m_vision.GetAnglePIDMode(5);

    this->anglePID->SetInputRange(-180, 180);
    this->anglePID->SetOutputRange(-1, 1);
    this->anglePID->SetAbsoluteTolerance(0.5);
    this->anglePID->SetContinuous(true);

    this->angle = 0;
}

void Vision::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new GetData());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Vision::SetValues(double distance, double alpha)
{
    this->distance = distance;
    this->alpha = alpha;
}

double Vision::GetDistance()
{
    return this->distance;
}

double Vision::GetAlpha()
{
    return this->alpha;
}

PIDController *Vision::GetAnglePID()
{
    /*
    Returns (PIDController*) Angle PID Controller.
  */
    return this->anglePID;
}

void Vision::SetAngleOutput(double angle)
{
    /*
    Sets Angle PID output.

    (double) angle -> angle.
  */
    this->angle = angle;
}

double Vision::GetAngleOutput()
{
    /*
    Gets Angle PID output.

    Returns (double) angle.
  */
    return this->angle;
}

PIDController *Vision::GetAnglePIDMode(int mode)
{
    /*
    Sets PID values of angle loop, based on 3 existing modes:
    * mode 2 - difference of MAX 2 degrees between PID target and cur real angle.
    * mode 5 - 2 < difference <= 5
    * mode 20 - difference > 5

    (int) mode -> PID mode (2/5/20)

    Returns (PIDController*) with correct values.
  */

    if (mode == 20)
        return new PIDController(0.0139, 0, 0.019, 0, this->angle_source, this->angle_output, 0.02);

    else if (mode == 5)
        return new PIDController(0.045, 0, 0.026, 0, this->angle_source, this->angle_output, 0.02);

    else if (mode == 2)
        return new PIDController(0.0918, 0, 0.052, 0, this->angle_source, this->angle_output, 0.02);

    return new PIDController(0, 0, 0, 0, this->angle_source, this->angle_output, 0.02);
}

void Vision::SetAnglePIDMode(int mode)
{
    /*
    Changes Angle PID Modes. See also "Chassis::GetAnglePIDMode".

    (int) mode -> PID mode (2/5/20)
    */

    if (mode == 20)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.0139);
        Robot::m_chassis.GetAnglePID()->SetD(0.019);
    }

    else if (mode == 5)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.045);
        Robot::m_chassis.GetAnglePID()->SetD(0.026);
    }

    else if (mode == 2)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.0918);
        Robot::m_chassis.GetAnglePID()->SetD(0.052);
    }
}