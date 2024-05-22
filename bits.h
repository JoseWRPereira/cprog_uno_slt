/* 
 * File:                bits.h
 * Author:              josewrpereira
 * Comments:            Macros de manipulação de bits em variável ou registrador.
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
