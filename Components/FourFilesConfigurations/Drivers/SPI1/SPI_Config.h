/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for SPI1 Component    			                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : June 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/










#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/* Setup SPI1 pins A4/SS(HW), A5/SCK, A6/MISO, A7/MOSI on portA	*/
/*	 Initialize A5/SCK alternate function push-pull				*/
/*	 Initialize A6/MISO input pull-up							*/
/*	 Initialize A7/MOSI alternate function push-pull			*/
/* 	 Initialize your SS Pin as output push-pull					*/






/* Define Initial States For SPI1 *******************************/
/*										 						*/

#define SPI_Direction 			SPI_Direction_2Lines_FullDuplex
#define SPI_Mode 				SPI_Mode_Master			             // Mode
#define SPI_DataSize 			SPI_DataSize_8b    		             // 8-bit transactions
#define SPI_FirstBit 			SPI_FirstBit_MSB    	             // MSB first
#define SPI_CPOL 				SPI_CPOL_High                        // CPOL = 1, clock idle high
#define SPI_CPHA 				SPI_CPHA_2Edge                       // CPHA = 1
#define SPI_NSS 				SPI_NSS_Soft                         // use software SS
#define SPI_BaudRatePrescaler 	SPI_BaudRatePrescaler_64             // Ex (APB2->72)/64 = 1.125 MHz OR (APB2->72)/16 = 4.5 MHz

/*																*/
/****************************************************************/














#endif
