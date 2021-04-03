/************************************************************************************/
/* Description : This is a 'c' file to describe the Implementation of the systick	*/
/* 				 Driver																*/
/*																					*/
/* Created on  : May 25, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* Including needed files */
#include "STD_TYPE.h"

#include "Systick_Int.h"
#include "Scheduler_Int.h"






/********************************************************* PRIVATE SECTION ***************************************************************/
/*																																		 */




/**************** Task Definition ************************/
/*														 */

typedef struct {

	void (*Ptr2Fun)(void) 	;
	u8 Periodicity			;
	u8 Priority				;
	u8 Offset				;

	u8 State				;

}task_t ;

/*														 */
/*********************************************************/



/*																																		 */
/*****************************************************************************************************************************************/


/********************************************************* STATIC SECTION ****************************************************************/
/*																																		 */


static task_t Tasks[MAX_TASKS]					;
static u8 TaskCount 							;
static u8 HandlingCounter 						;
static u8 OS_FLAG								;


static void Sched_Handler(void) 				;


static void SelSort(void) 						;
static void SwapTask(u8 IndexA , u8 IndexB)     ;
static u8 SeqSearch( void (*Ptr2Task)(void) )   ;
static void Flag_Enabler( void )				;


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

void Sched_vInit(void){


	Systick_vSetTickTime( TICK_TIME_ms ) 	;

	Systick_vSetCallBack( Flag_Enabler ) 	;

	TaskCount = 0 							;

	HandlingCounter = 0 					;

	OS_FLAG = 0 							;


	for (u8 count = 0 ; count < MAX_TASKS ; count ++ ){

		Tasks[count].Ptr2Fun     = NULL  ;

		Tasks[count].Priority    = 0	 ;

		Tasks[count].Periodicity = 0 	 ;

		Tasks[count].State       = DEACTIVE_STATE 	 ;

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

	while (1){

		if ( OS_FLAG == 1 ){
			Sched_Handler() ;
			OS_FLAG = 0     ;
		}

	}

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Enables the OS_FLAG	 												             */
/*																				            	 */
/* Inputs : void 			              									    				 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

static void Flag_Enabler( void ){

	if ( OS_FLAG == 0 ){
		OS_FLAG = 1     ;
	}
	else {

		/* CPU LOAD IS FUCKED UP */

	}

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Creates a task, then sort the Tasks array (if needed)				             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function								 */
/* 			Copy_u8TaskPeriodicity -> the Task comes every "Copy_u8TaskTick"					 */
/* 			Copy_u8TaskPriority    -> Task Priority (Highest Priority = 0) - Minimum Prio. = 244 */
/*			Copy_u8TaskOffset	   -> Task Offset (In Ticks)									 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vCreatTask(  void (*Ptr2Task)(void) , u8 Copy_u8TaskPeriodicity ,
						u8 Copy_u8TaskPriority , u8 Copy_u8TaskOffset )

{

	Tasks[TaskCount].Ptr2Fun  		= Ptr2Task 	  	      		;

	Tasks[TaskCount].Periodicity    = Copy_u8TaskPeriodicity    ;

	Tasks[TaskCount].Priority 		= Copy_u8TaskPriority  	    ;

	Tasks[TaskCount].Offset   		= Copy_u8TaskOffset	 	    ;

	Tasks[TaskCount].State    		= ACTIVE_STATE 	 			;

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

		if( ( (HandlingCounter % Tasks[count].Periodicity) == 0 ) \
				&& ( Tasks[count].State == ACTIVE_STATE ) 	\
				&& ( Tasks[count].Offset == 0 )	){

			Tasks[count].Ptr2Fun() ;

		}
		else if ( ( Tasks[count].Offset > 0 ) ) {
			Tasks[count].Offset -- ;
		}

	}

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Suspends the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to suspend			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskSuspend( void (*Ptr2Task)(void) ) {

	u8 Order = SeqSearch( Ptr2Task ) ;

	Tasks[Order].State = DEACTIVE_STATE ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Resumes the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to resume			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskResume( void (*Ptr2Task)(void) ) {

	u8 Order = SeqSearch( Ptr2Task ) ;

	Tasks[Order].State = ACTIVE_STATE ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Deletes the Task	 												             */
/*																				            	 */
/* Inputs : void (*Ptr2Task)(void) -> Pointer to the task function you want to delete			 */
/* 																								 */
/* Outputs: void 																	             */
/*																					             */

void Sched_vTaskDelete( void (*Ptr2Task)(void) ) {

	u8 Order = SeqSearch( Ptr2Task ) ;

	Tasks[Order].Ptr2Fun  = NULL ;

	Tasks[Order].Priority = 255  ;

	SelSort() ;

	TaskCount -- ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Sequential Search on Tasks											             */

static u8 SeqSearch( void (*Ptr2Task)(void) ){

	u8 index = 255 ;

	if (Ptr2Task != NULL){

		for( u8 i = 0 ; i < TaskCount ; i++){

			if( Tasks[i].Ptr2Fun == Ptr2Task ){
				index = i ;
			}

		}

	}

	return index ;
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

	temp.Ptr2Fun  		= Tasks[IndexA].Ptr2Fun   		;
	temp.Priority		= Tasks[IndexA].Priority  		;
	temp.Periodicity    = Tasks[IndexA].Periodicity		;

	Tasks[IndexA].Ptr2Fun   		= Tasks[IndexB].Ptr2Fun   		;
	Tasks[IndexA].Priority  		= Tasks[IndexB].Priority  		;
	Tasks[IndexA].Periodicity		= Tasks[IndexB].Periodicity	  	;

	Tasks[IndexB].Ptr2Fun   		= temp.Ptr2Fun  		;
	Tasks[IndexB].Priority  		= temp.Priority 		;
	Tasks[IndexB].Periodicity	    = temp.Periodicity    	;

}

/*																					             */
/*************************************************************************************************/


/*																																		 */
/*****************************************************************************************************************************************/
