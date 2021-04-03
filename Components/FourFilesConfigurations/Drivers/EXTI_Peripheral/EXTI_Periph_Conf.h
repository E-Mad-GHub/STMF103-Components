/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons                                                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef EXTI_Periph_CONF_H_
#define EXTI_Periph_CONF_H_





/*****************************************************************************/
/*						     EXTI Number 									 */

#define EXTI_MAX_NB			5

/*																			 */
/*****************************************************************************/






/*****************************************************************************/
/*						     EXTI PORT 									 */

u8 EXTI_Trig_Type[EXTI_MAX_NB]={
									RISING_EDGE_TRIG,
									RISING_EDGE_TRIG,
									RISING_EDGE_TRIG,
									RISING_EDGE_TRIG,
									EXTI_DISABLED
								};
/*																			 */
/*****************************************************************************/








#endif /* ARM_RCC_CONF_H_ */
