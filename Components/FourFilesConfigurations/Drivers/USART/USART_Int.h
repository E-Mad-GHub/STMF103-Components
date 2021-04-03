/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the UART2 Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : May 5, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/



/*  File Guard  			*/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




/******* Configurations Dependencies ************************/
/*									        				*/

/* Defining Number of used data bits (UART_DATA_BITS)      	*/
#define DATA_BITS_8						0x00000000
#define DATA_BITS_9						0x00001000

/* Defining UART Number of Stop bits (UART_STOP_BITS)       */
#define STOP_BITS_1						0x00000000
#define STOP_BITS_0_5					0x00001000
#define STOP_BITS_2						0x00002000
#define STOP_BITS_1_5					0x00003000

/*									       				    */
/************************************************************/



/*************************************************************************************************/
/* Description: Initialization of UART2 includes initializing static variables and defining the  */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void UART_vInit( void ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Receive while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : void 																		         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8ReceiveBlocking( void ) ;

/*																					             */
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

void UART_vReceiveAsynchronous( u8 Copy_FrameNubmer , void (*Copy_PvoidFuncCallBack)(void) ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pDataArray					-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8TransmitBlocking( u8 * Copy_pDataArray ) ;

/*																					             */
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

void UART_vTransmitAsynchronous( u8 * Copy_pDataArray , void (*Copy_PvoidFuncCallBack)(void) )  ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Copy received frames in the given array			 					             */
/*																				            	 */
/* Inputs : Copy_pData						-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceivedAsynch( u8 * Copy_pAData ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Copy received frames in the given variable		 					             */
/*																				            	 */
/* Inputs : Copy_pData						-> Data Array								         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceivedBlocking( u8 * Copy_pData ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8SetCallBack( void (*Copy_PvoidFuncCallBack)(void) );

/*																					             */
/*************************************************************************************************/









#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
