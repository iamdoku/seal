#ifndef USART_H_
#define USART_H_

namespace usart
{
	void init (const unsigned int &ubrr);
	void transmit(const char* data, const bool nl = false);
	void transmit(const int &data, const bool nl = false);
	unsigned char receive();
}


#endif /* USART_H_ */