/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for UART Component    			                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : May 3, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_







/* Define Initial States  ***************************************/
/*										 						*/

/* Choose from (UART_DISABLE - UART_ENABLE_RX - UART_ENABLE_TX) */
#define UART_INIT_STATE				UART_ENABLE_RX

/* Choose for example 8000000 									*/
#define UART_PROCC_FREQ_Hz			8000000

/* Choose for example 9600	 									*/
#define UART_BAUD_RATE_Hz			9600

/* Choose from (DATA_BITS_8 - DATA_BITS_9) */
#define UART_DATA_BITS				DATA_BITS_8

/* Choose from (STOP_BITS_1 - STOP_BITS_0_5 -					*/
/* 				STOP_BITS_2 - STOP_BITS_1_5) 					*/
#define UART_STOP_BITS				STOP_BITS_1

/*																*/
/****************************************************************/














#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
