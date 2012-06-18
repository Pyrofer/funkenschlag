#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

void serial_init(void) {
	#define BAUD 9600
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	#if USE_2X /* output from setbaud.h */
		UCSR0A |= 1<<U2X0;
	#else
		UCSR0A &= ~(1<<U2X0);
	#endif
	#undef BAUD
	UCSR0B |= (1<<TXEN0 | 1<<RXEN0);
	UCSR0C |= (1<<UCSZ01 | 1<<UCSZ00);
//	UCSR0C |= (1<<URSEL | 1<<UCSZ01 | 1<<UCSZ00);
}

void serial_write(char c) {
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

void serial_write_str(char *s) {
	while (*s) {
		serial_write(*s++);
	}
}
