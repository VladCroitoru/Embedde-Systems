#ifndef UART_STDIO_H_
#define UART_STDIO_H_

#define F_CPU 1000000UL
#include <stdio.h>

void uart_stdio_Init(void);
int uart_putChar(char c, FILE *stream);
//char uart_getChar(void);

#endif /* UART_STDIO_H_ */