/*
 * Timer_Private.h
 *
 *  Created on: Jun 6, 2021
 *      Author: m
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*************************************************************Registers Adresses*******************************************/
/***************Timer 0 Registers**************/
#define TCCR0 *((volatile u8*)(0x53))
#define TCNT0 *((volatile u8*)(0x52))
#define OCR0  *((volatile u8*)(0x5C))
#define TIMSK *((volatile u8*)(0x59))
#define TIFR  *((volatile u8*)(0x58))
#define SFIOR *((volatile u8*)(0x50))
/*************Timer 1 Registers****************/
#define TCCR1A *((volatile u8*)(0x4F))
#define TCCR1B *((volatile u8*)(0x4E))
#define TCNT1H *((volatile u8*)(0x4D))
#define TCNT1L *((volatile u8*)(0x4C))
#define OCR1AH *((volatile u8*)(0x4B))
#define OCR1AL *((volatile u8*)(0x4A))
#define OCR1BH *((volatile u8*)(0x49))
#define OCR1BL *((volatile u8*)(0x48))
#define ICR1H  *((volatile u8*)(0x47))
#define ICR1L  *((volatile u8*)(0x46))
/*************Timer 2 Registers****************/
#define TCCR2 *((volatile u8*)(0x45))
#define TCNT2 *((volatile u8*)(0x44))
#define OCR2  *((volatile u8*)(0x43))
#define ASSR  *((volatile u8*)(0x42))

/****************************************************************Mapping Registers Bits Names*************************/
//TCCR0 Register
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7
//TIMSK Register
#define TOIE0	 0
#define OCIE0	 1
#define TOIE1 	 2
#define OCIE1B	 3
#define OCIE1A	 4
#define TICIE1   5
#define TOIE2	 6
#define OCIE2    7
//TIFR Register
#define TOV0	 0
#define OCF0	 1
#define TOV1 	 2
#define OCF1B	 3
#define OCF1A	 4
#define ICF1   	 5
#define TOV2	 6
#define OCF2     7
//SFIOR Register
#define PSR10	 0
#define PSR2	 1
#define PUD 	 2
#define ACME	 3
#define ADTS0    5
#define ADTS1	 6
#define ADTS2    7
//TCCR1A Register
#define WGM10	0
#define WGM11	1
#define FOC1B	2
#define FOC1A	3
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7
//TCCR1B Register
#define CS10	0
#define CS11	1
#define CS12	2
#define WGM12	3
#define WGM13	4
#define ICES1	6
#define ICNC1	7
//TCCR2 Register
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7
//ASSR Register
#define TCR2UB	0
#define OCR2UB	1
#define TCN2UB	2
#define AS2	3

/**********************ISR Declarations****************************************************************************/
void __vector_4(void)  __attribute__((signal));		//Timer/Counter2 Compare Match
void __vector_5(void)  __attribute__((signal));		//Timer/Counter2 Overflow
void __vector_6(void)  __attribute__((signal));		//Timer/Counter1 Capture Event
void __vector_7(void)  __attribute__((signal));		//Timer/Counter1 Compare Match A
void __vector_8(void)  __attribute__((signal));		//Timer/Counter1 Compare Match B
void __vector_9(void)  __attribute__((signal));		//Timer/Counter1 Overflow
void __vector_10(void) __attribute__((signal));		//Timer/Counter0 Compare Match
void __vector_11(void) __attribute__((signal));		//Timer/Counter0 Overflow

/**********************ISR Mapping Names***************************************************************************/
#define TIMER2_CTC_ISR 		__vector_4
#define TIMER2_OVF_ISR		__vector_5
#define TIMER1_CAPTURE_ISR	__vector_6
#define TIMER1_CTC_A_ISR 	__vector_7
#define TIMER1_CTC_B_ISR	__vector_8
#define TIMER1_OVF_ISR 		__vector_9
#define TIMER0_CTC_ISR 		__vector_10
#define TIMER0_OVF_ISR		__vector_11



