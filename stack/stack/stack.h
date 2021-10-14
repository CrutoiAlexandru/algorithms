#include <stdio.h>
#include <stdlib.h>

#ifndef __stack
#define __stack

#define TRUE  1;
#define FALSE 0;

typedef struct stack{
    int top;
    int *data;
}t_stack;

void INIT_STACK(t_stack *, int);
void PUSH(t_stack *, int);
void PRINTSTACK(t_stack);
int  STACK_EMPTY(t_stack);
int  POP(t_stack *);
void FREE_STACK(t_stack *);

#endif 