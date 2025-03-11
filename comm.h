/*
 * common.h
 *
 *  Created on: Mar 3, 2025
 *      Author: siva
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_



/*private defines--------------------------------------------------------------*/
/* logic states */
#define FALSE                 0                      /* False */
#define TRUE                  1                      /* True  */
#define LOW                   0                      /* Low   */
#define HIGH                  1                      /* High  */
#define CLEAR                 0                      /* Clear */


/* private Multi-File Global Variables declaration------------------------*/
extern UART_HandleTypeDef huart4;
extern FDCAN_HandleTypeDef hfdcan1;
extern FDCAN_HandleTypeDef hfdcan2;

/* Exported types --------------------------------------------------------*/
typedef enum
{
	BYTE_0, BYTE_1, BYTES_2,
	BYTES_3, BYTES_4, BYTES_5,
	BYTES_6, BYTES_7, BYTES_8,
	BYTES_9, BYTES_10, BYTES_11,
	BYTES_12, BYTES_13, BYTES_14

}enum_byte_size_t;



#endif /* INC_COMMON_H_ */
