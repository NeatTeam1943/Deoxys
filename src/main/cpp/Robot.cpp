/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

OI Robot::m_oi;
Chassis Robot::m_chassis;
ChassisPID Robot::m_chassisPID;
Intake Robot::m_intake;
Conveyor Robot::m_conveyor;
Camera Robot::m_camera;
Climber Robot::m_climber;
Vision Robot::m_vision;

std::shared_ptr<NetworkTable> Robot::table;

void Robot::RobotInit()
{
    //Robot::m_oi.GetStick()->SetRumble(Robot::m_oi.GetStick()->kRightRumble, 1);

    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    this->instance = nt::NetworkTableInstance::GetDefault(); // required to get the network table
    table = this->instance.GetTable("Vision");               // set table equal to our network table named ImageProcessing

    CameraServer::GetInstance()->StartAutomaticCapture();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
    //frc::SmartDashboard::PutNumber("Distance_vision", Robot::m_vision.GetDistance());
    //frc::SmartDashboard::PutNumber("Alpha_vision", Robot::m_vision.GetAlpha());
    frc::SmartDashboard::PutBoolean("Is loaded", Robot::m_conveyor.IsLoaded());
    frc::SmartDashboard::PutNumber("Distance", Robot::m_vision.GetDistance());
    frc::SmartDashboard::PutNumber("Alpha", Robot::m_vision.GetAlpha());
    frc::SmartDashboard::PutBoolean("Compressor", Robot::m_climber.GetEnabled());
    //cout << table->GetEntry("alpha").GetDouble(0) << endl;
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
    // std::string autoSelected = frc::SmartDashboard::GetString(
    //     "Auto Selector", "Default");
    // if (autoSelected == "My Auto") {
    //   m_autonomousCommand = &m_myAuto;
    // } else {
    //   m_autonomousCommand = &m_defaultAuto;
    // }

    m_autonomousCommand = m_chooser.GetSelected();

    if (m_autonomousCommand != nullptr)
    {
        m_autonomousCommand->Start();
    }
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit()
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (m_autonomousCommand != nullptr)
    {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif
