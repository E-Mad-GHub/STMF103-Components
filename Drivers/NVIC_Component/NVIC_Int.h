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



/****** Defining the Pin Config. Struct *****/
/*                                          */

typedef struct {

	u32 NVIC_PRIORITY_CONF ;
	u8  MAX_NB_INTRPT 	   ;

}NVIC_Profile;

/*                                          */
/********************************************/



/******* Defining the NVIC Interrupts *******/
/*                                          */

#define WWDG 		(u8)0
#define PVD			(u8)1
#define TAMPER		(u8)2
#define RTC			(u8)3
#define FLASH		(u8)4
#define RCC			(u8)5
#define EXTI0		(u8)6
#define EXTI1		(u8)7
#define EXTI2		(u8)8
#define EXTI3		(u8)9
#define EXTI4		(u8)10

/*                                          */
/********************************************/



/******* Configurations Dependencies ********/
/*									        */

#define INTR_STATE_ENABLED 			(u8)21
#define INTR_STATE_DISABLED 		(u8)20

/*									        */
/********************************************/




/*********** Configurations AIRCR ***********/
/*									        */

#define PRIORITY_PRE_16_SUB_00 		0x5FA0300            // For 16 Group - 00 Sub
#define PRIORITY_PRE_08_SUB_02 		0x5FA0400            // For 08 Group - 02 Sub
#define PRIORITY_PRE_04_SUB_04 		0x5FA0500            // For 04 Group - 04 Sub
#define PRIORITY_PRE_02_SUB_08 		0x5FA0600            // For 02 Group - 08 Sub
#define PRIORITY_PRE_00_SUB_16 		0x5FA0700            // For 00 Group - 16 Sub

/*									        */
/********************************************/







/*************************************************************************************************/
/* Description: Initializes the interrupt priority configuration								 */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 NVIC_u8Initialize( u32 Copy_u8PrioConf )  ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */

u8 NVIC_u8Enable(u8 Copy_u8IntrIndex) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8Disable(u8 Copy_u8IntrIndex);

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables all the PIE of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8EnableAll() ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Disables all the PIE of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8DisableAll() ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPrio(u8 Copy_u8IntrIndex , u8 Copy_u8Prem , u8 Copy_u8Sub ) ;

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets the Pending Flag of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPending(u8 Copy_u8IntrIndex);

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Clears the Pending Flag of the Indexed peripheral					             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8ClearPending(u8 Copy_u8IntrIndex);

/*																					             */
/*************************************************************************************************/

/////////////////////////////////////////

/*************************************************************************************************/
/* Description: Disables Peripheral Interrupts (GIE = 0)							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Disable_Peri(void);

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables Peripheral Interrupts (GIE = 1)	    						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Enable_Peri(void);

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables Peripheral and Faults Interrupts 							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Disable_Peri_Fault(void);

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables Peripheral and Faults Interrupts 							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Enable_Peri_Fault(void);

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables Interrupts with lower priority (Higher Written Value)		             */
/*																				            	 */
/* Inputs : u8 Copy_PriorityIndex -> the priority to start disabling interrupts with             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

//void NVIC_u8SetPriorityBase(u8 Copy_PriorityIndex);

/*																					             */
/*************************************************************************************************/


#endif /* ARM_GPIO_INT_H_ */
