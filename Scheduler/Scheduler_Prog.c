/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the systick	*/
/* 				 Driver																*/
/*																					*/
/* Created on  : Apr 22, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "../GPIO_Example/STD_TYPE.h"
#include "Systick_Int.h"
#include "Scheduler_Int.h"






/********************************************************* PRIVATE SECTION ***************************************************************/
/*																																		 */




/**************** Task Definition ************************/
/*														 */

typedef struct {

	void (*Ptr2Fun)(void) 	;
	u8 Ticks 				;
	u8 Priority				;

}task_t ;

/*														 */
/*********************************************************/



/*																																		 */
/*****************************************************************************************************************************************/





static task_t Tasks[MAX_TASKS];
static u8 TaskCount ;
static u8 HandlingCounter ;


static void Sched_Handler(void) ;


static void SelSort(void) ;
static void SwapTask(u8 IndexA , u8 IndexB) ;





/********************************************************* FUNCTIONS SECTION *************************************************************/
/*																																		 */


/*************************************************************************************************/
/* Description: Initializes the systick time, Set the call back function, initialize used Var.	 */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vInit(void){


	Systick_vSetTickTime( TICK_TIME_ms ) ;

	Systick_vSetCallBack( Sched_Handler ) ;

	TaskCount = 0 ;

	HandlingCounter = 0 ;

	for (u8 count = 0 ; count < MAX_TASKS ; count ++ ){

		Tasks[count].Ptr2Fun  = NULL ;

		Tasks[count].Priority = 0	 ;

		Tasks[count].Ticks    = 0 	 ;

	}

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Starts the Scheduler 												             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vStart(void) {

	Systick_vEnable() ;

}

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

void Sched_vCreatTask( void (*Ptr2Task)(void) , u8 Copy_u8TaskTick , u8 Copy_u8TaskPriority ) {

	Tasks[TaskCount].Ptr2Fun  = Ptr2Task 	  	      ;

	Tasks[TaskCount].Ticks    = Copy_u8TaskTick       ;

	Tasks[TaskCount].Priority = Copy_u8TaskPriority   ;

	TaskCount ++ ;

	if (TaskCount > 1){
		SelSort();
	}


}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Scheduler Handler													             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

static void Sched_Handler(void){


	HandlingCounter ++ ;

	for (u8 count = 0 ; count < TaskCount ; count ++ ){

		if( (HandlingCounter % Tasks[count].Ticks) == 0){
			Tasks[count].Ptr2Fun() ;
		}

	}

}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Select Sort on Tasks												             */

static void SelSort(void){
	u8 temp ;


	for( u8 i = 0 ; i < TaskCount-1 ; i++){

		temp = i ;

		for (u8 j = i+1 ; j < TaskCount ; j++){

			if (Tasks[temp].Priority > Tasks[j].Priority){

				temp = j ;

			}

		}

		SwapTask( i , temp ) ;

	}

}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Swapping two Tasks													             */

static void SwapTask(u8 IndexA , u8 IndexB){

	task_t temp ;

	temp.Ptr2Fun  = Tasks[IndexA].Ptr2Fun   ;
	temp.Priority = Tasks[IndexA].Priority  ;
	temp.Ticks    = Tasks[IndexA].Ticks		;

	Tasks[IndexA].Ptr2Fun   = Tasks[IndexB].Ptr2Fun   ;
	Tasks[IndexA].Priority  = Tasks[IndexB].Priority  ;
	Tasks[IndexA].Ticks		= Tasks[IndexB].Ticks	  ;

	Tasks[IndexB].Ptr2Fun   = temp.Ptr2Fun  ;
	Tasks[IndexB].Priority  = temp.Priority ;
	Tasks[IndexB].Ticks	    = temp.Ticks    ;

}

/*																					             */
/*************************************************************************************************/


/*																																		 */
/*****************************************************************************************************************************************/
