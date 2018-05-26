/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>

Drivetrain Robot::drivetrain;
OI Robot::oi;

void Robot::RobotInit()
{

}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
   frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
   frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic()
{
   frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{

}

START_ROBOT_CLASS(Robot)
