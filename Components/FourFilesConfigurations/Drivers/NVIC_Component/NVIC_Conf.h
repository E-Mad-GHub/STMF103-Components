/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons                                                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef ARM_RCC_CONF_H_
#define ARM_RCC_CONF_H_





/* Define Priority Configuration of Interrupts used *********/
/*										 					*/

#define NVIC_PRIORITY_CONF			PRIORITY_CONF_1

/*															*/
/************************************************************/








/************************************************************************/
/*							EXTI Configuration							*/


/* Define Parameters of EXTINTs used ************************/
/*										 					*/

#define EXTINT_NUMBER			5

/*															*/
/************************************************************/



/* Define the state of EXTINTs used *************************/
/*										 					*/

u8 EXTINT_State[EXTINT_NUMBER] = {
								   EXTRINTR_STATE_ENABLED,
								   EXTRINTR_STATE_ENABLED,
								   EXTRINTR_STATE_ENABLED,
								   EXTRINTR_STATE_ENABLED,
								   EXTRINTR_STATE_ENABLED
															} ;

/*															*/
/************************************************************/





/* Define the state of EXTINTs used *************************/
/*										 					*/

u8 EXTINT_Initial_Priority[EXTINT_NUMBER] = {
								                 (u8)0x60,
								                 (u8)0x10,
								                 (u8)0x20,
								                 (u8)0x30,
								                 (u8)0x40
															} ;

/*															*/
/************************************************************/



/*																		*/
/************************************************************************/




#endif /* ARM_RCC_CONF_H_ */
