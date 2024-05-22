/* 
 * File:                delay.h
 * Author:              josewrpereira
 * Comments:            Macro para produ��o de atraso em ms.
 * Revision history:    
 */

#ifndef DELAY_H
#define DELAY_H

#define F_CPU   16000000
#include <util/delay.h>

#define DELAY( t )        _delay_ms( t )

#endif
