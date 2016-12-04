#include "uart_stdio.h"

#define UART_BAUD  9600

#include <avr/io.h>
#include <stdio.h>

FILE std_out =  FDEV_SETUP_STREAM(uart_putChar, NULL, _FDEV_SETUP_RW);


int uart_putChar(char c, FILE *stream) {
	while(~UCSRA &(1<<UDRE));
	UDR = c;
	
	return 0;
}

/*
char uart_getChar(void){
	return;
} 
*/

void uart_stdio_Init(void) {

	#if F_CPU < 2000000UL && defined(U2X)
	UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */
	stdout = &std_out;
}
