/* *****************************************************************************
 * File:                gpio.h
 * Author:              josewrpereira
 * Comments:            Configuração e definição de entradas e saídas digitais.
 * Revision history:    
 **************************************************************************** */


////////////////////////////////////////////////////////////////////////////////
//  Registradores de configuração e manipulação de dados nos pinos
//
//        DDRxn   :   Data Direction Register
//        PORTxn  :   Data Register
//        PINxn   :   Input Pin Address
//
//        ===================
//        x |        n
//        ===================
//        B | 7 6 5 4 3 2 1 0
//        C |   6 5 4 3 2 1 0
//        D | 7 6 5 4 3 2 1 0
//        E |         3 2 1 0
//        ===================
//
//  Configuração e Manipulação de dados nos pinos
//
//        DDRxn = 1;          // Output
//            {
//                PORTxn = 1; //          High
//                PORTxn = 0; //          Low
//            }
//
//        DDRxn = 0;          // Input
//            {
//                PORTxn = 0; //          Pull-Up Resistor OFF
//                PORTxn = 1; //          Pull-Up Resistor ON
//                {
//                    (PINxn == 1)    //  ON
//                    (PINxn == 0)    //  OFF
//                }
//            }
//        
////////////////////////////////////////////////////////////////////////////////

#ifndef GPIO_H
#define GPIO_H

void gpio_init(void);

unsigned char gpi0( void );
unsigned char gpi1( void );
unsigned char gpi2( void );
unsigned char gpi3( void );

void gpo0( unsigned char b );
void gpo1( unsigned char b );
void gpo2( unsigned char b );
void gpo3( unsigned char b );

unsigned char gpo0_status( void );
unsigned char gpo1_status( void );
unsigned char gpo2_status( void );
unsigned char gpo3_status( void );

#endif
