/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "subsystems/Chassis.h"
#include "subsystems/Intake.h"
#include "subsystems/Conveyor.h"
#include "subsystems/Camera.h"
#include "subsystems/Climber.h"
#include "subsystems/Vision.h"
#include "subsystems/ChassisPID.h"

class OI;
class Chassis;
class Intake;
class Conveyor;
class Camera;
class Climber;
class Vision;
class ChassisPID;

class Robot : public frc::TimedRobot
{
  public:
    static OI m_oi;
    static Chassis m_chassis;
    static Intake m_intake;
    static Conveyor m_conveyor;
    static Camera m_camera;
    static Climber m_climber;
    static Vision m_vision;
    static ChassisPID m_chassisPID;

    static std::shared_ptr<NetworkTable> table;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

  private:
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc::Command *m_autonomousCommand = nullptr;
    frc::SendableChooser<frc::Command *> m_chooser;
    nt::NetworkTableInstance instance;
};