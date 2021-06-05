/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 30/5/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	KeyPad			 									     ***************************************/
/** Desciption: Definition of functions									 ***************************************/
/***************************************************************************************************************/

/*
 * Keypad_Program.c
 *
 *  Created on: May 30, 2021
 *      Author: m
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "Keypad_Config.h"

#include <avr/delay.h>

#if ALGORITHM == FULLY_ABSTRACT
void Keypad_VoidInit(void)
{
	//ROWS
	DIO_SetPinDirection(RO_PORT,R0,INPUT_PULLUP);
	DIO_SetPinDirection(R1_PORT,R1,INPUT_PULLUP);
	DIO_SetPinDirection(R2_PORT,R2,INPUT_PULLUP);
	DIO_SetPinDirection(R3_PORT,R3,INPUT_PULLUP);

	//COLUMNS
	DIO_SetPinDirection(CO_PORT,C0,OUTPUT);
	DIO_SetPinDirection(C1_PORT,C1,OUTPUT);
	DIO_SetPinDirection(C2_PORT,C2,OUTPUT);
	DIO_SetPinDirection(C3_PORT,C3,OUTPUT);
}


u8 Keypad_VoidGetPressed(void)
{
	u8 value=244;			//any value

	//C0=1 C1=1 C2=1 C3=1
	DIO_SetPinValue(CO_PORT,C0,HIGH);
	DIO_SetPinValue(C1_PORT,C1,HIGH);
	DIO_SetPinValue(C2_PORT,C2,HIGH);
	DIO_SetPinValue(C3_PORT,C3,HIGH);

	//1ST CHECK
	//C0=0 C1=1 C2=1 C3=1
	DIO_SetPinValue(CO_PORT,C0,LOW);
	DIO_SetPinValue(C1_PORT,C1,HIGH);
	DIO_SetPinValue(C2_PORT,C2,HIGH);
	DIO_SetPinValue(C3_PORT,C3,HIGH);

	if (DIO_GetPinValue(RO_PORT,R0)==0)
		{
		value=BUTTON0;
		while(DIO_GetPinValue(RO_PORT,R0)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R1_PORT,R1)==0)
		{
		value=BUTTON4;
		while(DIO_GetPinValue(R1_PORT,R1)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R2_PORT,R2)==0)
		{
		value=BUTTON8;
		while(DIO_GetPinValue(R2_PORT,R2)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R3_PORT,R3)==0)
		{
		value=BUTTON12;
		while(DIO_GetPinValue(R3_PORT,R3)==0);		//to hold the program here as long as the key is still pressed
		}

	//2ND CHECK
	//C0=1 C1=0 C2=1 C3=1
	DIO_SetPinValue(CO_PORT,C0,HIGH);
	DIO_SetPinValue(C1_PORT,C1,LOW);
	DIO_SetPinValue(C2_PORT,C2,HIGH);
	DIO_SetPinValue(C3_PORT,C3,HIGH);

	if (DIO_GetPinValue(RO_PORT,R0)==0)
		{
		value=BUTTON1;
		while(DIO_GetPinValue(RO_PORT,R0)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R1_PORT,R1)==0)
		{
		value=BUTTON5;
		while(DIO_GetPinValue(R1_PORT,R1)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R2_PORT,R2)==0)
		{
		value=BUTTON9;
		while(DIO_GetPinValue(R2_PORT,R2)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R3_PORT,R3)==0)
		{
		value=BUTTON13;
		while(DIO_GetPinValue(R3_PORT,R3)==0);		//to hold the program here as long as the key is still pressed
		}


	//3RD CHECK
	//C0=1 C1=1 C2=0 C3=1
	DIO_SetPinValue(CO_PORT,C0,HIGH);
	DIO_SetPinValue(C1_PORT,C1,HIGH);
	DIO_SetPinValue(C2_PORT,C2,LOW);
	DIO_SetPinValue(C3_PORT,C3,HIGH);

	if (DIO_GetPinValue(RO_PORT,R0)==0)
		{
		value=BUTTON2;
		while(DIO_GetPinValue(RO_PORT,R0)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R1_PORT,R1)==0)
		{
		value=BUTTON6;
		while(DIO_GetPinValue(R1_PORT,R1)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R2_PORT,R2)==0)
		{
		value=BUTTON10;
		while(DIO_GetPinValue(R2_PORT,R2)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R3_PORT,R3)==0)
		{
		value=BUTTON14;
		while(DIO_GetPinValue(R3_PORT,R3)==0);		//to hold the program here as long as the key is still pressed
		}


	//4TH CHECK
	//C0=1 C1=1 C2=1 C3=0
	DIO_SetPinValue(CO_PORT,C0,HIGH);
	DIO_SetPinValue(C1_PORT,C1,HIGH);
	DIO_SetPinValue(C2_PORT,C2,HIGH);
	DIO_SetPinValue(C3_PORT,C3,LOW);

	if (DIO_GetPinValue(RO_PORT,R0)==0)
		{
		value=BUTTON3;
		while(DIO_GetPinValue(RO_PORT,R0)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R1_PORT,R1)==0)
		{
		value=BUTTON7;
		while(DIO_GetPinValue(R1_PORT,R1)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R2_PORT,R2)==0)
		{
		value=BUTTON11;
		while(DIO_GetPinValue(R2_PORT,R2)==0);		//to hold the program here as long as the key is still pressed
		}
	else if (DIO_GetPinValue(R3_PORT,R3)==0)
		{
		value=BUTTON15;
		while(DIO_GetPinValue(R3_PORT,R3)==0);		//to hold the program here as long as the key is still pressed
		}

	return value;
}


#elif ALGORITHM == TWO_PORT_ALGORITHM

void Keypad_VoidInit(void)
{
	u8 C,R;
	for (C=0;C<COLUMN_NNUMBERS;C++)						//columns output
		DIO_SetPinDirection(COLUMN_PORT,C,OUTPUT);
	for (R=0;R<ROWS_NNUMBERS;R++)						//rows input PULL UP
		DIO_SetPinDirection(ROWS_PORT,R,INPUT_PULLUP);
}

u8 Keypad_VoidGetPressed(void)
{
	u8 value=244;
	u8 C,R;
	for (C=0;C<COLUMN_NNUMBERS;C++)
		DIO_SetPinValue(COLUMN_PORT,C,HIGH);

	for (C=0;C<COLUMN_NNUMBERS;C++)
	{
		DIO_SetPinValue(COLUMN_PORT,C,LOW);
		for (R=0;R<ROWS_NNUMBERS;R++)
		{
			if (DIO_GetPinValue(ROWS_PORT,R)==0)
			{
				while (DIO_GetPinValue(ROWS_PORT,R)==0);	//to hold the program here as long as the key is still pressed
				value= (COLUMN_NNUMBERS*R)+C;				//equation to return the number of button
			}
		}
		DIO_SetPinValue(COLUMN_PORT,C,HIGH);
	}

	switch(value)
	{
	case 0:
		value=BUTTON0;
		break;
	case 1:
		value=BUTTON1;
		break;
	case 2:
		value=BUTTON2;
		break;
	case 3:
		value=BUTTON3;
		break;
	case 4:
		value=BUTTON4;
		break;
	case 5:
		value=BUTTON5;
		break;
	case 6:
		value=BUTTON6;
		break;
	case 7:
		value=BUTTON7;
		break;
	case 8:
		value=BUTTON8;
		break;
	case 9:
		value=BUTTON9;
		break;
	case 10:
		value=BUTTON10;
		break;
	case 11:
		value=BUTTON11;
		break;
	case 12:
		value=BUTTON12;
		break;
	case 13:
		value=BUTTON13;
		break;
	case 14:
		value=BUTTON14;
		break;
	case 15:
		value=BUTTON15;
		break;
	default:
		break;
	}
	return value;
}







#endif

