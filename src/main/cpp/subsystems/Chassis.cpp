/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.Gigi was here.                       */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"
#include "RobotMap.h"

#include <math.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

#define CLIP(value) ((value <= 0.1 && value >= -0.1) ? 0 : value)

Chassis::Chassis() : Subsystem("ExampleSubsystem")
{
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

    // Temporary
    this->forwardLimitSwitch = new DigitalInput(0);
}

bool Chassis::GetSwitchPressed()
{
    /*
    temporary, used to get value of switch.

    Returns (bool) - is Switch pressed.
  */

    return this->forwardLimitSwitch->Get();
}

void Chassis::InitDefaultCommand()
{
    /*
    Sets DriveByJoystick() as default command.
  */
    SetDefaultCommand(new DriveByJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::Drive(double mag, double rot, bool squared)
{
    /*
    See also "Drive.h".
  */
    this->drive->ArcadeDrive(mag, rot, squared);
}

void Chassis::Drive(Joystick *stick)
{
    /*
    See also "DriveByJoystick.h".
  */
    this->drive->ArcadeDrive(CLIP(stick->GetY()), CLIP(stick->GetX()), true); //!stick->GetRawButton(BTN_L_STICK)); // Solves Rotfus' issue
}

AHRS *Chassis::GetNavx()
{
    /*
    Returns (AHRS*) NavX.
  */
    return this->navx;
}

PIDController *Chassis::GetAnglePID()
{
    /*
    Returns (PIDController*) Angle PID Controller.
  */
    return this->anglePID;
}

double Chassis::GetNavxAngle()
{
    /*
    Returns (double) navX's current yaw.
  */
    return this->navx->GetYaw();
}

void Chassis::SetAngleOutput(double angle)
{
    /*
    Sets Angle PID output.

    (double) angle -> angle.
  */
    this->angle = angle;
}

double Chassis::GetAngleOutput()
{
    /*
    Gets Angle PID output.

    Returns (double) angle.
  */
    return this->angle;
}

PIDController *Chassis::GetAnglePIDMode(int mode)
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
        return new PIDController(0.013, 0, 0.02, 0, this->angle_source, this->angle_output, 0.02);

    else if (mode == 5)
        return new PIDController(0.04, 0, 0.025, 0, this->angle_source, this->angle_output, 0.02);

    else if (mode == 2)
        return new PIDController(0.065, 0, 0.0388, 0, this->angle_source, this->angle_output, 0.02);

    return new PIDController(0, 0, 0, 0, this->angle_source, this->angle_output, 0.02);
}

void Chassis::SetAnglePIDMode(int mode)
{
    /*
    Changes Angle PID Modes. See also "Chassis::GetAnglePIDMode".

    (int) mode -> PID mode (2/5/20)
    */

    if (mode == 20)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.013);
        Robot::m_chassis.GetAnglePID()->SetD(0.02);
    }

    else if (mode == 5)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.04);
        Robot::m_chassis.GetAnglePID()->SetD(0.025);
    }

    else if (mode == 2)
    {
        Robot::m_chassis.GetAnglePID()->SetP(0.065);
        Robot::m_chassis.GetAnglePID()->SetD(0.0388);
    }
}