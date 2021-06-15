/*
 * Timer_Program.c
 *
 *  Created on: Jun 6, 2021
 *      Author: m
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Timer_Private.h"
#include "Timer_Config.h"
#include "Timer_Interface.h"



void (*Timer1_GlobalPtrToFun_CAPTURE_ISR)(void) 	= '\0';
void (*Timer1_GlobalPtrToFun_OverFlow_ISR)(void) 	= '\0';
void (*Timer2_GlobalPtrToFun_CTC_ISR)(void)			= '\0';
void (*Timer2_GlobalPtrToFun_OverFlow_ISR)(void) 	= '\0';
void (*Timer0_GlobalPtrToFun_CTC_ISR)(void) 		= '\0';
void (*Timer0_GlobalPtrToFun_OverFlow_ISR)(void)	= '\0';

/************************************************TIMER0****************************************************************************************/
void Timer0_VoidInit(void)
{

	/****************Timer 0 Mode Select******************************/
	#if TIMER0_MODE_SELECT == NORMAL				//Select normal mode
	ClearBit(TCCR0,WGM01);
	ClearBit(TCCR0,WGM00);
	ClearBit(TCCR0,COM01);
	ClearBit(TCCR0,COM00);
	#elif TIMER0_MODE_SELECT == CTC					//Select CTC
	SetBit(TCCR0,WGM01);
	ClearBit(TCCR0,WGM00);
	OCR0=TIMER0_COMPAREMATCH_VALUE;
		/****************Timer 0 NON-PWM Mode Output Pin(OC0) Mode Select******************************/
		#if TIMER0_NON_PWM_MODE_OUTPUTPIN_MODE == OC0_DISCONNECTED
		ClearBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#elif TIMER0_NON_PWM_MODE_OUTPUTPIN_MODE == TOGGLE_OC0_ON_COMPARE_MATCH
		ClearBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		#elif TIMER0_NON_PWM_MODE_OUTPUTPIN_MODE == CLEAR_OC0_ON_COMPARE_MATCH
		SetBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#elif TIMER0_NON_PWM_MODE_OUTPUTPIN_MODE == SET_OC0_ON_COMPARE_MATCH
		SetBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		#else
		#warning "Wrong Input for Timer 0 NON-PWM Mode Output Pin(OC0) Mode Select"
		#endif
	#elif TIMER0_MODE_SELECT == PWM_FAST			//select Fast PWM Mode
	SetBit(TCCR0,WGM01);
	SetBit(TCCR0,WGM00);
		/****************Timer 0 Fast PWM Mode Output Pin(OC0) Mode Select******************************/
		#if TIMER0_FAST_PWM_MODE_OUTPUTPIN_MODE		==	 OC0_DISCONNECTED
		ClearBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#elif TIMER0_FAST_PWM_MODE_OUTPUTPIN_MODE		==	 NON_INVERTING					//Noninverting Mode
		SetBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#elif TIMER0_FAST_PWM_MODE_OUTPUTPIN_MODE	==	 INVERTING						//inverting Mode
		SetBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		#else
		#warning "Wrong Input for Timer 0 Fast PWM Mode Output Pin(OC0) Mode Select"
		#endif
	#elif TIMER0_MODE_SELECT == PWM_PHASE_CORRECT			//select Phase Correct PWM Mode
	ClearBit(TCCR0,WGM01);
	SetBit(TCCR0,WGM00);
			/****************Timer 0 phase correct PWM Mode Output Pin Mode Select******************************/
		#if TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		==	 CLEAR_WHEN_UP_SET_WHEN_DOWN			// Clear when count up , Set when count down
		SetBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#elif TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE	==	 SET_WHEN_UP_CLEAR_WHEN_DOWN			// Set when count up , Clear when count down
		SetBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		#elif TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE == OC0_DISCONNECTED
		ClearBit(TCCR0,COM01);
		ClearBit(TCCR0,COM00);
		#endif
	#else 										// Generate warning Timer0 mode select
	//Wrong input
	#warning "Wrong Input for Timer 0 MODE"
	#endif

		/*************************************************
		//put the required preload value in the TCNT for the first overflow
		 */
		TCNT0=TIMER0_PRELOAD_VALUE;

	/****************Timer 0 Prescaler Select*************************/
	#if TIMER0_PRESCALER_SELECT == NO_ClOCK_SOURCE		//No clock source (Timer/Counter stopped).
	ClearBit(TCCR0,CS02);
	ClearBit(TCCR0,CS01);
	ClearBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_1			//clkI/O/(No prescaling)
	ClearBit(TCCR0,CS02);
	ClearBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_8			//clkI/O/8 (From prescaler)
	ClearBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	ClearBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_64			//clkI/O/64 (From prescaler)
	ClearBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_256			//clkI/O/256 (From prescaler)
	SetBit(TCCR0,CS02);
	ClearBit(TCCR0,CS01);
	ClearBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_1024			//clkI/O/1024 (From prescaler)
	SetBit(TCCR0,CS02);
	ClearBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_EXTERNAL_T0_FALLINGEDGE			//External clock source on T0 pin. Clock on falling edge.
	SetBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	ClearBit(TCCR0,CS00);
	#elif TIMER0_PRESCALER_SELECT == PRESCALER_EXTERNAL_T0_RISINGEDGE			//External clock source on T0 pin. Clock on rising edge.
	SetBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);
	#else 													// Generate warning Timer0 Prescaler select
	#warning "Wrong Input for Timer 0 Prescaler"
	#endif


	/*****************Timer 0 Overflow Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER0_NORMAL_MODE_INTERRUPT == ENABLE
	SetBit(TIMSK,TOIE0);
	#elif TIMER0_NORMAL_MODE_INTERRUPT == DISABLE
	ClearBit(TIMSK,TOIE0);
	#endif

	/*****************Timer 0 Compare Match Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER0_CTC_MODE_INTERRUPT == ENABLE
	SetBit(TIMSK,OCIE0);
	#elif TIMER0_CTC_MODE_INTERRUPT == DISABLE
	ClearBit(TIMSK,OCIE0);
	#endif

	//global interrupt (if it's not here make sure it's in the main)
	//GlobalInterrupt_VoidEnableGlobalInterrupt();
}


/*This function takes the duty cycle as a percentage from 0 to 100*/
void Timer0_VoidSetDutyCycle(u8 Copy_U8Duty)
{
	OCR0=(Copy_U8Duty/(f32)100)*255;
}

