#ifndef __queue
#define __queue

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1;
#define FALSE 0;

int top_length;

typedef struct queue{
    int *data;
    int  head, tail, length;
}t_queue;

void INIT_QUEUE(t_queue *, int);
void ENQUEUE(t_queue *, int);
void PRINT_QUEUE(t_queue);
int  QUEUE_EMPTY(t_queue);
int  DEQUEUE(t_queue *);
void FREE_QUEUE(t_queue *);

#endif 