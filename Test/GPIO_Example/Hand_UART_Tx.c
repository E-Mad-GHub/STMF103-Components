/************************************************************************************/
/* Description : This is a 'c' file to describe the the Handler of the USART Driver	*/
/*																					*/
/* Created on  : Mar 15, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "Hand_UART_Tx.h"

#include "STD_TYPE.h"
#include "../../Drivers/GPIO_Component/ARM_GPIO_Int.h"








/*   Defining a structure of type "Pin_Conf" in which its skeleton is initiated in the "GPIO" header file        */
Pin_Conf UART_Tx_Struct ;





/*****************************************************************************************************************/
/* Description: Write the Pin configurations as a structure then using 'GPIO' API configure this Pin			 */
/*																												 */
/* Inputs  ->  void	        : ...																				 */
/*															            										 */
/* Outputs ->  u8Error      : Error State																		 */
/*																												 */

u8 UART_Tx_Init(void){

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;




	/*   Choosing the Pin Configurations according to the values found in the "GPIO" header file  */
	/*	 for example:
	   Struct_Name.Pin_Value   = GPIO_PIN0  	    		;
	   Struct_Name.Port_Number = GPIO_PORT_A  	    		;
	   Struct_Name.Mode	       = MODE_OUTPUT_PUSH_PULL      ;
	   Struct_Name.Frequency   = Freq_10_MHz          	    ;
	*/

	UART_Tx_Struct.Pin_Value   = GPIO_PIN0  	    		;
	UART_Tx_Struct.Port_Number = GPIO_PORT_A  	 		    ;
	UART_Tx_Struct.Mode		   = MODE_INPUT_PULL_UP	        ;
	UART_Tx_Struct.Frequency   = MODE_INPUT       		    ;



	/* 	 Sending the configurations to the Function "GPIO_u8PinConfigure" as a pointer  */
	/* 	 to structure and assigning the error level according to the success			*/
	/* 	 level of the configurations 													*/
	Local_Err_state = GPIO_u8PinConfigure( & UART_Tx_Struct ) ;



	/* Return Error Level */
	return Local_Err_state ;
}

/*																												 */
/*****************************************************************************************************************/





/*****************************************************************************************************************/
/* Description: Set the UART Pin output High																	 */
/*																												 */
/* Inputs  ->  void               : ...																			 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_SetPin_High( void ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;


	/* 	 Set the UART Pin to High	*/
	Local_Err_state = GPIO_u8SetPinValue ( UART_Tx_Struct.Pin_Value , UART_Tx_Struct.Port_Number , PIN_VALUE_HIGH ) ;


	/* Return Error Level */
	return Local_Err_state ;
}

/*																												 */
/*****************************************************************************************************************/





/*****************************************************************************************************************/
/* Description: Set the UART Pin output Low																		 */
/*																												 */
/* Inputs  ->  void               : ...																			 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_SetPin_Low( void ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;


	/* 	 Set the UART Pin to Low 	*/
	Local_Err_state = GPIO_u8SetPinValue ( UART_Tx_Struct.Pin_Value , UART_Tx_Struct.Port_Number , PIN_VALUE_LOW ) ;


	/* Return Error Level */
	return Local_Err_state ;
}

/*																												 */
/*****************************************************************************************************************/



/*****************************************************************************************************************/
/* Description: Read the UART Pin State	    																	 */
/*																												 */
/* Inputs  ->  *Copy_Pu8PinState  : Pointer to the variable to contain the state of the pin						 */
/* 															            										 */
/* Outputs ->  u8Error    		  : Error State																	 */
/*																												 */

u8 UART_Tx_GetPin_State( u8 * Copy_Pu8PinState ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;


	/* 	 Get the UART Pin to in the 'Copy_Pu8PinState' pointer 	*/
	Local_Err_state = GPIO_u8GetPinValue ( UART_Tx_Struct.Pin_Value , UART_Tx_Struct.Port_Number , Copy_Pu8PinState ) ;


	/* Return Error Level */
	return Local_Err_state ;
}

/*																												 */
/*****************************************************************************************************************/






