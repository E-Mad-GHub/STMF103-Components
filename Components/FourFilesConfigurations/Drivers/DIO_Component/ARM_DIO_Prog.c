/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the DIO Component   */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include "ARM_DIO_Int.h"
#include "ARM_DIO_Priv.h"
#include "ARM_DIO_Conf.h"








/*************************************************************************************************************************************************/
/* Description: Set the Pins Direction ( Input or Output )	and Value (High or Low) as mentioned in the Configuration File                       */
/*																					                                                             */
/* Inputs:  Void   									         						                                                             */
/* 																        			                                                             */
/* Outputs: Void                    												                                                             */
/*																					                                                             */

void DIO_voidInit(void){

	DIO_u8SetPinDirection( DIO_PIN0 , DIO_PIN0_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN1 , DIO_PIN1_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN2 , DIO_PIN2_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN3 , DIO_PIN3_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN4 , DIO_PIN4_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN5 , DIO_PIN5_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN6 , DIO_PIN6_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN7 , DIO_PIN7_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN8 , DIO_PIN8_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN9 , DIO_PIN9_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN10 , DIO_PIN10_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN11 , DIO_PIN11_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN12 , DIO_PIN12_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN13 , DIO_PIN13_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN14 , DIO_PIN14_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN15 , DIO_PIN15_DIRECTION );

	DIO_u8SetPinDirection( DIO_PIN16 , DIO_PIN16_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN17 , DIO_PIN17_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN18 , DIO_PIN18_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN19 , DIO_PIN19_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN20 , DIO_PIN20_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN21 , DIO_PIN21_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN22 , DIO_PIN22_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN23 , DIO_PIN23_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN24 , DIO_PIN24_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN25 , DIO_PIN25_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN26 , DIO_PIN26_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN27 , DIO_PIN27_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN28 , DIO_PIN28_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN29 , DIO_PIN29_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN30 , DIO_PIN30_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN31 , DIO_PIN31_DIRECTION );


	DIO_u8SetPinDirection( DIO_PIN32 , DIO_PIN32_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN33 , DIO_PIN33_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN34 , DIO_PIN34_DIRECTION );

	DIO_u8SetPinDirection( DIO_PIN35 , DIO_PIN35_DIRECTION );
	DIO_u8SetPinDirection( DIO_PIN36 , DIO_PIN36_DIRECTION );

	/***************************************************************************/

	DIO_u8SetPinValue( DIO_PIN0 ,  DIO_PIN0_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN1 ,  DIO_PIN1_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN2 ,  DIO_PIN2_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN3 ,  DIO_PIN3_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN4 ,  DIO_PIN4_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN5 ,  DIO_PIN5_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN6 ,  DIO_PIN6_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN7 ,  DIO_PIN7_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN8 ,  DIO_PIN8_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN9 ,  DIO_PIN9_INIT_VAL  );
	DIO_u8SetPinValue( DIO_PIN10 , DIO_PIN10_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN11 , DIO_PIN11_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN12 , DIO_PIN12_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN13 , DIO_PIN13_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN14 , DIO_PIN14_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN15 , DIO_PIN15_INIT_VAL );

	DIO_u8SetPinValue( DIO_PIN16 , DIO_PIN16_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN17 , DIO_PIN17_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN18 , DIO_PIN18_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN19 , DIO_PIN19_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN20 , DIO_PIN20_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN21 , DIO_PIN21_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN22 , DIO_PIN22_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN23 , DIO_PIN23_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN24 , DIO_PIN24_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN25 , DIO_PIN25_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN26 , DIO_PIN26_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN27 , DIO_PIN27_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN28 , DIO_PIN28_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN29 , DIO_PIN29_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN30 , DIO_PIN30_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN31 , DIO_PIN31_INIT_VAL );

	DIO_u8SetPinValue( DIO_PIN32 , DIO_PIN32_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN33 , DIO_PIN33_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN34 , DIO_PIN34_INIT_VAL );

	DIO_u8SetPinValue( DIO_PIN35 , DIO_PIN35_INIT_VAL );
	DIO_u8SetPinValue( DIO_PIN36 , DIO_PIN36_INIT_VAL );


}

/*																					                                                             */
/*************************************************************************************************************************************************/








