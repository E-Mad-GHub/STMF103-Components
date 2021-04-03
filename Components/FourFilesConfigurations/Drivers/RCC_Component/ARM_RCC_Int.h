/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the RCC Component in high efficiency*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard                       */
#ifndef ARM_RCC_INT_H_
#define ARM_RCC_INT_H_





#define ENABLED 				(u8)1
#define DISABLED 				(u8)0

#define ARM_GPIO_A				(u8)100
#define ARM_GPIO_B				(u8)101
#define ARM_GPIO_C				(u8)102
#define ARM_GPIO_D				(u8)103
#define ARM_AFIO				(u8)104
#define ARM_USART2				(u8)105
#define ARM_SPI1				(u8)106
#define ARM_SPI2				(u8)107
#define ARM_I2C1				(u8)108
#define ARM_I2C2				(u8)109





/*************************************************************************************/
/* Description: Set the PINs Direction ( Input or Output )							 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Direction  : The Direction of the chosen Pin	            			 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

void RCC_voidInit(void) ;

/*																					 */
/*************************************************************************************/


/*************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

void RCC_voidSetPerState( u8 Copy_u8PerIndx , u8 Copy_u8State ) ;

/*																					 */
/*************************************************************************************/


#endif /* ARM_RCC_INT_H_ */