void Timer0_SetCallBackFun_CTC_ISR ( void(*Timer0_CopyPtrToFun_CTC_ISR)(void) )
{
	Timer0_GlobalPtrToFun_CTC_ISR=Timer0_CopyPtrToFun_CTC_ISR;
}

void Timer0_SetCallBackFun_OverFlow_ISR ( void(*Timer0_CopyPtrToFun_OverFlow_ISR)(void) )
{
	Timer0_GlobalPtrToFun_OverFlow_ISR=Timer0_CopyPtrToFun_OverFlow_ISR;
}

/************************************************TIMER1****************************************************************************************/
void Timer1_VoidInit(void)
{
	/****************Timer 1 Mode Select******************************/
	#if TIMER1_MODE_SELECT == TIMER1_NORMAL				//Select normal mode
	ClearBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);			// for normal mode OC1A/OC1B disconnected.		(3mlt el pins di f el Normal mode bs table 44,45,46)
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
			//ICU Noise Canceler Activation
			#if TIMER1_ICU_NOISE_CANCELER_SELECT == TIMER1_ICU_NOISE_CANCELER_ENABLE
			SetBit(TCCR1B,ICNC1);
			#elif TIMER1_ICU_NOISE_CANCELER_SELECT == TIMER1_ICU_NOISE_CANCELER_DISABLE
			ClearBit(TCCR1B,ICNC1);
			#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_CORRECT_8BITS					//Select PWM, Phase Correct, 8-bit
	ClearBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_CORRECT_9BITS					//Select PWM, Phase Correct, 9-bit
	ClearBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_CORRECT_10BITS					//Select PWM, Phase Correct, 10-bit
	ClearBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_CTC_TOP_OCR1A					//Select CTC with OCR1A as top
	ClearBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if	TIMER1_CTC_TOP_OCR1A_OC1A_Behaviour == TIMER1_CTC_TOP_OCR1A_OC1A_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1A_Behaviour == TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1A_ON_COMPARE_MATCH
		ClearBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1A_Behaviour == TIMER1_CTC_TOP_OCR1A_CLEAR_OC1A_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1A_Behaviour == TIMER1_CTC_TOP_OCR1A_SET_OC1A_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if	TIMER1_CTC_TOP_OCR1A_OC1B_Behaviour == TIMER1_CTC_TOP_OCR1A_OC1B_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1B_Behaviour == TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1B_ON_COMPARE_MATCH
		ClearBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1B_Behaviour == TIMER1_CTC_TOP_OCR1A_CLEAR_OC1B_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_OCR1A_OC1B_Behaviour == TIMER1_CTC_TOP_OCR1A_SET_OC1B_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_FAST_8BITS					//Select Fast PWM, 8-bit
	ClearBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1B1);
		SetBit(TCCR2,COM1B0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_FAST_9BITS					//Select Fast PWM, 9-bit
	ClearBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1B1);
		SetBit(TCCR2,COM1B0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_FAST_10BITS					//Select Fast PWM, 10-bit
	ClearBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1B1);
		SetBit(TCCR2,COM1B0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1				//Select PWM, Phase and Frequency Correct with ICR1 as top
	SetBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A			//Select PWM, Phase and Frequency Correct with OCR1A as top
	SetBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_CORRECT_TOP_ICR1					//Select PWM, Phase Correct with ICR1 as top
	SetBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A					//Select PWM, Phase Correct with OCR1A as top
	SetBit(TCCR1B,WGM13);
	ClearBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);

	#elif TIMER1_MODE_SELECT == TIMER1_CTC_TOP_ICR1					//Select CTC with ICR1 as top
	SetBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);
					//OC1A pin behaviour
		#if	TIMER1_CTC_TOP_ICR1_OC1A_Behaviour == TIMER1_CTC_TOP_ICR1_OC1A_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1A_Behaviour == TIMER1_CTC_TOP_ICR1_TOGGLE_OC1A_ON_COMPARE_MATCH
		ClearBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1A_Behaviour == TIMER1_CTC_TOP_ICR1_CLEAR_OC1A_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1A_Behaviour == TIMER1_CTC_TOP_ICR1_SET_OC1A_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
					//OC1B pin behaviour
		#if	TIMER1_CTC_TOP_ICR1_OC1B_Behaviour == TIMER1_CTC_TOP_ICR1_OC1B_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1B_Behaviour == TIMER1_CTC_TOP_ICR1_TOGGLE_OC1B_ON_COMPARE_MATCH
		ClearBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1B_Behaviour == TIMER1_CTC_TOP_ICR1_CLEAR_OC1B_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif	TIMER1_CTC_TOP_ICR1_OC1B_Behaviour == TIMER1_CTC_TOP_ICR1_SET_OC1B_ON_COMPARE_MATCH
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_FAST_TOP_ICR1					//Select Fast PWM with ICR1 as top
	SetBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	ClearBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1B1);
		SetBit(TCCR2,COM1B0);
		#endif

	#elif TIMER1_MODE_SELECT == TIMER1_PWM_FAST_TOP_OCR1A					//Select Fast PWM with OCR1A as top
	SetBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1A,WGM10);
		//OC1A pin behaviour
		#if TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1A1);
		ClearBit(TCCR2,COM1A0);
		#elif TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1A1);
		SetBit(TCCR2,COM1A0);
		#endif
		//OC1B pin behaviour
		#if TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_DISCONNECTED
		ClearBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_NON_INVERTING
		SetBit(TCCR2,COM1B1);
		ClearBit(TCCR2,COM1B0);
		#elif TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE	==	TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_INVERTING
		SetBit(TCCR2,COM1B1);
		SetBit(TCCR2,COM1B0);
		#endif

	#endif




		/*************************************************
		//put the required preload value in the TCNT for the first overflow
		 */
	//	TCNT2=TIMER2_PRELOAD_VALUE;



	/****************Timer 1 Prescaler Select*************************/
	#if TIMER1_PRESCALER_SELECT == TIMER1_NO_ClOCK_SOURCE		//No clock source (Timer/Counter stopped).
	ClearBit(TCCR1B,CS12);
	ClearBit(TCCR1B,CS11);
	ClearBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_1			//clkI/O/(No prescaling)
	ClearBit(TCCR1B,CS12);
	ClearBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_8			//clkI/O/8 (From prescaler)
	ClearBit(TCCR1B,CS12);
	SetBit(TCCR1B,CS11);
	ClearBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_64			//clkI/O/64 (From prescaler)
	ClearBit(TCCR1B,CS12);
	SetBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_256			//clkI/O/256 (From prescaler)
	SetBit(TCCR1B,CS12);
	ClearBit(TCCR1B,CS11);
	ClearBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_1024			//clkI/O/1024 (From prescaler)
	SetBit(TCCR1B,CS12);
	ClearBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_EXTERNAL_T1_FALLINGEDGE			//External clock source on T1 pin. Clock on falling edge.
	SetBit(TCCR1B,CS12);
	SetBit(TCCR1B,CS11);
	ClearBit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == TIMER1_PRESCALER_EXTERNAL_T1_RISINGEDGE			//External clock source on T1 pin. Clock on rising edge.
	SetBit(TCCR1B,CS12);
	SetBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	#else 													// Generate warning Timer1 Prescaler select
	#warning "Wrong Input for Timer 1 Prescaler"
	#endif




	/*****************Timer 1 Overflow Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER1_NORMAL_MODE_INTERRUPT == TIMER1_NORMAL_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,TOIE1);
	#elif TIMER1_NORMAL_MODE_INTERRUPT == TIMER1_NORMAL_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,TOIE1);
	#endif

	/*****************Timer 1 Compare A Match Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER1_CTC_A_MODE_INTERRUPT == TIMER1_CTC_A_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,OCIE1A);
	#elif TIMER1_CTC_A_MODE_INTERRUPT == TIMER1_CTC_A_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,OCIE1A);
	#endif

	/*****************Timer 1 Compare B Match Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER1_CTC_B_MODE_INTERRUPT == TIMER1_CTC_B_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,OCIE1B);
	#elif TIMER1_CTC_B_MODE_INTERRUPT == TIMER1_CTC_B_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,OCIE1B);
	#endif

	/*****************Timer 1 Input Capture Interrupt Enable/Disable****************************************/
	//(if you enable the ICU INT make sure that you enabled the Overflow INT)
	#if TIMER1_ICU_MODE_INTERRUPT == TIMER1_ICU_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,TICIE1);
	#elif TIMER1_ICU_MODE_INTERRUPT == TIMER1_ICU_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,TICIE1);
	#endif

	//global interrupt (if it's not here make sure it's in the main)
	//GlobalInterrupt_VoidEnableGlobalInterrupt();}
}

