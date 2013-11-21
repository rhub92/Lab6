/*
 * motorMovement.c
 *
 *  Created on: Nov 20, 2013
 *      Author: c15ryan.hub
 */

#include "motorMovement.h"

void initMotorTimer() {

    P1DIR |= BIT2;
    P1DIR |= BIT1;
    //P1SEL |= BIT2;
    P2DIR |= BIT0;
    P2DIR |= BIT1;
    //P2SEL |= BIT0;
    //P1SEL |= BIT1;
    //P2SEL |= BIT1;


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


    TA0CTL |= MC0;
    TA1CTL |= MC0;
}

void leftMotorForward() {
    P1SEL |= BIT1;
    P1SEL |= BIT2;
    //P2SEL &= ~BIT0;
    //P2SEL &= ~BIT1;

	TA0CCTL0 |= OUTMOD_5;
    TA0CCTL1 |= OUTMOD_7;
    //TA1CCTL0 |= OUTMOD_7;
    //TA1CCTL1 |= OUTMOD_5;

    TA0CCR0 = 100;
    //TA1CCR1 = 0;
    TA0CCR1 = 60;
    //_delay_cycles(5000000);
    //TA0CCR1 = 0;
}

void rightMotorForward() {
    P2SEL |= BIT0;
    P2SEL |= BIT1;
    //P1SEL &= ~BIT1;
    //P1SEL &= ~BIT2;

	TA1CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;

    TA1CCR0 = 100;
    //TA0CCR1 = 0;
    TA1CCR1 = 60;
    //_delay_cycles(5000000);
    //TA1CCR1 = 0;
}

void leftMotorBackwards() {
    P1SEL |= BIT1;
    P1SEL |= BIT2;

	TA0CCTL0 |= OUTMOD_7;
    TA0CCTL1 |= OUTMOD_7;

    TA0CCR0 = 100;
    //TA1CCR1 = 0;
    TA0CCR1 = 40;
}

void rightMotorBackwards() {
    P2SEL |= BIT0;
    P2SEL |= BIT1;

	TA1CCTL0 |= OUTMOD_7;
    TA1CCTL1 |= OUTMOD_7;

    TA1CCR0 = 100;
    //TA0CCR1 = 0;
    TA1CCR1 = 40;
}

void moveRobotForward() {
	leftMotorForward();
	rightMotorForward();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}

void moveRobotBackwards() {
	leftMotorBackwards();
	rightMotorBackwards();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}

void stopRobot() {
    P2SEL &= ~BIT0;
    P2SEL &= ~BIT1;
    P1SEL &= ~BIT1;
    P1SEL &= ~BIT2;

    TA0CCR0 = 100;
    TA1CCR0 = 100;
    TA0CCR1 = 0;
    TA1CCR1 = 0;

}

void moveRobotSharpLeft() {
	rightMotorForward();
	leftMotorBackwards();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}

void moveRobotSharpRight() {
	leftMotorForward();
	rightMotorBackwards();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}

void moveRobotLeft() {
	rightMotorForward();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}

void moveRobotRight() {
	leftMotorForward();
	_delay_cycles(2000000);
	TA0CCTL0 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_7;
}
