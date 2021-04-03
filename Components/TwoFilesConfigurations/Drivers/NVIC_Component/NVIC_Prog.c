/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the GPIO		*/
/* 				 Driver																*/
/*																					*/
/* Created on  : Mar 14, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "../../Handlers/GPIO_Example/STD_TYPE.h"
#include "NVIC_Int.h"










/********************************************************* PRIVATE SECTION ***************************************************************/
/*																																		 */

static u32 Local_Conf ;


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


/****************** Misc. *******************/
/*                                          */

#define MAX_REG_BITS		(u8)32
#define MAX_INTRPT_NB		(u8)80

/*                                          */
/********************************************/

/*																																		 */
/*****************************************************************************************************************************************/













/********************************************************* FUNCTIONS SECTION *************************************************************/
/*																																		 */


/*************************************************************************************************/
/* Description: Initializes the interrupt priority configuration								 */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 NVIC_u8Initialize( u32 Copy_u8PrioConf ) {
	u8 Local_u8ErrorState = ERROR_OK ;

	//( ((Register_32*) AIRCR ) -> RegAccess ) = (u32)Copy_u8PrioConf ;  // Set Priority Configuration

	if(!(   ( ((Register_32*) AIRCR ) -> RegAccess ) = (u32)Copy_u8PrioConf     )) {
		Local_u8ErrorState = ERROR_NOK ;
	}


	Local_Conf = ( (Copy_u8PrioConf & (0x0000F00)) >> 8 ) ;




	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8Enable(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_Reg_Nb = Copy_u8IntrIndex / MAX_REG_BITS ;
	u8 Local_Pin_Nb = Copy_u8IntrIndex % MAX_REG_BITS ;


	if(!(   ISER -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
		Local_u8ErrorState = ERROR_NOK ;
	}



	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables the PIE of the Indexed peripheral							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8Disable(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_Reg_Nb = Copy_u8IntrIndex / MAX_REG_BITS ;
	u8 Local_Pin_Nb = Copy_u8IntrIndex % MAX_REG_BITS ;

	if(!(   ICER -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
		Local_u8ErrorState = ERROR_NOK ;
	}



	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables all the PIE of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8EnableAll() {
	u8 Local_u8ErrorState = ERROR_OK ;

	for (u8 count = 0 ; count < MAX_INTRPT_NB ; count ++){

			u8 Local_Reg_Nb = count / MAX_REG_BITS ;
			u8 Local_Pin_Nb = count % MAX_REG_BITS ;


			if(!(   ISER -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
				Local_u8ErrorState = ERROR_NOK ;
			}

	}


	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables all the PIE of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8DisableAll() {
	u8 Local_u8ErrorState = ERROR_OK ;

	for (u8 count = 0 ; count < MAX_INTRPT_NB ; count ++){

			u8 Local_Reg_Nb = count / MAX_REG_BITS ;
			u8 Local_Pin_Nb = count % MAX_REG_BITS ;


			if(!(   ICER -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
				Local_u8ErrorState = ERROR_NOK ;
			}

	}


	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Sets the Priority of the required Interrupt							             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPrio(u8 Copy_u8IntrIndex , u8 Copy_u8Prem , u8 Copy_u8Sub ) {
	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_Pin_Nb = Copy_u8IntrIndex % MAX_REG_BITS ;

	u8 Local_Pre_Shift = Local_Conf+1;

	u8 Local_Sub_Shift = 4;


	if(Local_Conf == 7){
		Local_Pre_Shift = 0;
	}
	else if(Local_Conf == 3){
		Local_Sub_Shift = 0;
	}

	//IPR -> INT_NUM[Local_Pin_Nb] = (u8)( (Copy_u8Prem << Local_Pre_Shift)|(Copy_u8Sub << Local_Sub_Shift) ) ;

	if(!(   IPR -> INT_NUM[Local_Pin_Nb] = (u8)( (Copy_u8Prem << Local_Pre_Shift)|(Copy_u8Sub << Local_Sub_Shift) )   )) {
		Local_u8ErrorState = ERROR_NOK ;
	}

	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Sets the Pending Flag of the Indexed peripheral						             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8SetPending(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_Reg_Nb = Copy_u8IntrIndex / MAX_REG_BITS ;
	u8 Local_Pin_Nb = Copy_u8IntrIndex % MAX_REG_BITS ;

	//( ((Register_32*) ISPR ) -> RegAccess ) = (1 << ( 6 )  ) ;

	if(!(   ISPR -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
		Local_u8ErrorState = ERROR_NOK ;
	}



	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Clears the Pending Flag of the Indexed peripheral					             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex    -> No of Interrupt					 			                 */
/* 																								 */
/* Outputs: u8Error			    -> Error State										             */
/*																					             */

u8 NVIC_u8ClearPending(u8 Copy_u8IntrIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_Reg_Nb = Copy_u8IntrIndex / MAX_REG_BITS ;
	u8 Local_Pin_Nb = Copy_u8IntrIndex % MAX_REG_BITS ;

	//( ((Register_32*) ISPR ) -> RegAccess ) = (1 << ( 6 )  ) ;

	if(!(   ICPR -> REG_NUM[Local_Reg_Nb] = (1 << (Local_Pin_Nb)  )   )) {
		Local_u8ErrorState = ERROR_NOK ;
	}



	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/


/////////// Special Registers


/*************************************************************************************************/
/* Description: Disables Peripheral Interrupts (GIE = 0)							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Disable_Peri(void) {

	asm("MOV r0, #1 ");
	asm("MSR PRIMASK, r0");

	return;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables Peripheral Interrupts (GIE = 1)	    						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Enable_Peri(void) {

	asm("MOV r0, #0 ");
	asm("MSR PRIMASK, r0");

	return;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables Peripheral and Faults Interrupts 							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Disable_Peri_Fault(void) {

	asm("MOV r0, #1 ");
	asm("MSR FAULTMASK, r0");

	return;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Enables Peripheral and Faults Interrupts 							             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void NVIC_u8Enable_Peri_Fault(void) {

	asm("MOV r0, #0 ");
	asm("MSR FAULTMASK, r0");

	return;
}

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Disables Interrupts with lower priority (Higher Written Value)		             */
/*																				            	 */
/* Inputs : u8 Copy_PriorityIndex -> the priority to start disabling interrupts with             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */
/*
void NVIC_u8SetPriorityBase(u8 Copy_PriorityIndex) {

	u8 x = Copy_PriorityIndex ;

	asm("LDR  r1,x");
	asm("MSR BASEPRI, r0");

	return;
}
*/
/*																					             */
/*************************************************************************************************/




/*																																		 */
/*****************************************************************************************************************************************/
