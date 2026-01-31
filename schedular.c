
#include "scheduler.h"
#include<stdio.h>


static void taskA(int id)
{
    printf("Task A running, id = %d\n", id);
}

static void taskB(int id)
{
    printf("Task B runnig, id = %d \n", id);
}

//static const array of structures
static const TIMED_TASK timed_task[] =
{
    { 2, taskA, 1}, /* every 2 ticks*/
    { 5, taskB, 2}, /*every 5 ticks*/
    { 0,NULL,0}        /*sentinel*/
};



void scheduler_run(void)
{
    static UCHAR time = 0;
    const TIMED_TASK *t;

    if(tick==0)
        return;

    tick--;
    time++;

    for(t = timed_task; t->interval != 0; t++)
    {
        if((time % t->interval) == 0)
        {
            t->task(t->id);
        }
    }

}
