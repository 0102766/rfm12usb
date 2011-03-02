#ifndef UART_H
#define UART_H

#if defined(__AVR_ATmega48__)

#define UCSRA UCSR0A
#define UCSRB UCSR0B
#define UCSRC UCSR0C
#define UBRRL UBRR0L
#define UBRRH UBRR0H
#define UDR UDR0
#define RXC RXC0
#define TXC TXC0
#define UDRE UDRE0
#define TXEN TXEN0
#define RXEN RXEN0
#define UCSZ0 UCSZ00
#define URSEL

#endif

/**
 * UART Library
 *
 * #define F_CPU 12000000         // Oszillator-Frequenz in Hz
 * #define UART_INTERRUPT 1
 * #define UART_BAUD_RATE 19200
 * #define UART_RXBUFSIZE 16
 * #define UART_TXBUFSIZE 16
 * #define UART_LINE_BUFFER_SIZE 40
 * #define UART_LEDS             // LED1 and LED2 toggle on tx and rx interrupt
 *
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

void uart_init();

void uart_putc(char c);
void uart_putstr(char * str);
void uart_putstr_P(PGM_P str);
void uart_hexdump(char *buf, int len);

char uart_getc();
char uart_getc_nb(char *c);		// returns 1 on success

//get one Cariage return terminated line
//echo charakters back on Uart
//returns buffer with zero terminated line on success, 0 pointer otherwise
char * uart_getline_nb();

#endif
