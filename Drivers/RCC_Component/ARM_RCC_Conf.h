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


/*****************************************************************************/
/*						     Clock Sources 									 */

#define RCC_HSI_CLK			CLK_ENABLED
#define RCC_HSE_CLK			CLK_DISABLED

/******************************************************/
/*                 PLL Settings                       */

#define RCC_PLL_CLK			CLK_DISABLED

/*													  */
/*													  */
/*													  */
#define RCC_PLL_SRC			HSI_CLK
/*													  */
/* Example PLL_MUL_4 , PLL_MUL_65(for mul by 6.5) 	  */
#define RCC_PLL_MUL			PLL_MUL_4

/*                 				                      */
/******************************************************/

#define RCC_SYS_CLK_SRC 	HSI_CHOICE

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/*						     Pre Scalers 									 */

/* Choose from 1,2,4,8,16,64,128,256 or 512  */
#define RCC_AHB_PRE			AHB_DIV_1

/* Choose from 1,2,4,8 or 16   */
#define RCC_APB1_PRE		APB_DIV_1

/* Choose from 1,2,4,8 or 16   */
#define RCC_APB2_PRE		APB_DIV_1

/*																			 */
/*****************************************************************************/






#endif /* ARM_RCC_CONF_H_ */
