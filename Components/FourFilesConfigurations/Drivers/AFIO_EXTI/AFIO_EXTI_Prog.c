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

#include "AFIO_EXTI_Int.h"
#include "AFIO_EXTI_Conf.h"
#include "AFIO_EXTI_Priv.h"



void AFIO_EXTI_Init(void){

	for( u8 Loop_EXT = 0 ; Loop_EXT < EXTI_MAX_NB ; Loop_EXT ++ ){

		if(AFIO_EXTI_PORT[Loop_EXT] != AFIO_DISABLED ){
			AFIO_voidSetEXTIPort( Loop_EXT , AFIO_EXTI_PORT[Loop_EXT] ) ;
		}

	}

}





void AFIO_voidSetEXTIPort( u8 Copy_u8EXTIIndx , u8 Copy_u8Port ){

	switch(Copy_u8EXTIIndx){

	case EXTI_0:

		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) &= ~((u32)(0x0000000F)) ;
		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) |= ((u32)(Copy_u8Port << EXTI_0)) ;

		break ;

	case EXTI_1:

		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) &= ~((u32)(0x000000F0)) ;
		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) |= ((u32)(Copy_u8Port << EXTI_1)) ;

		break ;

	case EXTI_2:

		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) &= ~((u32)(0x00000F00)) ;
		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) |= ((u32)(Copy_u8Port << EXTI_2)) ;

		break ;

	case EXTI_3:

		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) &= ~((u32)(0x0000F000)) ;
		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) |= ((u32)(Copy_u8Port << EXTI_3)) ;

		break ;

	case EXTI_4:

		( ((Register_32*) AFIO_EXTI2 ) -> RegAccess ) &= ~((u32)(0x0000000F)) ;
		( ((Register_32*) AFIO_EXTI1 ) -> RegAccess ) |= ((u32)(Copy_u8Port << EXTI_0)) ;

    	break ;
	}

}
















