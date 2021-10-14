#include "stack.h"

void INIT_STACK(t_stack *S, int init_size){
    S->data = (int*)malloc(init_size*sizeof(int));
    S->top = 0;
}

void PUSH(t_stack *S, int value){
    S->top++;
    S->data[S->top] = value;
}

void PRINTSTACK(t_stack S){
    printf("\n");

    int i;

    printf("Valorile stivei: ");
    
    for(i = 1; i <= S.top; i++){
        printf("%d", S.data[i]);
        printf("    ");
    }

    printf("\n");
}

int STACK_EMPTY(t_stack S){
    if(S.top == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int POP(t_stack *S){
    int value;
    
    if(STACK_EMPTY(*S)){
        printf("Stiva e goala");
        
        return -1;
    }else{
        value = S->data[S->top];
        S->data[S->top] = 0;
        S->top--;
        
        return value;
    }
}

void FREE_STACK(t_stack *S){
    free(S->data);
    
    S->data = NULL;
    S->top = -1;
}
