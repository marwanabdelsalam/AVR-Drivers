/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 25/5/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	LCD			 									     ***************************************/
/** Desciption: Functions Definition									 ***************************************/
/***************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Interface.h"

#include "LCD_Config.h"
#include <avr/delay.h>


void LCD_VoidSendDataU8(u8 Copy_U8Data)
{
	  //Values
	  DIO_SetPinValue(CONTROL_PORT,RS,HIGH);				// RS=1		(data)
	  DIO_SetPinValue(CONTROL_PORT,RW,LOW);					// RW=0		(write)

	  switch(MODE)
	  {
	  case MODE8BIT:
		  DIO_SetPortValue( DATA_PORT, Copy_U8Data);			//put the data you want to write on the data port
		  //rising edge (bafta7 elshebak)
		  DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);					//ENABLE	PB2
		  _delay_us(2);
		  DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);
		  _delay_ms(1);										//badilo wa2t en yekteb el data di
		  break;
	  case MODE4BIT:
		 ///////////////////////////////send the data in two steps/////////////////////////
		  //step 1
		 DIO_SetPortHighNibbleValue(DATA_PORT,((GetHighNibble(Copy_U8Data))));
		//rising edge (bafta7 elshebak)
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);			//ENABLE=1
		  _delay_us(2);
			 DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);		//ENABLE=0
		  _delay_ms(1);								//badilo wa2t en yekteb el data di
		  //step 2
		  DIO_SetPortHighNibbleValue(DATA_PORT,((GetLowNibble(Copy_U8Data))));
		//rising edge (bafta7 elshebak)
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);			//ENABLE=1
		  _delay_us(2);
			 DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);		//ENABLE=0
		  _delay_ms(1);								//badilo wa2t en yekteb el data di
		  break;
	  default :
		  break;
	  }
}



void LCD_VoidSendCommand(u8 Copy_U8Command)
{

	  DIO_SetPinValue(CONTROL_PORT,RS,LOW);					// RS=0	(command)
	  DIO_SetPinValue(CONTROL_PORT,RW,LOW);					// RW=0 (write)

	switch(MODE)
	{
	case MODE8BIT :
		  DIO_SetPortValue( DATA_PORT, Copy_U8Command);			//put the data you want to write on the data port
		  //rising edge (bafta7 elshebak)
		  DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);		  //ENABLE=1
		  _delay_us(2);
		  DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);
		  _delay_ms(1);								//badilo wa2t en yekteb el data di
		  break;
	case MODE4BIT :

		 ///////////////////////////////send the data in two steps/////////////////////////
		 DIO_SetPortHighNibbleValue(DATA_PORT,(GetHighNibble(Copy_U8Command)));
	     //rising edge (bafta7 elshebak)
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);			//ENABLE=1
	     _delay_us(2);
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);		//ENABLE=0
		 _delay_ms(1);								//badilo wa2t en yekteb el data di

		 DIO_SetPortHighNibbleValue(DATA_PORT,(GetLowNibble(Copy_U8Command)));
		 //rising edge (bafta7 elshebak)
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,HIGH);			//ENABLE=1
		 _delay_us(2);
		 DIO_SetPinValue(CONTROL_PORT,ENABLE,LOW);		//ENABLE=0
		 _delay_ms(1);								//badilo wa2t en yekteb el data di

		  break;
	default:
		break;





	}
}
void LCD_VoidInit(void)
{
    DIO_SetPinDirection(CONTROL_PORT,RS,OUTPUT);			//RS pin is output
	DIO_SetPinDirection(CONTROL_PORT,RW,OUTPUT);			//RW pin is output
    DIO_SetPinDirection(CONTROL_PORT,ENABLE,OUTPUT);			//ENABLE	PB2

	switch(MODE)
	{
	case MODE8BIT:
	//Direction of PORT output always (b3mlha hna 3shan msh kol showaya a3mlha lma bagy a call sendCommand w sendData w tt3ml mra wa7da hna)
	DIO_SetPortDirection(DATA_PORT,PORT_OUTPUT);			//Data Port is output

  //wait for more than 30ms
  _delay_ms(40);
  //function set (0b,0,0,1,DL,N,F,X,X)     (DL=1)(8-bit mode) ,(N=1)(2 lines) , (F=0)(5x7 dots)
  LCD_VoidSendCommand(0b00111100);
  _delay_ms(1);
  //Display ON/OFF  (0b00001DCB)  (D=1)(Display is ON) ,(C=1)(Cursor Display is ON) , (B=1)(Cursor Blink)
  LCD_VoidSendCommand(0b00001100);
  _delay_ms(1);
  //Clear Display	Constant always 0b00000001
  LCD_VoidSendCommand(0b00000001);
  _delay_ms(2);
	//Entry Mode Set (0b0,0,0,0,0,1,I/D,SH)  (I/D=1)(Increase the DDRAM address by 1) , (SH=0)(The entire display isn't shifted)
	LCD_VoidSendCommand(0b00000110);
	_delay_ms(1);
	break;

	case MODE4BIT:
		DIO_SetPortHighNibbleDirection(DATA_PORT,OUTPUT);	 	//DATA PORT IS OUTPUT

		_delay_ms(50);

		//function set
		//(send first 0000 with no effect then the first line -> 0010)
		LCD_VoidSendCommand(0b00000010);
		_delay_ms(1);
		//(0b,0,0,1,DL,,,N,F,X,X)     (DL=1)(8-bit mode) ,(N=1)(2 lines) , (F=0)(5x7 dots)
		LCD_VoidSendCommand(0b00101100);
		_delay_ms(1);
		//Display ON/OFF  (0b00001DCB)  (D=1)(Display is ON) ,(C=1)(Cursor Display is ON) , (B=1)(Cursor Blink)
		LCD_VoidSendCommand(0b00001100);
		_delay_ms(1);
		//Clear Display	Constant always 0b00000001
		LCD_VoidSendCommand(0b00000001);
		_delay_ms(2);
		//Entry Mode Set (0b0,0,0,0,0,1,I/D,SH)  (I/D=1)(Increase the DDRAM address by 1) , (SH=0)(The entire display isn't shifted)
		LCD_VoidSendCommand(0b00000110);
		_delay_ms(1);
		break;
	default :
		break;
	}
}




void LCD_VoidSendString(u8 Copy_StringData[])
{
	u8 i;
	for (i=0;Copy_StringData[i]!='\0';i++)
		LCD_VoidSendDataU8(Copy_StringData[i]);
}

void LCD_VoidSendNumber(u32 Copy_U32Data)
{
	u8 count = DigitsCount(Copy_U32Data);
	u8 array[count];
	u8 i;
	for (i=0;i<count;i++)
		{
		array[i]=Copy_U32Data%10;
		Copy_U32Data=Copy_U32Data/10;
		}
	for (i=count; i > 0 ; i--)
		LCD_VoidSendDataU8(array[i-1]+48);
}

u8 DigitsCount(u32 Copy_U32Data)
{
	u8 count=0;
	if (Copy_U32Data==0)count=1;
	while(Copy_U32Data!=0)
	{
		count++;
		Copy_U32Data=Copy_U32Data/10;
	}
	return count;
}

void LCD_VoidClearDisplay()
{
	LCD_VoidSendCommand(0b00000001);
	_delay_ms(2);
}


//this function make the AC points to first address in the CGRAM to start drawing (check page 16 Datasheet)
void LCD_VoidSetCGRAMAddress0(void)
{
	LCD_VoidSendCommand(0b01000000);

}

//this function takes the specific address of the location in CGRAM(0-63) we want to draw on ,, if this address <0 and >63 do nothing
void LCD_VoidSetCGRAMAddress(u8 Copy_U8CGRAMAdress)
{
	if(Copy_U8CGRAMAdress>=0 && Copy_U8CGRAMAdress<64)
	LCD_VoidSendCommand(0b01000000|Copy_U8CGRAMAdress);

}

//this function takes the location number of the CGRAM (0-7) (8 locations) to draw on
void LCD_VoidSetCGRAMPattern(u8 Copy_U8CGRAMPattern)
{
	if (Copy_U8CGRAMPattern>=0 && Copy_U8CGRAMPattern<=7)
	LCD_VoidSendCommand(0b01000000|(Copy_U8CGRAMPattern*8));		//bec each pattern 8 locations in the CGRAM

}

//this funtion takes the number of row (0-1) and number of column(0-15) to set the location in the LCD monitor we want to print on
void LCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Column)
{
	/* Setting DDRAM Address RS R/w DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
	 * 						 0	0	1	AC6 AC5 AC4 AC3 AC2 AC1 AC0
	 * 1st row from address 1,0000000 to 1,0001111 (16 places visible) and the rest of the row invisible
	 * 2nd row from address 1,1000000 to 1,1001111 (16 places visible) and the rest of the row invisible
	 	 page 16 Datasheet
	*/
	switch (Copy_U8Row)
	{
	case 0:
		LCD_VoidSendCommand(0b10000000 | Copy_U8Column);	//it can be (128+Copy_U8Column)
		break;
	case 1:
		LCD_VoidSendCommand(0b10000000 |0b01000000 | Copy_U8Column);	////it can be (128+64+Copy_U8Column)
	}
}



