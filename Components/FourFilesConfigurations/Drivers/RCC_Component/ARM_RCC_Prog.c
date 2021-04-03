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

#include "ARM_RCC_Int.h"
#include "ARM_RCC_Conf.h"
#include "ARM_RCC_Priv.h"



/*************************************************************************************************************************************************/
/* Description: Set the PINs Direction ( Input or Output )							                                                             */
/*																					                                                             */
/* Inputs:  u8PinNB      : The Number of Pin		         						                                                             */
/* 		    u8Direction  : The Direction of the chosen Pin	            			                                                             */
/* Outputs: u8Error      : Error State												                                                             */
/*																					                                                             */

void RCC_voidInit(void){


	/*   Initialization Steps : Enabling the HSI then Choosing it as the SysClk then close other clocks then		*/
	/*   edit whatever we need according to the Configure File   													*/

	/* Enable the HSI Clk  (also its supposed to be enabled after reset , but in case if not)  */
	(((Register_32*) LOCAL_RCC_CR ) -> RegAccess )   |= (u32)(1) ;

	/* Assign the HSI as SysClk */
	(((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ) &= (u32)~((u32)0x03);

	/* Disable the PLL Clk  */
	(((Register_32*) LOCAL_RCC_CR ) -> RegAccess )   &= (u32)(~(1<<24)) ;

	/* Disable the HSE Clk  */
	(((Register_32*) LOCAL_RCC_CR ) -> RegAccess )   &= (u32)(~(1<<16)) ;




	/****************************************************************************************************************/




	if ( RCC_HSI_CLK == CLK_ENABLED ){
			SET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , RCC_HSI_BNumb )    ;
			while(! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSI_BNumb+1) ))){}
	}

	if ( RCC_HSE_CLK == CLK_ENABLED ){
			SET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , RCC_HSE_BNumb )    ;
			while(! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSE_BNumb+1) ))){}
	}

	if ( RCC_PLL_CLK == CLK_ENABLED ){



		/* PLL SOURCE CONFIG.   */

			if ( RCC_PLL_SRC == HSI_CLK){

				if( ! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSI_BNumb+1) ) ) ){
						SET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , RCC_HSI_BNumb )    ;
						while(! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSI_BNumb+1) ))){}
				}


				CLR_BIT( (((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ) , PLL_SRC_BIT )    ;


			}
			else if ( RCC_PLL_SRC == HSE_CLK){

				if( ! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSE_BNumb+1) ) ) ){
						SET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , RCC_HSE_BNumb )    ;
						while(! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_HSE_BNumb+1) ))){}
				}


				SET_BIT( (((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ) , PLL_SRC_BIT )    ;

			}


		/***********************************************/

		/* PLL MULT CONFIG.    */

			ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),18,GET_BIT(RCC_PLL_MUL,0)) ;
			ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),19,GET_BIT(RCC_PLL_MUL,1)) ;
			ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),20,GET_BIT(RCC_PLL_MUL,2)) ;
			ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),21,GET_BIT(RCC_PLL_MUL,3)) ;

		/***********************************************/




		/* TURNING ON THE PLL   */

			SET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , RCC_PLL_BNumb )    ;
			while(! (GET_BIT( (((Register_32*) LOCAL_RCC_CR ) -> RegAccess ) , (RCC_PLL_BNumb+1) ))){}

		/***********************************************/

	}




	/* CHOOSING THE SYS CLK    */

	ASSIGN_NIBBLE( SYS_CLK_NIB_Nb , RCC_SYS_CLK_SRC , (((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ) )	;

	/***************************/





	/* CHOOSING PRESCALERS VALUES  */

	/* AHB PRE */
	ASSIGN_NIBBLE( 1 , RCC_AHB_PRE , (((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ) )  ;
	/***********/

	/* AHB1 PRE */
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  8   ,GET_BIT(RCC_APB1_PRE,0)) ;
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  9   ,GET_BIT(RCC_APB1_PRE,1)) ;
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  10  ,GET_BIT(RCC_APB1_PRE,2)) ;
	/***********/

	/* AHB2 PRE */
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  11  ,GET_BIT(RCC_APB2_PRE,0)) ;
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  12  ,GET_BIT(RCC_APB2_PRE,1)) ;
	ASSIGN_BIT((((Register_32*) LOCAL_RCC_CFGR ) -> RegAccess ),  13  ,GET_BIT(RCC_APB2_PRE,2)) ;
	/***********/




}


void RCC_voidSetPerState( u8 Copy_u8PerIndx , u8 Copy_u8State ){

	switch(Copy_u8PerIndx){

	case ARM_GPIO_A:

		if(Copy_u8State){
			SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 2 ) ;
		}
		else {
			CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 2 ) ;
		}
		break ;

	case ARM_GPIO_B:
		if(Copy_u8State){
			SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 3 ) ;
		}
		else {
			CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 3 ) ;
		}
		break ;

	case ARM_GPIO_C:
		if(Copy_u8State){
			SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 4 ) ;
		}
		else {
			CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 4 ) ;
		}
		break ;

	case ARM_GPIO_D:
		if(Copy_u8State){
			SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 5 ) ;
		}
		else {
			CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 5 ) ;
		}
		break ;

	case ARM_AFIO:
    	if(Copy_u8State){
    		SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 0 ) ;
    	}
    	else {
    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 0 ) ;
    	}
    	break ;

	case ARM_USART2:
    	if(Copy_u8State){
    		SET_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 17 ) ;
    	}
    	else {
    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 17 ) ;
    	}
    	break ;

	case ARM_SPI1:
	    	if(Copy_u8State){
	    		SET_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 12 ) ;
	    	}
	    	else {
	    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB2_EN ) -> RegAccess ) , 12 ) ;
	    	}
	    	break ;

	case ARM_SPI2:
	    	if(Copy_u8State){
	    		SET_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 14 ) ;
	    	}
	    	else {
	    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 14 ) ;
	    	}
	    	break ;

	case ARM_I2C1:
	    	if(Copy_u8State){
	    		SET_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 21 ) ;
	    	}
	    	else {
	    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 21 ) ;
	    	}
	    	break ;

	case ARM_I2C2:
	    	if(Copy_u8State){
	    		SET_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 22 ) ;
	    	}
	    	else {
	    		CLR_BIT( (((Register_32*) LOCAL_RCC_APB1_EN ) -> RegAccess ) , 22 ) ;
	    	}
	    	break ;

	}

}
















