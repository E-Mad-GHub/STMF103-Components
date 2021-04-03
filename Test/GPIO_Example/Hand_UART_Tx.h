/************************************************************************************/
/* Description : This is a 'h' file to describe the the Handler of the USART Driver	*/
/*																					*/
/* Created on  : Mar 15, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/

/* File Guard */
#ifndef Hand_UART_TX_H_
#define Hand_UART_TX_H_




/*****************************************************************************************************************/
/* Description: Write the Pin configurations as a structure then using 'GPIO' API configure this Pin			 */
/*																												 */
/* Inputs  ->  void	        : ...																				 */
/*															            										 */
/* Outputs ->  u8Error      : Error State																		 */
/*																												 */

u8 UART_Tx_Init(void) ;

/*																												 */
/*****************************************************************************************************************/





/*****************************************************************************************************************/
/* Description: Set the UART Pin output High																	 */
/*																												 */
/* Inputs  ->  void               : ...																			 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_SetPin_High( void ) ;

/*																												 */
/*****************************************************************************************************************/





/*****************************************************************************************************************/
/* Description: Set the UART Pin output Low																		 */
/*																												 */
/* Inputs  ->  void               : ...																			 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_SetPin_Low( void ) ;

/*																												 */
/*****************************************************************************************************************/





/*****************************************************************************************************************/
/* Description: Read the UART Pin State	    																	 */
/*																												 */
/* Inputs  ->  *Copy_Pu8PinState  : Pointer to the variable to contain the state of the pin						 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_GetPin_State( u8 * Copy_Pu8PinState ) ;

/*																												 */
/*****************************************************************************************************************/






#endif /* 2_FILES_MODE_HANDLERS_UART_TX_UART_TX_H_ */
