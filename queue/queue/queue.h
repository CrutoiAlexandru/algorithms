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

void INIT_QUEUE(t_queue *Q, int INIT_SIZE);
void ENQUEUE(t_queue *Q, int value);
void PRINT_QUEUE(t_queue Q);
int  QUEUE_EMPTY(t_queue Q);
int  DEQUEUE(t_queue *Q);
void FREE_QUEUE(t_queue *Q);

#endif 