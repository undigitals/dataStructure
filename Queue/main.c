/*===== createQueue =====*/
#include "Header.h"

void display(QUEUE* queue);

int main(){
    int choice,item;
    int *data;
    QUEUE* categ;
    categ  = creatingQueue();
    
    while(1){
        printf("\n 1.Enqueue: \n");
        printf("\n 2.Dequeue: \n");
        printf("\n 3.Display: \n");
        printf("\n 4.Exit: \n");
        
        scanf("\n%i",&choice);
        
        switch (choice) {
            case 1:
                scanf("%i", &item);
                data = (int*)malloc(sizeof(int));
                *data = item;
                enqueue(categ, data);
                break;
            case 2:
                dequeue(categ, (void*)&item);
                break;
            case 3:
                display(categ);
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }
    
    return 0;
}

void display(QUEUE* queue){
    static int* dataPtr;
    
    while(!isEmpty(queue)){
        dequeue(queue, (void*)&dataPtr);
        printf("%i\t",*dataPtr);
    }
}
