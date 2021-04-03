/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the GPIO		*/
/* 				 Driver																*/
/*																					*/
/* Created on  : Mar 14, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "../../Handlers/GPIO_Example/STD_TYPE.h"
#include "ARM_GPIO_Int.h"





/*****************************************************************************************************************************************************/
/* Description: Configure the pin just like the configurations sent through the structure								    						 */
/*																																					 */
/* Inputs  ->  Copy_S_Pin_Conf_PinConf      : Pointer to structure containing the Pin Configurations												 */
/*															            																			 */
/* Outputs ->  u8Error      : Error State																											 */
/*																																					 */

u8 GPIO_u8PinConfigure( const Pin_Conf * Copy_S_Pin_Conf_PinConf ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;

	/* Checking on the pointer if null or not */
	if (Copy_S_Pin_Conf_PinConf == NULL ){

		Local_Err_state = ERROR_NOK ;

	}

	/* If the pointer is not null pointer  	  */
	else {

		/* Concatenating the 2 bits of the 'Mode' and the 'Frequency' to obtain a nibble to be used for each Pin configuration */
		u8 config_mask = ( (Copy_S_Pin_Conf_PinConf -> Mode) << 2 ) | ( Copy_S_Pin_Conf_PinConf -> Frequency ) ;



		/* Checking if the chosen configuration of the Pin is input pull to apply changes on the ODR 						   */
		if ( config_mask == INPUT_PULL_DOWN_MASK ){

			GPIO_u8SetPinValue ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) , (Copy_S_Pin_Conf_PinConf -> Port_Number) , PIN_VALUE_LOW );

		}
		else if ( config_mask == INPUT_PULL_UP_MASK ){

			GPIO_u8SetPinValue ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) , (Copy_S_Pin_Conf_PinConf -> Port_Number) , PIN_VALUE_HIGH );
			config_mask = INPUT_PULL_DOWN_MASK ;

		}






		switch ( (Copy_S_Pin_Conf_PinConf -> Port_Number) ){

			/******** PORT A ASSIGNATION ******************************************************************************************************************************/
			case GPIO_PORT_A:
				if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < CONTROL_REGISTER_MAX_NUMB_OF_PINS ){

					( ((Register_32*) GPIO_CRLA_REG ) -> RegAccess ) &= (~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) ))        ;
					( ((Register_32*) GPIO_CRLA_REG ) -> RegAccess ) |= (u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) )  ;

				}
				else if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < PORT_MAX_NUMB_OF_PINS ){

					( ((Register_32*) GPIO_CRHA_REG ) -> RegAccess ) &= \
							(~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value -CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) ))        ;
					( ((Register_32*) GPIO_CRHA_REG ) -> RegAccess ) |= \
							(u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value -CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) )  ;

				}
				else {

					Local_Err_state = ERROR_NOK ;

				}

				break;
			/**************************************************************************************************************************************/


			/******** PORT B ASSIGNATION ******************************************************************************************************************************/
			case GPIO_PORT_B:
				if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < CONTROL_REGISTER_MAX_NUMB_OF_PINS ){

					( ((Register_32*) GPIO_CRLB_REG ) -> RegAccess ) &= (~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) ))        ;
					( ((Register_32*) GPIO_CRLB_REG ) -> RegAccess ) |= (u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) )  ;

				}
				else if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < PORT_MAX_NUMB_OF_PINS ){

					( ((Register_32*) GPIO_CRHB_REG ) -> RegAccess ) &= \
							(~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) ))        ;
					( ((Register_32*) GPIO_CRHB_REG ) -> RegAccess ) |= \
							(u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) )  ;

				}
				else {

					Local_Err_state = ERROR_NOK ;

				}

				break;
			/**************************************************************************************************************************************/



			/******** PORT C ASSIGNATION ******************************************************************************************************************************/
			case GPIO_PORT_C:
            	if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < CONTROL_REGISTER_MAX_NUMB_OF_PINS ){

            		( ((Register_32*) GPIO_CRLC_REG ) -> RegAccess ) &= (~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) ))        ;
            		( ((Register_32*) GPIO_CRLC_REG ) -> RegAccess ) |= (u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) )  ;

				}
				else if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < PORT_MAX_NUMB_OF_PINS ){

					( ((Register_32*) GPIO_CRHC_REG ) -> RegAccess ) &= \
							(~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) ))        ;
					( ((Register_32*) GPIO_CRHC_REG ) -> RegAccess ) |= \
							(u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) )  ;

            	}
				else {

					Local_Err_state = ERROR_NOK ;

				}

            	break;
    		/**************************************************************************************************************************************/



    		/******** PORT D ASSIGNATION ******************************************************************************************************************************/
            case GPIO_PORT_D:
            	if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < CONTROL_REGISTER_MAX_NUMB_OF_PINS ){

            		( ((Register_32*) GPIO_CRLD_REG ) -> RegAccess ) &= (~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) ))        ;
            		( ((Register_32*) GPIO_CRLD_REG ) -> RegAccess ) |= (u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value) ) )  ;

            	}
            	else if ( (Copy_S_Pin_Conf_PinConf -> Pin_Value) < PORT_MAX_NUMB_OF_PINS ){

            		( ((Register_32*) GPIO_CRHD_REG ) -> RegAccess ) &= \
            				(~(u32)( 15 << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) ))        ;
            		( ((Register_32*) GPIO_CRHD_REG ) -> RegAccess ) |= \
            				(u32)( config_mask << ( 4*(Copy_S_Pin_Conf_PinConf -> Pin_Value-CONTROL_REGISTER_MAX_NUMB_OF_PINS) ) )  ;

            	}
				else {

					Local_Err_state = ERROR_NOK ;

				}

            	break;
    		/**************************************************************************************************************************************/



            default :

            	Local_Err_state = ERROR_NOK ;


		}


	}



	return Local_Err_state ;
}

