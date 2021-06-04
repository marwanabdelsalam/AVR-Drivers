/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 1/6/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	External Interrupt			 						     ***************************************/
/** Desciption: Definition of functions									 ***************************************/
/***************************************************************************************************************/


/*
 * EXTINT_Program.c
 *
 *  Created on: Jun 1, 2021
 *      Author: m
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"			//mafrod 8lt bs 3shan a3raf asha8al el ISR
#include "EXTINT_Private.h"
#include "EXTINT_Interface.h"
#include "DIO_Interface.h"

void EXTINT_VoidInit(u8 Copy_U8ExternalInterruptNumber)
{
	switch(Copy_U8ExternalInterruptNumber)
	{
	case INT0:
		//INT0

		/*interrupt sense control
		  MCUCR Reg(BIT1,BIT0) --> ISC01,ISC00 = 00 --> LOW LEVEL
		  MCUCR Reg(BIT1,BIT0) --> ISC01,ISC00 = 01 --> FALLING OR RISING EDGE
		  MCUCR Reg(BIT1,BIT0) --> ISC01,ISC00 = 10 --> FALLING EDGE
		  MCUCR Reg(BIT1,BIT0) --> ISC01,ISC00 = 11 --> RISING EDGE
		   */
		  //MCUCR Reg(BIT1,BIT0) --> ISC01,ISC00 = 10 --> FALLING EDGE
		ClearBit(MCUCR,0);
		SetBit(MCUCR,1);

		//Setting Peripheral Interrupt Enable of INT0	GICR Reg(BIT6)
		SetBit(GICR,6);

		//Setting Global Interrupt Enable SREG Reg(BIT7)
		SetBit(SREG,7);

		//Definig the interrupt pin as input pull up
		DIO_SetPinDirection(PORTD,PIN2,INPUT_PULLUP);	//INT0

		break;

	case INT1:
		//INT1

		/*interrupt sense control
		  MCUCR Reg(BIT3,BIT2) --> ISC11,ISC10 = 00 --> LOW LEVEL
		  MCUCR Reg(BIT3,BIT2) --> ISC11,ISC10 = 01 --> FALLING OR RISING EDGE
		  MCUCR Reg(BIT3,BIT2) --> ISC11,ISC10 = 10 --> FALLING EDGE
		  MCUCR Reg(BIT3,BIT2) --> ISC11,ISC10 = 11 --> RISING EDGE
		   */
		  //MCUCR Reg(BIT3,BIT2) --> ISC11,ISC10 = 10 --> FALLING EDGE
		ClearBit(MCUCR,2);
		SetBit(MCUCR,3);

		//Setting Peripheral Interrupt Enable of INT0	GICR Reg(BIT7)
		SetBit(GICR,7);

		//Setting Global Interrupt Enable SREG Reg(BIT7)
		SetBit(SREG,7);

		//Definig the interrupt pin as input pull up
		DIO_SetPinDirection(PORTD,PIN3,INPUT_PULLUP);	//INT0

		break;

	case INT2:
		//INT2

		/*interrupt sense control
		  MCUCSR Reg(BIT6) --> ISC2=0 --> FALLING EDGE
		  MCUCSR Reg(BIT6) --> ISC2=1 --> RISING EDGE
		   */
		  //MCUCSR Reg(BIT6) --> ISC2=0 --> FALLING EDGE
		ClearBit(MCUCSR,6);

		//Setting Peripheral Interrupt Enable of INT0	GICR Reg(BIT5)
		SetBit(GICR,5);

		//Setting Global Interrupt Enable SREG Reg(BIT7)
		SetBit(SREG,7);

		//Definig the interrupt pin as input pull up
		DIO_SetPinDirection(PORTB,PIN2,INPUT_PULLUP);	//INT0

		break;

	default :
		break;
	}
}



//ISR of INT0
void __vector_1(void)
{
	//toggle led
	ToggleBit(PORTA_REG,0);

}

//ISR of INT1
void __vector_2(void)
{
	//toggle led
	ToggleBit(PORTA_REG,1);

}

//ISR of INT2
void __vector_3(void)
{
	//toggle led
	ToggleBit(PORTA_REG,2);

}

