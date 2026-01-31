#ifndef SCHEDULAR_H
#define SCHEDULAR_H

typedef unsigned char UCHAR;

extern volatile UCHAR tick;

typedef void (*TASK_FN)(int);

typedef struct{
        UCHAR interval;
        TASK_FN task;
        int id;
}TIMED_TASK;


void scheduler_run(void);

#endif // SCHEDULAR_H
