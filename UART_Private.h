/*
 * UART_Private.h
 *
 *  Created on: Jun 14, 2021
 *      Author: MarwanAbdelsalam
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR *((volatile u8*)(0x2C))
#define UCSRA *((volatile u8*)(0x2B))
#define UCSRB *((volatile u8*)(0x2A))
#define UBRRL *((volatile u8*)(0x29))

#define UCSRC *((volatile u8*)(0x40))			// ???????????
#define UBRRH *((volatile u8*)(0x40))


/***********************************************************************/
//UCSRA Register
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0
//UCSRB Register

#define RXCIE		7
#define TXCIE		6
#define UDRIE	5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8	0
//UCSRC Register

#define URSEL		7
#define UMSEL		6
#define UPM1	5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL	0
//UBRRH Register
#define URSEL		7



/**********************************************************************Configuration****************************************************/


/**********************U2X: Double the USART Transmission Speed Enable/Disable select (in the Asynchronous mode only)***********/
#define UART_U2X_DISABLE	0
#define UART_U2X_ENABLE		1
/**********************Multi-processor Communication Mode Enable/Disable select	************************************************/
#define UART_MULTIPROCESSOR_COMM_MODE_DISABLE	0
#define UART_MULTIPROCESSOR_COMM_MODE_ENABLE	1
/**********************Receiving Complete Interrupt Enable/Disable Select*******************************************************/
#define UART_RX_COMPLETE_INTERRUPT_DISABLE	0
#define UART_RX_COMPLETE_INTERRUPT_ENABLE	1
/***********************Transmitting Complete Interrupt Enable/Disable Select***************************************************/
#define UART_TX_COMPLETE_INTERRUPT_DISABLE	0
#define UART_TX_COMPLETE_INTERRUPT_ENABLE	1
/***********************Data Register(UDR) Empty Interrupt Enable/Disable Select************************************************/
#define UART_UDR_EMPTY_INTERRUPT_DISABLE	0
#define UART_UDR_EMPTY_INTERRUPT_ENABLE		1
/***********************Receiver Enable/Disable Select**************************************************************************/
#define UART_RECEIVER_DISABLE	0
#define UART_RECEIVER_ENABLE	1
/***********************Transmitter Enable/Disable Select***********************************************************************/
#define UART_TRANSMITTER_DISABLE	0
#define UART_TRANSMITTER_ENABLE		1
/***********************Data Size Select 5/6/7/8/9 bits*************************************************************************/
#define UART_CHAR_SIZE_5BITS	0
#define UART_CHAR_SIZE_6BITS	1
#define UART_CHAR_SIZE_7BITS	2
#define UART_CHAR_SIZE_8BITS	3
#define UART_CHAR_SIZE_9BITS	4
/***********************UART Mode Select Synchronous/Asynchronous***************************************************************/
#define UART_MODE_ASYNCHRONOUS 		0
#define UART_MODE_SYNCHRONOUS 		1
/***********************UART Parity Mode Select Disabled/Even/Odd***************************************************************/
#define UART_PARITY_MODE_DISABLE	0
#define UART_PARITY_MODE_EVEN		1
#define UART_PARITY_MODE_ODD		2
/***********************UART Stop Bit Mode Select 1bit/2bits********************************************************************/
#define UART_STOPBIT_MODE_1BIT		0
#define UART_STOPBIT_MODE_2BIT 		1
/*UART Frequency Select (according to your crystal frequency)*****************************************************************/
#define UART_FREQUENCY_OSC_1MHZ			0
#define UART_FREQUENCY_OSC_1.8432MHZ	1
#define UART_FREQUENCY_OSC_2MHZ			2
#define UART_FREQUENCY_OSC_3.6864MHZ	3
#define UART_FREQUENCY_OSC_4MHZ			4
#define UART_FREQUENCY_OSC_7.3728MHZ	5
#define UART_FREQUENCY_OSC_8MHZ			6
#define UART_FREQUENCY_OSC_11.0592MHZ	7
#define UART_FREQUENCY_OSC_14.74561MHZ	8
#define UART_FREQUENCY_OSC_16MHZ		9
#define UART_FREQUENCY_OSC_18.4320MHZ	10
#define UART_FREQUENCY_OSC_20MHZ		11
/***********************UART Baud Rate Select*********************************************************************************/
#define UART_BAUDRATE_2400		0
#define UART_BAUDRATE_4800		1
#define UART_BAUDRATE_9600		2
#define UART_BAUDRATE_14.4k		3
#define UART_BAUDRATE_19.2k		4
#define UART_BAUDRATE_28.8k		5
#define UART_BAUDRATE_38.4k		6
#define UART_BAUDRATE_57.6k		7
#define UART_BAUDRATE_76.8k		8
#define UART_BAUDRATE_115.2k	9
#define UART_BAUDRATE_230.4k	10
#define UART_BAUDRATE_250k		11
#define UART_BAUDRATE_0.5M		12
#define UART_BAUDRATE_1M		13
#define UART_BAUDRATE_2400		14
#define UART_BAUDRATE_2400		15



#endif /* UART_PRIVATE_H_ */
