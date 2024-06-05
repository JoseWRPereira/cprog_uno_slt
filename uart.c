#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char uart_rx_var = 0;


ISR(USART0_RX_vect)
{
    uart_rx_var = UDR0;
    UDR0 = uart_rx_var;
}


void uart_init( void )
{
    cli();
    UBRR0 = 103; // 9600bps
    UCSR0B = 0x98;
    UCSR0C = 0x06;
    sei();
}

void uart_tx( unsigned char t )
{
	UDR0 = t;
}

unsigned char uart_rx( void )
{
	return( uart_rx_var );
}