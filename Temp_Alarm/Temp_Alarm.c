/*
 * Temp_Alarm.c
 *
 *  Created on: 2015-06-14
 *      Author: sajjad
 */
#include <avr/io.h> 
#include <util/delay.h>

int main(void) {
	short unsigned int voltage=0;
	unsigned char temperature=0; //celsius
	float threshold=28.0;
	DDRD = DDRD | 0b00000100; //making D2 output port= digital 2

	//set up the ADC
	ADMUX = 0x00; //ADC0 = analog input0
	ADMUX |= (1 << REFS0); //AVCC
	ADCSRA	|= (1 << ADPS1) | (1 << ADPS0); //ADC clock prescaler=8
	ADCSRA |= (1 << ADEN); //Enable

	while (1) {
		//start ADC conversion
		ADCSRA |= (1 << ADSC);
		//wait for ADC conversion to be finished
		loop_until_bit_is_clear(ADCSRA, ADSC);
		//read ADC value
		voltage= ADC;
		float temperature= (voltage/1024.0) * 500.0;

		if (temperature > threshold) {
			PORTD |= 0b00000100; //turn on LED
		}else {
			PORTD &= 0b00000000; //turn off LED
		}
	}
}
