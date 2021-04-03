/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons                                                                */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Feb 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef ARM_DIO_CONF_H_
#define ARM_DIO_CONF_H_




/****** Defining the Pin Direction *******************************************/
/*										                                     */
/* Range : 	INPUT_ANALOG	          OUTPUT_10_PUSH_PULL                    */
/* 		   	INPUT_FLOATING	          OUTPUT_10_OPEN_DRAIN   	             */
/*          INPUT_PULL_UP		      OUTPUT_10_AF_PUSH_PULL 	             */
/*          INPUT_PULL_DOWN           OUTPUT_10_AF_OPEN_DRAIN	             */
/* 				 															 */
/* 			OUTPUT_2_PUSH_PULL        OUTPUT_50_PUSH_PULL    				 */
/*          OUTPUT_2_OPEN_DRAIN       OUTPUT_50_OPEN_DRAIN   				 */
/*          OUTPUT_2_AF_PUSH_PULL     OUTPUT_50_AF_PUSH_PULL  				 */
/*          OUTPUT_2_AF_OPEN_DRAIN    OUTPUT_50_AF_OPEN_DRAIN				 */
/*																			 */

/* GPIO A																	 */
#define      DIO_PIN0_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN1_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN2_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN3_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN4_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN5_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN6_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN7_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN8_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN9_DIRECTION        OUTPUT_2_PUSH_PULL
#define      DIO_PIN10_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN11_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN12_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN13_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN14_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN15_DIRECTION       OUTPUT_2_PUSH_PULL

/* GPIO B																	 */
#define      DIO_PIN16_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN17_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN18_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN19_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN20_DIRECTION       INPUT_PULL_UP
#define      DIO_PIN21_DIRECTION       INPUT_PULL_UP
#define      DIO_PIN22_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN23_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN24_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN25_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN26_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN27_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN28_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN29_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN30_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN31_DIRECTION       OUTPUT_2_PUSH_PULL

/* GPIO C																	 */
#define      DIO_PIN32_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN33_DIRECTION       INPUT_PULL_DOWN
#define      DIO_PIN34_DIRECTION       INPUT_PULL_DOWN

/* GPIO D																	 */
#define      DIO_PIN35_DIRECTION       OUTPUT_2_PUSH_PULL
#define      DIO_PIN36_DIRECTION       OUTPUT_2_PUSH_PULL

/*																			 */
/*****************************************************************************/



/********* Defining the Pin Value ********************************************/
/*																			 */
/* Range : 	GPIO_VAL_INPUT_PUP       GPIO_VAL_OUTPUT_HIGH                    */
/* 		   	GPIO_VAL_INPUT_PDOWN     GPIO_VAL_OUTPUT_LOW                     */


/* GPIO A																	 */
#define      DIO_PIN0_INIT_VAL        GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN1_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN2_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN3_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN4_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN5_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN6_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN7_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN8_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN9_INIT_VAL        GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN10_INIT_VAL       GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN11_INIT_VAL       GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN12_INIT_VAL       GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN13_INIT_VAL       GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN14_INIT_VAL       GPIO_VAL_OUTPUT_LOW
#define      DIO_PIN15_INIT_VAL       GPIO_VAL_OUTPUT_LOW

/* GPIO B																	 */
#define      DIO_PIN16_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN17_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN18_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN19_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN20_INIT_VAL       GPIO_VAL_INPUT_PUP
#define      DIO_PIN21_INIT_VAL       GPIO_VAL_INPUT_PUP
#define      DIO_PIN22_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN23_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN24_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN25_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN26_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN27_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN28_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN29_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN30_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN31_INIT_VAL       GPIO_VAL_OUTPUT_HIGH

/* GPIO C																	 */
#define      DIO_PIN32_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN33_INIT_VAL       GPIO_VAL_INPUT_PDOWN
#define      DIO_PIN34_INIT_VAL       GPIO_VAL_INPUT_PDOWN

/* GPIO D																	 */
#define      DIO_PIN35_INIT_VAL       GPIO_VAL_OUTPUT_HIGH
#define      DIO_PIN36_INIT_VAL       GPIO_VAL_OUTPUT_HIGH

/*																			 */
/*****************************************************************************/






#endif /* ARM_DIO_CONF_H_ */
