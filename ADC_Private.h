/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 2/6/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	ADC			 										     ***************************************/
/** Desciption: Register Adresses										 ***************************************/
/***************************************************************************************************************/



#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX *((volatile u8*)(0x27))
#define ADCSRA *((volatile u8*)(0x26))
#define ADCH *((volatile u8*)(0x25))
#define ADCL *((volatile u8*)(0x24))
#define SFIOR *((volatile u8*)(0x50))
#define ADC_DHL *((volatile u16*)(0x24))		//3shan y2ra el low w el high m3a b3d(base address 0x24)
#define SREG *((volatile u8*)0x5F)


//ISR Declaration
void __vector_16(void) __attribute__((signal));

//Defining bits names
//ADMUX Register
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0
//ADCSRA Register
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
//SREG Register
#define I 7
//SFIOR Register
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#endif /* ADC_PRIVATE_H_ */
