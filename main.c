#include "delay.h"
#include "gpio.h"
#include "adc.h"
#include "pwm_t0.h"
#include "uart.h"

int main(void) 
{
    gpio_init();
    adc_init();
    pwm_t0_init();
    uart_init();
    while (1) 
    {
		adc_start();
		while( !adc_available() )
			;
		switch( uart_rx() )
		{
			case '1': set_pwm_a( 10 ); set_pwm_b( 10 ); break;
			case '2': set_pwm_a( 20 ); set_pwm_b( 20 ); break;
			case '3': set_pwm_a( 30 ); set_pwm_b( 30 ); break;
			case '4': set_pwm_a( 40 ); set_pwm_b( 40 ); break;
			case '5': set_pwm_a( 50 ); set_pwm_b( 50 ); break;
			case '6': set_pwm_a( 60 ); set_pwm_b( 60 ); break;
			case '7': set_pwm_a( 70 ); set_pwm_b( 70 ); break;
			case '8': set_pwm_a( 80 ); set_pwm_b( 80 ); break;
			case '9': set_pwm_a( 90 ); set_pwm_b( 90 ); break;
			case '0': set_pwm_a(  0 ); set_pwm_b(  0 ); break;
		}
		
    }
}
