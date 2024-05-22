#include <avr/io.h>
#include <avr/interrupt.h>
#include "bits.h"


// -------------------------------------- Vars
unsigned int adc0_value = 0;
unsigned int adc1_value = 0;
unsigned int adc_value;
unsigned char adc_available_flag = 0;



// -------------------------------------- adc_init
    // Seleção de tensão de referência
#define ADC_AVCC    BITVAL(REFS0)
#define ADC_1V1     (BITVAL(REFS1)|BITVAL(REFS0))
#define ADC_AREF    0

    // Ajuste de bits (Left Adjust Result)
#define ADC_LAR    BITVAL(ADLAR)

    // Seleção de canal para conversao
#define ADC_CH0     0
#define ADC_CH1     1
// --------------------------------------
    // Habilita conversor AD
#define ADC_EN      BITVAL(ADEN)
    // Inicia a conversao AD
#define ADC_START   BITVAL(ADSC)
    // Habilita Trigger Automatico
#define ADC_ATE     BITVAL(ADATE)
    // Habilita Interrupcao
#define ADC_IE      BITVAL(ADIE)
    // Fator de divisao - ADC Prescaler
#define ADC_FREQ_DIV_2      0x1
#define ADC_FREQ_DIV_4      0x2
#define ADC_FREQ_DIV_8      0x3
#define ADC_FREQ_DIV_16     0x4
#define ADC_FREQ_DIV_32     0x5
#define ADC_FREQ_DIV_64     0x6
#define ADC_FREQ_DIV_128    0x7



// -------------------------------------- adc_init
void adc_init( void )
{
    cli();
    ADMUX = (ADC_AVCC | ADC_CH0);
    ADCSRA = (ADC_EN | ADC_IE | ADC_FREQ_DIV_128);
    sei();
}



// -------------------------------------- adc_start
void adc_start( void )
{
    SETBIT(ADMUX, MUX0);        // CH1
    SETBIT(ADCSRA, ADSC);       // START
	adc_available_flag = 0;
}



// -------------------------------------- adc_interrupt
ISR( ADC_vect )
{
    adc_value = ADC;
    if( TSTBIT(ADMUX, MUX0) )   // CH1
    {
        adc1_value = adc_value;
        CLRBIT(ADMUX, MUX0);        // CH0
        SETBIT(ADCSRA, ADSC);       // START
    }
    else                        // CH0
    {
        adc0_value = adc_value;
		adc_available_flag = 1;
    }
}



// -------------------------------------- adc available
char adc_available( void )
{
	return( adc_available_flag );
}


// -------------------------------------- adc result
int adc_ch0( void )
{
    return( adc0_value );
}
int adc_ch1( void )
{
    return( adc1_value );
}