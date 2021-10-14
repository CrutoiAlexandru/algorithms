#include "stack/stack.h"

int main(){
    t_stack stack;
    int value = -1;

    INIT_STACK(&stack, 20);

    while(value != 0){
        printf("\n");  
        printf("Introduceti valoarea: ");   scanf("%d", &value);

        PUSH(&stack, value);
        PRINTSTACK(stack);
    }

    while(!STACK_EMPTY(stack)){
        POP(&stack);
        PRINTSTACK(stack);
    }

    POP(&stack);

    FREE_STACK(&stack);
}