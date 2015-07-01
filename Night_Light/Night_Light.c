/*
 * Night_Light.c
 *
 *  Created on: 2015-06-14
 *      Author: sajjad
 */
#include <avr/io.h> //Defines pins, ports, etc.
#include <util/delay.h>

int main(void) {
	short unsigned int photo_value=0;
	short unsigned int threshold=600;
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
		photo_value= ADC;

		if (photo_value < threshold) {
			PORTD |= 0b00000100; //turn on LED
		}else {
			PORTD &= 0b00000000; //turn off LED
		}
	}
}
