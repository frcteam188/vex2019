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
/*
//Initialization
	clearTimer(T1);
	while(time1[T1] < 2000){
		motor[armLeft] = 127;
		motor[armRight] = -127;
		if (time1[T1] > 600){
			motor[baseLeft] = -127;
			motor[baseRight] = 127;
		}
		if (time1[T1] > 1600){
			motor[armLeft] = 5;
			motor[armRight] = -5;
		}
		if (time1[T1] > 1500){
				motor[backRight] = -127;
				motor[backLeft] = 127;
				motor[frontRight] = -127;
				motor[frontLeft] = 127;
		}
	}
// Moving forward
	clearTimer(T1);
	while (time1[T1] < 1200){
		motor[backRight] = -127;
		motor[backLeft] = 127;
		motor[frontRight] = -127;
		motor[frontLeft] = 127;
	}

// Picking up mobile base
	clearTimer(T1);
	while (time1[T1] < 1500){
		if (time1[T1] < 1000){
		motor[baseLeft] = 127;
		motor[baseRight] = -127;
		}
	}

// Turning
	clearTimer(T1);
	while (time1[T1] < 000){
			motor[backRight] = 127;
			motor[backLeft] = -127;
			motor[frontRight] = 127;
			motor[frontLeft] = -127;
	}
	clearTimer(T1);
	while (time1[T1] < 000){
		motor[backRight] = 127;
		motor[backLeft] = -127 + 100;
		motor[frontRight] = 127;
		motor[frontLeft] = -127 + 100;
	}
	clearTimer(T1);

	while (time1[T1] < 2000){
			motor[backRight] = 127;
			motor[backLeft] = 127;
			motor[frontRight] = 127;
			motor[frontLeft] = 127;
	}
/*
// Moving forward while moving arm up
	while (time1[T1] < 500){
		motor[armLeft] = -50; // move arm down
		motor[armRight] = -50;
		motor[backRight] = -127; //movement
		motor[backLeft] = 127;
		motor[frontRight] = -127;
		motor[frontLeft] = 127;
	}
// moving forward while dropping cone
	while (time1[T1] < 500){
		motor[armLeft] = 20; // apply constant pressure to stabilize arm
		motor[armRight] = 20;
		motor[backRight] = -127; // movement
		motor[backLeft] = 127;
		motor[frontRight] = -127;
		motor[frontLeft] = 127;
		motor[clawLeft] = -127; // drop cone
		motor[clawRight] = -127;
	}
	/*
		// moving forward
		while (time1[T1] < 1000){
			motor[backRight] = -127;
			motor[backLeft] = 127;
			motor[frontRight] = -127;
			motor[frontLeft] = 127;
		}
	*/
	// Dropping mobile base
	/*clearTimer(T1);
	while (time1[T1] < 500){
		motor[baseLeft] = -127;
		motor[baseRight] = -127;
	}
	while (time1[T1] < 1000){
		motor[backRight] = 127;
		motor[backLeft] = -127;
		motor[frontRight] = 127;
		motor[frontLeft] = -127;
	}
	*/
	motor[clawLeft] = 30;
	motor[clawRight] = 30;
	int clawClosed = 0;
	while(true){
			motor[frontLeft] = (vexRT[Ch3] + vexRT[Ch1]);
			motor[backLeft] = (vexRT[Ch3] + vexRT[Ch1]);
			motor[frontRight] = (-1*vexRT[Ch3] + vexRT[Ch1]);
			motor[backRight] = (-1*vexRT[Ch3] + vexRT[Ch1]);

			motor[baseLeft] = (vexRT[Ch3Xmtr2]); // left joystick for mobile base
			motor[baseRight] = -(vexRT[Ch3Xmtr2]);

			motor[armLeft] = (vexRT[Ch2Xmtr2]); // right joystick for arm
			motor[armRight] = -(vexRT[Ch2Xmtr2]);

			int closedButton = vexRT[Btn6DXmtr2], openButton = vexRT[Btn5DXmtr2];
			if (openButton == 1){
				motor[clawLeft] = -127;
				motor[clawRight] = -127;
				// open claw (run claw motors)
				clawClosed = 0;
			}
			else if (closedButton == 1){
				// close claw
				motor[clawLeft] = 127;
				motor[clawRight] = 127;
				clawClosed = 1;
			}
			else if (clawClosed == 1 && closedButton == 0){
				motor[clawLeft] = 15;
				motor[clawRight] = 15;
			}

			else {
				motor[clawLeft] = 0;
				motor[clawRight] = 0;
			}
	}

}
