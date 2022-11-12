#pragma config(Motor,  port1,           armleft,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          armright,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true){
		motor[armright] = 0;
		motor[armleft] = 0;

		while(vexRT[Btn8U]){
			motor[armleft] = 127;
			motor[armright] = 127;
		}
		while(vexRT[Btn8D]){
			motor[armleft] = -127;
			motor[armright] = -127;
		}
	}
}