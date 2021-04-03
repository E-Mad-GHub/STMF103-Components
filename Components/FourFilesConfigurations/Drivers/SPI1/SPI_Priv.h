/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the SPI1 Component 		        */
/* 				 This Driver Supports STM32F103                                     */
/*																					*/
/* Created on  : June 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/



/* File Guard  			*/
#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_




/****** Defining the Peripheral Struct ******/
/*                                          */

typedef struct {

	  u16 CR1;
	  u16 RESERVED0;
	  u16 CR2;
	  u16 RESERVED1;
	  u16 SR;
	  u16 RESERVED2;
	  u16 DR;
	  u16 RESERVED3;
	  u16 CRCPR;
	  u16 RESERVED4;
	  u16 RXCRCR;
	  u16 RESERVED5;
	  u16 TXCRCR;
	  u16 RESERVED6;
	  u16 I2SCFGR;
	  u16 RESERVED7;
	  u16 I2SPR;
	  u16 RESERVED8;

}SPIx;

/*                                          */
/********************************************/





/********* Hardware Dependencies ****************************/
/*									        				*/

/* Defining Register ADDRESS   		        				*/
#define PERIPH_BASE           ((u32)0x40000000)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)


/* Assigning Registers ADDRESSes  	        				*/
SPIx * SPI1 =  (SPIx *) SPI1_BASE ;

/* Assigning Hardware Aspects   	        				*/
#define SPI_CRCPolynomial  	 7


/* Defining Masks *******************************************/
/* SPI SPE mask */
#define CR1_SPE_Set          ((u16)0x0040)
#define CR1_SPE_Reset        ((u16)0xFFBF)

/* I2S I2SE mask */
#define I2SCFGR_I2SE_Set     ((u16)0x0400)
#define I2SCFGR_I2SE_Reset   ((u16)0xFBFF)

/* SPI CRCNext mask */
#define CR1_CRCNext_Set      ((u16)0x1000)

/* SPI CRCEN mask */
#define CR1_CRCEN_Set        ((u16)0x2000)
#define CR1_CRCEN_Reset      ((u16)0xDFFF)

/* SPI SSOE mask */
#define CR2_SSOE_Set         ((u16)0x0004)
#define CR2_SSOE_Reset       ((u16)0xFFFB)

/* SPI registers Masks */
#define CR1_CLEAR_Mask       ((u16)0x3040)
#define I2SCFGR_CLEAR_Mask   ((u16)0xF040)

/* SPI or I2S mode selection masks */
#define SPI_Mode_Select      ((u16)0xF7FF)


/* I2S clock source selection masks */
#define I2S2_CLOCK_SRC       ((u16)(0x00020000))
#define I2S3_CLOCK_SRC       ((u16)(0x00040000))
#define I2S_MUL_MASK         ((u16)(0x0000F000))
#define I2S_DIV_MASK         ((u16)(0x000000F0))

/* Defining Flags *******************************************/
#define SPI_FLAG_RXNE        ((u32)0x0001)
#define SPI_FLAG_TXE         ((u32)0x0002)
#define I2S_FLAG_CHSIDE      ((u32)0x0004)
#define I2S_FLAG_UDR         ((u32)0x0008)
#define SPI_FLAG_CRCERR      ((u32)0x0010)
#define SPI_FLAG_MODF        ((u32)0x0020)
#define SPI_FLAG_OVR         ((u32)0x0040)
#define SPI_FLAG_BSY         ((u32)0x0080)
#define SPI_ENABLE			 ((u32)0x0040)

/*									        			 	*/
/************************************************************/







#endif /* EXTINT_COMPONENT_EXTINT_PRIV_H_ */
