/*
 * Timer_Interface.h
 *
 *  Created on: Jun 6, 2021
 *      Author: m
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

// Timer 0 Functions
void Timer0_VoidInit(void);
void Timer0_VoidSetDutyCycle(u8 Copy_U8Duty);
void Timer0_SetCallBackFun_CTC_ISR ( void(*Timer0_CopyPtrToFun_CTC_ISR)(void) );
void Timer0_SetCallBackFun_OverFlow_ISR ( void(*Timer0_CopyPtrToFun_OverFlow_ISR)(void) );

// Timer 1 Functions
void Timer1_VoidInit(void);
void Timer1_VoidSelectICU_FallingEdge(void);
void Timer1_VoidSelectICU_RisingEdge(void);
void Timer1_SetCallBackFun_Capture_ISR ( void(*Timer1_CopyPtrToFun_CAPTURE_ISR)(void) );
void Timer1_SetCallBackFun_OverFlow_ISR ( void(*Timer1_CopyPtrToFun_OverFlow_ISR)(void) );

// Timer 2 Functions
void Timer2_VoidInit(void);
void Timer2_VoidSetDutyCycle(u8 Copy_U8Duty);
void Timer2_SetCallBackFun_CTC_ISR ( void(*Timer2_CopyPtrToFun_CTC_ISR)(void) );
void Timer2_SetCallBackFun_OverFlow_ISR ( void(*Timer2_CopyPtrToFun_OverFlow_ISR)(void) );


#endif /* TIMER_INTERFACE_H_ */
