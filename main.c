#include "motorMovement.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    initMotorTimer();

    while (1) {

    	moveRobotForward();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);


    	moveRobotBackwards();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);


    	moveRobotSharpLeft();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);


    	moveRobotSharpRight();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);

    	moveRobotLeft();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);

    	moveRobotRight();
    	_delay_cycles(1500000);
    	stopRobot();
    	_delay_cycles(1500000);

    }
    return 0;
}
