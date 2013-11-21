/*
 * motorMovement.h
 *
 *  Created on: Nov 20, 2013
 *      Author: c15ryan.hub
 */

#include <msp430.h>

void initMotorTimer();

void leftMotorForward();

void rightMotorForward();

void leftMotorBackwards();

void rightMotorBackwards();

void moveRobotForward();

void moveRobotBackwards();

void moveRobotSharpLeft();

void moveRobotSharpRight();

void moveRobotLeft();

void moveRobotRight();
