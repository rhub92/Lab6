/*
 * motorMovement.c
 *
 *  Created on: Nov 20, 2013
 *      Author: c15ryan.hub
 */

#include "motorMovement.h"

/*
 * Subroutine Name: initMotorTimer
 * Author: Ryan Hub
 * Function:intializes the timer on the motors
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void initMotorTimer() {

	// Initializes the pins on the MSP430
    P1DIR |= BIT2;
    P1SEL |= BIT2;

    P1DIR |= BIT1;
    P1SEL |= BIT1;

    P2DIR |= BIT0;
    P2SEL |= BIT0;

    P2DIR |= BIT1;
    P2SEL |= BIT1;

    // Stop timer A0
    TA0CTL &= ~(MC1|MC0);
    TA1CTL &= ~(MC1|MC0);

    // Clear timer A0
    TA0CTL |= TACLR;
    TA1CTL |= TACLR;

    // Configure for SMCLK
    TA0CTL |= TASSEL1;
    TA1CTL |= TASSEL1;

    // Sets the signal period to 100 clock cycles and
    // initializes the duty cycles to 0
    TA0CCR0 = 100;
    TA0CCR1 = 0;
    TA1CCR0 = 100;
    TA1CCR1 = 0;

    // Sets TACCTL0 to reset mode and TACCTL1 to reset/set mode
    TA0CCTL0 |= OUTMOD_5;
    TA0CCTL1 |= OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;

    // Count up
    TA0CTL |= MC0;
    TA1CTL |= MC0;
}

/*
 * Subroutine Name: leftMotorForward
 * Author: Ryan Hub
 * Function:moves the left motor forward
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void leftMotorForward() {
	TA0CCTL0 |= OUTMOD_5;
	_delay_cycles(10000);
    TA0CCR1 = 60;
}

/*
 * Subroutine Name: rightMotorForward
 * Author: Ryan Hub
 * Function:moves the right motor forward
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void rightMotorForward() {
	TA1CCTL0 |= OUTMOD_5;
	_delay_cycles(10000);
    TA1CCR1 = 60;
}

/*
 * Subroutine Name: leftMotorBackwards
 * Author: Ryan Hub
 * Function:moves the left motor backwards
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void leftMotorBackwards() {
	TA0CCTL0 &= ~OUTMOD0;
	TA0CCTL0 |= OUTMOD_4;
	_delay_cycles(10000);
	TA0CCR1 = 0;
}

/*
 * Subroutine Name: rightMotorBackwards
 * Author: Ryan Hub
 * Function:moves the right motor backwards
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void rightMotorBackwards() {
	TA1CCTL0 &= ~OUTMOD0;
	TA1CCTL0 |= OUTMOD_4;
	_delay_cycles(10000);
	TA1CCR1 = 0;
}

/*
 * Subroutine Name: moveRobotForward
 * Author: Ryan Hub
 * Function:moves the robot forward
 * Inputs: none
 * Outputs: none
 * Subroutines used: leftMotorForward, rightMotorForward
 */

void moveRobotForward() {
	leftMotorForward();
	rightMotorForward();
}

/*
 * Subroutine Name: moveRobotBackwards
 * Author: Ryan Hub
 * Function:moves the robot backwards
 * Inputs: none
 * Outputs: none
 * Subroutines used: leftMotorBackwards, rightMotorBackwards
 */

void moveRobotBackwards() {
	leftMotorBackwards();
	rightMotorBackwards();
}

/*
 * Subroutine Name: stopRobot
 * Author: Ryan Hub
 * Function: stops the robot
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void stopRobot() {
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;

    TA0CCR1 = 0;
    TA1CCR1 = 0;
}

/*
 * Subroutine Name: moveRobotSharpLeft
 * Author: Ryan Hub
 * Function: makes the robot do a sharp left
 * Inputs: none
 * Outputs: none
 * Subroutines used: leftMotorBackwards, rightMotorForward
 */

void moveRobotSharpLeft() {
	rightMotorForward();
	leftMotorBackwards();
}

/*
 * Subroutine Name: moveRobotSharpRight
 * Author: Ryan Hub
 * Function: makes the robot do a sharp right
 * Inputs: none
 * Outputs: none
 * Subroutines used: rightMotorBackwards, leftMotorForward
 */

void moveRobotSharpRight() {
	leftMotorForward();
	rightMotorBackwards();
}

/*
 * Subroutine Name: moveRobotLeft
 * Author: Ryan Hub
 * Function: makes the robot turn left
 * Inputs: none
 * Outputs: none
 * Subroutines used: rightMotorForward
 */

void moveRobotLeft() {
	rightMotorForward();
}

/*
 * Subroutine Name: moveRobotRight
 * Author: Ryan Hub
 * Function: makes the robot turn right
 * Inputs: none
 * Outputs: none
 * Subroutines used: leftMotorForward
 */

void moveRobotRight() {
	leftMotorForward();
}
