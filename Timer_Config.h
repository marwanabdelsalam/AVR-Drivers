/*
 * Timer_Config.h
 *
 *  Created on: Jun 6, 2021
 *      Author: m
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/***************************************************************************************************************/
/*************************************** Timer 0 ***************************************************************/
/***************************************************************************************************************/

/******************************	Timer 0 Maximum Overflow Value saved in static u16 variable in Timer0 Overflow ISR (countOV)*****************************/
#define TIMER0_MAX_OVERFLOW 10000
/******************************	Timer 0 Preload Value (TCNT0) (max preload value is 255)*****************************/
#define TIMER0_PRELOAD_VALUE	0
/******************************	Timer 0 Compare Match Value (OCR0) (max Compare Match Value is 255)*****************************/
#define TIMER0_COMPAREMATCH_VALUE	100

/****************Timer 0 Select Mode *********************
NORMAL				=	0
CTC					=	1
PWM_FAST			=	2
PWM_PHASE_CORRECT	=	3
 */
#define TIMER0_MODE_SELECT		 PWM_FAST



/****************Timer 0 Prescaler Select*************************
 NO_ClOCK_SOURCE					=	0
 PRESCALER_1						=	1
 PRESCALER_8						=	2
 PRESCALER_64						=	3
 PRESCALER_256						=	4
 PRESCALER_1024						=	5
 PRESCALER_EXTERNAL_T0_FALLINGEDGE	=	6
 PRESCALER_EXTERNAL_T0_RISINGEDGE	=	7 							*/
#define TIMER0_PRESCALER_SELECT		 PRESCALER_256



/****************Timer 0 Fast PWM Mode Output Pin(OC0) Mode Select******************************
OC0_DISCONNECTED    =	0
NON_INVERTING		=	1
INVERTING			=	2										*/
#define TIMER0_FAST_PWM_MODE_OUTPUTPIN_MODE		 NON_INVERTING

/****************Timer 0 NON-PWM Mode Output Pin(OC0) Mode Select******************************
 OC0_DISCONNECTED				=		0
 TOGGLE_OC0_ON_COMPARE_MATCH	=		1
 CLEAR_OC0_ON_COMPARE_MATCH		=		2
 SET_OC0_ON_COMPARE_MATCH		=		3				*/
#define TIMER0_NON_PWM_MODE_OUTPUTPIN_MODE 	OC0_DISCONNECTED


/*****************Timer 0 Phase Correct PWM Select OUTPUT pin Mode *******************
OC0_DISCONNECTED 					=	0
CLEAR_WHEN_UP_SET_WHEN_DOWN			=	1
SET_WHEN_UP_CLEAR_WHEN_DOWN			=	2						*/
#define TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		 SET_WHEN_UP_CLEAR_WHEN_DOWN







/*******************************	Timer 0 NORMAL MODE Interrupt Select	**************************
 ENABLE  = 0
 DISABLE = 1			*/
#define TIMER0_NORMAL_MODE_INTERRUPT	DISABLE


/*******************************	Timer 0 CTC MODE Interrupt Select	**************************
 ENABLE  = 0
 DISABLE = 1			*/
#define TIMER0_CTC_MODE_INTERRUPT	DISABLE






/***************************************************************************************************************/
/*************************************** Timer 2 ***************************************************************/
/***************************************************************************************************************/
/******************************	Timer 2 Maximum Overflow Value saved in static u16 variable in Timer2 Overflow ISR (countOV)*****************************/
#define TIMER2_MAX_OVERFLOW 5000
/******************************	Timer 0 Preload Value (TCNT2) (max preload value is 255)*****************************/
#define TIMER2_PRELOAD_VALUE	0
/******************************	Timer 0 Compare Match Value (OCR2) (max Compare Match Value is 255)*****************************/
#define TIMER2_COMPAREMATCH_VALUE	100
/****************Timer 2 Select Mode *********************
TIMER2_NORMAL				=	0
TIMER2_CTC					=	1
TIMER2_PWM_FAST				=	2
TIMER2_PWM_PHASE_CORRECT	=	3
 */
#define TIMER2_MODE_SELECT		 TIMER2_PWM_FAST
/****************Timer 2 Prescaler Select*************************
 TIMER2_NO_ClOCK_SOURCE						=	0
 TIMER2_PRESCALER_1							=	1
 TIMER2_PRESCALER_8							=	2
 TIMER2_PRESCALER_32						=	3
 TIMER2_PRESCALER_64						=	4
 TIMER2_PRESCALER_128						=	5
 TIMER2_PRESCALER_256						=	6
 TIMER2_PRESCALER_1024						=	7 							*/
