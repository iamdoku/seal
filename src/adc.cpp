#include <avr/io.h>

namespace adc {
	void init()
	{
		ADMUX |= (1 << REFS0);
		ADCSRA |= (1 <<ADPS1) | (1 <<ADPS2);
		ADCSRA |= (1 << ADEN);
		
	}

	int getSample(const unsigned int &c)
	{
		if (c >= 0 && c <= 7)
		ADMUX |= c;
		ADCSRA |= (1 << ADSC);
		while(!(ADCSRA & (1 << ADIF)))
			;
		return ADC;
	}
}