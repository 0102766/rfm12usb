#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <avr/sleep.h>

#include "rfm12.h"
#include "uart.h"


int main ( void )
{
	//uint8_t i = 0;
	//uint16_t ticker = 0;
	
;
	
	//DDRD |= (_BV(PD7));
	//PORTD |= _BV(PD7);

	//_delay_ms(250);
	//_delay_ms(250);
	//_delay_ms(250);
	//rfm12_init();
	//_delay_ms(250);
	//rfm12_set_wakeup_timer(10);	
			
	//sei();
	
	////uart_putstr ("\r\n");
	////uart_putstr ("Hello\r\n");
	
	//DDRB   &= ~(_BV(1));

	//while (42)
	//{
		//if(!(PINB & (_BV(1))))
		//{
			//ticker = 1;
		//}
		
		//if(ticker && (PINB & (_BV(1))))
		//{
			//ticker = 0;
			
			////uart_putstr ("tx ");
			//rfm12_tx (1, 0x23, &i);
			
			//i++;
		//}

		//rfm12_tick();
		
		//sleep_mode();
	//}
		uint8_t *bufcontents;
	uint8_t i;
	 uint8_t teststring[] = "ping\r\n";
 uint8_t packettype = 0xEE;
 rfm12_init();  /* initialize the library */
 uart_init();
 sei();
 uart_putstr ("knock ");
 while (23)
 {
   _delay_ms(250);
   _delay_ms(250);
   _delay_ms(250);
   _delay_ms(250);
		if (rfm12_rx_status() == STATUS_COMPLETE)
		{

			uart_putstr ("new packet:\r\n");

			bufcontents = rfm12_rx_buffer();

			// dump buffer contents to uart			
			for (i=0;i<rfm12_rx_len();i++)
			{
				uart_putc ( bufcontents[i] );
			}
			
			// tell the implementation that the buffer
			// can be reused for the next data.
			rfm12_rx_clear();

		}
   rfm12_tx (sizeof(teststring), packettype, teststring);
   rfm12_tick();  /* periodic tick function - call that one once in a while */
 }

}