#define TIMER2_PRESCALER_SELECT		 TIMER2_PRESCALER_8
/****************Timer 2 Fast PWM Mode Output Pin(OC2) Mode Select******************************
TIMER2_OC2_DISCONNECTED    =	0
TIMER2_NON_INVERTING		=	1
TIMER2_INVERTING			=	2										*/
#define TIMER2_FAST_PWM_MODE_OUTPUTPIN_MODE		 TIMER2_NON_INVERTING
/****************Timer 2 NON-PWM Mode Output Pin(OC0) Mode Select******************************
 TIMER2_OC2_DISCONNECTED				=		0
 TIMER2_TOGGLE_OC2_ON_COMPARE_MATCH		=		1
 TIMER2_CLEAR_OC2_ON_COMPARE_MATCH		=		2
 TIMER2_SET_OC2_ON_COMPARE_MATCH		=		3				*/
#define TIMER2_NON_PWM_MODE_OUTPUTPIN_MODE 	TIMER2_OC2_DISCONNECTED
/*****************Timer 2 Phase Correct PWM Select OUTPUT pin Mode *******************
TIMER2_OC2_DISCONNECTED 					=	0
TIMER2_CLEAR_WHEN_UP_SET_WHEN_DOWN			=	1
TIMER2_SET_WHEN_UP_CLEAR_WHEN_DOWN			=	2						*/
#define TIMER2_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		 TIMER2_SET_WHEN_UP_CLEAR_WHEN_DOWN
/*******************************	Timer 2 NORMAL MODE Interrupt Select	**************************
 TIMER2_NORMAL_MODE_INTERRUPT_ENABLE  = 0
 TIMER2_NORMAL_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER2_NORMAL_MODE_INTERRUPT			TIMER2_NORMAL_MODE_INTERRUPT_DISABLE

/*******************************	Timer 2 CTC MODE Interrupt Select	**************************
 TIMER2_NORMAL_MODE_INTERRUPT_ENABLE  = 0
 TIMER2_NORMAL_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER2_CTC_MODE_INTERRUPT				TIMER2_NORMAL_MODE_INTERRUPT_DISABLE





/***************************************************************************************************************/
/*************************************** Timer 1 ***************************************************************/
/***************************************************************************************************++************/
/****************Timer 1 Select Mode *********************
TIMER1_NORMAL									=	0
TIMER1_PWM_PHASE_CORRECT_8BITS					=	1
TIMER1_PWM_PHASE_CORRECT_9BITS					=	2
TIMER1_PWM_PHASE_CORRECT_10BITS					=	3
TIMER1_CTC_TOP_OCR1A							=	4
TIMER1_PWM_FAST_8BITS							=	5
TIMER1_PWM_FAST_9BITS							=	6
TIMER1_PWM_FAST_10BITS							=	7
TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1		=	8
TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A	=	9
TIMER1_PWM_PHASE_CORRECT_TOP_ICR1				=	10
TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A				=	11
TIMER1_CTC_TOP_ICR1								=	12
TIMER1_PWM_FAST_TOP_ICR1						=	13
TIMER1_PWM_FAST_TOP_OCR1A						=	14
 */
#define TIMER1_MODE_SELECT 			TIMER1_CTC_TOP_ICR1
/****************Timer 1 Prescaler Select*************************
 TIMER1_NO_ClOCK_SOURCE					=	0
 TIMER1_PRESCALER_1						=	1
 TIMER1_PRESCALER_8						=	2
 TIMER1_PRESCALER_64						=	3
 TIMER1_PRESCALER_256						=	4
 TIMER1_PRESCALER_1024						=	5
 TIMER1_PRESCALER_EXTERNAL_T1_FALLINGEDGE	=	6
 TIMER1_PRESCALER_EXTERNAL_T1_RISINGEDGE	=	7 							*/
#define TIMER1_PRESCALER_SELECT TIMER1_PRESCALER_256
/*******************************	Timer 1 NORMAL MODE Interrupt Select	**************************
 TIMER1_NORMAL_MODE_INTERRUPT_ENABLE  = 0
 TIMER1_NORMAL_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER1_NORMAL_MODE_INTERRUPT				TIMER1_NORMAL_MODE_INTERRUPT_DISABLE
/*******************************	Timer 1 CTC A MODE Interrupt Select	**************************
 TIMER1_CTC_A_MODE_INTERRUPT_ENABLE  = 0
 TIMER1_CTC_A_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER1_CTC_A_MODE_INTERRUPT				TIMER1_CTC_A_MODE_INTERRUPT_DISABLE
/*******************************	Timer 1 CTC B MODE Interrupt Select	**************************
 TIMER1_CTC_B_MODE_INTERRUPT_ENABLE  = 0
 TIMER1_CTC_B_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER1_CTC_B_MODE_INTERRUPT				TIMER1_CTC_B_MODE_INTERRUPT_DISABLE
/*******************************	Timer 1 Input Capture Interrupt Select	**************************
 TIMER1_ICU_MODE_INTERRUPT_ENABLE  = 0
 TIMER1_ICU_MODE_INTERRUPT_DISABLE = 1			*/
