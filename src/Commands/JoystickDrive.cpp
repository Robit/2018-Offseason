/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "JoystickDrive.h"

JoystickDrive::JoystickDrive()
{
   // Use Requires() here to declare subsystem dependencies
   // eg. Requires(Robot::chassis.get());
   Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void JoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute()
{
   Robot::drivetrain.ArcadeDrive(Robot::oi.GetJoystick().GetRawAxis(1), -(Robot::oi.GetJoystick().GetRawAxis(4) > 0 ? 1 : -1) * Robot::oi.GetJoystick().GetRawAxis(4) * Robot::oi.GetJoystick().GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickDrive::IsFinished()
{
   return false;
}

// Called once after isFinished returns true
void JoystickDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDrive::Interrupted()
{
   Robot::drivetrain.LeftDrive(0);
   Robot::drivetrain.RightDrive(0);
}
