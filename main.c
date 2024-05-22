#include "delay.h"
#include "gpio.h"
#include "adc.h"
#include "timer0.h"
#include "uart.h"

int main(void) 
{
    int ad = 0;
    gpio_init();
    adc_init();
    timer0_init();
    uart_init();

    while (1) 
    {
    }
}
