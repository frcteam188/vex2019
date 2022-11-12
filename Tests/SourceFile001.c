#pragma config(Motor,  port2,           a_motor,    tmotorVex393_MC29, openLoop)
#include <stdarg.h>

int resetMotors(int motor, ...){

  va_list ap;
  int i;

  va_start (ap, count);         /* Initialize the argument list. */

  for (i = 0; i < count; i++)
    va_arg (ap, int) = 0;    /* Get the next argument value. */

  va_end (ap);
}

task main()
{
	resetMotors(motor[a_motor]);

	if (vexRT[Btn8D]){
		motor[a_motor] = 127;
	}


}
