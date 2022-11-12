#pragma config(Motor,  port2,           leftfront,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftmidone,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftmidtwo,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftback,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightfront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightmidone,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightmidtwo,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightback,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true){
		motor[leftfront] = vexRT[Ch1] + vexRT[Ch3];
		motor[leftmidone] = vexRT[Ch1] + vexRT[Ch3];
		motor[leftmidtwo] = vexRT[Ch1] + vexRT[Ch3];
		motor[leftback] = vexRT[Ch1] + vexRT[Ch3];
		motor[rightfront] = -vexRT[Ch1] + vexRT[Ch3];
		motor[rightmidone] = -vexRT[Ch1] + vexRT[Ch3];
		motor[rightmidtwo] = -vexRT[Ch1] + vexRT[Ch3];
		motor[rightback] = -vexRT[Ch1] + vexRT[Ch3];
	}

}