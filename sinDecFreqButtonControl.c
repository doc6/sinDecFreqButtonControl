/*
 * sinefnDecFreq.c
 *
 * A program to generate a sine wave using the DCA module
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>


/*
 * init_portD()
 *
 * Controls a motors forward and backwards
 *  speed with DAC for the Arduino Uno.
 *
 * D O Corlett 3/08/16
 */
void init_ports(void)
{
	/* Make all 8 bits of Port D outputs */
	DDRD = 0xff;
	/* Set outputs to low voltage. */
	PORTD = 0;
	/* Set input ports. */
	DDRB = 0x00 & 0x3f;
}

void delay_ms(unsigned int xms)
{
    while (xms) {
        _delay_ms(0.96);
        xms--;
    }
}


/*
 * write_dac()
 *
 * Write 8-bit number out to DAC via port D.
 */
void write_dac(unsigned char value)
{
	PORTD = value;
}

/**  Main Function  ********************************************************/

int main(void)
{
	init_ports();

	while (1)
	{
		write_dac( 127 + (((((2*((PINB & 0x20) >> 5))-1))*(((PINB & 0x1f)*4))))); //Calculation for speed and direction control of the motor
	}

	return 0;
}

