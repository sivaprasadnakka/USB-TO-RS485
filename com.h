

/*
 * com.h
 *
 *  Created on: Feb 22, 2025
 *      Author: siva
 */

#ifndef INC_COM_H_
#define INC_COM_H_

/* private macros--------------------------------------------------------*/
#define UART4_RE_LOW            HAL_GPIO_WritePin(A0_UART4_RE_GPIO_Port,\
		                         A0_UART4_RE_Pin, GPIO_PIN_RESET)
#define UART4_RE_HIGH           HAL_GPIO_WritePin(A0_UART4_RE_GPIO_Port, \
		                         A0_UART4_RE_Pin, GPIO_PIN_SET)

#define UART4_DE_LOW            HAL_GPIO_WritePin(A0_UART4_DE_GPIO_Port, \
		                         A0_UART4_DE_Pin, GPIO_PIN_RESET)
#define UART4_DE_HIGH           HAL_GPIO_WritePin(A0_UART4_DE_GPIO_Port, \
		                         A0_UART4_DE_Pin, GPIO_PIN_SET)





//#define FALSE                 0                      /* False */
//#define TRUE                  1                      /* True  */
//#define LOW                   0                      /* Low   */
//#define HIGH                  1                      /* High  */
//#define CLEAR                 0                      /* Clear */


/*typedef enum
{
	BYTE_0, BYTE_1, BYTES_2,
	BYTES_3, BYTES_4, BYTES_5,
	BYTES_6, BYTES_7, BYTES_8,
	BYTES_9, BYTES_10, BYTES_11,
	BYTES_12, BYTES_13, BYTES_14

}enum_byte_size_t;*/


/* private Multi-File Global Variables declaration------------------------*/
extern uint8_t COM_u8_rx_data;
extern UART_HandleTypeDef huart4;
extern bool COM_RX_Cmplt_Flag;


/*private Multi-File Global Function prototypes---------------------------*/
extern void COM_Init(void);
extern void COM_data_tx(void);
extern void COM_data_reception_mode(void);
extern void COM_data_rx_process(void);



/* Exported types --------------------------------------------------------*/



#endif /* INC_COM_H_ */




