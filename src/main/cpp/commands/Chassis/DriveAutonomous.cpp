/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Chassis/DriveAutonomous.h"

DriveAutonomous::DriveAutonomous() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_chassis);
}

// Called just before this Command runs the first time
void DriveAutonomous::Initialize() {
  Robot::m_chassis.GetNavx()->ZeroYaw();
  this->file.open("/home/lvuser/p.txt");
  this->count = 0;

  // Set first PID Angle mode
  string cur_line = "";
  getline(this->file, cur_line);

  string arr [3] = { "", "", "" };
  int counter = 0;
  for (int i = 0; i < cur_line.length(); i++) {
    char c = cur_line[i];
    if (c == ' ') {
      counter++;
      continue;
    }

    arr[counter] += c;
  }
  
  double first_angle = std::stod(arr[0]);
  int angle_mode = 0;
  
  if (first_angle <= 2)
  {
    Robot::m_chassis.SetAnglePIDMode(2);
    angle_mode = 2;
  }

  else
  {
    if (first_angle <= 5) 
    {
      Robot::m_chassis.SetAnglePIDMode(5);
      angle_mode = 5;
    }
    else
    {
      Robot::m_chassis.SetAnglePIDMode(20);
      angle_mode = 20;
    }
  }

  cout << "Angle PID Mode set to " << angle_mode << ". " << endl;

  Robot::m_chassis.GetAnglePID()->SetSetpoint(0);
  Robot::m_chassis.GetAnglePID()->Enable();

  //Robot::m_chassis.GetAnglePID()->SetSetpoint(this->angle);
  //cout << "Cur: " << Robot::m_chassis.GetNavxAngle() << endl;
  //Robot::m_chassis.GetAnglePID()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveAutonomous::Execute() {
  
  string cur_line = "";
  int count = 0;

  while (!this->file.eof())
  {
    if (count == this->count)
    {
      getline(this->file, cur_line);
      break;
    }
    count++;
  }

  string arr [3] = { "", "", "" };
  int counter = 0;
  for (int i = 0; i < cur_line.length(); i++) {
    char c = cur_line[i];
    if (c == ' ') {
      counter++;
      continue;
    }

    arr[counter] += c;
  }

  // WEIRD BUG TEMP. FIX

  try
  {
    double cur_angle = std::stod(arr[0]);
    double cur_accel = std::stod(arr[2]);
    double cur_time = std::stod(arr[1]);


    if (cur_time >= this->count * 0.02) 
    {
      Robot::m_chassis.GetAnglePID()->SetSetpoint(cur_angle);
    }

    // Change PID Mode
    int angle_mode = 0;
    double difference_angle = cur_angle - Robot::m_chassis.GetNavx()->GetYaw();
    if (difference_angle < 0) { difference_angle = -1 * difference_angle; }
  
    if (difference_angle <= 2)
    {
      Robot::m_chassis.SetAnglePIDMode(2);
      angle_mode = 2;
    }

    else
    {
      if (difference_angle <= 5) 
      {
        Robot::m_chassis.SetAnglePIDMode(5);
        angle_mode = 5;
      }
      else
      {
        Robot::m_chassis.SetAnglePIDMode(20);
        angle_mode = 20;
      }
    }

    cout << "Angle PID Mode set to " << angle_mode << ". " << endl;

    Robot::m_chassis.Drive(0.25, Robot::m_chassis.GetAngleOutput(), false);

    cout << "Angle: " << Robot::m_chassis.GetNavx()->GetYaw() << ", Error:" << cur_angle - Robot::m_chassis.GetNavx()->GetYaw() << endl;
  }

  catch (exception& e)
  {
    cout << "reached end" << endl;
    End();
  }
}

// Make this return true when this Command no longer needs to run execute()
bool DriveAutonomous::IsFinished() { 

  return this->file.eof();
  //return Robot::m_chassis.GetAnglePID()->OnTarget();
}

// Called once after isFinished returns true
void DriveAutonomous::End() {
  this->file.close();
  cout << "Finished Autonomous session." << endl;
  Robot::m_chassis.GetAnglePID()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAutonomous::Interrupted() {
  End();
}
