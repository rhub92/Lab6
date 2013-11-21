/*
 * motorMovement.c
 *
 *  Created on: Nov 20, 2013
 *      Author: c15ryan.hub
 */

#include "motorMovement.h"

void initMotorTimer() {

    P1DIR |= BIT2;
    P1SEL |= BIT2;

    P1DIR |= BIT1;
    P1SEL |= BIT1;

    P2DIR |= BIT0;
    P2SEL |= BIT0;

    P2DIR |= BIT1;
    P2SEL |= BIT1;

    TA0CTL &= ~(MC1|MC0);
    TA1CTL &= ~(MC1|MC0);

    TA0CTL |= TACLR;
    TA1CTL |= TACLR;

    TA0CTL |= TASSEL1;
    TA1CTL |= TASSEL1;

    TA0CCR0 = 100;
    TA0CCR1 = 0;
    TA1CCR0 = 100;
    TA1CCR1 = 0;

    TA0CCTL0 |= OUTMOD_5;
    TA0CCTL1 |= OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;
    TA1CTL |= MC0;
}

void leftMotorForward() {
	TA0CCTL0 |= OUTMOD_5;
	_delay_cycles(10000);
    TA0CCR1 = 60;
}

void rightMotorForward() {
	TA1CCTL0 |= OUTMOD_5;
	_delay_cycles(10000);
    TA1CCR1 = 60;
}

void leftMotorBackwards() {
	TA0CCTL0 &= ~OUTMOD0;
	TA0CCTL0 |= OUTMOD_4;
	_delay_cycles(10000);
	TA0CCR1 = 0;
}

void rightMotorBackwards() {
	TA1CCTL0 &= ~OUTMOD0;
	TA1CCTL0 |= OUTMOD_4;
	_delay_cycles(10000);
	TA1CCR1 = 0;
}

void moveRobotForward() {
	leftMotorForward();
	rightMotorForward();
}

void moveRobotBackwards() {
	leftMotorBackwards();
	rightMotorBackwards();
}

void stopRobot() {
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;

    TA0CCR1 = 0;
    TA1CCR1 = 0;
}

void moveRobotSharpLeft() {
	rightMotorForward();
	leftMotorBackwards();
}

void moveRobotSharpRight() {
	leftMotorForward();
	rightMotorBackwards();
}

void moveRobotLeft() {
	rightMotorForward();
}

void moveRobotRight() {
	leftMotorForward();
}
