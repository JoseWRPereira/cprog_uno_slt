#ifndef ADC_H
#define ADC_H

void adc_init();
void adc_start( void );
char adc_available( void );
int adc_ch0( void );
int adc_ch1( void );

#endif
