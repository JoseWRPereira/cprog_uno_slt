#ifndef UART_H
#define UART_H

void uart_init( void );
void uart_tx( unsigned char t );
unsigned char uart_rx( void );

#endif