#define TIMER1_ICU_MODE_INTERRUPT				TIMER1_ICU_MODE_INTERRUPT_DISABLE
/****************Timer 1 NON-PWM Mode(CTC TOP_OCR1A) Output Pin(OC1A) Mode Select******************************
 TIMER1_CTC_TOP_OCR1A_OC1A_DISCONNECTED						0
 TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1A_ON_COMPARE_MATCH			1
 TIMER1_CTC_TOP_OCR1A_CLEAR_OC1A_ON_COMPARE_MATCH			2
 TIMER1_CTC_TOP_OCR1A_SET_OC1A_ON_COMPARE_MATCH				3		*/
#define TIMER1_CTC_TOP_OCR1A_OC1A_Behaviour TIMER1_CTC_TOP_OCR1A_OC1A_DISCONNECTED
/****************Timer 1 NON-PWM Mode(CTC TOP_OCR1A) Output Pin(OC1B) Mode Select******************************
 TIMER1_CTC_TOP_OCR1A_OC1B_DISCONNECTED						0
 TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1B_ON_COMPARE_MATCH			1
 TIMER1_CTC_TOP_OCR1A_CLEAR_OC1B_ON_COMPARE_MATCH			2
 TIMER1_CTC_TOP_OCR1A_SET_OC1B_ON_COMPARE_MATCH				3		*/
 #define TIMER1_CTC_TOP_OCR1A_OC1B_Behaviour TIMER1_CTC_TOP_OCR1A_OC1B_DISCONNECTED
/****************Timer 1 NON-PWM Mode(CTC TOP_ICR1) Output Pin(OC1A) Mode Select******************************
 TIMER1_CTC_TOP_ICR1_OC1A_DISCONNECTED						0
 TIMER1_CTC_TOP_ICR1_TOGGLE_OC1A_ON_COMPARE_MATCH			1
 TIMER1_CTC_TOP_ICR1_CLEAR_OC1A_ON_COMPARE_MATCH			2
 TIMER1_CTC_TOP_ICR1_SET_OC1A_ON_COMPARE_MATCH				3		*/
 #define TIMER1_CTC_TOP_ICR1_OC1A_Behaviour TIMER1_CTC_TOP_ICR1_OC1A_DISCONNECTED
/****************Timer 1 NON-PWM Mode(CTC TOP_ICR1) Output Pin(OC1B) Mode Select******************************
 TIMER1_CTC_TOP_ICR1_OC1B_DISCONNECTED						0
 TIMER1_CTC_TOP_ICR1_TOGGLE_OC1B_ON_COMPARE_MATCH			1
 TIMER1_CTC_TOP_ICR1_CLEAR_OC1B_ON_COMPARE_MATCH			2
 TIMER1_CTC_TOP_ICR1_SET_OC1B_ON_COMPARE_MATCH				3		*/
#define TIMER1_CTC_TOP_ICR1_OC1B_Behaviour TIMER1_CTC_TOP_ICR1_OC1B_DISCONNECTED
/****************Timer 1 Fast PWM Mode 8bits Output Pin(OC1A) Mode Select******************************
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2			*/
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE			TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode 8bits Output Pin(OC1B) Mode Select******************************
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2			*/
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE			TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode 9bits Output Pin(OC1A) Mode Select*****************************
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2			*/
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE			TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode 9bits Output Pin(OC1B) Mode Select******************************
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2			*/
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE			TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode 10bits Output Pin(OC1A) Mode Select******************************
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE			TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode 10bits Output Pin(OC1B) Mode Select******************************
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE			TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode TOP_ICR1 Output Pin(OC1A) Mode Select******************************
#define TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE			TIMER1_PWM_FAST_TOP_ICR1_OC1A_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode TOP_ICR1 Output Pin(OC1B) Mode Select******************************
#define TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE			TIMER1_PWM_FAST_TOP_ICR1_OC1B_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode TOP_OCR1A Output Pin(OC1A) Mode Select******************************
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE			TIMER1_PWM_FAST_TOP_OCR1A_OC1A_OUTPUTPIN_MODE_DISCONNECTED
/****************Timer 1 Fast PWM Mode TOP_OCR1A Output Pin(OC1B) Mode Select******************************
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_INVERTING			2		*/
#define TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE			TIMER1_PWM_FAST_TOP_OCR1A_OC1B_OUTPUTPIN_MODE_DISCONNECTED




#endif /* TIMER_CONFIG_H_ */
