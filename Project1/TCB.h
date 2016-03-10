

/* Author1 name: Nitin Pasumarthy
   ID :1207666508
   email ID: npasumar@asu.edu 
 
   Author2 name: Tanushree Chakravorty
   ID :1207664935
   email ID: tkchakra@asu.edu 

   Author3 name: Alekhya Cheruvu
   ID :1209209296
   email ID: acheruvu@asu.edu */


/* contains the functions necessary for allocating TCB to thread */

#include <ucontext.h>
#include <stdio.h>
#include <string.h>

typedef struct _TCB_t {    /*structure which contains the next and prev pointers of the nodes */
	ucontext_t context;
	struct _TCB_t *prev;
	struct _TCB_t *next;
} TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)  
{
	memset(tcb, '\0', sizeof(TCB_t));
	getcontext(&tcb->context);          /* intializing the TCB of the thread and giving the runner function */
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	makecontext(&tcb->context, function, 0);


}
