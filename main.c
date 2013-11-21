#include "motorMovement.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    initMotorTimer();
    leftMotorForward();
    rightMotorForward();

    while (1) {}
    return 0;
}
