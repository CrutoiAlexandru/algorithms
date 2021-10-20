#ifndef __stack
#define __stack

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1;
#define FALSE 0;

typedef struct stack{
    int top;
    int *data;
}t_stack;

void INIT_STACK(t_stack *S, int init_size);
void PUSH(t_stack *S, int value);
void PRINTSTACK(t_stack S);
int  STACK_EMPTY(t_stack S);
int  POP(t_stack *S);
void FREE_STACK(t_stack *S);

#endif 