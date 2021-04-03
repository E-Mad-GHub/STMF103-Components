/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the RCC Component in high efficiency*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard                       */
#ifndef AFIO_EXTI_INT_H_
#define AFIO_EXTI_INT_H_


#define AFIO_DISABLED				(u8)55


#define EXTI_0					(u8)0
#define EXTI_1			 		(u8)1
#define EXTI_2			 		(u8)2
#define EXTI_3					(u8)3
#define EXTI_4					(u8)4

#define PORTA					0X0
#define PORTB					0X1
#define PORTC					0X2



/*************************************************************************************/
/* Description: Set the Ports to EXTIs												 */
/*																					 */
/* Inputs:  void      							         							 */
/* 		  														         			 */
/* Outputs: void      																 */
/*																					 */

void AFIO_EXTI_Init(void) ;

/*																					 */
/*************************************************************************************/


/*************************************************************************************/
/* Description: Set the Port of the EXTI to work on									 */
/*																					 */
/* Inputs:  Copy_u8EXTIIndx      : The Number of EXTI		         				 */
/* 		    												            			 */
/* 		    Copy_u8Port      	 : The port to be assigned to the EXTI  			 */
/*																					 */

void AFIO_voidSetEXTIPort( u8 Copy_u8EXTIIndx , u8 Copy_u8Port ) ;

/*																					 */
/*************************************************************************************/



#endif /* ARM_RCC_INT_H_ */
