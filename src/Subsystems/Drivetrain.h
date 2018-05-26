/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <ctre/phoenix.h>

class Drivetrain : public frc::Subsystem
{
   private:
   WPI_TalonSRX * m_lMotorFront = new WPI_TalonSRX(5);
   WPI_TalonSRX * m_lMotorBack = new WPI_TalonSRX(4);
   WPI_TalonSRX * m_rMotorFront = new WPI_TalonSRX(3);
   WPI_TalonSRX * m_rMotorBack = new WPI_TalonSRX(2);
   double m_deadband = 0.2;

   public:
      Drivetrain();
      void InitDefaultCommand() override;
      void LeftDrive(double speed);
      void RightDrive(double speed);
      void ArcadeDrive(double xSpeed, double zRotation);
};

