//Hello World with bare metal programming
#include <avr/io.h>
#include <util/delay.h>
 
#define DELAY_MS 1000
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 DDRB = 0b00100000; //_BV(DDB5);
 
 while(1) {
  /* set pin 5 high to turn led on */
  PORTB |= 0b00100000;;
  _delay_ms(2*DELAY_MS);
 
  /* set pin 5 low to turn led off */
  PORTB &= 0b00000000;
  _delay_ms(DELAY_MS);
 }
 return 0;
}
