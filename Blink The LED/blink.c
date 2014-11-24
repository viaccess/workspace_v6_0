//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  J. Stevenson
//  Texas Instruments, Inc
//  July 2011
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>				

#define LED_RED			BIT0			// The Red LED is on P1.0
#define LED_GREEN		BIT6			// Green LED is P1.6

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= LED_RED + LED_GREEN;					// Set P1.0 to output direction


	for(;;) {
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= LED_RED +  LED_GREEN;				// Toggle P1.0 using exclusive-OR

		i = 5000;					// SW Delay
		do i--;
		while(i != 0);
	}
	
	return 0;
}
