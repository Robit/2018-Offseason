/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drivetrain.h"
#include "../Commands/JoystickDrive.h"

Drivetrain::Drivetrain() :
      Subsystem("Drivetrain")
{

}

void Drivetrain::InitDefaultCommand()
{
   // Set the default command for a subsystem here.
   SetDefaultCommand(new JoystickDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::LeftDrive(double speed)
{
   m_lMotorFront->Set(speed);
   m_lMotorBack->Set(speed);
}

void Drivetrain::RightDrive(double speed)
{
   m_rMotorFront->Set(-speed);
   m_rMotorBack->Set(-speed);
}

void Drivetrain::ArcadeDrive(double xSpeed, double zRotation)
{
   double leftMotorOutput;
   double rightMotorOutput;

   if (fabs(xSpeed) <= m_deadband)
      xSpeed = 0;
   if (fabs(zRotation) <= m_deadband)
      zRotation = 0;

   double maxInput = std::copysign(std::max(std::abs(xSpeed), std::abs(zRotation)), xSpeed);

   if (xSpeed >= 0.0)
   {
      // First quadrant, else second quadrant
      if (zRotation >= 0.0)
      {
         leftMotorOutput = maxInput;
         rightMotorOutput = xSpeed - zRotation;
      }
      else
      {
         leftMotorOutput = xSpeed + zRotation;
         rightMotorOutput = maxInput;
      }
   }
   else
   {
      // Third quadrant, else fourth quadrant
      if (zRotation >= 0.0)
      {
         leftMotorOutput = xSpeed + zRotation;
         rightMotorOutput = maxInput;
      }
      else
      {
         leftMotorOutput = maxInput;
         rightMotorOutput = xSpeed - zRotation;
      }
   }
   LeftDrive(leftMotorOutput);
   RightDrive(rightMotorOutput);
}

