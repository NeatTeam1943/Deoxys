/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define JOYTICK_PORT 0

// Ports - to be changed!
#define CHASSIS_RIGHT_FRONT 5
#define CHASSIS_RIGHT_REAR 6
#define CHASSIS_LEFT_FRONT 7
#define CHASSIS_LEFT_REAR 8

#define INTAKE_ROLLER 1
#define INTAKE_LIFT 2

#define CONVEYOR_FIRST 3
#define CONVEYOR_SECOND 4


// Joystick buttons ports

#define BTN_A 0 // Outtake
#define BTN_B 1 // Intake
#define BTN_X 2
#define BTN_Y 3
#define BTN_BUMPER_L 4 // Shoot slow
#define BTN_BUMPER_R 5 // Shoot
#define BTN_SELECT 6
#define BTN_START 7
#define BTN_L_STICK 8 // Drive slow
#define BTN_R_STICK 9 // Reset Camera

#define AXIS_LEFT_X 0 // DO NOT USE!!!
#define AXIS_LEFT_Y 1 // DO NOT USE!!!
#define AXIS_LEFT_TRIGGER 2 // Lift down
#define AXIS_RIGHT_TRIGGER 3 // Lift up
#define AXIS_RIGHT_X 4 // Camera sides
#define AXIS_RIGHT_Y 5 // Camera Up/Down

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
