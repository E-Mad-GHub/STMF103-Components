/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the SPI1		    */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : June 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#include "STD_TYPE.h"


#include <SPI_Int.h>
#include <SPI_Priv.h>
#include <SPI_Config.h>






/**************  Static Variables ***************/



/************************************************/




/*************** Static Functions ***************/

static u8 SPIGetFlagStatus( u16 SPI_I2S_FLAG ) ;

/************************************************/





/************************************************************************************************************************************************************/
/*																																						 	*/
/*										APIs																												*/
/*																																							*/



/*************************************************************************************************/
/* Description: Initialization of SPI1 includes initializing static variables and defining the   */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void SPI1_vInit( void ) {

	u16 tmpreg = 0;

	/*---------------------------- SPIx CR1 Configuration ------------------------*/
	  /* Get the SPI1 CR1 value */
	  tmpreg = SPI1->CR1;
	  /* Clear BIDIMode, BIDIOE, RxONLY, SSM, SSI, LSBFirst, BR, MSTR, CPOL and CPHA bits */
	  tmpreg &= CR1_CLEAR_Mask;
	  /* Configure SPIx: direction, NSS management, first transmitted bit, BaudRate prescaler
	     master/salve mode, CPOL and CPHA */
	  /* Set BIDImode, BIDIOE and RxONLY bits according to SPI_Direction value */
	  /* Set SSM, SSI and MSTR bits according to SPI_Mode and SPI_NSS values */
	  /* Set LSBFirst bit according to SPI_FirstBit value */
	  /* Set BR bits according to SPI_BaudRatePrescaler value */
	  /* Set CPOL bit according to SPI_CPOL value */
	  /* Set CPHA bit according to SPI_CPHA value */
	  tmpreg |= (u16)((u32) SPI_Direction | SPI_Mode |
	                  SPI_DataSize | SPI_CPOL |
	                  SPI_CPHA | SPI_NSS |
	                  SPI_BaudRatePrescaler | SPI_FirstBit | SPI_ENABLE );
	  /* Write to SPIx CR1 */
	  SPI1->CR1 = tmpreg;

	  /* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
	  SPI1->I2SCFGR &= SPI_Mode_Select;

	/*---------------------------- SPIx CRCPOLY Configuration --------------------*/
	  /* Write to SPIx CRCPOLY */
	  SPI1->CRCPR = SPI_CRCPolynomial;

}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Receive while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : void 																		         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 SPI_u8ExchangeData_Blocking( u8 Copy_u8DataUpload , u8 * Copy_u8DataDownload ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if ( Copy_u8DataDownload == NULL){
		Local_u8ErrorState = ERROR_NOK ;
	}
	else {

		// Approach 2,
		while(!SPIGetFlagStatus( SPI_FLAG_TXE));
		SPI1->DR = Copy_u8DataUpload ;
		//while(!SPIGetFlagStatus( SPI_FLAG_RXNE));

		delay_milliSecond(1);
		*Copy_u8DataDownload = SPI1->DR; 			// read received

	}

	return Local_u8ErrorState ;

}

/*																								 */
/*************************************************************************************************/



/*																																						 	*/
/*																																							*/
/************************************************************************************************************************************************************/











/************************************************************************************************************************************************************/
/*																																						 	*/
/*										Static Functions																									*/
/*																																							*/


static u8 SPIGetFlagStatus( u16 SPI_I2S_FLAG)
{
  u8 bitstatus = 0;

  /* Check the status of the specified SPI/I2S flag */
  if ((SPI1->SR & SPI_I2S_FLAG) != (u16)0)
  {
    /* SPI_FLAG is set */
    bitstatus = 1;
  }
  else
  {
    /* SPI_FLAG is reset */
    bitstatus = 0;
  }
  /* Return the SPI_FLAG status */
  return  bitstatus;
}


/*																																						 	*/
/*																																							*/
/************************************************************************************************************************************************************/








