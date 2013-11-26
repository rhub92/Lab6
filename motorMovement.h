/*
 * motorMovement.h
 *
 * Author: Ryan Hub
 *
 * Function: This provides the function prototypes used for the code necessary to make the robot move in the directions we want it to move in
 */

#include <msp430.h>

// Initializes the timer on the motors

void initMotorTimer();

// Moves the left motor forward

void leftMotorForward();

// Moves the right motor forward

void rightMotorForward();

// Moves the left motor backwards

void leftMotorBackwards();

// Moves the right motor backwards

void rightMotorBackwards();

// Moves the robot forward

void moveRobotForward();

// Moves the robot backwards

void moveRobotBackwards();

// Makes the robot execute a sharp left

void moveRobotSharpLeft();

// Makes the robot execute a sharp right

void moveRobotSharpRight();

// Turns the robot left

void moveRobotLeft();

// Turns the robot right

void moveRobotRight();

// Stops the robot

void stopRobot();
