#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#ifndef USART_PRESCALER
#define USART_PRESCALER 103U
#endif

#include <avr/io.h>
#include <util/setbaud.h>
#include <stdio.h>

namespace usart
{
	void init(const unsigned int &ubrr)
	{
		UBRR0L = static_cast<unsigned char> (ubrr);
		UBRR0H = static_cast<unsigned char> (ubrr >> 8);
		UCSR0A &= ~(1 << U2X0);
		UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
		UCSR0C |= (1 << USBS0) | (3 << UCSZ00);
	}

	void transmit(const char* data, const bool nl = false)
	{
		for (; *data != '\0' ; ++data)
		{
			while(!(UCSR0A & (1 << UDRE0)))
				;
			UDR0 = *data;
		}
		if (nl)
			transmit("\n");
	}

	void transmit(const int &data, const bool nl = false)
	{
		char buff[7];
		sprintf(buff, "%d", data);
		transmit(buff);
		if (nl)
			transmit("\n");
	}
	
	unsigned char receive()
	{
		while(!(UCSR0A & (1 << RXC0)))
			;
		return UDR0;
	}
}
