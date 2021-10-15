#include "queue.h"

void INIT_QUEUE(t_queue *Q, int INIT_SIZE){
    Q->data   = (int*)malloc(INIT_SIZE*sizeof(int));
    Q->head   = 0;
    Q->tail   = 0;
    Q->length = 0;
}

void ENQUEUE(t_queue *Q, int value){
    Q->data[Q->tail] = value;
    Q->length++;

    if(Q->tail == Q->length){
        Q->tail = 1;
    }else{
        Q->tail++;
    }
}

void PRINT_QUEUE(t_queue Q){
    int i;

    for (i = Q.head; i <= Q.head + Q.length - 1; i++) {
        printf("%d", Q.data[i]);
    }

    printf("\n");
}

int QUEUE_EMPTY(t_queue Q){
    if(Q.head == top_length - 1){
        printf("queue empty");
        return TRUE;
    }else{
        return FALSE;
    }
}

int DEQUEUE(t_queue *Q){
    int value = Q->data[Q->head];

    Q->length--;
    
    //not sure if original ideea was correct
    //if(Q->head == Q->length){
    //    Q->head = 1;
    //}else{
        Q->head++;
    //}

    return value;
}

void FREE_QUEUE(t_queue *Q){
    free(Q->data);
    Q->data = NULL;
    Q->head = -1;
    Q->tail = -1;
}
