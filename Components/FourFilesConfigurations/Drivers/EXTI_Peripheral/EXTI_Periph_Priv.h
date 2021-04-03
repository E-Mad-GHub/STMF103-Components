/************************************************************************************/
/* Description : This is an Private file that contains the private definitions and  */
/*               functions implementations needed to use the RCC Component  	    */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef EXTI_Periph_PRIV_H_
#define EXTI_Periph_PRIV_H_




/*****************************************************************************/
/*						     Registers Addresses							 */

/* Defining Addresses												         */
#define EXTI_IMR              		           0x40010400
#define EXTI_RTSR              		           0x40010408
#define EXTI_FTSR              		           0x4001040C

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/*						     EXTI Names 									 */

u8 EXTI_Name[EXTI_MAX_NB] =     {
									(u8)0,
									(u8)1,
									(u8)2,
									(u8)3,
									(u8)4
								};
/*																			 */
/*****************************************************************************/




#endif /* ARM_RCC_PRIV_H_ */
