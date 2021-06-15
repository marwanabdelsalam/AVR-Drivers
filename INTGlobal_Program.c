/*
 * INTGlobal_Program.c
 *
 *  Created on: Jun 7, 2021
 *      Author: m
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTGlobal_Private.h"
#include "INTGlobal_Interface.h"

void GlobalInterrupt_VoidEnableGlobalInterrupt(void)
{
	SetBit(SREG,I);
}
void GlobalInterrupt_VoidDisableGlobalInterrupt(void)
{
	ClearBit(SREG,I);

}
