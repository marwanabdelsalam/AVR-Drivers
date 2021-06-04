/***************************************************************************************************************/
/** Author    : Marwan Abdelsalam 										 ***************************************/
/** Data      : 1/6/2021		  									     ***************************************/
/** Version   :	1.0.0												     ***************************************/
/** DriverName:	External Interrupt			 						     ***************************************/
/** Desciption: Defining the Registers									 ***************************************/
/***************************************************************************************************************/

#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_




#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)
#define SREG *((volatile u8*)0x5F)

//ISR Declaration
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


#endif /* EXTINT_PRIVATE_H_ */
