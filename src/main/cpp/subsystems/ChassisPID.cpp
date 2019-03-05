/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ChassisPID.h"

#include "RobotMap.h"

#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

#define CLIP(value) ((value <= 0.1 && value >= -0.1) ? 0 : value)

ChassisPID::ChassisPID()
    : PIDSubsystem("ChassisPID", 1.0, 0.0, 0.0)
{
    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
    // Define Chassis
    this->right_front = new WPI_TalonSRX(CHASSIS_RIGHT_FRONT);
    this->right_rear = new WPI_TalonSRX(CHASSIS_RIGHT_REAR);
    this->left_front = new WPI_TalonSRX(CHASSIS_LEFT_FRONT);
    this->left_rear = new WPI_TalonSRX(CHASSIS_LEFT_REAR);

    this->right = new SpeedControllerGroup(*this->right_front, *this->right_rear);
    this->left = new SpeedControllerGroup(*this->left_front, *this->left_rear);

    this->drive = new DifferentialDrive(*this->right, *this->left);

    // PID stuff
    this->navx = new AHRS(SPI::Port::kMXP);

    // PID angle
    this->angle_source = new AngleSource();
    this->angle_output = new AngleOutput();

    this->anglePID = new PIDController(0.013, 0, 0.02, 0, this->angle_source, this->angle_output, 0.02); //Robot::m_chassis.GetAnglePIDMode(20);

    this->anglePID->SetInputRange(-180, 180);
    this->anglePID->SetOutputRange(-1, 1);
    this->anglePID->SetAbsoluteTolerance(0.5);
    this->anglePID->SetContinuous(true);

    this->angle = 0;
}

double ChassisPID::ReturnPIDInput()
{
    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    return this->GetNavx()->GetYaw();
}

void ChassisPID::UsePIDOutput(double output)
{
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    this->Drive(0, output, false);
}

void ChassisPID::InitDefaultCommand()
{
    /*
    Sets DriveByJoystick() as default command.
  */
    SetDefaultCommand(new DriveByJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ChassisPID::Drive(double mag, double rot, bool squared)
{
    /*
    See also "Drive.h".
  */
    this->drive->ArcadeDrive(mag, rot, squared);
}

void ChassisPID::Drive(Joystick *stick)
{
    /*
    See also "DriveByJoystick.h".
  */
    this->drive->ArcadeDrive(CLIP(stick->GetY()), CLIP(stick->GetX()), true); //!stick->GetRawButton(BTN_L_STICK)); // Solves Rotfus' issue
}

AHRS *ChassisPID::GetNavx()
{
    /*
    Returns (AHRS*) NavX.
  */
    return this->navx;
}

PIDController *ChassisPID::GetAnglePID()
{
    /*
    Returns (PIDController*) Angle PID Controller.
  */
    return this->anglePID;
}

double ChassisPID::GetNavxAngle()
{
    /*
    Returns (double) navX's current yaw.
  */
    return this->navx->GetYaw();
}

void ChassisPID::SetAngleOutput(double angle)
{
    /*
    Sets Angle PID output.

    (double) angle -> angle.
  */
    this->angle = angle;
}

double ChassisPID::GetAngleOutput()
{
    /*
    Gets Angle PID output.

    Returns (double) angle.
  */
    return this->angle;
}