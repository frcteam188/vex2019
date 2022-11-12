#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backRight,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	while(true)
	{
		motor[frontLeft] = vexRT[3] + vexRT[1];//motor configuation is messed up, plz connect motors to motor ports
		//analog ports have to be reconfigured
		motor[frontRight] = -vexRT[3] + vexRT[1];
		motor[backLeft] = vexRT[3] + vexRT[1];
		motor[backRight] = -vexRT[3] + vexRT[1];
	}

}