/*************************************************************************************************************************************************/
/* Description: Set the PINs Direction ( Input or Output )							                                                             */
/*																					                                                             */
/* Inputs:  u8PinNB      : The Number of Pin		         						                                                             */
/* 		    u8Direction  : The Direction of the chosen Pin	            			                                                             */
/* Outputs: u8Error      : Error State												                                                             */
/*																					                                                             */

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB , u8 Copy_u8Direction ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;

	Local_u8PORT_ID = Copy_u8PinNB / GPIO_NB_OF_PINS_IN_PORTA_B ;
	Local_u8Pin_ID  = Copy_u8PinNB % GPIO_NB_OF_PINS_IN_PORTA_B ;


	if( (Copy_u8PinNB >= GPIO_MAXPINNB) || ( Copy_u8Direction > OUTPUT_50_AF_OPEN_DRAIN ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {



		if( Copy_u8Direction == INPUT_PULL_UP ){


			switch (Local_u8PORT_ID){

				case LOCAL_PORTA_CHOICE:
					SET_BIT(((Register_32*) GPIO_ODRA_REG ) -> RegAccess , Local_u8Pin_ID )  ;

					break;

				case LOCAL_PORTB_CHOICE:
					SET_BIT(((Register_32*) GPIO_ODRB_REG ) -> RegAccess , Local_u8Pin_ID )  ;
					break;



				case LOCAL_PORTC_D_CHOICE:

					switch(Local_u8Pin_ID){
					case 0 ... 2 :
						SET_BIT(((Register_32*) GPIO_ODRC_REG ) -> RegAccess , (Local_u8Pin_ID+13) )  ;
						break;

					case 3 ... 4 :
						SET_BIT(((Register_32*) GPIO_ODRD_REG ) -> RegAccess , (Local_u8Pin_ID-3) )  ;
						break;

					}
			}


		}
		else if( Copy_u8Direction == INPUT_PULL_DOWN ){

			switch (Local_u8PORT_ID){
					case LOCAL_PORTA_CHOICE:
						CLR_BIT(((Register_32*) GPIO_ODRA_REG ) -> RegAccess , Local_u8Pin_ID )  ;

						break;
					case LOCAL_PORTB_CHOICE:
						CLR_BIT(((Register_32*) GPIO_ODRB_REG ) -> RegAccess , Local_u8Pin_ID )  ;
						break;



					case LOCAL_PORTC_D_CHOICE:

						switch(Local_u8Pin_ID){
						case 0 ... 2 :
							CLR_BIT(((Register_32*) GPIO_ODRC_REG ) -> RegAccess , (Local_u8Pin_ID+13) )  ;
							break;
						case 3 ... 4 :
							CLR_BIT(((Register_32*) GPIO_ODRD_REG ) -> RegAccess , (Local_u8Pin_ID-3) )  ;
							break;
						}
				}

			Copy_u8Direction = INPUT_PULL_UP ;
		}






		/* Setting the Desired Pin Direction */
		switch (Local_u8PORT_ID){


		case LOCAL_PORTA_CHOICE:

			switch(Local_u8Pin_ID){
			case 0 ... 7 :
				ASSIGN_NIBBLE( Local_u8Pin_ID , Copy_u8Direction ,  ((Register_32*) GPIO_CRLA_REG ) -> RegAccess )  ;
				break;
			case 8 ... 15:
				ASSIGN_NIBBLE( (Local_u8Pin_ID-8 ) , Copy_u8Direction ,  ((Register_32*) GPIO_CRHA_REG ) -> RegAccess )  ;
				break;
			}

			break;

		case LOCAL_PORTB_CHOICE:

			switch(Local_u8Pin_ID){
			case 0 ... 7 :
				ASSIGN_NIBBLE( Local_u8Pin_ID , Copy_u8Direction ,  ((Register_32*) GPIO_CRLB_REG ) -> RegAccess )  ;
				break;
			case 8 ... 15:
				ASSIGN_NIBBLE( (Local_u8Pin_ID-8 ) , Copy_u8Direction ,  ((Register_32*) GPIO_CRHB_REG ) -> RegAccess )  ;
				break;
			}

			break;


    	case LOCAL_PORTC_D_CHOICE:

			switch(Local_u8Pin_ID){
			case 0 ... 2 :
				ASSIGN_NIBBLE( (Local_u8Pin_ID+5 ) , Copy_u8Direction ,  ((Register_32*) GPIO_CRHC_REG ) -> RegAccess )  ;
				break;
			case 3 ... 4 :
				ASSIGN_NIBBLE( (Local_u8Pin_ID-3 ) , Copy_u8Direction ,  ((Register_32*) GPIO_CRLD_REG ) -> RegAccess )  ;
				break;
			}

			break;

		default:
			Local_u8Error = ERROR_NOK ;


		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					                                                             */
/*************************************************************************************************************************************************/








/*************************************************************************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        		                                                                             */
/*																	                                                                             */
/* Inputs:  u8PinNB      : The Number of Pin		         		                                                                             */
/* 		    u8Value      : The Value of the output on the chosen Pin                                                                             */
/* Outputs: u8Error      : Error State								                                                                             */
/*																	                                                                             */

u8 DIO_u8SetPinValue(u8 Copy_u8PinNB , u8 Copy_u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;

	if( (Copy_u8PinNB >= GPIO_MAXPINNB) || ( Copy_u8Value > GPIO_VAL_OUTPUT_HIGH ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = Copy_u8PinNB / GPIO_NB_OF_PINS_IN_PORTA_B ;
		Local_u8Pin_ID  = Copy_u8PinNB % GPIO_NB_OF_PINS_IN_PORTA_B ;


		/* Setting the Desired Pin Direction */
		switch (Local_u8PORT_ID){


		case LOCAL_PORTA_CHOICE:
			if(Copy_u8Value){
				(((Register_32*) GPIO_BSRA_REG ) -> RegAccess ) = ( 1 << Local_u8Pin_ID ) ;
			}
			else{
				(((Register_32*) GPIO_BRRA_REG ) -> RegAccess ) = ( 1 << Local_u8Pin_ID ) ;
			}

			break;

		case LOCAL_PORTB_CHOICE:
			if(Copy_u8Value){
				(((Register_32*) GPIO_BSRB_REG ) -> RegAccess ) = ( 1 << Local_u8Pin_ID ) ;
			}
			else{
				(((Register_32*) GPIO_BRRB_REG ) -> RegAccess ) = ( 1 << Local_u8Pin_ID ) ;
			}

			break;



		case LOCAL_PORTC_D_CHOICE:

			switch(Local_u8Pin_ID){
			case 0 ... 2 :
				if(Copy_u8Value){
					(((Register_32*) GPIO_BSRC_REG ) -> RegAccess ) = ( 1 << (Local_u8Pin_ID+13) ) ;
				}
				else{
					(((Register_32*) GPIO_BRRC_REG ) -> RegAccess ) = ( 1 << (Local_u8Pin_ID+13) ) ;
				}
				break;
			case 3 ... 4 :
				if(Copy_u8Value){
					(((Register_32*) GPIO_BSRD_REG ) -> RegAccess ) = ( 1 << (Local_u8Pin_ID-3) ) ;
				}
				else{
					(((Register_32*) GPIO_BRRD_REG ) -> RegAccess ) = ( 1 << (Local_u8Pin_ID-3) ) ;
				}
				break;
			}

			break;



		default:
			Local_u8Error = ERROR_NOK ;


		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					                                                             */
/*************************************************************************************************************************************************/






/*************************************************************************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        						                                                             */
/*																				                                                                 */
/* Inputs:  u8PinNB      : The Number of Pin		         						                                                             */
/* 		    *PCopy_u8Value : The Pointer to variable which will carry received val.                                                              */
/* Outputs: u8Error      : Error State												                                                             */
/*																				                                                                 */

u8 DIO_u8GetPinValue(u8 Copy_u8PinNB , u8 * PCopy_u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;

	if( (Copy_u8PinNB >= GPIO_MAXPINNB) || ( PCopy_u8Value == NULL ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = Copy_u8PinNB / GPIO_NB_OF_PINS_IN_PORTA_B ;
		Local_u8Pin_ID  = Copy_u8PinNB % GPIO_NB_OF_PINS_IN_PORTA_B ;


		/* Setting the Desired Pin Direction */
		switch (Local_u8PORT_ID){


		case LOCAL_PORTA_CHOICE:

			* PCopy_u8Value = GET_BIT( (((Register_32*) GPIO_IDRA_REG ) -> RegAccess ), Local_u8Pin_ID ) ;

			break;

		case LOCAL_PORTB_CHOICE:

			* PCopy_u8Value = GET_BIT( (((Register_32*) GPIO_IDRB_REG ) -> RegAccess ), Local_u8Pin_ID ) ;

			break;

		case LOCAL_PORTC_D_CHOICE:

			switch(Local_u8Pin_ID){

			case 0 ... 2 :

				* PCopy_u8Value = GET_BIT( (((Register_32*) GPIO_IDRC_REG ) -> RegAccess ), (Local_u8Pin_ID+13) ) ;

				break;
			case 3 ... 4 :

				* PCopy_u8Value = GET_BIT( (((Register_32*) GPIO_IDRD_REG ) -> RegAccess ), (Local_u8Pin_ID-3) ) ;

				break;
			}

			break;

		default:
			Local_u8Error = ERROR_NOK ;


		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					                                                             */
/*************************************************************************************************************************************************/










/*************************************************************************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        		                                                                             */
/*																	                                                                             */
/* Inputs:  u8PinNB      : The Number of Pin		         		                                                                             */
/* 		    u8Value      : The Value of the output on the chosen Pin                                                                             */
/* Outputs: u8Error      : Error State								                                                                             */
/*																	                                                                             */

u8 DIO_u8SetPortValue(u8 Copy_u8PortNB , u8 Copy_u8Value ) {

	u8 Local_u8Error   ;

	if( (Copy_u8PortNB >= GPIO_PORT_MAXPINNB) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		/* Setting the Desired Pin Direction */
		switch (Copy_u8PortNB){


		case LOCAL_PORTA_CHOICE:

			(((Register_32*) GPIO_ODRA_REG ) -> RegAccess ) = ( Copy_u8Value ) ;

			break;

		case LOCAL_PORTB_CHOICE:

			(((Register_32*) GPIO_ODRB_REG ) -> RegAccess ) = ( Copy_u8Value ) ;

			break;

		case LOCAL_PORTC_CHOICE:

			(((Register_32*) GPIO_ODRC_REG ) -> RegAccess ) = ( Copy_u8Value ) ;

			break;

		case LOCAL_PORTD_CHOICE:

			(((Register_32*) GPIO_ODRD_REG ) -> RegAccess ) = ( Copy_u8Value ) ;

			break;




		default:
			Local_u8Error = ERROR_NOK ;


		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					                                                             */
/*************************************************************************************************************************************************/




/*************************************************************************************************************************************************/
/* Description: Get the PINs Value in a u32 Variable ( High or Low )	                                                                         */
/*																	                                                                             */
/* Inputs:  u8PinNB      : The Number of Pin		         		                                                                             */
/* 		    u8Value      : The Value of the output on the chosen Pin                                                                             */
/* Outputs: u8Error      : Error State								                                                                             */
/*																	                                                                             */

u8 DIO_u8GetPortValue(u8 Copy_u8PortNB , u16 * PCopy_u8Value ) {

	u8 Local_u8Error   ;

	if( (Copy_u8PortNB > GPIO_MAXPINNB) || ( PCopy_u8Value == NULL ) ){
			Local_u8Error = ERROR_NOK ;
	}
	else {


		/* Setting the desired Value in required Pin */
		switch (Copy_u8PortNB){
		case LOCAL_PORTA_CHOICE:
			* PCopy_u8Value=(((Register_32*) GPIO_IDRA_REG ) -> RegAccess ) ;
			break;

		case LOCAL_PORTB_CHOICE:
			* PCopy_u8Value=(((Register_32*) GPIO_IDRB_REG ) -> RegAccess ) ;
			break;

		case LOCAL_PORTC_CHOICE:
			* PCopy_u8Value=(((Register_32*) GPIO_IDRC_REG ) -> RegAccess ) ;
			break;

		case LOCAL_PORTD_CHOICE:
			* PCopy_u8Value=(((Register_32*) GPIO_IDRD_REG ) -> RegAccess ) ;
			break;

		}



		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error;

}

/*																					                                                             */
/*************************************************************************************************************************************************/




















