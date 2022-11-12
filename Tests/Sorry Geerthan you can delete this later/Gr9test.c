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

void stable_arm(){
	motor[armLeft] = 0 + 0.1 * (motor[backRight] - motor[backLeft])/2;
	motor[armRight] = 0 - 0.1 * (motor[backRight] - motor[backLeft])/2;
}
task main(){

//Initialization
	clearTimer(T1);
		motor[backRight] = -0;
				motor[backLeft] = 0;
				motor[frontRight] = -0;
				motor[frontLeft] = 0;
	while(time1[T1] < 1100){
		motor[armLeft] = 127;
		motor[armRight] = -127;

		}
		if (time1[T1] > 500){
			motor[armLeft] = 0 + 0.2 * (motor[backRight] - motor[backLeft])/2;
			motor[armRight] = 0 - 0.2 * (motor[backRight] - motor[backLeft])/2;
		}

	}
