/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the SPI1 Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : June 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/



/*  File Guard  			*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_




/******* Configurations Dependencies ************************/
/*									        				*/

/* SPI Direction ***************************************/

#define SPI_Direction_2Lines_FullDuplex ((u16)0x0000)
#define SPI_Direction_2Lines_RxOnly     ((u16)0x0400)
#define SPI_Direction_1Line_Rx          ((u16)0x8000)
#define SPI_Direction_1Line_Tx          ((u16)0xC000)

/*******************************************************/

/* SPI Mode ********************************************/

#define SPI_Mode_Master                 ((u16)0x0104)
#define SPI_Mode_Slave                  ((u16)0x0000)

/*******************************************************/

/* SPI Data Size ***************************************/

#define SPI_DataSize_16b                ((u16)0x0800)
#define SPI_DataSize_8b                 ((u16)0x0000)

/*******************************************************/

/* SPI First Bit ***************************************/

#define SPI_FirstBit_MSB                ((u16)0x0000)
#define SPI_FirstBit_LSB                ((u16)0x0080)

/*******************************************************/

/* SPI Clk Pol. ****************************************/

#define SPI_CPOL_Low                    ((u16)0x0000)
#define SPI_CPOL_High                   ((u16)0x0002)

/*******************************************************/

/* SPI Clk Phase ***************************************/

#define SPI_CPHA_1Edge                  ((u16)0x0000)
#define SPI_CPHA_2Edge                  ((u16)0x0001)

/*******************************************************/

/* SPI SSel Type ***************************************/

#define SPI_NSS_Soft                    ((u16)0x0200)
#define SPI_NSS_Hard                    ((u16)0x0000)

/*******************************************************/

/* SPI PreScaler ***************************************/

#define SPI_BaudRatePrescaler_2         ((u16)0x0000)
#define SPI_BaudRatePrescaler_4         ((u16)0x0008)
#define SPI_BaudRatePrescaler_8         ((u16)0x0010)
#define SPI_BaudRatePrescaler_16        ((u16)0x0018)
#define SPI_BaudRatePrescaler_32        ((u16)0x0020)
#define SPI_BaudRatePrescaler_64        ((u16)0x0028)
#define SPI_BaudRatePrescaler_128       ((u16)0x0030)
#define SPI_BaudRatePrescaler_256       ((u16)0x0038)

/*******************************************************/

/*									       				    */
/************************************************************/



/*************************************************************************************************/
/* Description: Initialization of SPI1 includes initializing static variables and defining the   */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void SPI1_vInit( void ) ;

/*																					             */
/*************************************************************************************************/

/*************************************************************************************************/
/* Description: Receive while blocking the processor 			 					             */
/*																				            	 */
/* Inputs : void 																		         */
/*																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 SPI_u8ExchangeData_Blocking( u8 Copy_u8DataUpload , u8 * Copy_u8DataDownload ) ;

/*																					             */
/*************************************************************************************************/






#endif
