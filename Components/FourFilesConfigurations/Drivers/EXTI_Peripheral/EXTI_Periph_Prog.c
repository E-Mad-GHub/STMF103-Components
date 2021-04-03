/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the RCC Component   */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include "EXTI_Periph_Int.h"
#include "EXTI_Periph_Conf.h"
#include "EXTI_Periph_Priv.h"



void EXTI_Periph_Init(void){

	for( u8 Loop_EXT = 0 ; Loop_EXT < EXTI_MAX_NB ; Loop_EXT ++ ){

		if(EXTI_Trig_Type[Loop_EXT] != EXTI_DISABLED ){

			EXTI_voidSetEXTIStatus( Loop_EXT , EXTI_ENABLED ) ;
			EXTI_voidSetEXTITrigType( EXTI_Name[0] , EXTI_Trig_Type[Loop_EXT] ) ;

		}
		else if(EXTI_Trig_Type[Loop_EXT] == EXTI_DISABLED ){

			EXTI_voidSetEXTIStatus( Loop_EXT , EXTI_DISABLED ) ;

		}

	}

}





void EXTI_voidSetEXTIStatus( u8 Copy_u8EXTIIndx , u8 Copy_u8Status ){

	switch(Copy_u8EXTIIndx){

	case EXTI_0:

		( ((Register_32*) EXTI_IMR ) -> RegAccess ) &= ~((u32)(1 << EXTI_0)) ;
		( ((Register_32*) EXTI_IMR ) -> RegAccess ) |= ((u32)(Copy_u8Status << EXTI_0)) ;

		break ;

	case EXTI_1:

		( ((Register_32*) EXTI_IMR ) -> RegAccess ) &= ~((u32)(1 << EXTI_1)) ;
		( ((Register_32*) EXTI_IMR ) -> RegAccess ) |= ((u32)(Copy_u8Status << EXTI_1)) ;

		break ;

	case EXTI_2:

		( ((Register_32*) EXTI_IMR ) -> RegAccess ) &= ~((u32)(1 << EXTI_2)) ;
		( ((Register_32*) EXTI_IMR ) -> RegAccess ) |= ((u32)(Copy_u8Status << EXTI_2)) ;

		break ;

	case EXTI_3:

		( ((Register_32*) EXTI_IMR ) -> RegAccess ) &= ~((u32)(1 << EXTI_3)) ;
		( ((Register_32*) EXTI_IMR ) -> RegAccess ) |= ((u32)(Copy_u8Status << EXTI_3)) ;

		break ;

	case EXTI_4:

		( ((Register_32*) EXTI_IMR ) -> RegAccess ) &= ~((u32)(1 << EXTI_4)) ;
		( ((Register_32*) EXTI_IMR ) -> RegAccess ) |= ((u32)(Copy_u8Status << EXTI_4)) ;

    	break ;
	}

}




void EXTI_voidSetEXTITrigType( u8 Copy_u8EXTIIndx , u8 Copy_u8TType ){

	switch(Copy_u8TType){

	case RISING_EDGE_TRIG:

		( ((Register_32*) EXTI_RTSR ) -> RegAccess ) = ((u32)(1 << Copy_u8EXTIIndx)) ;

		break ;

	case FALLING_EDGE_TRIG:

		( ((Register_32*) EXTI_FTSR ) -> RegAccess ) = ((u32)(1 << Copy_u8EXTIIndx)) ;

		break ;


	}

}