void LCD_VoidDrawCGRAM_ManPattern(void)
{
  	LCD_VoidSendDataU8 (0b00001110);
	LCD_VoidSendDataU8 (0b00001110);
	LCD_VoidSendDataU8 (0b00000100);
	LCD_VoidSendDataU8 (0b00011111);
	LCD_VoidSendDataU8 (0b00000100);
	LCD_VoidSendDataU8 (0b00001010);
	LCD_VoidSendDataU8 (0b00010001);
	LCD_VoidSendDataU8 (0b00010001);
}

void LCD_VoidDrawCGRAM_AlefPattern(void)
{
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
}

void LCD_VoidDrawCGRAM_WawPattern(void)
{
	LCD_VoidSendDataU8(0b00000111);
	LCD_VoidSendDataU8(0b00000101);
	LCD_VoidSendDataU8(0b00000111);
	LCD_VoidSendDataU8(0b00000001);
	LCD_VoidSendDataU8(0b00000111);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
}

void LCD_VoidDrawCGRAM_RahPattern(void)
{
	LCD_VoidSendDataU8(0b00000001);
	LCD_VoidSendDataU8(0b00000001);
	LCD_VoidSendDataU8(0b00000001);
	LCD_VoidSendDataU8(0b00000010);
	LCD_VoidSendDataU8(0b00000100);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);

}

