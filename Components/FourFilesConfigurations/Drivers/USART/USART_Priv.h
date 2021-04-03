/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the UART2 Component 		        */
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : May 5, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/



/* File Guard  			*/
#ifndef UART_PRIV_H_
#define UART_PRIV_H_




/****** Defining the Peripheral Struct ******/
/*                                          */

typedef struct {

	u32   SR    ;
	u32   DR    ;
	u32   BRR   ;
	u32   CR1   ;
	u32   CR2   ;
	u32   CR3   ;
	u32   GTPR  ;

}USART;

/*                                          */
/********************************************/





/********* Hardware Dependencies ****************************/
/*									        				*/

/* Defining Register ADDRESS   		        				*/
#define USART2_Add     				0x40004400

/* Assigning Registers ADDRESSes  	        				*/
USART * USART2 =  (USART *) USART2_Add ;

/* Defining UART States	(UART_INIT_STATE)	   				*/
#define UART_DISABLE 				0xFFFFDFFF
#define UART_ENABLE_RX				0x00002004
#define UART_ENABLE_TX				0x00002008

/* Defining Masks				          					*/
#define LOCAL_INIT_STATE_MASK		0xFFFFDFF3
#define LOCAL_DATA_BITS_MASK		0xFFFFEFFF
#define LOCAL_STOP_BITS_MASK		0xFFFFCFFF
#define LOCAL_TX_MASK				0x00000040
#define LOCAL_RX_MASK				0x00000020
#define LOCAL_TX_EN_INTR_MASK		0x00000040
#define LOCAL_TX_DS_INTR_MASK		0xFFFFFFBF
#define LOCAL_RX_EN_INTR_MASK		0x00000020
#define LOCAL_RX_DS_INTR_MASK		0xFFFFFFDF
#define LOCAL_TC_CLEAR_MASK			0xFFFFFFBF
#define LOCAL_RXN_CLEAR_MASK		0xFFFFFFDF
#define LOCAL_DISABLE_UART_MASK		0xFFFFDFFF

/*									        			 	*/
/************************************************************/







#endif /* EXTINT_COMPONENT_EXTINT_PRIV_H_ */
