/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the UART Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : May 3, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/



/*  File Guard  			*/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




/******* Configurations Dependencies ************************/
/*									        				*/

/* Defining UART States	(UART_INIT_STATE)	   				*/
#define UART_DISABLE 					0x00000000
#define UART_ENABLE_RX					0x00002004
#define UART_ENABLE_TX					0x00002008

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
/* Description: Initialization of ADC includes initializing static variables and defining the    */
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
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_vReceive_Blocking( void ) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pDataArray					-> Data Array								         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vTransmit_Blocking( u8 * Copy_pDataArray ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Transmit while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : Copy_pDataArray					-> Data Array								         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void UART_vGetReceived( u8 * Copy_pData ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 UART_u8SetCallBack( void (*Copy_PvoidFuncCallBack)(void) ) ;

/*																					             */
/*************************************************************************************************/









#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
