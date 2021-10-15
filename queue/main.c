#include "queue/queue.h"

int main(){
    t_queue queue;
    int value = -1;

    INIT_QUEUE(&queue, 20);

    while(value != 0){
        scanf("%d", &value);
        
        // if(value != 0){
            ENQUEUE(&queue, value);
            PRINT_QUEUE(queue);
        // }
    }

    top_length = queue.length;

    while (!QUEUE_EMPTY(queue)) {
        DEQUEUE(&queue);
        PRINT_QUEUE(queue);
    }

    FREE_QUEUE(&queue);
}