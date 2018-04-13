//
//  Header.h
//  Queue
//
//  Created by Umid Negmatullayev on 4/13/18.
//  Copyright © 2018 Umid Negmatullayev. All rights reserved.
//
#ifndef Header_h
#define Header_h
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


// declaring the QUEUE_NODE
typedef struct NODE{
    void* data;
    struct NODE* next;
}NODE;

// declaring the QUEUE
typedef struct {
    NODE* front;
    NODE* rear;
    int cnt;
}QUEUE;

// initializing the QUEUE
QUEUE* creatingQueue(){
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    
    if(queue){
        queue->front=NULL;
        queue->rear = NULL;
        queue->cnt=0;
    }
    return queue;
}

// function prototypes
bool isEmpty(QUEUE*);
bool dequeue(QUEUE* queue, void** dataPtr);
bool enqueue(QUEUE* queue, void* data);
bool isEmpty(QUEUE* queue);


// enqueueu
bool enqueue(QUEUE* queue, void* data){
    NODE* node;
    
    // allocating storage for node
    node = (NODE*)malloc(sizeof(NODE));
    
    // checking if node created in the heap
    if(!node){
        return false;
    }
    
    // assigning usr data to node data
    node->data=data;
    node->next=NULL;
    
    // if queue is empty we assign both front and rear to the node
    if(queue->cnt==0)
        queue->front=node;
    
    // if queue is not empty we just assign rear->next to node
    else
        queue->rear->next=node;
    
    
    // in any case we need to upgade count and we shift rear to next node
    (queue->cnt)++;
    queue->rear=node;
    return true;
}

bool dequeue(QUEUE* queue, void** dataPtr){
    NODE* temp=NULL;
    
    if(!isEmpty(queue)){
        *dataPtr = queue->front->data;
        temp = queue->front;
    }else{
        return false;
    }
    if(queue->cnt==1){
        queue->rear=queue->front=NULL;
    }else{
        queue->front=queue->front->next;
    }
    
    (queue->cnt)--;
    free(temp);
    
    return true;
}


bool isEmpty(QUEUE* queue){
    if(queue->cnt==0)
        return true;
    return false;
}







#endif /* Header_h */

