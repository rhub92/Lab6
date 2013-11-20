#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer


    P1DIR |= BIT2;					// TA0CCR1 on P1.2
    P1DIR |= BIT1;
    P1SEL |= BIT2;
    P2DIR |= BIT0;
    P2DIR |= BIT1;
    P2SEL |= BIT0;

    P1OUT |= BIT1;
    P1OUT &= ~BIT2;
    P2OUT |= BIT1;
    P2OUT &= ~BIT0;


   TACTL &= ~(MC1|MC0);            // stop timer A0

    TACTL |= TACLR;                // clear timer A0

    TACTL |= TASSEL1;           // configure for SMCLK

    //TA1CCR0 = 100;
    TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TACCR1 = 75;                // set duty cycle to 25/100 (25%)
    TACCR2 = 75;
    //TA1CCR1 = 0;

    TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
    //TA0CCTL0 |= OUTMOD_5;

    TACTL |= MC0;                // count up

    while (1) {}
    return 0;
}
