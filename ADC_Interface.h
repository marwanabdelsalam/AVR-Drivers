/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 2/6/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	ADC			 									     ***************************************/
/** Desciption: Functions prototypes									 ***************************************/
/***************************************************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_VoidInit(void);
u16 ADC_U16ReadDigitalValue(u8 Copy_U8ChannelNumb);
void ADC_VoidStartConversion(void);

//channels definition
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#endif /* ADC_INTERFACE_H_ */
