/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the UART		    */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : May 3, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"


#include <USART_Int.h>
#include <USART_Priv.h>
#include <USART_Config.h>






/**************  Static Variables ***************/

static u16 Received_Data ;
static void (*PtrToFunction)(void) ;

/************************************************/




/*************** Static Functions ***************/



/************************************************/





/*************************************************************************************************/
/* Description: Initialization of ADC includes initializing static variables and defining the    */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void UART_vInit( void ) {

	USART2 -> CR1 |= UART_INIT_STATE 	;

	USART2 -> CR1 |= UART_DATA_BITS	;

	USART2 -> CR2 |= UART_STOP_BITS  	;

	USART2 -> BRR  = (UART_PROCC_FREQ_Hz / UART_BAUD_RATE_Hz)  ;

}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Receive while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : void 																		         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_vReceive_Blocking( void ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	u16 counter = 500 ;


	while( (  (( (USART2 -> SR)&(LOCAL_RX_MASK) ) == 0 ) && counter > 0  ) )  {
		counter -- ;
	}


	if ((counter == 0) && ( (( (USART2 -> SR)&(LOCAL_RX_MASK) ) == 0 ) )){
		Local_u8ErrorState = ERROR_NOK ;
	}
	else{
		Received_Data = (u8)(USART2 -> DR) ;
	}


	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pDataArray					-> Data Array								         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vTransmit_Blocking( u8 * Copy_pDataArray ) {

	u8 i = 0 ;

	while(Copy_pDataArray[i] != '\0'){

		USART2 -> DR  = (u32)Copy_pDataArray[i];
		i++ ;

		while( ( (USART2 -> SR)&(LOCAL_TX_MASK) ) == 0 )  ;

	}

}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pData						-> Data Array								         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceived( u8 * Copy_pData ){

	*Copy_pData = Received_Data ;

}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8SetCallBack( void (*Copy_PvoidFuncCallBack)(void) ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if(Copy_PvoidFuncCallBack != NULL){
		PtrToFunction = Copy_PvoidFuncCallBack ;
	}
	else {
		Local_u8ErrorState = ERROR_NOK ;
	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/











/*************************************************************************************************/
/* Description: USART ISR							 								             */
/*																				            	 */
/* 																								 */
/*																					             */

void USART2_IRQHandler(void){



	if(PtrToFunction != NULL){
		PtrToFunction() ;
	}




}

/*																					             */
/*************************************************************************************************/



