/************************************************************************************/
/* Description : This is an Private file that contains the private definitions and  */
/*               functions implementations needed to use the DIO Component  	    */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef ARM_DIO_PRIV_H_
#define ARM_DIO_PRIV_H_




/********* Hardware Dependencies ************/
/*									        */

/* Defining the Number of Pins in port      */
#define GPIO_NB_OF_PINS_IN_PORTA_B   	16
#define GPIO_NB_OF_PINS_IN_PORTC     	3
#define GPIO_NB_OF_PINS_IN_PORTD   		2

/* Defining maximum No. of pins available   */
#define GPIO_MAXPINNB        			37

/* Defining maximum No. of ports            */
#define GPIO_PORT_MAXPINNB    			4

/*									        */
/********************************************/





/*****************************************************************************/
/*						     Registers Addresses							 */

/* Defining CRLA,CRLb,CRLC,CRLD Addresses							         */
#define GPIO_CRLA_REG                         0x40010800
#define GPIO_CRHA_REG                         0x40010804
#define GPIO_IDRA_REG                         0x40010808
#define GPIO_ODRA_REG                         0x4001080C
#define GPIO_BSRA_REG                         0x40010810
#define GPIO_BRRA_REG                         0x40010814
#define GPIO_LCKA_REG                         0x40010818

#define GPIO_CRLB_REG                         0x40010C00
#define GPIO_CRHB_REG                         0x40010C04
#define GPIO_IDRB_REG                         0x40010C08
#define GPIO_ODRB_REG                         0x40010C0C
#define GPIO_BSRB_REG                         0x40010C10
#define GPIO_BRRB_REG                         0x40010C14
#define GPIO_LCKB_REG                         0x40010C18

#define GPIO_CRLC_REG                         0x40011000
#define GPIO_CRHC_REG                         0x40011004
#define GPIO_IDRC_REG                         0x40011008
#define GPIO_ODRC_REG                         0x4001100C
#define GPIO_BSRC_REG                         0x40011010
#define GPIO_BRRC_REG                         0x40011014
#define GPIO_LCKB_REG                         0x40010C18

#define GPIO_CRLD_REG                         0x40011400
#define GPIO_CRHD_REG                         0x40011404
#define GPIO_IDRD_REG                         0x40011408
#define GPIO_ODRD_REG                         0x4001140C
#define GPIO_BSRD_REG                         0x40011410
#define GPIO_BRRD_REG                         0x40011414
#define GPIO_LCKD_REG                         0x40011418


/*																			 */
/*****************************************************************************/













#endif /* ARM_DIO_PRIV_H_ */
