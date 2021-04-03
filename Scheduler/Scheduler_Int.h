/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Systick Component efficiently   */
/*																					*/
/* Created on  : Apr 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




/* File Guard *******************************/
#ifndef SCHED_INT_H_
#define SCHED_INT_H_



/********************************************************* CONFIG. SECTION ***************************************************************/
/*																																		 */

#define TICK_TIME_ms				500
#define MAX_TASKS					3

/*																																		 */
/*****************************************************************************************************************************************/





/********************************************************* FUNCTIONS SECTION *************************************************************/
/*																																		 */


/*************************************************************************************************/
/* Description: Initializes the systick time, Set the call back function, initialize used Var.	 */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vInit(void) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Starts the Scheduler 												             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vStart(void) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Creates a task, then sort the Tasks array (if needed)				             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function								 */
/* 			Copy_u8TaskTick        -> the Task comes every "Copy_u8TaskTick"					 */
/* 			Copy_u8TaskPriority    -> Task Priority (Highest Priority is 0)        				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vCreatTask( void (*Ptr2Task)(void) , u8 Copy_u8TaskTick , u8 Copy_u8TaskPriority ) ;

/*																					             */
/*************************************************************************************************/





/*																																		 */
/*****************************************************************************************************************************************/









#endif
