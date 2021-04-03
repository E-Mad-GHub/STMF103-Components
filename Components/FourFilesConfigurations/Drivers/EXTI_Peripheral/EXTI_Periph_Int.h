/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the RCC Component in high efficiency*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard                       */
#ifndef EXTI_Periph_INT_H_
#define EXTI_Periph_INT_H_


#define EXTI_ENABLED			(u8)1
#define EXTI_DISABLED			(u8)0


#define EXTI_0					(u8)0
#define EXTI_1			 		(u8)1
#define EXTI_2			 		(u8)2
#define EXTI_3					(u8)3
#define EXTI_4					(u8)4


#define RISING_EDGE_TRIG		0X30
#define FALLING_EDGE_TRIG		0X31




/*************************************************************************************/
/* Description: Set the EXTIs Status and Edge trigger type							 */
/*																					 */
/* Inputs:  void      							         							 */
/* 		  														         			 */
/* Outputs: void      																 */
/*																					 */

void EXTI_Periph_Init(void) ;

/*																					 */
/*************************************************************************************/


/*************************************************************************************/
/* Description: Set the EXTI status     											 */
/*																					 */
/* Inputs:  Copy_u8EXTIIndx      : The Number of EXTI		         				 */
/* 		    												            			 */
/* 		    Copy_u8Status      	 : The Status to be assigned to the EXTI  			 */
/*																					 */

void EXTI_voidSetEXTIStatus( u8 Copy_u8EXTIIndx , u8 Copy_u8Status ) ;

/*																					 */
/*************************************************************************************/



/*************************************************************************************/
/* Description: Set the EXTI status     											 */
/*																					 */
/* Inputs:  Copy_u8EXTIIndx      : The Number of EXTI		         				 */
/* 		    												            			 */
/* 		    Copy_u8TType      	 : The Edge Type to be assigned to the EXTI 		 */
/*																					 */

void EXTI_voidSetEXTITrigType( u8 Copy_u8EXTIIndx , u8 Copy_u8TType ) ;

/*																					 */
/*************************************************************************************/



#endif /* ARM_RCC_INT_H_ */
