/* ********************************************
 * File:   gpio.c
 * Author: josewrpereira
 * Created on 22 de Abril de 2024, 21:35
 ******************************************** */

// Entradas Digitais (Digital Inputs - DI)
// PB0: DI0
// PB1: DI1
// PB4: DI2
// PB5: DI3

// Saídas Digitais (Digital Outputs - DO)
// PD2: PO0
// PD3: PO1
// PD4: DO2
// PD7: DO3

#include <avr/io.h>
#include "bits.h"

void gpio_init(void)
{
        // Configuração Entradas/Saídas
    CLRBIT(DDRB, 0);
    CLRBIT(DDRB, 1);
    CLRBIT(DDRB, 4);
    CLRBIT(DDRB, 5);
    
    SETBIT(DDRD, 2);
    SETBIT(DDRD, 3);
    SETBIT(DDRD, 4);
    SETBIT(DDRD, 7);

        // Habilitação de Resistor de Pull-up
    SETBIT(PORTB, 0);
    SETBIT(PORTB, 1);
    SETBIT(PORTB, 4);
    SETBIT(PORTB, 5);
    
        // Inicialização de Saídas
    CLRBIT(PORTD, 2);
    CLRBIT(PORTD, 3);
    CLRBIT(PORTD, 4);
    CLRBIT(PORTD, 7);
}


unsigned char gpi0( void )
{
    return( !TSTBIT(PINB, 0) );
}
unsigned char gpi1( void )
{
    return( !TSTBIT(PINB, 1) );
}
unsigned char gpi2( void )
{
    return( !TSTBIT(PINB, 4) );
}
unsigned char gpi3( void )
{
    return( !TSTBIT(PINB, 5) );
}


void gpo0( unsigned char b )
{
    if( b )
        SETBIT(PORTD,2);
    else
        CLRBIT(PORTD,2);
}
void gpo1( unsigned char b )
{
    if( b ) SETBIT(PORTD,3); else CLRBIT(PORTD,3);
}
void gpo2( unsigned char b )
{
    if( b ) SETBIT(PORTD,4); else CLRBIT(PORTD,4);
}
void gpo3( unsigned char b )
{
    if( b ) SETBIT(PORTD,7); else CLRBIT(PORTD,7);
}


unsigned char gpo0_status( void )
{
    return( TSTBIT(PORTD, 2) );
}
unsigned char gpo1_status( void )
{
    return( TSTBIT(PORTD, 3) );
}
unsigned char gpo2_status( void )
{
    return( TSTBIT(PORTD, 4) );
}
unsigned char gpo3_status( void )
{
    return( TSTBIT(PORTD, 7) );
}