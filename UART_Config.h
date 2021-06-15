/*
 * UART_Config.h
 *
 *  Created on: Jun 15, 2021
 *      Author: MarwanAbdelsalamm
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/**********************U2X: Double the USART Transmission Speed Enable/Disable select (in the Asynchronous mode only)***********
#define UART_U2X_DISABLE	0
#define UART_U2X_ENABLE		1									*/
#define UART_U2X_Select 	UART_U2X_DISABLE

/**********************Multi-processor Communication Mode Enable/Disable select	************************************************
#define UART_MULTIPROCESSOR_COMM_MODE_DISABLE	0
#define UART_MULTIPROCESSOR_COMM_MODE_ENABLE	1				*/
#define UART_MULTIPROCESSOR_COMM_MODE_SELECT	UART_MULTIPROCESSOR_COMM_MODE_DISABLE

/**********************Receiving Complete Interrupt Enable/Disable Select*******************************************************
#define UART_RX_COMPLETE_INTERRUPT_DISABLE	0
#define UART_RX_COMPLETE_INTERRUPT_ENABLE	1					*/
#define UART_RX_COMPLETE_INTERRUPT_SELECT	UART_RX_COMPLETE_INTERRUPT_DISABLE

/***********************Transmitting Complete Interrupt Enable/Disable Select***************************************************
#define UART_TX_COMPLETE_INTERRUPT_DISABLE	0
#define UART_TX_COMPLETE_INTERRUPT_ENABLE	1					*/
#define UART_TX_COMPLETE_INTERRUPT_SELECT	UART_TX_COMPLETE_INTERRUPT_DISABLE

/***********************Data Register(UDR) Empty Interrupt Enable/Disable Select************************************************
#define UART_UDR_EMPTY_INTERRUPT_DISABLE	0
#define UART_UDR_EMPTY_INTERRUPT_ENABLE		1					*/
#define UART_UDR_EMPTY_INTERRUPT_SELECT		UART_UDR_EMPTY_INTERRUPT_DISABLE
/***********************Receiver Enable/Disable Select**************************************************************************
#define UART_RECEIVER_DISABLE	0
#define UART_RECEIVER_ENABLE	1								*/
#define UART_RECEIVER_SELECT	UART_RECEIVER_ENABLE
/***********************Transmitter Enable/Disable Select***********************************************************************
#define UART_TRANSMITTER_DISABLE	0
#define UART_TRANSMITTER_ENABLE		1							*/
#define UART_TRANSMITTER_SELECT		UART_TRANSMITTER_ENABLE
/***********************Data Size Select 5/6/7/8/9 bits*************************************************************************
#define UART_CHAR_SIZE_5BITS	0
#define UART_CHAR_SIZE_6BITS	1
#define UART_CHAR_SIZE_7BITS	2
#define UART_CHAR_SIZE_8BITS	3
#define UART_CHAR_SIZE_9BITS	4								*/
#define UART_CHAR_SIZE			UART_CHAR_SIZE_8BITS
/***********************UART Mode Select Synchronous/Asynchronous***************************************************************
#define UART_MODE_ASYNCHRONOUS 		0
#define UART_MODE_SYNCHRONOUS 		1							*/
#define UART_MODE 					UART_MODE_ASYNCHRONOUS
/***********************UART Parity Mode Select Disabled/Even/Odd***************************************************************
#define UART_PARITY_MODE_DISABLE	0
#define UART_PARITY_MODE_EVEN		1
#define UART_PARITY_MODE_ODD		2							*/
#define UART_PARITY_MODE			UART_PARITY_MODE_DISABLE
/***********************UART Stop Bit Mode Select 1bit/2bits********************************************************************
#define UART_STOPBIT_MODE_1BIT		0
#define UART_STOPBIT_MODE_2BIT 		1							*/
#define UART_STOPBIT_MODE					UART_STOPBIT_MODE_1BIT
/***********************UART Clock Polarity(this bit has only benefits in synchronous mode)************************************
#define UART_CLOCK_POLARITY_DISABLE					0
#define UART_CLOCK_POLARITY_RISING_TX_FALLING_RX	0
#define UART_CLOCK_POLARITY_FALLING_TX_RISING_RX	1			*/
#define UART_CLOCK_POLARITY							UART_CLOCK_POLARITY_DISABLE
/*UART Frequency Select (according to your crystal frequency)*****************************************************************
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
#define UART_FREQUENCY_OSC_20MHZ		11						*/
#define UART_FREQUENCY_OSC				UART_FREQUENCY_OSC_8MHZ
/***********************UART Baud Rate Select(check table 68. in data sheet p165 before selecting)************************
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
#define UART_BAUDRATE_1M		13								*/
#define UART_BAUDRATE			UART_BAUDRATE_9600

#endif /* UART_CONFIG_H_ */
