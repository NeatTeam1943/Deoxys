/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Computer's Ports
#define JOYTICK_PORT 0

// CAN Ports
#define CHASSIS_RIGHT_FRONT 5
#define CHASSIS_RIGHT_REAR 6
#define CHASSIS_LEFT_FRONT 3
#define CHASSIS_LEFT_REAR 4

#define INTAKE_ROLLER 1
#define INTAKE_LIFT 2

#define CONVEYOR_FIRST 7
#define CONVEYOR_SECOND 8

// PWM Ports
#define CAMERA_VERTICAL_SERVO 1
#define CAMERA_HORIZONTAL_SERVO 0

// PCM Ports
#define OPEN_PISTON 1
#define CLOSE_PISTON 0

// DIO Ports
#define LOADING_SWITCH 1

// Joystick Buttons Ports
#define BTN_A 0 // Outtake
#define BTN_B 1 // Intake
#define BTN_X 2 // Open / Close Piston
#define BTN_Y 3
#define BTN_BUMPER_L 4 // Shoot slow
#define BTN_BUMPER_R 5 // Shoot
#define BTN_SELECT 6
#define BTN_START 7
#define BTN_L_STICK 8 // Drive slow
#define BTN_R_STICK 9 // Reset Camera

// Stick Ports
#define AXIS_LEFT_X 1        // DO NOT USE!!!
#define AXIS_LEFT_Y 0        // DO NOT USE!!!
#define AXIS_LEFT_TRIGGER 2  // Lift down
#define AXIS_RIGHT_TRIGGER 3 // Lift up
#define AXIS_RIGHT_X 4       // Camera Horizontal
#define AXIS_RIGHT_Y 5       // Camera Vertical

// Constants
#define vertical_middle 25
#define horizontal_middle 85
