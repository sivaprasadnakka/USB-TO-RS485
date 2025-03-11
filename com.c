/*
 * com.c
 *
 *  Created on: Feb 22, 2025
 *      Author: siva
 */

/* com - RS485 communication */



/* Private includes ---------------------------------------------------------*/
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "com.h"
#include"common.h"
#include "can.h"
/* private variables declarations----------------------------------------------*/
uint8_t COM_u8_rx_data;
uint8_t COM_u8aa_tx_buff[10];
uint8_t COM_u8aa_rx_buff[10];
uint8_t cnt;
bool COM_RX_Cmplt_Flag;
/* private function prototypes-------------------------------------------------*/
void COM_Init(void);
void COM_data_reception_mode(void);
void COM_data_tx(void);
void COM_data_rx_process(void);
//void COM_data_rx_process(void);

/* private user code-----------------------------------------------------------*/
/**
  * @brief com Initializations
  */
void COM_Init(void)
{
	UART4_RE_LOW;
	HAL_UART_Receive_IT(&huart4, &COM_u8_rx_data, BYTE_1);
}

/**
  * @brief data transmission
  */
void COM_data_tx(void)
{
	//uint16_t u16_Checksum = CLEAR;
	COM_u8aa_tx_buff[0] = 0x00;
	COM_u8aa_tx_buff[1] = 0x01;
	COM_u8aa_tx_buff[2] = 0x02;
	COM_u8aa_tx_buff[3] = 0x03;
	COM_u8aa_tx_buff[4] = 0x04;
	COM_u8aa_tx_buff[5] = 0x05;
	UART4_RE_HIGH;
	UART4_DE_HIGH;
	HAL_UART_Transmit_IT(&huart4, COM_u8aa_tx_buff, 6);
}


/**
  * @brief data Reception Mode
  */
void COM_data_reception_mode(void)
{
	/* Clear RX Buffer */
	memset(COM_u8aa_rx_buff, CLEAR, 1);
	/* UART1 in receiving mode */
	UART4_DE_LOW;
	UART4_RE_LOW;
	/* setup USART1 to rx callback after Rxbyte_length(1 byte) */
	HAL_UART_Receive_IT(&huart4, &COM_u8_rx_data, BYTE_1);
	//HAL_UART_Receive_IT(&huart4,COM_u8aa_rx_buff,10);
}

void COM_data_rx_process(void)
{
	if(cnt < 10)
	{
		COM_u8aa_rx_buff[cnt] = COM_u8_rx_data;
		cnt++;
		if(COM_u8aa_rx_buff[9]== 0xDD)
		{
			COM_RX_Cmplt_Flag = TRUE;
			cnt = 0;
//			memset(COM_u8aa_rx_buff, CLEAR, 1);
		}
	}
	else
	{
		cnt = CLEAR;
	}
}






