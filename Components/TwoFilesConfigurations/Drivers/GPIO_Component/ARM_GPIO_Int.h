/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the DIO Component in high efficiency*/
/*																					*/
/* Created on  : Mar 13, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard *******************************/
#ifndef ARM_DIO_INT_H_
#define ARM_DIO_INT_H_




/****** Defining the Pin Config. Struct *****/
/*                                          */

typedef struct {

	u8  Pin_Value       ;
	u8  Port_Number 	;
	u8  Frequency		;
	u8  Mode			;

}Pin_Conf;

/*                                          */
/********************************************/




/****** Defining the Peripheral Struct ******/
/*                                          */
/*
typedef struct {

	u32   CRL_REG   ;
	u32   CRH_REG   ;
	u32   IDR_REG   ;
	u32   ODR_REG   ;
	u32   BSR_REG   ;
	u32   BRR_REG   ;
	u32   LCK_REG   ;

}GPIO_Peripheral;
*/
/*                                          */
/********************************************/




/*****************************************************************************/
/*						     Registers Addresses							 */

/* Assigning GPIOs Addresses to the peripherals						         */
/*
GPIO_Peripheral * const GPIO_A =  (GPIO_Peripheral *) 0x40010800 ;


GPIO_Peripheral * const GPIO_B =  (GPIO_Peripheral *) 0x40010C00 ;


GPIO_Peripheral * const GPIO_C =  (GPIO_Peripheral *) 0x40011000 ;


GPIO_Peripheral * const GPIO_D =  (GPIO_Peripheral *) 0x40011400 ;
*/

/*																			 */
/*****************************************************************************/



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




/*** Defining the Pin Number in each Port ***/
/*                                          */

#define       GPIO_PORT_A        (u8)0
#define       GPIO_PORT_B        (u8)1
#define       GPIO_PORT_C        (u8)2
#define       GPIO_PORT_D        (u8)3

/*                                          */
/********************************************/



/*** Defining the Pin Number in each Port ***/
/*                                          */

#define       GPIO_PIN0        (u8)0
#define       GPIO_PIN1        (u8)1
#define       GPIO_PIN2        (u8)2
#define       GPIO_PIN3        (u8)3
#define       GPIO_PIN4        (u8)4
#define       GPIO_PIN5        (u8)5
#define       GPIO_PIN6        (u8)6
#define       GPIO_PIN7        (u8)7
#define       GPIO_PIN8        (u8)8
#define       GPIO_PIN9        (u8)9
#define       GPIO_PIN10       (u8)10
#define       GPIO_PIN11       (u8)11
#define       GPIO_PIN12       (u8)12
#define       GPIO_PIN13       (u8)13
#define       GPIO_PIN14       (u8)14
#define       GPIO_PIN15       (u8)15

/*                                          */
/********************************************/




/*****************************************************************************/
/* 						CRL & CRH Configurations(1)							 */
/*					    PIN DIRECTIONS(In Runtime)							 */

/* Defining Input Mode														 */
#define     MODE_INPUT					                (u8)0

/* Defining Output Frequency (10MHz)										 */
#define     Freq_10_MHz			                        (u8)1

/* Defining Output Frequency (2MHz)											 */
#define     Freq_2_MHz           			            (u8)2

/* Defining Output Frequency (50MHz)										 */
#define     Freq_50_MHz			                        (u8)3

/*																			 */
/*****************************************************************************/




/*****************************************************************************/
/* 						CRL & CRH Configurations(2)							 */
/*					    PIN DIRECTIONS(In Runtime)							 */

/* Defining Input Configurations 											 */
#define     MODE_INPUT_ANALOG			                       (u8)0
#define     MODE_INPUT_FLOATING			                       (u8)1
#define 	MODE_INPUT_PULL_DOWN					           (u8)2
#define     MODE_INPUT_PULL_UP			                       (u8)3

/* Defining Mode Configurations 											 */
#define     MODE_OUTPUT_PUSH_PULL                              (u8)0
#define     MODE_OUTPUT_OPEN_DRAIN                             (u8)1
#define     MODE_OUTPUT_AF_PUSH_PULL                           (u8)2
#define     MODE_OUTPUT_AF_OPEN_DRAIN                          (u8)3

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/* 						IDR & ODR Configurations							 */
/*							   PIN VALUES									 */

#define		PIN_VALUE_HIGH  				   	       			1
#define		PIN_VALUE_LOW  				       	 	  			0

/*																			 */
/*****************************************************************************/





/*****************************************************************************/
/* 						Magic Numbers Definitions							 */
/*							   												 */

#define		CONTROL_REGISTER_MAX_NUMB_OF_PINS					8
#define		PORT_MAX_NUMB_OF_PINS      	 	   				 	16
#define		INPUT_PULL_DOWN_MASK								8
#define 	INPUT_PULL_UP_MASK									12

/*																			 */
/*****************************************************************************/







/*********************************************************************************************************/
/* Description: Configure the pin just like the configurations sent through the structure				 */
/*																					 					 */
/* Inputs  ->  Copy_S_Pin_Conf_PinConf      : Pointer to structure containing the Pin Configurations	 */
/*															            								 */
/* Outputs ->  u8Error      : Error State																 */
/*																										 */

u8 GPIO_u8PinConfigure( const Pin_Conf * Copy_S_Pin_Conf_PinConf )  ;

/*																										 */
/*********************************************************************************************************/



/*********************************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        											 */
/*																					 					 */
/* Inputs:  Copy_PinIndex      : The Number of Pin														 */
/* 			Copy_PortIndex     : The Port Index ( A , B , C , D ) 										 */
/* 		    Copy_PinValue      : The Value of the output on the chosen Pin	     						 */
/* Outputs: u8Error            : Error State															 */
/*																					 					 */

u8 GPIO_u8SetPinValue ( const u8 Copy_PinIndex , const u8 Copy_PortIndex , const u8 Copy_PinValue ) ;

/*																										 */
/*********************************************************************************************************/



/*********************************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        											 */
/*																										 */
/* Inputs:  Copy_PinIndex      : The Number of Pin									 					 */
/* 			Copy_PortIndex	   : The Port Index															 */
/* 		    *Copy_PinValue 	   : The Pointer to variable which will carry received val. 				 */
/* Outputs: u8Error            : Error State															 */
/*							  																			 */

u8 GPIO_u8GetPinValue ( const u8 Copy_PinIndex , const u8 Copy_PortIndex , u8 * Copy_PinValue ) ;

/*																										 */
/*********************************************************************************************************/




#endif /* ARM_GPIO_INT_H_ */
