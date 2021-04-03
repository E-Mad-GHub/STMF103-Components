/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the UART2		    */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : May 5, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"


#include <USART_Int.h>
#include <USART_Priv.h>
#include <USART_Config.h>






/**************  Static Variables ***************/

static u16 Received_Data ;
static u16 Received_Asynch [2][MAX_RECEIVED_FRAMES] ;
static void (*PtrToFunction)(void) ;

static u8 AsynchCounter ;
static u8 Tx_Flag  ;
static u8 Rx_Flag  ;
static u8 * TxData ;
static u8 Frames   ;
static u8 ReadIndex  ;
static u8 WriteIndex ;

/************************************************/




/*************** Static Functions ***************/

static void UART_vClearTC( void )		;
static void UART_vClearRXN( void )		;
static void UART_vEnableTxIntr( void )  ;
static void UART_vDisableTxIntr( void ) ;
static void UART_vEnableRxIntr( void )  ;
static void UART_vDisableRxIntr( void ) ;
static void SwapReadWrite( void )		;
static void UART_Mode_Tx( void )		;
static void UART_Mode_Rx( void )		;
static void UART_Mode_Disable( void )	;


/************************************************/





/************************************************************************************************************************************************************/
/*																																						 	*/
/*										APIs																												*/
/*																																							*/