/*This function Select the Trigger that raise the interrupt of the ICU as the falling edge on the ICP1 Pin*/
void Timer1_VoidSelectICU_FallingEdge(void)
{
	ClearBit(TCCR1B,ICES1);
}

/*This function Select the Trigger that raise the interrupt of the ICU as the rising edge on the ICP1 Pin*/
void Timer1_VoidSelectICU_RisingEdge(void)
{
	SetBit(TCCR1B,ICES1);
}

void Timer1_SetCallBackFun_Capture_ISR ( void(*Timer1_CopyPtrToFun_CAPTURE_ISR)(void) )
{
	Timer1_GlobalPtrToFun_CAPTURE_ISR=Timer1_CopyPtrToFun_CAPTURE_ISR;
}

void Timer1_SetCallBackFun_OverFlow_ISR ( void(*Timer1_CopyPtrToFun_OverFlow_ISR)(void) )
{
	Timer1_GlobalPtrToFun_OverFlow_ISR=Timer1_CopyPtrToFun_OverFlow_ISR;
}


/************************************************TIMER2****************************************************************************************/
void Timer2_VoidInit(void)
{

	/****************Timer 2 Mode Select******************************/
	#if TIMER2_MODE_SELECT == TIMER2_NORMAL				//Select normal mode
	ClearBit(TCCR2,WGM21);
	ClearBit(TCCR2,WGM20);
	ClearBit(TCCR2,COM21);
	ClearBit(TCCR2,COM20);
	#elif TIMER2_MODE_SELECT == TIMER2_CTC					//Select CTC
	SetBit(TCCR2,WGM21);
	ClearBit(TCCR2,WGM20);
	OCR2=TIMER2_COMPAREMATCH_VALUE;
		/****************Timer 2 NON-PWM Mode Output Pin(OC2) Mode Select******************************/
		#if TIMER2_NON_PWM_MODE_OUTPUTPIN_MODE == TIMER2_OC2_DISCONNECTED
		ClearBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#elif TIMER2_NON_PWM_MODE_OUTPUTPIN_MODE == TIMER2_TOGGLE_OC2_ON_COMPARE_MATCH
		ClearBit(TCCR2,COM21);
		SetBit(TCCR2,COM20);
		#elif TIMER2_NON_PWM_MODE_OUTPUTPIN_MODE == TIMER2_CLEAR_OC2_ON_COMPARE_MATCH
		SetBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#elif TIMER2_NON_PWM_MODE_OUTPUTPIN_MODE == TIMER2_SET_OC2_ON_COMPARE_MATCH
		SetBit(TCCR2,COM21);
		SetBit(TCCR2,COM20);
		#else
		#warning "Wrong Input for Timer 2 NON-PWM Mode Output Pin(OC2) Mode Select"
		#endif
	#elif TIMER2_MODE_SELECT == TIMER2_PWM_FAST			//select Fast PWM Mode
	SetBit(TCCR2,WGM21);
	SetBit(TCCR2,WGM20);
		/****************Timer 2 Fast PWM Mode Output Pin(OC2) Mode Select******************************/
		#if TIMER2_FAST_PWM_MODE_OUTPUTPIN_MODE		==	 TIMER2_OC2_DISCONNECTED
		ClearBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#elif TIMER2_FAST_PWM_MODE_OUTPUTPIN_MODE		==	 TIMER2_NON_INVERTING					//Noninverting Mode
		SetBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#elif TIMER2_FAST_PWM_MODE_OUTPUTPIN_MODE	==	 TIMER2_INVERTING						//inverting Mode
		SetBit(TCCR2,COM21);
		SetBit(TCCR2,COM20);
		#else
		#warning "Wrong Input for Timer 2 Fast PWM Mode Output Pin(OC2) Mode Select"
		#endif
	#elif TIMER2_MODE_SELECT == TIMER2_PWM_PHASE_CORRECT			//select Phase Correct PWM Mode
	ClearBit(TCCR2,WGM21);
	SetBit(TCCR2,WGM20);
			/****************Timer 2 phase correct PWM Mode Output Pin Mode Select******************************/
		#if TIMER2_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		==	 TIMER2_CLEAR_WHEN_UP_SET_WHEN_DOWN			// Clear when count up , Set when count down
		SetBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#elif TIMER2_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE	==	 TIMER2_SET_WHEN_UP_CLEAR_WHEN_DOWN			// Set when count up , Clear when count down
		SetBit(TCCR2,COM21);
		SetBit(TCCR2,COM20);
		#elif TIMER2_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE == TIMER2_OC2_DISCONNECTED
		ClearBit(TCCR2,COM21);
		ClearBit(TCCR2,COM20);
		#endif
	#else 										// Generate warning Timer2 mode select
	//Wrong input
	#warning "Wrong Input for Timer 2 MODE"
	#endif

		/*************************************************
		//put the required preload value in the TCNT for the first overflow
		 */
		TCNT2=TIMER2_PRELOAD_VALUE;

	/****************Timer 2 Prescaler Select*************************/
	#if TIMER2_PRESCALER_SELECT == TIMER2_NO_ClOCK_SOURCE		//No clock source (Timer/Counter stopped).
	ClearBit(TCCR2,CS22);
	ClearBit(TCCR2,CS21);
	ClearBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_1			//clkI/O/(No prescaling)
	ClearBit(TCCR2,CS22);
	ClearBit(TCCR2,CS21);
	SetBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_8			//clkI/O/8 (From prescaler)
	ClearBit(TCCR2,CS22);
	SetBit(TCCR2,CS21);
	ClearBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_32			//clkI/O/32 (From prescaler)
	ClearBit(TCCR2,CS22);
	SetBit(TCCR2,CS21);
	SetBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_64			//clkI/O/64 (From prescaler)
	SetBit(TCCR2,CS22);
	ClearBit(TCCR2,CS21);
	ClearBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_128			//clkI/O/128 (From prescaler)
	SetBit(TCCR2,CS22);
	ClearBit(TCCR2,CS21);
	SetBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_256			//clkI/O/256 (From prescaler)
	SetBit(TCCR2,CS22);
	SetBit(TCCR2,CS21);
	ClearBit(TCCR2,CS20);
	#elif TIMER2_PRESCALER_SELECT == TIMER2_PRESCALER_1024			//clkI/O/1024 (From prescaler)
	SetBit(TCCR2,CS22);
	SetBit(TCCR2,CS21);
	SetBit(TCCR2,CS20);
	#else 													// Generate warning Timer2 Prescaler select
	#warning "Wrong Input for Timer 2 Prescaler"
	#endif


	/*****************Timer 2 Overflow Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER2_NORMAL_MODE_INTERRUPT == TIMER2_NORMAL_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,TOIE2);
	#elif TIMER2_NORMAL_MODE_INTERRUPT == TIMER2_NORMAL_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,TOIE2);
	#endif

	/*****************Timer 2 Compare Match Interrupt Enable/Disable (For PWM Disable this interrupt)*******/
	#if TIMER2_CTC_MODE_INTERRUPT == TIMER2_CTC_MODE_INTERRUPT_ENABLE
	SetBit(TIMSK,OCIE2);
	#elif TIMER2_CTC_MODE_INTERRUPT == TIMER2_CTC_MODE_INTERRUPT_DISABLE
	ClearBit(TIMSK,OCIE2);
	#endif

	//global interrupt (if it's not here make sure it's in the main)
	//GlobalInterrupt_VoidEnableGlobalInterrupt();
}

