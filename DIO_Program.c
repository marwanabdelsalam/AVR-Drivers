/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 											 ***************************************/
/** Data      : 24/5/2021		  										     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	DIO			 										     ***************************************/
/** Desciption: Defining the DIO Functions						 ***************************************/
/***************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Private.h"
#include "DIO_Interface.h"


//Pin Functions
void DIO_SetPinDirection(u8 PORT,u8 PIN,u8 DIRECTION)
{
	switch(PORT)
	{
		case PORTA:	
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearBit(DDRA_REG,PIN);
				SetBit(PORTA_REG,PIN);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearBit(DDRA_REG,PIN);
				ClearBit(PORTA_REG,PIN);
				break;
			case OUTPUT:
				SetBit(DDRA_REG,PIN);
				break;
			default :
				break;
			}
			break;

		case PORTB:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearBit(DDRB_REG,PIN);
				SetBit(PORTB_REG,PIN);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearBit(DDRB_REG,PIN);
				ClearBit(PORTB_REG,PIN);
				break;
			case OUTPUT:
				SetBit(DDRB_REG,PIN);
				break;
			default :
				break;
			}
			break;

		case PORTC:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearBit(DDRC_REG,PIN);
				SetBit(PORTC_REG,PIN);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearBit(DDRC_REG,PIN);
				ClearBit(PORTC_REG,PIN);
				break;
			case OUTPUT:
				SetBit(DDRC_REG,PIN);
				break;
			default :
				break;
			}
			break;

		case PORTD:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearBit(DDRD_REG,PIN);
				SetBit(PORTD_REG,PIN);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearBit(DDRD_REG,PIN);
				ClearBit(PORTD_REG,PIN);
				break;
			case OUTPUT:
				SetBit(DDRD_REG,PIN);
				break;
			default :
				break;
			}
			break;
	}
}

void DIO_SetPinPullUp(u8 PORT, u8 PIN)
{
	switch (PORT)
	{
	case PORTA:
		SetBit(PORTA_REG,PIN);
		break;
	case PORTB:
		SetBit(PORTB_REG,PIN);
		break;
	case PORTC:
		SetBit(PORTC_REG,PIN);
		break;
	case PORTD:
		SetBit(PORTD_REG,PIN);
		break;
	default :
		break;
	}
}


void DIO_SetPinValue(u8 PORT,u8 PIN,u8 VALUE)
{
	switch(PORT)
	{
		case PORTA:	
			if (VALUE==LOW)
			{
				ClearBit(PORTA_REG,PIN);
			}
			else if (VALUE==HIGH)
			{
				SetBit(PORTA_REG,PIN);
			}
			else
			{
				//do nothing
			}
			break;
		case PORTB:
			if (VALUE==LOW)
			{
				ClearBit(PORTB_REG,PIN);
			}
			else if (VALUE==HIGH)
			{
				SetBit(PORTB_REG,PIN);
			}
			else
			{
				//do nothing
			}
			break;

		case PORTC:
			if (VALUE==LOW)
			{
				ClearBit(PORTC_REG,PIN);
			}
			else if (VALUE==HIGH)
			{
				SetBit(PORTC_REG,PIN);
			}
			else
			{
				//do nothing
			}
			break;

		case PORTD:
			if (VALUE==LOW)
			{
				ClearBit(PORTD_REG,PIN);
			}
			else if (VALUE==HIGH)
			{
				SetBit(PORTD_REG,PIN);
			}
			else
			{
				//do nothing
			}
			break;
		default :
			break;	//do nothing
	}
	
}



void DIO_TogPinValue(u8 PORT,u8 PIN)
{
	switch(PORT)
	{
		case PORTA:	
			ToggleBit(PORTA_REG,PIN);
			break;
		case PORTB:
			ToggleBit(PORTB_REG,PIN);
			break;

		case PORTC:
			ToggleBit(PORTC_REG,PIN);
			break;

		case PORTD:
			ToggleBit(PORTD_REG,PIN);
			break;
		default :
			break;	//do nothing
	}
	
}

void DIO_TogPinDirection(u8 PORT,u8 PIN)
{
	switch(PORT)
	{
		case PORTA:
			ToggleBit(DDRA_REG,PIN);
			break;
		case PORTB:
			ToggleBit(DDRB_REG,PIN);
			break;

		case PORTC:
			ToggleBit(DDRC_REG,PIN);
			break;

		case PORTD:
			ToggleBit(DDRD_REG,PIN);
			break;
		default :
			break;	//do nothing
	}

}

u8 DIO_GetPinValue(u8 PORT,u8 PIN)
{
	u8 PinValue;
	switch(PORT)
	{
		case PORTA:
			PinValue=GetBit(PINA_REG,PIN);
			break;
		case PORTB:
			PinValue=GetBit(PINB_REG,PIN);
			break;
		case PORTC:
			PinValue=GetBit(PINC_REG,PIN);
			break;
		case PORTD:
			PinValue=GetBit(PIND_REG,PIN);
			break;
		default :
			break;
	}
	return PinValue;
}

void DIO_SetPortValue(u8 PORT,u8 VALUE)
{
	switch(PORT)
	{
		case PORTA:
			PORTA_REG=VALUE;
			break;
		case PORTB:
			PORTB_REG=VALUE;
			break;
		case PORTC:
			PORTC_REG=VALUE;
			break;
		case PORTD:
			PORTD_REG=VALUE;
			break;
		default :
			break;	//do nothing
	}
}




void DIO_SetPortLowNibbleDirection(u8 PORT,u8 DIRECTION)
{

	switch(PORT)
	{
		case PORTA:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearLowNibble(DDRA_REG);
				SetLowNibble(PORTA_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearLowNibble(DDRA_REG);
				ClearLowNibble(PORTA_REG);
				break;
			case OUTPUT:
				SetLowNibble(DDRA_REG);
				break;
			default :
				break;
			}
			break;

		case PORTB:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearLowNibble(DDRB_REG);
				SetLowNibble(PORTB_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearLowNibble(DDRB_REG);
				ClearLowNibble(PORTB_REG);
				break;
			case OUTPUT:
				SetLowNibble(DDRB_REG);
				break;
			default :
				break;
			}
			break;

		case PORTC:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearLowNibble(DDRC_REG);
				SetLowNibble(PORTC_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearLowNibble(DDRC_REG);
				ClearLowNibble(PORTC_REG);
				break;
			case OUTPUT:
				SetLowNibble(DDRC_REG);
				break;
			default :
				break;
			}
			break;

		case PORTD:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearLowNibble(DDRD_REG);
				SetLowNibble(PORTD_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearLowNibble(DDRD_REG);
				ClearLowNibble(PORTD_REG);
				break;
			case OUTPUT:
				SetLowNibble(DDRD_REG);
				break;
			default :
				break;
			}
			break;
	}

}
void DIO_SetPortHighNibbleDirection(u8 PORT,u8 DIRECTION)
{
	switch(PORT)
	{
		case PORTA:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearHighNibble(DDRA_REG);
				SetHighNibble(PORTA_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearHighNibble(DDRA_REG);
				ClearHighNibble(PORTA_REG);
				break;
			case OUTPUT:
				SetHighNibble(DDRA_REG);
				break;
			default :
				break;
			}
			break;

		case PORTB:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearHighNibble(DDRB_REG);
				SetHighNibble(PORTB_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearHighNibble(DDRB_REG);
				ClearHighNibble(PORTB_REG);
				break;
			case OUTPUT:
				SetHighNibble(DDRB_REG);
				break;
			default :
				break;
			}
			break;

		case PORTC:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearHighNibble(DDRC_REG);
				SetHighNibble(PORTC_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearHighNibble(DDRC_REG);
				ClearHighNibble(PORTC_REG);
				break;
			case OUTPUT:
				SetHighNibble(DDRC_REG);
				break;
			default :
				break;
			}
			break;

		case PORTD:
			switch (DIRECTION)
			{
			case INPUT_PULLUP:
				ClearHighNibble(DDRD_REG);
				SetHighNibble(PORTD_REG);
				break;
			case INPUT_HIGHIMPEDENCE:
				ClearHighNibble(DDRD_REG);
				ClearHighNibble(PORTD_REG);
				break;
			case OUTPUT:
				SetHighNibble(DDRD_REG);
				break;
			default :
				break;
			}
			break;
	}

}

void DIO_SetPortLowNibbleValue(u8 PORT,u8 VALUE)
{
	switch (PORT)
	{
	case PORTA:
		AssignLowNibble(PORTA_REG,VALUE);
		break;
	case PORTB:
		AssignLowNibble(PORTB_REG,VALUE);
		break;
	case PORTC:
		AssignLowNibble(PORTC_REG,VALUE);
		break;
	case PORTD:
		AssignLowNibble(PORTD_REG,VALUE);
		break;
	default:
		break;
	}
}
void DIO_SetPortHighNibbleValue(u8 PORT,u8 VALUE)
{
	switch (PORT)
	{
	case PORTA:
		AssignHighNibble(PORTA_REG,VALUE);
		break;
	case PORTB:
		AssignHighNibble(PORTB_REG,VALUE);
		break;
	case PORTC:
		AssignHighNibble(PORTC_REG,VALUE);
		break;
	case PORTD:
		AssignHighNibble(PORTD_REG,VALUE);
		break;
	default:
		break;
	}
}

void DIO_SetPortDirection(u8 PORT,u8 DIRECTION)
{
	switch(PORT)
	{
		case PORTA:	
			DDRA_REG=DIRECTION;
			break;
		case PORTB:
			DDRB_REG=DIRECTION;
			break;
		case PORTC:
			DDRC_REG=DIRECTION;
			break;
		case PORTD:
			DDRD_REG=DIRECTION;
			break;
		default :
			break;	//do nothing
	}
}





/*
u8* DIO_GetPortValue(u8 PORT,u8 PIN)
{
	//Assignment 		return in an array
	
}
*/





