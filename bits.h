/* 
 * File:                bits.h
 * Author:              josewrpereira
 * Comments:            Macros de manipula��o de bits em vari�vel ou registrador.
 * Revision history:    
 */

#ifndef BITS_H
#define	BITS_H

#define BITVAL(bit)         (1<<bit)

#define SETBIT(var,bit)     (var |=  (1<<bit))
#define CLRBIT(var,bit)     (var &= ~(1<<bit))
#define TOGBIT(var,bit)     (var ^=  (1<<bit))
#define TSTBIT(var,bit)     (var &   (1<<bit))

#endif	
