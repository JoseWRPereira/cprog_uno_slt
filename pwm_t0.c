#include <avr/io.h>
#include <avr/interrupt.h>
//#include "gpio.h"
#include "bits.h"


//ISR(TIMER0_OVF_vect)
//{
//    TCNT0 = 256-20;
//    ++pwm_cont;
//    pwm_cont %= 100;
//
//    if( pwm_cont < pwm0 )
//        gpo0( 1 );
//    else
//        gpo0( 0 );
//}
//
//void timer0_init( void )
//{
//    cli();
//    TCCR0B = 0x03;
//    TIMSK0 = 0x01;
//    TCNT0 = 256-20;
//    sei();
//}



void pwm_t0_init( void )
{
    cli();
		// Hab. pinos como saída
    DDRD |= ((1<<6) | (1<<5));
    
		// (0x03): Mode 3 - Fast PWM
	TCCR0A = 0x03;
		// (1<<7): Habilita PWM A
//	SETBIT(TCCR0A,7);
		// (1<<5): Habilita PWM B
//	SETBIT(TCCR0A,5);
		// Clock Source / 64 (from prescaler)
    TCCR0B = 0x03;
	
    OCR0A = 128;
    OCR0B = 128;

	TIMSK0 = 0x7;
    TCNT0 = 0;
    sei();
}

void set_pwm_a( unsigned int pwm )
{
	if( pwm == 0 )
	{
		CLRBIT(TCCR0A,7);
	}
	else 
	{
		OCR0A = (pwm > 100) ? 255 : ((pwm << 8)/100);
		SETBIT(TCCR0A,7);
	}
}

void set_pwm_b( unsigned int pwm )
{
	if( pwm == 0 )
	{
		CLRBIT(TCCR0A,5);
	}
	else
	{
		OCR0B = (pwm > 100) ? 255 : ((pwm << 8)/100);
		SETBIT(TCCR0A,5);
	}
}

