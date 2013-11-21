#include "motorMovement.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    initMotorTimer();


    while (1) {
    	moveRobotForward();
    	//leftMotorBackwards();
    	//rightMotorBackwards();


    	//moveRobotBackwards();
    	_delay_cycles(1000000);
    	stopRobot();
    	_delay_cycles(1000000);

    }
    return 0;
}