/*This function takes the duty cycle as a percentage from 0 to 100*/
void Timer2_VoidSetDutyCycle(u8 Copy_U8Duty)
{
	OCR2=(Copy_U8Duty/(f32)100)*255;
}

void Timer2_SetCallBackFun_CTC_ISR ( void(*Timer2_CopyPtrToFun_CTC_ISR)(void) )
{
	Timer2_GlobalPtrToFun_CTC_ISR=Timer2_CopyPtrToFun_CTC_ISR;
}

void Timer2_SetCallBackFun_OverFlow_ISR ( void(*Timer2_CopyPtrToFun_OverFlow_ISR)(void) )
{
	Timer2_GlobalPtrToFun_OverFlow_ISR=Timer2_CopyPtrToFun_OverFlow_ISR;
}
















/************************************************ISRs****************************************************************************************/

//Timer/Counter0 Overflow ISR
void TIMER0_OVF_ISR(void)
{
	if (Timer0_GlobalPtrToFun_OverFlow_ISR!='\0')
	{
		Timer0_GlobalPtrToFun_OverFlow_ISR();
	}

	/*
	static u16 Timer0_StaticU16OverflowCount=0;
	Timer0_StaticU16OverflowCount++;

	if (Timer0_StaticU16OverflowCount==TIMER0_MAX_OVERFLOW)
	{
		DIO_TogPinValue(PORTB,PIN0);
		Timer0_StaticU16OverflowCount=0;
		TCNT0=TIMER0_PRELOAD_VALUE;

	}
	*/
}

