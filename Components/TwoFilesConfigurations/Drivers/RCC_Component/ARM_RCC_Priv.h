/************************************************************************************/
/* Description : This is an Private file that contains the private definitions and  */
/*               functions implementations needed to use the RCC Component  	    */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef ARM_RCC_PRIV_H_
#define ARM_RCC_PRIV_H_






/*****************************************************************************/
/*						     Registers Addresses							 */

/* Defining Addresses												         */
#define LOCAL_RCC_CR                         0x40021000		/* Control Reg.  */

#define LOCAL_RCC_CFGR						 0x40021004		/* Config. Reg.  */

#define LOCAL_RCC_CIR						 0x40021008		/* clk Intrpt    */

#define LOCAL_RCC_AHB_EN					 0x40021014		/* AHB  Enable	 */
#define LOCAL_RCC_APB1_EN					 0x4002101C		/* APB1 Enable	 */
#define LOCAL_RCC_APB1_RST					 0x40021010		/* APB1 Reset    */
#define LOCAL_RCC_APB2_EN					 0x40021018		/* APB2 Enable   */
#define LOCAL_RCC_APB2_RST					 0x4002100C		/* APB2 Reset    */

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/*						     CLOCK BITS										 */

#define RCC_HSI_BNumb						(u8)0
#define RCC_HSE_BNumb						(u8)16
#define RCC_PLL_BNumb						(u8)24

#define CLK_ENABLED							(u8)60
#define CLK_DISABLED						(u8)61


/*																			 */
/*****************************************************************************/




/*****************************************************************************/
/*						     PLL SOURCES									 */

#define HSI_CLK								(u8)0
#define HSE_CLK								(u8)1

#define PLL_SRC_BIT							(u8)16

/*																			 */
/*****************************************************************************/




/*****************************************************************************/
/*						     PLL MULTIPLIERS								 */

#define PLL_MUL_4	                         0b0010
#define PLL_MUL_5	                         0b0011
#define PLL_MUL_6	                         0b0100
#define PLL_MUL_7	                         0b0101
#define PLL_MUL_8	                         0b0110
#define PLL_MUL_9	                         0b0111
#define PLL_MUL_65	                         0b1101

/*																			 */
/*****************************************************************************/


/*****************************************************************************/
/*						     SYS CLK Nibble Nb								 */

#define SYS_CLK_NIB_Nb						(u8)0

#define HSI_CHOICE							0b0000
#define HSE_CHOICE							0b0001
#define PLL_CHOICE							0b0010



/*																			 */
/*****************************************************************************/


/*****************************************************************************/
/*						     AHP PRESCALER  								 */

#define AHB_DIV_1							0b0000
#define AHB_DIV_2							0b1000
#define AHB_DIV_4							0b1001
#define AHB_DIV_8							0b1010
#define AHB_DIV_16							0b1011
#define AHB_DIV_64							0b1100
#define AHB_DIV_128							0b1101
#define AHB_DIV_256							0b1110
#define AHB_DIV_512							0b1111

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/*						     APB PRESCALER  								 */

#define APB_DIV_1							0b000
#define APB_DIV_2							0b100
#define APB_DIV_4							0b101
#define APB_DIV_8							0b110
#define APB_DIV_16							0b111


/*																			 */
/*****************************************************************************/





#endif /* ARM_RCC_PRIV_H_ */
