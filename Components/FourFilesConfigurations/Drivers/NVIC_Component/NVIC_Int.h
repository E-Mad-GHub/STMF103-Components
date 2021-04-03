/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the DIO Component in high efficiency*/
/*																					*/
/* Created on  : Mar 13, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard *******************************/
#ifndef NVIC_INT_H_
#define NVIC_INT_H_










/** Defining External Interrupt Index *******/
/*                                          */

#define       EXTINT_0     		 (u8)0
#define       EXTINT_1     		 (u8)1
#define       EXTINT_2     		 (u8)2
#define       EXTINT_3     		 (u8)3
#define       EXTINT_4     		 (u8)4

/*                                          */
/********************************************/

/*****************************************************************************/
/*						     Registers Addresses							 */

/* Defining Private Variables               */


/*																			 */
/*****************************************************************************/



/******* Configurations Dependencies ********/
/*									        */

#define EXTRINTR_STATE_ENABLED 		(u8)1
#define EXTRINTR_STATE_DISABLED 	(u8)0

/*									        */
/********************************************/




/*********** Configurations AIRCR ***********/
/*									        */

#define PRIORITY_CONF_1 		0x5FA0300            // For 16 Group - 0 Sub
#define PRIORITY_CONF_2 		0x5FA0400            // For 8  Group - 2 Sub
#define PRIORITY_CONF_3 		0x5FA0500            // For 4  Group - 4 Sub
#define PRIORITY_CONF_4 		0x5FA0600            // For 2  Group - 8 Sub
#define PRIORITY_CONF_5 		0x5FA0700            // For 0  Group - 16 Sub

/*									        */
/********************************************/






/*************************************************************************************************/
/* Description: Initializes the pointers to Fns, Sets the initial states (PIE) of each Interrupt */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 NVIC_u8Initialize( void ) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority Configuration of the NVIC							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPrioConf( u32 Copy_u8PrioConf ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Enable(u8 Copy_u8IntrIndex) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8Disable(u8 Copy_u8IntrIndex) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 EXTINT_u8SetPrio(u8 Copy_u8IntrIndex , u8 Copy_u8Prio ) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8Enable(void) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8Disable(void) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

void NVIC_USART2_INT_u8SetPrio( u8 Copy_u8Prio ) ;

/*																					             */
/*************************************************************************************************/



#endif /* ARM_GPIO_INT_H_ */
