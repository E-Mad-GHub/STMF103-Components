/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the UART Component 		        */
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : May 3, 2019 														*/
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
#define USART2_Add     					 0x40004400

/* Assigning Registers ADDRESSes  	        				*/
USART * USART2 =  (USART *) USART2_Add ;

/* Defining Masks				          					*/
#define LOCAL_INIT_STATE_MASK		0xFFFFDFF3
#define LOCAL_DATA_BITS_MASK		0xFFFFEFFF
#define LOCAL_STOP_BITS_MASK		0xFFFFCFFF
#define LOCAL_TX_MASK				0x00000040
#define LOCAL_RX_MASK				0x00000020

/*									        			 	*/
/************************************************************/







#endif /* EXTINT_COMPONENT_EXTINT_PRIV_H_ */
