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





/******* Defining the NVIC ISER Struct ******/
/*                                          */

typedef struct {

	u32  REG_NUM[8]      ;

}NVIC_ISER;

/*                                          */
/********************************************/



/******* Defining the NVIC ICER Struct ******/
/*                                          */

typedef struct {

	u32  REG_NUM[8]      ;

}NVIC_ICER;

/*                                          */
/********************************************/



/******* Defining the NVIC ISPR Struct ******/
/*                                          */

typedef struct {

	u32  REG_NUM[8]      ;

}NVIC_ISPR;

/*                                          */
/********************************************/




/******* Defining the NVIC ISPR Struct ******/
/*                                          */

typedef struct {

	u32  REG_NUM[8]      ;

}NVIC_ICPR;

/*                                          */
/********************************************/




/******* Defining the NVIC ISPR Struct ******/
/*                                          */

typedef struct {

	u32  REG_NUM[8]      ;

}NVIC_IABR;

/*                                          */
/********************************************/




/******* Defining the NVIC ISPR Struct ******/
/*                                          */

typedef struct {

	u8  INT_NUM[240]      ;

}NVIC_IPR;

/*                                          */
/********************************************/




/*****************************************************************************/
/*						     Registers Addresses							 */

/* Assigning GPIOs Addresses to the peripherals						         */


#define AIRCR  (u32)0xE000ED08 + (u32)0x0C


NVIC_ISER * ISER =  (NVIC_ISER *) 0xE000E100 ;


NVIC_ICER * ICER =  (NVIC_ICER *) 0xE000E180 ;


NVIC_ISPR * ISPR =  (NVIC_ISPR *) 0xE000E200 ;


NVIC_ISPR * ICPR =  (NVIC_ISPR *) 0xE000E280 ;


NVIC_IABR * IABR =  (NVIC_IABR *) 0xE000E300 ;


NVIC_IPR *  IPR  =  (NVIC_IPR *)  0xE000E400 ;




/*																			 */
/*****************************************************************************/


/****************************************************************************/
/*								MASKS USED									*/

#define UART2_EN_DIS_MASK				0X00000040


/*																			*/
/****************************************************************************/


#endif /* ARM_RCC_PRIV_H_ */