/*																																					 */
/*****************************************************************************************************************************************************/








/*****************************************************************************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        																						 */
/*																																					 */
/* Inputs:  Copy_PinIndex      : The Number of Pin									 																 */
/* 			Copy_PortIndex     : The Port Index ( A , B , C , D ) 																					 */
/* 		    Copy_PinValue      : The Value of the output on the chosen Pin	     																	 */
/* Outputs: u8Error     	   : Error State																										 */
/*																																					 */



u8 GPIO_u8SetPinValue ( const u8 Copy_PinIndex , const u8 Copy_PortIndex , const u8 Copy_PinValue ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;


	static Register_32 * BSRR_Register_Array[4] = { (Register_32 *)GPIO_BSRA_REG , (Register_32 *)GPIO_BSRB_REG , (Register_32 *)GPIO_BSRC_REG , (Register_32 *)GPIO_BSRD_REG } ;
	static Register_32 * BRR_Register_Array[4]  = { (Register_32 *)GPIO_BRRA_REG , (Register_32 *)GPIO_BRRB_REG , (Register_32 *)GPIO_BRRC_REG , (Register_32 *)GPIO_BRRD_REG } ;

	if ( Copy_PortIndex < 4 ){
	        switch(Copy_PinValue){

	        case PIN_VALUE_HIGH:

	        	( BSRR_Register_Array[Copy_PortIndex] -> RegAccess ) = ( 1 << Copy_PinIndex )   ;

	        	break;


	        case PIN_VALUE_LOW:

	        	( BRR_Register_Array[Copy_PortIndex] -> RegAccess ) = ( 1 << Copy_PinIndex )   ;

	        	break;


	        default:
	        	Local_Err_state = ERROR_NOK ;


	        }
	}
	else {
		Local_Err_state = ERROR_NOK ;
	}




	return Local_Err_state ;
}

/*																																					 */
/*****************************************************************************************************************************************************/






/*****************************************************************************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        																						 */
/*																																					 */
/* Inputs:  Copy_PinIndex      : The Number of Pin																									 */
/* 			Copy_PortIndex     : The Port Index ( A , B , C , D ) 																					 */
/* 		    *Copy_PinValue     : The Value of the input on the chosen Pin	     																	 */
/* Outputs: u8Error     	   : Error State										 																 */
/*																																					 */



u8 GPIO_u8GetPinValue ( const u8 Copy_PinIndex , const u8 Copy_PortIndex , u8 * Copy_PinValue ) {

	/* 	 Defining the error level of the function   */
	u8 Local_Err_state = ERROR_OK	;


	static Register_32 * IDR_Register_Array[4] = { (Register_32 *)GPIO_IDRA_REG , (Register_32 *)GPIO_IDRB_REG , (Register_32 *)GPIO_IDRC_REG , (Register_32 *)GPIO_IDRD_REG } ;


	if ( Copy_PortIndex < 4 ){


		if( ( IDR_Register_Array[Copy_PortIndex] -> RegAccess ) & ( 1 << Copy_PinIndex ) )  {

			* Copy_PinValue = PIN_VALUE_HIGH ;

		}
		else {

			* Copy_PinValue = PIN_VALUE_LOW ;

		}


	}
	else {
		Local_Err_state = ERROR_NOK ;
	}




	return Local_Err_state ;
}

/*																																					 */
/*****************************************************************************************************************************************************/


