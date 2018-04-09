/* ADT for Queue*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void* dataPtr;
    struct node* next;
}QUEUE_NODE;

typedef struct {
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
    int count;
}QUEUE;

// Prototype declarations
QUEUE* createQueue (void);
QUEUE* destroyQueue (QUEUE* queue);

bool dequeue (QUEUE* queue, void** itemPtr);
bool enqueue (QUEUE* queue, void* itemPtr);
int queueCount (QUEUE* queue);

bool emptyQueue (QUEUE* queue);


void display(QUEUE* queue);
// End of Queue ADT Definitions


/* ===== createQueue =====*/

QUEUE* createQueue(void){
    // Local Definitions
    QUEUE* queue;
    
    // Statements
    queue = (QUEUE*) malloc (sizeof(QUEUE));
    if(queue){
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    } // if
    return queue;
} // createQueue

/*===== enqueue =====*/
bool enqueue(QUEUE* queue, void* itemPtr){
    // Local Definitions
    QUEUE_NODE* newPtr;
    
    // Statements
    if(!(newPtr = (QUEUE_NODE*) malloc (sizeof(QUEUE_NODE)))){
        return false;
    }
    
    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;
    
    if(queue->count == 0){
        // Inserting into null queue
        queue->front = newPtr;
    }else{
        queue->rear->next = newPtr;
    }
    
    (queue->count)++;
    queue->rear = newPtr;
    return true;
} // enqueue


/* ===== dequeue =====*/
bool dequeue (QUEUE* queue, void** itemPtr){
    // Local Definitions
    QUEUE_NODE* deleteLoc;
    
    // Statements
    if(!queue->count){
        return false;
    }
    *itemPtr = queue->front->dataPtr;
    deleteLoc = queue->front;
    if(queue->count==1){
        // Deleting only item in queue
        queue->rear = queue->front = NULL;
    }else{
        queue->front= queue->front->next;
    }
    (queue->count)--;
    free(deleteLoc);
    
    return true;
} // dequeue


/*===== emptyQueue =====*/
bool emptyQueue(QUEUE* queue){
    // Statements
    return (queue->count==0);
} // emptyQueue


/*===== display =====*/
void display(QUEUE* queue){
    QUEUE_NODE* temp;
    if(emptyQueue(queue)){
        printf("Nothing to display!!");
    }
    temp=queue->front;
    int sum =(int)temp->dataPtr;
    while(temp!=NULL){
        printf("%i \t", sum);
        temp=temp->next;
    }
    
}










