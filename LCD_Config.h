/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 25/5/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	LCD			 									     ***************************************/
/** Desciption: Hardware Configurations									 ***************************************/
/***************************************************************************************************************/



#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define CONTROL_PORT PORTB
#define DATA_PORT PORTC				// in case of 4 bit mode connect to the most significant 4 pins of the port ,, else , handle it in the code

//control pins
#define RS PIN0
#define RW PIN1
#define ENABLE PIN2

//data pins
#define DB4	PIN4
#define DB5 PIN5
#define DB6 PIN6
#define DB7 PIN7
/*Modes*/
#define MODE8BIT 0
#define MODE4BIT 1

#define MODE MODE8BIT



#endif /* LCD_CONFIG_H_ */
