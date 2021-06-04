/***************************************************************************************************************/
/** Author : Marwan Abdelsalam 											 ***************************************/
/** Data : 24/5/2021		  										     ***************************************/
/** Version :	1.0.0												     ***************************************/
/** DriverName:	DIO			 										     ***************************************/
/** Desciption: Defining the DIO Abbreviations and Functions Declaration ***************************************/
/***************************************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Registers Macros*/
#define PORTA 0 
#define PORTB 1 
#define PORTC 2
#define PORTD 3

/*Pin Directions*/
#define OUTPUT 1
#define INPUT_PULLUP 0
#define INPUT_HIGHIMPEDENCE 2

/*Port Output*/
#define PORT_OUTPUT 0xff
#define PORT_INPUT 0	

/*Pin Values*/
#define HIGH 1
#define LOW 0

/*Port Values*/
#define PORT_HIGH 0xff
#define PORT_LOW 0

/*Pins Numbers*/
typedef enum
{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
}PIN_t;

/*Pins Numbers by macros*/
/*
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
*/
	
/*DIOFunction Prototypes*/

//Pin Functions
void DIO_SetPinDirection(u8 PORT,u8 PIN,u8 DIRECTION);
void DIO_SetPinValue(u8 PORT,u8 PIN,u8 VALUE);
void DIO_TogPinDirection(u8 PORT,u8 PIN);
void DIO_TogPinValue(u8 PORT,u8 PIN);
u8 DIO_GetPinValue(u8 PORT,u8 PIN);
void DIO_SetPinPullUp(u8 PORT, u8 PIN);


//port Functions
void DIO_SetPortDirection(u8 PORT,u8 DIRECTION);
void DIO_SetPortValue(u8 PORT,u8 VALUE);
u8 DIO_GetPortValue(u8 PORT);

//Low Nibble Functions
void DIO_SetPortLowNibbleDirection(u8 PORT,u8 DIRECTION);
void DIO_SetPortLowNibbleValue(u8 PORT,u8 VALUE);
u8 DIO_GetPortLowNibbleValue(u8 PORT);

//High Nibble Functions
void DIO_SetPortHighNibbleDirection(u8 PORT,u8 DIRECTION);
void DIO_SetPortHighNibbleValue(u8 PORT,u8 VALUE);
u8 DIO_GetPortHighNibbleValue(u8 PORT);


void DIO_SetPinPullUp(u8 PORT, u8 PIN);
#endif /* AVR_DIO_INTERFACE_H_ */
