/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons                                                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef AFIO_EXTI_CONF_H_
#define AFIO_EXTI_CONF_H_





/*****************************************************************************/
/*						     EXTI Number 									 */

#define EXTI_MAX_NB			5

/*																			 */
/*****************************************************************************/






/*****************************************************************************/
/*						     EXTI PORT 									 */

u8 AFIO_EXTI_PORT[EXTI_MAX_NB]={
									PORTA,
									PORTA,
									PORTA,
									PORTA,
									AFIO_DISABLED
								};
/*																			 */
/*****************************************************************************/








#endif /* ARM_RCC_CONF_H_ */
