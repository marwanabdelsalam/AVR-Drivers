/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 25/5/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	LCD			 									     ***************************************/
/** Desciption: Functions prototypes									 ***************************************/
/***************************************************************************************************************/

/*
 * LCD_Interface.h
 *
 *  Created on: May 25, 2021
 *      Author: m
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*Rows number*/
#define ROW1 0
#define ROW2 1

/*Columns number*/
typedef enum COL_NUM
{
	COL1,COL2,COL3,COL4,COL5,COL6,COL7,COL8,COL9,COL10,COL11,COL12,COL13,COL14,COL15,COL16
}COL_NUM;

/*CGRAM Patterns*/
typedef enum CGRAM_Patterns
{
	PATTERN1,PATTERN2,PATTERN3,PATTERN4,PATTERN5,PATTERN6,PATTERN7,PATTERN8
}CGRAM_Patterns;


/*function prototypes*/
void LCD_VoidSendDataU8(u8 Copy_U8Data);
void LCD_VoidSendNumber(u32 Copy_U32Data);
void LCD_VoidSendString(u8 Copy_StringData[]);
void LCD_VoidSendCommand(u8 Copy_U8Command);
void LCD_VoidInit(void);
u8 DigitsCount(u32 Copy_U32Data);


void LCD_VoidClearDisplay(void);

void LCD_VoidSetCGRAMAddress0(void);
void LCD_VoidSetCGRAMAddress(u8 Copy_U8CGRAMAdress);
void LCD_VoidSetCGRAMPattern(u8 Copy_U8CGRAMPattern);

void LCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Column);

/*patterns function*/
void LCD_VoidDrawCGRAM_ManPattern(void);
void LCD_VoidDrawCGRAM_AlefPattern(void);
void LCD_VoidDrawCGRAM_WawPattern(void);
void LCD_VoidDrawCGRAM_RahPattern(void);
void LCD_VoidDrawCGRAM_MeemMarbotaPattern(void);
void LCD_VoidDrawCGRAM_NoonNotMarbotaPattern(void);


void LCD_VoidDrawCGRAM_ManWithBall1(void);
void LCD_VoidDrawCGRAM_ManWithBall2(void);
void LCD_VoidDrawCGRAM_FootballGoal(void);
void LCD_VoidDrawCGRAM_Football(void);
void LCD_VoidDrawCGRAM_ManWithoutBall(void);


/*tasks function*/

//name in English moving to the end of line 1 and appear character by character in line 2
void task1(void);
//name in Arabic appear in different positions
void task2(void);
//man playing with ball till he reaches the goal then score
void task3(void);

#endif /* LCD_INTERFACE_H_ */
