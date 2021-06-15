/*
 * UART_Interface.h
 *
 *  Created on: Jun 14, 2021
 *      Author: m
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_VoidInit(void);
void UART_VoidTransmitData(u8 Copy_U8Data);
u8 UART_U8ReceiveData(void);

#endif /* UART_INTERFACE_H_ */