void LCD_VoidDrawCGRAM_MeemMarbotaPattern(void)
{
	LCD_VoidSendDataU8(0b00011111);
	LCD_VoidSendDataU8(0b00000101);
	LCD_VoidSendDataU8(0b00000111);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);

}

void LCD_VoidDrawCGRAM_NoonNotMarbotaPattern(void)
{
	LCD_VoidSendDataU8(0b00010101);
	LCD_VoidSendDataU8(0b00010001);
	LCD_VoidSendDataU8(0b00010001);
	LCD_VoidSendDataU8(0b00010001);
	LCD_VoidSendDataU8(0b00011111);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);
	LCD_VoidSendDataU8(0x00);

}

void LCD_VoidDrawCGRAM_ManWithBall1(void)
{
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0xd);
	LCD_VoidSendDataU8(0xa);
	LCD_VoidSendDataU8(0x8);

}

void LCD_VoidDrawCGRAM_ManWithBall2(void)
{
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x9);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0xc);
	LCD_VoidSendDataU8(0xa);

}


void LCD_VoidDrawCGRAM_FootballGoal(void)
{
	LCD_VoidSendDataU8(0x7);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x7);

}

void LCD_VoidDrawCGRAM_Football(void)
{
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x1);
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x0);
	LCD_VoidSendDataU8(0x0);

}

void LCD_VoidDrawCGRAM_ManWithoutBall(void)
{
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0x1c);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0x8);
	LCD_VoidSendDataU8(0xc);
	LCD_VoidSendDataU8(0xa);

}



//name like in markets
void task1(void){

	LCD_VoidInit();

	u8 name[6]={'M','a','r','w','a','n'};

		while(1)
		{
			int i,j,k,n=0;
				for(j=0;j<16;j++)
				{
					LCD_VoidSetPosition(0,j);
					for (i=0;i<6;i++)
					LCD_VoidSendDataU8(name[i]);
					if(j>=11)
					{
						LCD_VoidSetPosition(1,0);
						for (k=5-(n++);k<6;k++)
						{
						LCD_VoidSendDataU8(name[k]);}
					}
					_delay_ms(200);
					LCD_VoidClearDisplay();
				}
				for(j=0;j<16;j++)
				{
					LCD_VoidSetPosition(1,j);
					for (i=0;i<6;i++)
					LCD_VoidSendDataU8(name[i]);
					_delay_ms(200);
					LCD_VoidClearDisplay();
				}

}}

