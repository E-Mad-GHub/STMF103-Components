/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the DIO Component in high efficiency*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard                       */
#ifndef ARM_DIO_INT_H_
#define ARM_DIO_INT_H_



/**** Defining the Port Number in Numbers ***/
/*                                          */

#define LOCAL_PORTA_CHOICE	       0
#define LOCAL_PORTB_CHOICE	       1
#define LOCAL_PORTC_D_CHOICE	   2
#define LOCAL_PORTC_CHOICE		   3
#define LOCAL_PORTD_CHOICE 		   4

/*                                          */
/********************************************/



/**** Defining the Pin Number in Numbers ****/
/*                                          */

/* GPIO A									*/
#define       DIO_PIN0        (u8)0
#define       DIO_PIN1        (u8)1
#define       DIO_PIN2        (u8)2
#define       DIO_PIN3        (u8)3
#define       DIO_PIN4        (u8)4
#define       DIO_PIN5        (u8)5
#define       DIO_PIN6        (u8)6
#define       DIO_PIN7        (u8)7
#define       DIO_PIN8        (u8)8
#define       DIO_PIN9        (u8)9
#define       DIO_PIN10       (u8)10
#define       DIO_PIN11       (u8)11
#define       DIO_PIN12       (u8)12
#define       DIO_PIN13       (u8)13
#define       DIO_PIN14       (u8)14
#define       DIO_PIN15       (u8)15

/* GPIO B									*/
#define       DIO_PIN16       (u8)16
#define       DIO_PIN17       (u8)17
#define       DIO_PIN18       (u8)18
#define       DIO_PIN19       (u8)19
#define       DIO_PIN20       (u8)20
#define       DIO_PIN21       (u8)21
#define       DIO_PIN22       (u8)22
#define       DIO_PIN23       (u8)23
#define       DIO_PIN24       (u8)24
#define       DIO_PIN25       (u8)25
#define       DIO_PIN26       (u8)26
#define       DIO_PIN27       (u8)27
#define       DIO_PIN28       (u8)28
#define       DIO_PIN29       (u8)29
#define       DIO_PIN30       (u8)30
#define       DIO_PIN31       (u8)31

/* GPIO C									*/
#define       DIO_PIN32       (u8)32
#define       DIO_PIN33       (u8)33
#define       DIO_PIN34       (u8)34

/* GPIO D									*/
#define       DIO_PIN35       (u8)35
#define       DIO_PIN36       (u8)36

/*                                          */
/********************************************/






/*****************************************************************************/
/* 						CRL & CRH Configurations							 */
/*					   PIN DIRECTIONS(In Runtime)							 */

/* Defining Input Configurations 											 */
#define     INPUT_ANALOG			               0b0000
#define     INPUT_FLOATING			               0b0100
#define     INPUT_PULL_UP			               0b1000
#define 	INPUT_PULL_DOWN						   0b1100

/* Defining Output Configurations (10MHz)									 */
#define     OUTPUT_10_PUSH_PULL                    0b0001
#define     OUTPUT_10_OPEN_DRAIN                   0b0101
#define     OUTPUT_10_AF_PUSH_PULL                 0b1001
#define     OUTPUT_10_AF_OPEN_DRAIN                0b1101

/* Defining Output Configurations (2MHz)									 */
#define     OUTPUT_2_PUSH_PULL                     0b0010
#define     OUTPUT_2_OPEN_DRAIN                    0b0110
#define     OUTPUT_2_AF_PUSH_PULL                  0b1010
#define     OUTPUT_2_AF_OPEN_DRAIN                 0b1110

/* Defining Output Configurations (50MHz)									 */
#define     OUTPUT_50_PUSH_PULL                    0b0011
#define     OUTPUT_50_OPEN_DRAIN                   0b0111
#define     OUTPUT_50_AF_PUSH_PULL                 0b1011
#define     OUTPUT_50_AF_OPEN_DRAIN                0b1111

/*																			 */
/*****************************************************************************/



/*****************************************************************************/
/* 						IDR & ODR Configurations							 */
/*							   PIN VALUES									 */

#define		GPIO_VAL_INPUT_PUP  				   1
#define		GPIO_VAL_INPUT_PDOWN  				   0

#define		GPIO_VAL_OUTPUT_HIGH  				   1
#define		GPIO_VAL_OUTPUT_LOW  				   0

/*																			 */
/*****************************************************************************/




void DIO_voidInit(void);



/*************************************************************************************/
/* Description: Set the PINs Direction ( Input or Output )							 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Direction  : The Direction of the chosen Pin	            			 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB , u8 Copy_u8Direction ) ;

/*																					 */
/*************************************************************************************/


/*************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

u8 DIO_u8SetPinValue(u8 Copy_u8PinNB , u8 Copy_u8Value ) ;

/*																					 */
/*************************************************************************************/



/*************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    *PCopy_u8Value : The Pointer to variable which will carry received val.  */
/* Outputs: u8Error      : Error State												 */
/*																					 */

u8 DIO_u8GetPinValue(u8 Copy_u8PinNB , u8 * PCopy_u8Value ) ;

/*																					 */
/*************************************************************************************/






/*************************************************************************************/
/* Description: Set the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

u8 DIO_u8SetPortValue(u8 Copy_u8PortNB , u8 Copy_u8Value ) ;

/*																					 */
/*************************************************************************************/



/*************************************************************************************/
/* Description: Get the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    *u8Value     : The Pointer to variable which will carry the received val.*/
/* Outputs: u8Error      : Error State												 */
/*																					 */

u8 DIO_u8GetPortValue(u8 Copy_u8PortNB , u16 * PCopy_u8Value ) ;

/*																					 */
/*************************************************************************************/





#endif /* ARM_DIO_INT_H_ */