//Timer/Counter2 Overflow ISR
void TIMER2_OVF_ISR(void)
{
	if (Timer2_GlobalPtrToFun_OverFlow_ISR!='\0')
	{
		Timer2_GlobalPtrToFun_OverFlow_ISR();
	}

/*
	static u16 Timer2_StaticU16OverflowCount=0;
	Timer2_StaticU16OverflowCount++;

	if (Timer2_StaticU16OverflowCount==TIMER2_MAX_OVERFLOW)
	{
		DIO_TogPinValue(PORTB,PIN0);
		Timer2_StaticU16OverflowCount=0;
		TCNT2=TIMER2_PRELOAD_VALUE;

	}
*/
}

//Timer/Counter0 Compare Match ISR
void TIMER0_CTC_ISR(void)
{
	if (Timer0_GlobalPtrToFun_CTC_ISR!='\0')
	{
		Timer0_GlobalPtrToFun_CTC_ISR();
	}

	/*
	static u16 Timer0_StaticU16OverflowCount=0;
	Timer0_StaticU16OverflowCount++;

	if (Timer0_StaticU16OverflowCount==TIMER0_MAX_OVERFLOW)
	{
		DIO_TogPinValue(PORTB,PIN0);
		Timer0_StaticU16OverflowCount=0;

	}
	*/
}

