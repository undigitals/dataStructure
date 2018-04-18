#ifndef Queue
#define Queue

#include <stdlib.h>
#include <stdbool.h>

// defining queue
typedef struct QUEUE{
    void* buffer[10];
    int front;
    int rear;
    int cnt;
}QUEUE;

QUEUE* createQueue(){
    QUEUE* queue;
    queue=(QUEUE*)malloc(sizeof(QUEUE));
    
    if(queue){
        queue->front=0;
        queue->rear=0;
        queue->cnt=0;
    }
    return queue;
}

QUEUE destroy(QUEUE* queue){
    
}

bool enqueue(QUEUE* queue, void* data){
    
    if(queue->cnt==10){
        return false;
    }
    queue->buffer[queue->rear]=data;
    queue->rear=(queue->rear+1)%10;
    
    (queue->cnt)++;
    return true;
}

bool dequeue(QUEUE* queue, void** data){
    if(queue->cnt==0){
        return false;
    }
    *data=queue->buffer[queue->front];
    queue->front=(queue->front+1)%10;
    
    (queue->cnt)--;
    return true;
}

#endif
