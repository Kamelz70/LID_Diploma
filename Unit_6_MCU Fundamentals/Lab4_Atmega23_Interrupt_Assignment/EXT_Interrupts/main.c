#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void main()
{
	SREG &= ~(1 << 7);	   // Disable interrupts by clearing I-bit
	DDRD &= (~(1 << PD3)); // Configure INT1/PD3 as input pin
	PORTD |= (1 << PD3);   // Enable the internal pull up resistor at PD3 pin
	GICR |= (1 << INT1)|(1 << INT2)|(1 << INT0);   // Enable all external interrupt pins
	// Trigger INT1 with the falling edge
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);
	// Trigger INT0 with any edge
	MCUCR |= (1 << 0);
	MCUCR &= ~(1 << 1);
	// Trigger INT2 with rising edge
	MCUCSR &= (1 << ISC2);
	SREG |= (1 << 7); // Enable interrupts by setting I-bit}

	// Setting pins PD2,PD3 and PB2 as input
	DDRD  &= ~( (1<<PIND2) | (1<<PIND3))  ;
	DDRB  &= ~(1<<PINB2);


	// Setting LED pins PD5,PD6 and PD7 as output pins
	DDRD |= ((1<<PD5) | (1<<PD6) | (1<<PD7)) ;


	while(1)
	{
		PORTD &= ~((1<<PD5) | (1<<PD6) | (1<<PD7)) ;
		_delay_ms(1000);
	}


}

ISR(INT0_vect)
{
	PORTD |= (1<<PD5);
	_delay_ms(1000);
	PORTD  &= ~(1<<PD5);

}

ISR(INT1_vect)
{
	PORTD |= (1<<PD6);
	_delay_ms(1000);
	PORTD  &= ~(1<<PD6);
}

ISR(INT2_vect)
{
	PORTD |= (1<<PD7);
	_delay_ms(1000);
	PORTD  &= ~(1<<PD7);
}