/****************Timer 0 Select Mode Options *********************/
#define NORMAL					0
#define CTC						1
#define PWM_FAST				2
#define PWM_PHASE_CORRECT		3
/****************Timer 0 Prescaler Select Options*************************/
#define NO_ClOCK_SOURCE							0
#define PRESCALER_1								1
#define PRESCALER_8								2
#define PRESCALER_64							3
#define PRESCALER_256							4
#define PRESCALER_1024							5
#define PRESCALER_EXTERNAL_T0_FALLINGEDGE		6
#define PRESCALER_EXTERNAL_T0_RISINGEDGE		7
/****************Timer 0 NON-PWM Mode Output Pin(OC0) Mode Select******************************/
#define OC0_DISCONNECTED					0
#define TOGGLE_OC0_ON_COMPARE_MATCH			1
#define CLEAR_OC0_ON_COMPARE_MATCH			2
#define SET_OC0_ON_COMPARE_MATCH			3
/****************Timer 0 Fast PWM Mode Output Pin(OC0) Mode Select******************************/
#define OC0_DISCONNECTED		0
#define NON_INVERTING			1
#define INVERTING				2
/*****************Timer 0 Phase Correct PWM Select OUTPUT pin Mode *******************/
#define OC0_DISCONNECTED				0
#define CLEAR_WHEN_UP_SET_WHEN_DOWN		1
#define SET_WHEN_UP_CLEAR_WHEN_DOWN		2
/*******************************	Timer 0 NORMAL MODE Interrupt Select	**************************/
#define ENABLE			0
#define DISABLE 		1
/*******************************	Timer 0 CTC MODE Interrupt Select	**************************/
#define ENABLE			0
#define DISABLE 		1




/****************Timer 2 Select Mode Options *********************/
#define TIMER2_NORMAL					0
#define TIMER2_CTC						1
#define TIMER2_PWM_FAST					2
#define TIMER2_PWM_PHASE_CORRECT		3
/****************Timer 2 Prescaler Select Options*************************/
#define TIMER2_NO_ClOCK_SOURCE							0
#define TIMER2_PRESCALER_1								1
#define TIMER2_PRESCALER_8								2
#define TIMER2_PRESCALER_32								3
#define TIMER2_PRESCALER_64								4
#define TIMER2_PRESCALER_128							5
#define TIMER2_PRESCALER_256							6
#define TIMER2_PRESCALER_1024							7
/****************Timer 2 NON-PWM Mode Output Pin(OC2) Mode Select******************************/
#define TIMER2_OC2_DISCONNECTED						0
#define TIMER2_TOGGLE_OC2_ON_COMPARE_MATCH			1
#define TIMER2_CLEAR_OC2_ON_COMPARE_MATCH			2
#define TIMER2_SET_OC2_ON_COMPARE_MATCH				3
/****************Timer 2 Fast PWM Mode Output Pin(OC2) Mode Select******************************/
#define TIMER2_OC2_DISCONNECTED			0
#define TIMER2_NON_INVERTING			1
#define TIMER2_INVERTING				2
/*****************Timer 2 Phase Correct PWM Select OUTPUT pin Mode *******************/
#define TIMER2_OC2_DISCONNECTED					0
#define TIMER2_CLEAR_WHEN_UP_SET_WHEN_DOWN		1
#define TIMER2_SET_WHEN_UP_CLEAR_WHEN_DOWN		2
/*******************************	Timer 2 NORMAL MODE Interrupt Select	**************************/
#define TIMER2_NORMAL_MODE_INTERRUPT_ENABLE			0
#define TIMER2_NORMAL_MODE_INTERRUPT_DISABLE 		1
/*******************************	Timer 2 CTC MODE Interrupt Select	**************************/
#define TIMER2_NORMAL_MODE_INTERRUPT_ENABLE			0
#define TIMER2_NORMAL_MODE_INTERRUPT_DISABLE 		1