//Timer/Counter2 Compare Match ISR
void TIMER2_CTC_ISR(void)
{
	if (Timer2_GlobalPtrToFun_CTC_ISR!='\0')
	{
		Timer2_GlobalPtrToFun_CTC_ISR();
	}

	/*
	static u16 Timer2_StaticU16OverflowCount=0;
	Timer2_StaticU16OverflowCount++;

	if (Timer2_StaticU16OverflowCount==TIMER2_MAX_OVERFLOW)
	{
		DIO_TogPinValue(PORTB,PIN0);
		Timer2_StaticU16OverflowCount=0;

	}
	*/
}


//Timer/Counter1 Input Capture Unit ISR
void TIMER1_CAPTURE_ISR(void)
{
	if (Timer1_GlobalPtrToFun_CAPTURE_ISR!='\0')
	{
		Timer1_GlobalPtrToFun_CAPTURE_ISR();
	}
	/*
	if (Timer1_GlobalU8ICUFlag==0)
	{
		Timer1_GlobalU16OverflowCount=0;
		SNAP1=ICR1LH+(Timer1_GlobalU16OverflowCount*65536);
		//Edge sellect falling
		ClearBit(TCCR1B,ICES1);		// For ICU Set FALLING edge
		Timer1_GlobalU8ICUFlag=1;
	}
	else if (Timer1_GlobalU8ICUFlag==1)
	{
		SNAP2=ICR1LH+(Timer1_GlobalU16OverflowCount*65536);
		//Edge sellect rising
		SetBit(TCCR1B,ICES1);		// For ICU Set rising edge
		Timer1_GlobalU8ICUFlag=2;
	}
	else if (Timer1_GlobalU8ICUFlag==2)
	{
		SNAP3=ICR1LH+(Timer1_GlobalU16OverflowCount*65536);
		Timer1_GlobalU8ICUFlag=3;
	}

	*/
}
//Timer/Counter1 Overflow ISR ISR
void TIMER1_OVF_ISR(void)
{
	Timer1_GlobalPtrToFun_OverFlow_ISR();
/*
	Timer1_GlobalU16OverflowCount++;
*/
}
