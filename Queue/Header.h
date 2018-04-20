#ifndef Queue
#define Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining queue
typedef struct QUEUE {
    void* buffer[10];
    int front;
    int rear;
    int cnt;
}QUEUE;

QUEUE* createQueue() {
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    
    if (queue) {
        queue->front = -1;
        queue->rear = -1;
        queue->cnt = 0;
    }
    return queue;
}

// function prototypes
bool enqueue(QUEUE* queue, void* data);
bool dequeue(QUEUE* queue, void** data);
bool isEmpty(QUEUE* queue);
bool isFull(QUEUE* queue);
bool peekRear(QUEUE* queue, void** data);
bool peekFront(QUEUE* queue, void** data);


bool enqueue(QUEUE* queue, void* data) {
    
    if (queue->cnt == 10) {
        return false;
    }
    queue->buffer[queue->rear] = data;
    queue->rear = (queue->rear + 1) % 10;
    
    (queue->cnt)++;
    return true;
}

bool dequeue(QUEUE* queue, void** data) {
    if (isEmpty(queue)) {
        return false;
    }
    printf("%i", queue->front);
    *data = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % 10;
    
    (queue->cnt)--;
    return true;
}

// is empty
bool isEmpty(QUEUE* queue) {
    return queue->cnt == 0;
}

// is full
bool isFull(QUEUE* queue) {
    return queue->cnt == 10;
}

// peekRear
bool peekRear(QUEUE* queue, void** data) {
    if (isEmpty(queue)) {
        return false;
    }
    *data = queue->buffer[queue->rear-1];
    
    return true;
}

// frontRear
bool peekFront(QUEUE* queue, void** data) {
    if (isEmpty(queue)) {
        return false;
    }
    *data = queue->buffer[queue->front];
    
    return true;
}


#endif

