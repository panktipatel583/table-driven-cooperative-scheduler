#include <stdio.h>
#include "scheduler.h"


volatile UCHAR tick = 0;

int main(void)
{
    printf("Schedular Start\n");

    /* Simulate timer interrupts */
    for(int i = 0; i<20;i++)
    {
        tick++;              /*pretend ISR would do this*/
        scheduler_run();     /*main loop work*/
    }

    return 0;

}
