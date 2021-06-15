/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 2/6/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	ADC			 									     ***************************************/
/** Desciption: Functions Definition									 ***************************************/
/***************************************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Private.h"

#include <avr/delay.h>
#include "DIO_Interface.h"
#include "LCD_Interface.h"


void ADC_VoidInit(void)
{
	/*
	Voltage Reference Selections for ADC - (ADMUX Register bit7(REFS1) and bit6(REFS0))
	REFS1 REFS0 = 0 0 --> AREF, Internal Vref turned off
	REFS1 REFS0 = 0 1 --> AVCC with external capacitor at AREF pin (if not connected to external voltage it will take its voltage from PORTA)
	REFS1 REFS0 = 1 0 --> Reserved
	REFS1 REFS0 = 1 1 --> Internal 2.56V Voltage Reference with external capacitor at AREF pin
	*/
	//Select AVCC with external capacitor at AREF pinC
	ClearBit(ADMUX,REFS1);
	SetBit(ADMUX,REFS0);

	/*
	 the presentation of the ADC conversion result(10 bits) in the ADC Data Register ADCH ADCL (8+8=16 bits) - (ADMUX Register bit5(ADLAR))
	 ADLAR=0 --> Right adjustment		ADCH = ------98		ADCL = 76543210
	 ADLAR=1 --> Left adjustment		ADCH = 98765432		ADCL = 10------
	 */
	//Select Right adjustment
	ClearBit(ADMUX,ADLAR);




	/*
	ADC Enable - (ADCSRA Register bit7(ADEN))
	ADEN=1 --> ADC is enabled
	ADEN=0 --> ADC is disabled
	Turning the ADC off while a conversion is in progress, will terminate this conversion.
	*/
	//Enable ADC
	SetBit(ADCSRA,ADEN);




	/*
	 ADC Auto Triggering Enable - (ADCSRA Register bit5(ADATE))
	 ADATE=1 --> Auto Triggering is enabled
	 ADATE=0 --> Auto Triggering is disabled
	 */
	//Disable Auto trigger
	SetBit(ADCSRA,ADATE);

	/*
	 this step in only done when auto triggering is enabled
	 ADC Auto Trigger Source - (SFIOR Register bits 5:7(ADTS2) (ADTS1) (ADTS0))
	 check page 218 for all trigger sources
	 000 -> free running mode
	 001 -> Analog Comparator				??
	 010 -> External Interrupt Request 0
	 */
	ClearBit(SFIOR,ADTS2);
	ClearBit(SFIOR,ADTS1);
	ClearBit(SFIOR,ADTS0);


	/*
	 ADC Interrupt Enable- (ADCSRA Register bit3(ADIE))
	 ADIE=1 --> Interrupt is enabled 				if this choice is chosen you have to enable the global interrupt
	 ADIE=0 --> Interrupt is disabled
	 */
	//Disable Interrupt
	SetBit(ADCSRA,ADIE);



	/*
	 ADC Prescaler Select Bits - (ADCSRA Register bit2:0 (ADPS2) (ADPS1) (ADPS0))
		ADPS2	ADPS1	ADPS0	DivisionFactor
		0		 0		 0		 2
		0		 0		 1		 2
		0		 1		 0		 4
		0		 1		 1		 8
		1		 0		 0		 16
		1		 0		 1		 32
		1		 1		 0		 64
		1		 1		 1		 128
	b7adedha 3la asas el features bta3et el ADC page 201 13us-260us b7ot frequency tgebly elrange da
	 */
	//ADC Prescaler =64
	SetBit(ADCSRA,ADPS2);
	SetBit(ADCSRA,ADPS1);
	SetBit(ADCSRA,ADPS0);


}


u16 ADC_U16ReadDigitalValue(u8 Copy_U8ChannelNumb)
{
	/*
	  Analog Channel and Gain Selection Bits - (ADMUX Register bit4:0(MUX4 MUX3 MUX2 MUX1 MUX0))
	  MUX4..0
	  00000 ADC0
	  00001 ADC1
	  00010 ADC2
	  00011 ADC3
	  00100 ADC4			//single ended options, for more modes about differential check page 215
	  00101 ADC5
	  00110 ADC6
	  00111 ADC7
	 */

	//select channel
	//make all 5 bits zero at first --> then ORing with the channel number to select which channel to work
	ADMUX = ADMUX & 0b1110000;
	if (Copy_U8ChannelNumb<8)
		ADMUX=ADMUX | Copy_U8ChannelNumb;

	/*
	  ADC Start Conversion - (ADCSRA Register bit6 (ADSC))
	  In Single Conversion mode, write this bit to one to start each conversion
	*/
	//start conversion
	SetBit(ADCSRA,ADSC);

	/*
	 ADC Interrupt Flag - (ADCSRA Register bit4 (ADIF))
	 This bit is set when an ADC conversion completes and the Data Registers are updated
	 ADIF is cleared by writing a logical one to the flag
	 */
	//wait while firing flag (conversion completed)
	while(GetBit(ADCSRA,ADIF) == 0);
	//clear INT flag
	SetBit(ADCSRA,ADIF);
	// return data
	return ADC_DHL;

}

//if we work with free running we have to call this function just once in the main
void ADC_VoidStartConversion(void)
{
	//start conversion
	SetBit(ADCSRA,ADSC);
}

void ADC_VoidSelectChannel(u8 Copy_U8ChannelNumb)
{
	ADMUX = ADMUX & 0b1110000;
	if (Copy_U8ChannelNumb<8)
		ADMUX = ADMUX | Copy_U8ChannelNumb;
}

/*if you will work with interrupt you'll have to start conversion and select the channel by yourself in the while 1
 * Ex:
 * 		ADC_VoidSelectChannel(ADC0);
		ADC_VoidStartConversion();
 * */
//ISR of ADC
void __vector_16(void)
{

	DIO_TogPinValue(PORTA,PIN1);
	_delay_ms(200);

	u16 AnalogValue=(ADC_DHL*5000UL)/1023;
	u16 TEMP_C=AnalogValue/10;
	LCD_VoidClearDisplay();
	LCD_VoidSetPosition(0,0);
	LCD_VoidSendNumber(TEMP_C);
	LCD_VoidSetPosition(0,3);
	LCD_VoidSendString("C");

}

