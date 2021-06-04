/**********************************************************************/
/** Author : MarwanAbdelsalam   ***************************************/
/** Data : 23/5/2021		    ***************************************/
/** Version :				    ***************************************/
/** DriverName:				    ***************************************/
/** Desc:Dealing with registers ***************************************/
/**********************************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

// Bit Operations
#define SetBit(reg,bit_num)    reg |=  (1<<bit_num)
#define ClearBit(reg,bit_num)  reg &= ~(1<<bit_num)
#define ToggleBit(reg,bit_num) reg ^=  (1<<bit_num)
#define GetBit(reg,bit_num) ((reg>>bit_num)&1)
#define AssignBit(reg,bit_num,value) if(((reg>>bit_num)&1)&&(!value)) ClearBit(reg,bit_num); else if (!((reg>>bit_num)&1)&&(value)) SetBit(reg,bit_num)

//Low Nibble Operations
#define GetLowNibble(reg) reg&0x0f
#define SetLowNibble(reg) reg|=0x0f
#define ClearLowNibble(reg) reg&=0xf0
#define AssignLowNibble(reg,value) reg=(reg & 0xf0)| value
#define ToggleLowNibble(reg) reg^=0x0f

//High Nibble Operation
#define GetHighNibble(reg) (reg>>4)&0x0f
#define SetHighNibble(reg) reg|=0xf0
#define ClearHighNibble(reg) reg&=0x0f
#define AssignHighNibble(reg,value) reg=(reg & 0x0f)|(value<<4)
#define ToggleHighNibble(reg) reg^=0xf0



#endif // BIT_MATH_H_INCLUDED
