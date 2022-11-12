#pragma config(Motor,  port1,           armRight,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           baseRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           baseLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          armLeft,       tmotorVex393_HBridge, openLoop, reversed)

task main()
{
	//AUTONOMOUS
	clearTimer(T1);
	while (time1[T1] < 2000) {
		if (time1[T1] < 1200) {
			// Lifts arm
			motor[armLeft] = 127;
			motor[armRight] = 127;
		}
		else {
			// Stops arm
			motor[armRight] = 0;
			motor[armLeft] = 0;
		}

		if (time1[T1] > 600) {
			// Lifts mobile base
			motor[baseLeft] = 127;
			motor[baseRight] = 127;
		}

		if (time1[T1] > 1150) {
			// Moves forward
			motor[frontLeft] = 127;
			motor[frontRight] = -127;
			motor[backLeft] = 127;
			motor[backRight] = -127;
		}

	}

	wait1Msec(1000);

	// Picks up mobile base
	motor[baseLeft] = -127;
	motor[baseRight] = -127;

	wait1Msec(800);

	motor[armLeft] = 127;
	motor[armRight] = 127;

	wait1Msec(300);

	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[backRight] = 0;

	wait1Msec(400);

	motor[armLeft] = 0;
	motor[armRight] = 0;

	wait1Msec(1200);

	// Places cone on mobile base
	motor[armLeft] = -50;
	motor[armRight] = -50;

	wait1Msec(800);

	// Drives backwards
	motor[frontLeft] = -40;
	motor[frontRight] = 127;
	motor[backLeft] = -40;
	motor[backRight] = 127;

	wait1Msec(1500);

	motor[frontLeft] = 10;
	motor[frontRight] = 127;
	motor[backLeft] = 0;
	motor[backRight] = 127;

	wait1Msec(2500);

	motor[frontLeft] = 127;
	motor[frontRight] = 127;
	motor[backLeft] = 127;
	motor[backRight] = 127;

	motor[baseLeft] = 0;
	motor[baseRight] = 0;

	// TURNING

	wait1Msec(1650);

	motor[armLeft] = 0;
	motor]armRight] = 0;

	// Curve
	motor[frontLeft] = 15;
	motor[frontRight] = -127;
	motor[backLeft] = 15;
	motor[backRight] = -127;

	// Releases claw
	motor[claw] = -127;

	wait1Msec(2600);

	motor[frontLeft] = -127;
	motor[frontRight] = -127;
	motor[backLeft] = -127;
	motor[backRight] = -127;

	wait1Msec(200);

	// Charges over bumps
	motor[frontLeft] = 127;
	motor[frontRight] = -127;
	motor[backLeft] = 127;
	motor[backRight] = -127;

	wait1Msec(2500);

	// Stops
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[backRight] = 0;

	wait1Msec(500);

	// Raises arm
	motor[arm] = 127;

	wait1Msec(600);


	// Extends mobile base
	motor[baseLeft] = 127;
	motor[baseRight] = 127;

	wait1Msec(600);

	motor[arm] = 0;

	wait1Msec(500);

	motor[baseLeft] = 0;
	motor[baseRight] = 0;

	// Pulls out leaving mobile base
	motor[frontLeft] = -127;
	motor[frontRight] = 127;
	motor[backLeft] = -127;
	motor[backRight] = 127;

	wait1Msec(1000);



	/*
	// Teleop
	while(true){
			bool clawClosed = true;
			motor[frontLeft] = (vexRT[Ch2] - vexRT[Ch4]);
			motor[backLeft] = (vexRT[Ch2] - vexRT[Ch4]);
			motor[frontRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);
			motor[backRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);

			motor[baseLeft] = (vexRT[Ch4Xmtr2]); // left joystick for mobile base
			motor[baseRight] = (vexRT[Ch4Xmtr2]);

			motor[armLeft] = (vexRT[Ch2Xmtr2]); // right joystick for arm
			motor[armRight] = (vexRT[Ch2Xmtr2]);

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

			else if (clawClosed == true){
				motor[clawLeft] = 15;
				motor[clawRight] = 15;
			}

			else
	}
	*/


}
