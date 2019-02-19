#ifndef ADC_H_
#define ADC_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define ADC8 8


namespace  adc 
{
	void init();
	int getSample(const unsigned int &c);
}

#endif
