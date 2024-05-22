#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"


//volatile unsigned char pwm0 = 85;
//volatile unsigned char pwm_cont = 0;
//
ISR(TIMER0_OVF_vect)
{
//    TCNT0 = 256-20;
//    ++pwm_cont;
//    pwm_cont %= 100;
//
//    if( pwm_cont < pwm0 )
//        gpo0( 1 );
//    else
//        gpo0( 0 );
}
//
//void timer0_init( void )
//{
//    cli();
//    TCCR0B = 0x03;
//    TIMSK0 = 0x01;
//    TCNT0 = 256-20;
//    sei();
//}



void timer0_init( void )
{
    cli();
    DDRD |= ((1<<6) | (1<<5));
    TCCR0A = ((1<<7) | (1<<5) | (0x03));
    TCCR0B = 0x03;// | (1<<3);
    OCR0A = 150;
    OCR0B = 200;
    TIMSK0 = 0x01 | 0x02 | 0x04;
    TCNT0 = 0;
    sei();
}


ISR(TIMER0_COMPA_vect)
{
}

