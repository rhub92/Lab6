/*
* Lab 6: PWM - "Robot Motion"
*
* Author: Ryan Hub
*
* Date: 26 November 2013
*
* Purpose: The purpose of this lab is to create a robot movement library that we can use to make the robot move in the following directions: forward,
* backwards, sharp left, sharp right, left, and right. These movements will be utilized in future labs to help our robot navigate through
* a maze by itself.
*
* Documentation: I received help on this lab from Captain Branchflower for the specific OUTMOD's I should be using in making the motors turn in
* the different directions.
*/


#include "motorMovement.h"


int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    initMotorTimer();						//Initializes the timer on the motors


    // Implements a loop of the robots motion by moving the robot in a certain direction for a second and a half and then stopping the robot
    // for a second and a half. The order of the robot's direction is forward, backwards, sharp left, sharp right, left, and then right.
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




