#include <avr/io.h>
#include <avr/interrupt.h>

ISR(USART0_RX_vect)
{
    char data = 0;
    data = UDR0;
    UDR0 = data;
}


void uart_init( void )
{
    cli();
    UBRR0 = 103; // 9600bps
    UCSR0B = 0x98;
    UCSR0C = 0x06;
    sei();
}