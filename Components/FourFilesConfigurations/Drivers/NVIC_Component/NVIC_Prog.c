/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the GPIO		*/
/* 				 Driver																*/
/*																					*/
/* Created on  : Mar 14, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "STD_TYPE.h"

#include <NVIC_Int.h>
#include <NVIC_Priv.h>
#include <NVIC_Conf.h>








/*************************************************************************************************/
/* Description: Initializes the pointers to Fns, Sets the initial states (PIE) of each Interrupt */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 NVIC_u8Initialize( void ) {
	u8 Local_u8ErrorState = ERROR_OK ;


	NVIC_u8SetPrioConf( NVIC_PRIORITY_CONF ) ;


	for(u8 count = 0 ; count < EXTINT_NUMBER ; count ++){


		if(EXTINT_State[count] == EXTRINTR_STATE_ENABLED){
			EXTINT_u8Enable(count) ;
		}
		else {
			EXTINT_u8Disable(count) ;
		}



		EXTINT_u8SetPrio( count , EXTINT_Initial_Priority[count] ) ;


	}




	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Sets the Priority Configuration of the NVIC							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPrioConf( u32 Copy_u8PrioConf ) {
	u8 Local_u8ErrorState = ERROR_OK ;

	( ((Register_32*) AIRCR ) -> RegAccess ) = (u32)Copy_u8PrioConf ;


	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/







/********************************************** USART APIs **************************************************************/
/*																														*/

/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8Enable(void) {


	ISER -> REG_NUM[1] = ( UART2_EN_DIS_MASK ) ;


}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8Disable(void) {


	ICER -> REG_NUM[1] = ( UART2_EN_DIS_MASK ) ;


}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8SetPrio( u8 Copy_u8Prio ) {


	IPR -> INT_NUM[38] = (u8)Copy_u8Prio ;


}

/*																					             */
/*************************************************************************************************/


/*																														*/
/************************************************************************************************************************/






/*********************************************** EXTI APIs **************************************************************/
/*																														*/

/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Enable(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	//ISER -> REG_NUM[0] = (1 << (6+ Copy_u8IntrIndex)  ) ;








	( ((Register_32*) 0xE000E100 ) -> RegAccess ) = (u32)(1 << ( 6+ Copy_u8IntrIndex )  ) ;



	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Disable(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	//ICER -> REG_NUM[0] = (1 << (6+ Copy_u8IntrIndex)  ) ;

	( ((Register_32*) 0xE000E180 ) -> RegAccess ) = (u32)(1 << ( 6+ Copy_u8IntrIndex )  ) ;

	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8SetPrio(u8 Copy_u8IntrIndex , u8 Copy_u8Prio ) {
	u8 Local_u8ErrorState = ERROR_OK ;

	IPR -> INT_NUM[6+Copy_u8IntrIndex] = (u8)Copy_u8Prio ;


	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/


/*																														*/
/************************************************************************************************************************/






