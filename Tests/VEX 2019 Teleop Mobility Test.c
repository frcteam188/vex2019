#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port2,           backRight,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true) {
		motor[frontLeft] = (vexRT[Ch2] - vexRT[Ch4]);
		motor[backLeft] = (vexRT[Ch2] - vexRT[Ch4]);
		motor[frontRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);
		motor[backRight] = (-1*vexRT[Ch2] - vexRT[Ch4]);
	}



}