/****************Timer 1 Select Mode Options *********************/
#define TIMER1_NORMAL										0
#define TIMER1_PWM_PHASE_CORRECT_8BITS						1
#define TIMER1_PWM_PHASE_CORRECT_9BITS						2
#define TIMER1_PWM_PHASE_CORRECT_10BITS						3
#define TIMER1_CTC_TOP_OCR1A								4
#define TIMER1_PWM_FAST_8BITS								5
#define TIMER1_PWM_FAST_9BITS								6
#define TIMER1_PWM_FAST_10BITS								7
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1			8
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A		9
#define TIMER1_PWM_PHASE_CORRECT_TOP_ICR1					10
#define TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A					11
#define TIMER1_CTC_TOP_ICR1									12
#define TIMER1_PWM_FAST_TOP_ICR1							13
#define TIMER1_PWM_FAST_TOP_OCR1A							14
/****************Timer 1 Prescaler Select Options*************************/
#define TIMER1_NO_ClOCK_SOURCE							0
#define TIMER1_PRESCALER_1								1
#define TIMER1_PRESCALER_8								2
#define TIMER1_PRESCALER_64								3
#define TIMER1_PRESCALER_256							4
#define TIMER1_PRESCALER_1024							5
#define TIMER1_PRESCALER_EXTERNAL_T1_FALLINGEDGE		6
#define TIMER1_PRESCALER_EXTERNAL_T1_RISINGEDGE			7
/*******************************	Timer 1 NORMAL MODE Interrupt Select	**************************/
#define TIMER1_NORMAL_MODE_INTERRUPT_ENABLE			0
#define TIMER1_NORMAL_MODE_INTERRUPT_DISABLE 		1
/*******************************	Timer 1 CTC A MODE Interrupt Select	**************************/
#define TIMER1_CTC_A_MODE_INTERRUPT_ENABLE			0
#define TIMER1_CTC_A_MODE_INTERRUPT_DISABLE 		1
/*******************************	Timer 1 CTC B MODE Interrupt Select	**************************/
#define TIMER1_CTC_B_MODE_INTERRUPT_ENABLE			0
#define TIMER1_CTC_B_MODE_INTERRUPT_DISABLE 		1
/*******************************	Timer 1 ICU MODE Interrupt Select	**************************/
#define TIMER1_ICU_MODE_INTERRUPT_ENABLE			0
#define TIMER1_ICU_MODE_INTERRUPT_DISABLE	 		1
/****************Timer 1 NON-PWM Mode(CTC TOP_OCR1A) Output Pin(OC1A) Mode Select******************************/
#define TIMER1_CTC_TOP_OCR1A_OC1A_DISCONNECTED						0
#define TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1A_ON_COMPARE_MATCH			1
#define TIMER1_CTC_TOP_OCR1A_CLEAR_OC1A_ON_COMPARE_MATCH			2
#define TIMER1_CTC_TOP_OCR1A_SET_OC1A_ON_COMPARE_MATCH				3
/****************Timer 1 NON-PWM Mode(CTC TOP_OCR1A) Output Pin(OC1B) Mode Select******************************/
#define TIMER1_CTC_TOP_OCR1A_OC1B_DISCONNECTED						0
#define TIMER1_CTC_TOP_OCR1A_TOGGLE_OC1B_ON_COMPARE_MATCH			1
#define TIMER1_CTC_TOP_OCR1A_CLEAR_OC1B_ON_COMPARE_MATCH			2
#define TIMER1_CTC_TOP_OCR1A_SET_OC1B_ON_COMPARE_MATCH				3
/****************Timer 1 NON-PWM Mode(CTC TOP_ICR1) Output Pin(OC1A) Mode Select******************************/
#define TIMER1_CTC_TOP_ICR1_OC1A_DISCONNECTED						0
#define TIMER1_CTC_TOP_ICR1_TOGGLE_OC1A_ON_COMPARE_MATCH			1
#define TIMER1_CTC_TOP_ICR1_CLEAR_OC1A_ON_COMPARE_MATCH				2
#define TIMER1_CTC_TOP_ICR1_SET_OC1A_ON_COMPARE_MATCH				3
/****************Timer 1 NON-PWM Mode(CTC TOP_ICR1) Output Pin(OC1B) Mode Select******************************/
#define TIMER1_CTC_TOP_ICR1_OC1B_DISCONNECTED						0
#define TIMER1_CTC_TOP_ICR1_TOGGLE_OC1B_ON_COMPARE_MATCH			1
#define TIMER1_CTC_TOP_ICR1_CLEAR_OC1B_ON_COMPARE_MATCH				2
#define TIMER1_CTC_TOP_ICR1_SET_OC1B_ON_COMPARE_MATCH				3


/****************Timer 1 Fast PWM Mode 8bits Output Pin(OC1A) Mode Select******************************/
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_8BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2

/****************Timer 1 Fast PWM Mode 8bits Output Pin(OC1B) Mode Select******************************/
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_8BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2

/****************Timer 1 Fast PWM Mode 9bits Output Pin(OC1A) Mode Select******************************/
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_9BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2
/****************Timer 1 Fast PWM Mode 9bits Output Pin(OC1B) Mode Select******************************/
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED		0
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_9BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2

/****************Timer 1 Fast PWM Mode 10bits Output Pin(OC1A) Mode Select******************************/
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_10BITS_OC1A_OUTPUTPIN_MODE_INVERTING			2
/****************Timer 1 Fast PWM Mode 10bits Output Pin(OC1B) Mode Select******************************/
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_DISCONNECTED			0
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_NON_INVERTING		1
#define TIMER1_PWM_FAST_10BITS_OC1B_OUTPUTPIN_MODE_INVERTING			2

#endif /* TIMER_PRIVATE_H_ */