/*************************************************************************************************/
/* Description: Initialization of UART2 includes initializing static variables and defining the  */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void UART_vInit( void ) {

	USART2 -> CR1 |= UART_DATA_BITS	;

	USART2 -> CR2 |= UART_STOP_BITS  	;

	USART2 -> BRR  = (UART_PROCC_FREQ_Hz / UART_BAUD_RATE_Hz)  ;

	UART_vClearTC()  ;
	UART_vDisableTxIntr() ;
	UART_vClearRXN() ;
	UART_vDisableRxIntr() ;

	for ( u8 count = 0 ; count < 2 ; count ++){
		for (u8 count2 = 0 ; count2 < MAX_RECEIVED_FRAMES ; count2 ++){
			Received_Asynch [count][count2] = ' ' ;
		}
	}

	WriteIndex = 0 ;
	ReadIndex = 0 ;

}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Receive while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : void 																		         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8ReceiveBlocking( void ) {

	u8 Local_u8ErrorState = ERROR_OK ;
	u16 counter = COUNTDOWN ;

	UART_Mode_Rx();

	UART_vDisableRxIntr() ;

	while( (  (( (USART2 -> SR)&(LOCAL_RX_MASK) ) == 0 ) && counter > 0  ) )  {
		counter -- ;
	}


	if ((counter == 0) && ( (( (USART2 -> SR)&(LOCAL_RX_MASK) ) == 0 ) )){
		Local_u8ErrorState = ERROR_NOK ;
	}
	else{
		Received_Data = (u8)(USART2 -> DR) 	 ;
		UART_vClearRXN()  					 ;
	}


	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Receive Asynchronously with Enabling the Interrupt 					             */
/*																				            	 */
/* Inputs : Copy_FrameNubmer 				-> No of frames to be Received				         */
/*			Copy_PvoidFuncCallBack			-> Pointer to the Call back function after receiving */
/* 	 	 	 	 	 	 	 	 	 	 	 	all the frames									 */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vReceiveAsynchronous( u8 Copy_FrameNubmer , void (*Copy_PvoidFuncCallBack)(void) ) {

	UART_Mode_Rx();

	AsynchCounter = 0 	 ;

	Frames = Copy_FrameNubmer ;

	for (u8 count = 0 ; count < MAX_RECEIVED_FRAMES ; count ++){
		Received_Asynch [WriteIndex][count] = ' ' ;
	}

	UART_u8SetCallBack( Copy_PvoidFuncCallBack ) ;

	UART_vClearRXN()  	 ;
	UART_vEnableRxIntr() ;

	Tx_Flag = 0 ;
	Rx_Flag = 1 ;


}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pDataArray					-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8TransmitBlocking( u8 * Copy_pDataArray ) {

	u8 i = 0 ;
	u16 counter = COUNTDOWN ;
	u8 Local_u8ErrorState = ERROR_OK ;

	UART_Mode_Tx();

	UART_vDisableTxIntr() ;


	while(Copy_pDataArray[i] != '\0'){

		USART2 -> DR  = (u32)Copy_pDataArray[i];
		i++ ;


		while( ( ((USART2 -> SR)&(LOCAL_TX_MASK) ) == 0) && (counter > 0)){
			counter -- ;
		}

		if ( ( ((USART2 -> SR)&(LOCAL_TX_MASK) ) == 0) && (counter == 0)){
			Local_u8ErrorState = ERROR_NOK ;
		}

	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Transmit Asynchronously with Enabling the Interrupt 				             */
/*																				            	 */
/* Inputs : Copy_pDataArray 				-> Pointer to the string to be sent			         */
/*			Copy_PvoidFuncCallBack			-> Pointer to the Call back function after 			 */
/* 	 	 	 	 	 	 	 	 	 	 	 	Transmitting all the frames						 */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vTransmitAsynchronous( u8 * Copy_pDataArray , void (*Copy_PvoidFuncCallBack)(void) ) {

	UART_Mode_Tx();

	AsynchCounter = 0 	 ;

	TxData = Copy_pDataArray ;

	UART_u8SetCallBack( Copy_PvoidFuncCallBack ) ;

	UART_vClearTC()  	 ;
	UART_vEnableTxIntr() ;


	if(Copy_pDataArray[AsynchCounter] != '\0'){

		Tx_Flag = 1 ;
		Rx_Flag = 0 ;
		USART2 -> DR  = (u32)Copy_pDataArray[AsynchCounter];

	}


}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Copy received frames in the given array			 					             */
/*																				            	 */
/* Inputs : Copy_pData						-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceivedAsynch( u8 * Copy_pAData ){

	for (u8 count = 0 ; count < MAX_RECEIVED_FRAMES ; count ++ ){

		if (count < Frames){
			Copy_pAData[count] = (u8)Received_Asynch [ReadIndex][count] ;

		}
		else {
			Copy_pAData[count] = ' ' ;
		}
	}

}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Copy received frames in the given variable		 					             */
/*																				            	 */
/* Inputs : Copy_pData						-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceivedBlocking( u8 * Copy_pData ){

	*Copy_pData = Received_Data ;

}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/*																								 */
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

void USART2_IRQHandler(void){


	if (Tx_Flag == 1){

		AsynchCounter ++ 	 ;

		UART_vClearTC()  	 ;

		if(TxData[AsynchCounter] != '\0'){

			Tx_Flag = 1 ;
			Rx_Flag = 0 ;
			USART2 -> DR  = (u32)TxData[AsynchCounter];

		}
		else {
			UART_Mode_Disable() ;
			Tx_Flag = 0 ;
			Rx_Flag = 0 ;
			PtrToFunction() ;
		}


	}
	else if (Rx_Flag == 1){

		Received_Asynch[WriteIndex][AsynchCounter] = (u16)(USART2 -> DR) 	 ;
		AsynchCounter++  ;
		UART_vClearRXN() ;
		Tx_Flag = 0 ;
		Rx_Flag = 1 ;

		if (AsynchCounter == Frames){

			SwapReadWrite() ;

			UART_Mode_Disable() ;

			Tx_Flag = 0 ;
			Rx_Flag = 0 ;
			PtrToFunction() ;

		}


	}


}

/*																					             */
/*************************************************************************************************/


/*																																							*/
/*																																							*/
/************************************************************************************************************************************************************/









/************************************************************************************************************************************************************/
/*																																						 	*/
/*										STATIC FUNCTIONS																									*/
/*																																							*/


/*************************************************************************************************/
/* Description: Clears TC Bit 						 			 					             */
/*																					             */

static void UART_vClearTC( void ){

	USART2 -> SR  &= LOCAL_TC_CLEAR_MASK ;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Clears RXN Bit 						 			 					             */
/*																					             */

static void UART_vClearRXN( void ){

	USART2 -> SR  &= LOCAL_RXN_CLEAR_MASK ;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables UART Tx Interrupt			 			 					             */
/*																				            	 */

static void UART_vEnableTxIntr( void ){

	USART2 -> CR1 |= LOCAL_TX_EN_INTR_MASK	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables UART Tx Interrupt			 			 					             */
/*																				            	 */

static void UART_vDisableTxIntr( void ){

	USART2 -> CR1 &= LOCAL_TX_DS_INTR_MASK	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables UART Rx Interrupt			 			 					             */
/*																				            	 */

static void UART_vEnableRxIntr( void ){

	USART2 -> CR1 |= LOCAL_RX_EN_INTR_MASK	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables UART Rx Interrupt			 			 					             */
/*																				            	 */

static void UART_vDisableRxIntr( void ){

	USART2 -> CR1 &= LOCAL_RX_DS_INTR_MASK	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Swap the two Receive memories					 					             */
/*																				            	 */

static void SwapReadWrite( void ){

	u8 temp    = ReadIndex  ;
	ReadIndex  = WriteIndex ;
	WriteIndex = temp       ;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enable and Set the UART Mode to Tx									             */
/*																				            	 */

static void UART_Mode_Tx( void ){

	USART2 -> CR1 |= UART_ENABLE_TX 	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enable and Set the UART Mode to Rx									             */
/*																				            	 */

static void UART_Mode_Rx( void ){

	USART2 -> CR1 |= UART_ENABLE_RX 	;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the UART 													             */
/*																				            	 */

static void UART_Mode_Disable( void ){

	USART2 -> CR1 &= UART_DISABLE		;

}

/*																					             */
/*************************************************************************************************/

/*																																						 	*/
/*																																							*/
/************************************************************************************************************************************************************/
