/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 30/5/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	KeyPad			 									     ***************************************/
/** Desciption: Hardware Configurations									 ***************************************/
/***************************************************************************************************************/

/*
 * Keypad_Config.h
 *
 *  Created on: May 30, 2021
 *      Author: m
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

//choose from here the algorithm based on your configuration
#define FULLY_ABSTRACT			    0
#define TWO_PORT_ALGORITHM 			1
#define ALGORITHM			        TWO_PORT_ALGORITHM

//TWO_PORT_ALGORITHM Configurations
#define COLUMN_PORT PORTD			//(start connecting the columns from PIN0 of its port)
#define ROWS_PORT PORTA				//(start connecting the rows from PIN0 of its port)
#define COLUMN_NNUMBERS 4
#define ROWS_NNUMBERS 4

//FULLY_ABSTRACT Configurations
//PORTS

#define RO_PORT PORTA
#define R1_PORT PORTA
#define R2_PORT PORTA
#define R3_PORT PORTA

#define CO_PORT PORTA
#define C1_PORT PORTA
#define C2_PORT PORTA
#define C3_PORT PORTA


//Buttons Mapping
#define BUTTON0 '7'
#define BUTTON1 '8'
#define BUTTON2 '9'
#define BUTTON3 '/'
#define BUTTON4 '4'
#define BUTTON5 '5'
#define BUTTON6 '6'
#define BUTTON7 '*'
#define BUTTON8 '1'
#define BUTTON9 '2'
#define BUTTON10 '3'
#define BUTTON11 '-'
#define BUTTON12 'c'
#define BUTTON13 '0'
#define BUTTON14 '='
#define BUTTON15 '+'

//ROWS PINS
#define R0 PIN0
#define R1 PIN1
#define R2 PIN2
#define R3 PIN3
//COLUMNS PINS
#define C0 PIN4
#define C1 PIN5
#define C2 PIN6
#define C3 PIN7


#endif /* KEYPAD_CONFIG_H_ */
