/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Systick Component efficiently   */
/*																					*/
/* Created on  : May 25, 2019 														*/
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


/********************************************************* DEFINE SECTION ****************************************************************/
/*																																		 */

#define ACTIVE_STATE				1
#define DEACTIVE_STATE				0

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
/* 			Copy_u8TaskPriority    -> Task Priority (Highest Priority = 0) - Minimum Prio. = 244 */
/*			Copy_u8TaskOffset	   -> Task Offset (In Ticks)									 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vCreatTask(  void (*Ptr2Task)(void) , u8 Copy_u8TaskTick ,
						u8 Copy_u8TaskPriority , u8 Copy_u8TaskOffset ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Suspends the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to suspend			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskSuspend( void (*Ptr2Task)(void) ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Resumes the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to resume			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskResume( void (*Ptr2Task)(void) ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Deletes the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to delete			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskDelete( void (*Ptr2Task)(void) ) ;

/*																					             */
/*************************************************************************************************/





/*																																		 */
/*****************************************************************************************************************************************/









#endif
