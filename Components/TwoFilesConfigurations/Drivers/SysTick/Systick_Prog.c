/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the systick	*/
/* 				 Driver																*/
/*																					*/
/* Created on  : Apr 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "../../Handlers/GPIO_Example/STD_TYPE.h"
#include "Systick_Int.h"






/********************************************************* PRIVATE SECTION ***************************************************************/
/*																																		 */



/*****************************************************************************/
/*						     Registers Addresses							 */

#define SYSTK_CONTROL			0xE000E010
#define SYSTK_RELOAD			0xE000E014
#define SYSTK_VALUE		    	0xE000E018

/*																			 */
/*****************************************************************************/


/****************** Misc. *******************/
/*                                          */

#define SYSTICK_ENABLE_MASK		((u32)1)
#define INTR_ENABLE_MASK		((u32)2)
#define INTR_CLK_MASK			((u32)4)

#define SYSTICK_DISABLE_MASK	0xFFFFFFFE

/*                                          */
/********************************************/

/*																																		 */
/*****************************************************************************************************************************************/






static void (*PtrToFunction)(void)  ;






/********************************************************* FUNCTIONS SECTION *************************************************************/
/*																																		 */


/*************************************************************************************************/
/* Description: Initializes the systick, enabling interupts and uses processor free running clk	 */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Systick_Init(void){

	( ((Register_32*) SYSTK_CONTROL ) -> RegAccess ) |= INTR_ENABLE_MASK 	;

	( ((Register_32*) SYSTK_CONTROL ) -> RegAccess ) |= INTR_CLK_MASK 		;

	PtrToFunction = NULL ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Enables the Systick 												             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Systick_vEnable(void) {

	( ((Register_32*) SYSTK_CONTROL ) -> RegAccess ) |= SYSTICK_ENABLE_MASK  ;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the Systick 												             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Systick_vDisable(void) {

	( ((Register_32*) SYSTK_CONTROL ) -> RegAccess ) &= SYSTICK_DISABLE_MASK  ;

}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Sets the Reload Reg. with the required ticks						             */
/*																				            	 */
/* Inputs : Copy_u8Time_ms 	->	Time Required in ms 						    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Systick_vSetTickTime( u16 Copy_u8Time_ms) {

	u32 Ticks;

	Ticks = Copy_u8Time_ms*1000*CLK_FREQUENCY_MHz ;

	( ((Register_32*) SYSTK_RELOAD ) -> RegAccess ) = Ticks  ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Assigns a Fn to the Function pointer of each Interrupt				             */
/*																				            	 */
/* Inputs : (*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/*																					             */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void Systick_vSetCallBack( void (*Copy_PvoidFuncCallBack)(void) ) {


	if(Copy_PvoidFuncCallBack != NULL){
		PtrToFunction = Copy_PvoidFuncCallBack ;
	}


}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Systick Handler														             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void SysTick_Handler(void){

	if(PtrToFunction != NULL){
		PtrToFunction() ;
	}

}

/*																					             */
/*************************************************************************************************/



/*																																		 */
/*****************************************************************************************************************************************/