//name moving in arabic
void task2(void)
{
	LCD_VoidInit();
	LCD_VoidSetCGRAMPattern(PATTERN1);
	LCD_VoidDrawCGRAM_MeemMarbotaPattern();
	LCD_VoidSetCGRAMPattern(PATTERN2);
	LCD_VoidDrawCGRAM_RahPattern();
	LCD_VoidSetCGRAMPattern(PATTERN3);
	LCD_VoidDrawCGRAM_WawPattern();
	LCD_VoidSetCGRAMPattern(PATTERN4);
	LCD_VoidDrawCGRAM_AlefPattern();
	LCD_VoidSetCGRAMPattern(PATTERN5);
	LCD_VoidDrawCGRAM_NoonNotMarbotaPattern();


	while(1)
	{
		LCD_VoidSetPosition(ROW1,COL1);
		LCD_VoidSendDataU8(PATTERN5);
		LCD_VoidSendDataU8(PATTERN4);
		LCD_VoidSendDataU8(PATTERN3);
		LCD_VoidSendDataU8(PATTERN2);
		LCD_VoidSendDataU8(PATTERN1);
		_delay_ms(500);
		LCD_VoidClearDisplay();

		LCD_VoidSetPosition(ROW2,COL4);
		LCD_VoidSendDataU8(PATTERN5);
		LCD_VoidSendDataU8(PATTERN4);
		LCD_VoidSendDataU8(PATTERN3);
		LCD_VoidSendDataU8(PATTERN2);
		LCD_VoidSendDataU8(PATTERN1);
		_delay_ms(500);
		LCD_VoidClearDisplay();

		LCD_VoidSetPosition(ROW1,COL6);
		LCD_VoidSendDataU8(PATTERN5);
		LCD_VoidSendDataU8(PATTERN4);
		LCD_VoidSendDataU8(PATTERN3);
		LCD_VoidSendDataU8(PATTERN2);
		LCD_VoidSendDataU8(PATTERN1);
		_delay_ms(500);
		LCD_VoidClearDisplay();

		LCD_VoidSetPosition(ROW2,COL10);
		LCD_VoidSendDataU8(PATTERN5);
		LCD_VoidSendDataU8(PATTERN4);
		LCD_VoidSendDataU8(PATTERN3);
		LCD_VoidSendDataU8(PATTERN2);
		LCD_VoidSendDataU8(PATTERN1);
		_delay_ms(500);
		LCD_VoidClearDisplay();

		LCD_VoidSetPosition(ROW1,COL12);
		LCD_VoidSendDataU8(PATTERN5);
		LCD_VoidSendDataU8(PATTERN4);
		LCD_VoidSendDataU8(PATTERN3);
		LCD_VoidSendDataU8(PATTERN2);
		LCD_VoidSendDataU8(PATTERN1);
		_delay_ms(500);
		LCD_VoidClearDisplay();


	}
}


void task3(void)
{
	LCD_VoidInit();
	LCD_VoidSetCGRAMPattern(PATTERN1);
	 LCD_VoidDrawCGRAM_ManWithBall1();

	LCD_VoidSetCGRAMPattern(PATTERN2);
	 LCD_VoidDrawCGRAM_ManWithBall2();

		LCD_VoidSetCGRAMPattern(PATTERN3);
		LCD_VoidDrawCGRAM_FootballGoal();

		LCD_VoidSetCGRAMPattern(PATTERN4);
		LCD_VoidDrawCGRAM_Football();

		LCD_VoidSetCGRAMPattern(PATTERN5);
		LCD_VoidDrawCGRAM_ManWithoutBall();



	 //LCD_VoidSetPosition(ROW1,COL1);
	 int j,i;
	 while (1)
	 {
			 for (j=0;j<11;j++)
			 {
				 LCD_VoidSetPosition(ROW2,j);
				 LCD_VoidSendDataU8(PATTERN2);

				 LCD_VoidSetPosition(ROW2,COL16);
				 LCD_VoidSendDataU8(PATTERN3);

				 _delay_ms(400);
				 LCD_VoidClearDisplay();
				 j++;
				 LCD_VoidSetPosition(ROW2,j);
				 LCD_VoidSendDataU8(PATTERN1);

				 LCD_VoidSetPosition(ROW2,COL16);
				 LCD_VoidSendDataU8(PATTERN3);

				 _delay_ms(400);
				 LCD_VoidClearDisplay();
			 }

			 for (i=j;i<15;i++)
			 {
				 LCD_VoidSetPosition(ROW2,COL16);
				 LCD_VoidSendDataU8(PATTERN3);

				 LCD_VoidSetPosition(ROW2,j-1);
				 LCD_VoidSendDataU8(PATTERN5);

				 LCD_VoidSetPosition(ROW2,i);
				 LCD_VoidSendDataU8(PATTERN4);
				 _delay_ms(600);
				 LCD_VoidClearDisplay();


			 }
			 LCD_VoidClearDisplay();
			 LCD_VoidSetPosition(ROW1,COL6);
			 LCD_VoidSendString("SCORE!!");
			 _delay_ms(200);
			 LCD_VoidClearDisplay();
			 _delay_ms(200);
			 LCD_VoidSetPosition(ROW1,COL6);
			 LCD_VoidSendString("SCORE!!");
			 _delay_ms(200);
			 LCD_VoidClearDisplay();
			 _delay_ms(200);
			 LCD_VoidSetPosition(ROW1,COL6);
			 LCD_VoidSendString("SCORE!!");
			 _delay_ms(200);
			 LCD_VoidClearDisplay();
			 _delay_ms(200);


	 }
}
