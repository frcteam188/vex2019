/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)
#pragma config(Motor,  port1,           backRight,     tmotorNone, openLoop)
#pragma config(Motor,  port2,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           clawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           clawRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           baseRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           baseLeft,      tmotorNone, openLoop)
#pragma config(Motor,  port9,           armLeft,       tmotorNone, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorNone, openLoop)

task main(){
// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // //Initialization
	clearTimer(T1);
	motor[clawLeft] = 20;
	motor[clawRight] = 20;

	while(time1[T1] < 2000){
		if (time1[T1] < 1170){
			motor[armLeft] = 127;
			motor[armRight] = -127;
		}
		if (time1[T1] > 600){
			motor[baseLeft] = -127;
			motor[baseRight] = 127;
		}
		if (time1[T1] > 1170){
			motor[armLeft] = 0;
			motor[armRight] = -0;
		}

		if (time1[T1] > 1200){
				motor[backRight] = -127;
				motor[backLeft] = 127;
				motor[frontRight] = -127;
				motor[frontLeft] = 127;
		}
	}
// Moving forward
	clearTimer(T1);
	while (time1[T1] < 00){
		motor[backRight] = -127;
		motor[backLeft] = 127;
		motor[frontRight] = -127;
		motor[frontLeft] = 127;
	}

// Picking up mobile base
	clearTimer(T1);
	while (time1[T1] < 1100){
		motor[baseLeft] = 127;
		motor[baseRight] = -127;
	}
	clearTimer(T1);
		//motor[backRight] = 	0;
		//motor[backLeft] = 	0;
		//motor[frontRight] = 0;
		//motor[frontLeft] = 	0;
// Turning
	clearTimer(T1);
	while (time1[T1] < 1200){
		motor[backRight] = 127;
		motor[backLeft] = -127;
		motor[frontRight] = 127;
		motor[frontLeft] = -127;
	}

	clearTimer(T1);
	int n = 30;
	while (time1[T1] < 1800){
		motor[backRight] = 127;
		motor[backLeft] = -127 + n;
		motor[frontRight] = 127;
		motor[frontLeft] = -127 + n;
		if (time1[T1] % 200 == 0 && motor[backLeft] < 127){
			n = n + 3;
		}
	}
	clearTimer(T1);
	//S-bend
	while (time1[T1] < 500){
			motor[backRight] = -30;
			motor[backLeft] = 127;
			motor[frontRight] = -30;
			motor[frontLeft] = 127;
	}
	clearTimer(T1);

// Moving forward while moving arm up
	while (time1[T1] < 2000){
		motor[armLeft] = -127; // move arm down
		motor[armRight] = 127;
		motor[backRight] = -127; //movement
		motor[backLeft] = 30;
		motor[frontRight] = -127;
		motor[frontLeft] = 30;
	}
	clearTimer(T1);

// moving forward while dropping cone
	while (time1[T1] < 500){
		motor[clawLeft] = -50; // drop cone
		motor[clawRight] = -50;
	}
	clearTimer(T1);



	// Dropping mobile base
	clearTimer(T1);
	while (time1[T1] < 1500){
		motor[armLeft] = 127;
		motor[armRight] = -127;
		if (time1[T1] > 500) {
			motor[baseLeft] = -127;
			motor[baseRight] = 127;
		}
	}
	while (time1[T1] < 200){
		motor[backRight] = 127;
		motor[backLeft] = -127;
		motor[frontRight] = 127;
		motor[frontLeft] = -127;
	}

stopAllMotors;
}
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................

			bool clawClosed = true;
			motor[frontLeft] = (vexRT[Ch2] - vexRT[Ch4]);
			motor[backLeft] = (vexRT[Ch2] - vexRT[Ch4]);
			motor[frontRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);
			motor[backRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);

			motor[baseLeft] = (vexRT[Ch4Xmtr2]); // left joystick for mobile base
			motor[baseRight] = (vexRT[Ch4Xmtr2]);

			motor[armLeft] = (vexRT[Ch2Xmtr2]); // right joystick for arm
			motor[armRight] = (vexRT[Ch2Xmtr2]);
			//motor[clawLeft] = (vexRT[Ch3Xmtr2]);
			//motor[clawRight] = (vexRT[Ch3Xmtr2]);
			int closedButton = vexRT[Btn6DXmtr2], openButton = vexRT[Btn5DXmtr2];
			if (openButton == 1){
				motor[clawLeft] = -127;
				motor[clawRight] = -127;
				// open claw (run claw motors)
				clawClosed = false;
			}
			else if (closedButton == 1){
				// close claw
				motor[clawLeft] = 127;
				motor[clawRight] = 127;
				clawClosed = true;
			}

			if (clawClosed == true){
				motor[clawLeft] = 5;
				motor[clawRight] = 5;
			}

    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();
  }
}
