/*===== createQueue =====*/
#include "Header.h"

void display(QUEUE* queue);

int main() {
    int choice, item;
    int *data;
    QUEUE* categ;
    categ = createQueue();
    
    while (1) {
        printf("\n 1.Enqueue: \n");
        printf("\n 2.Dequeue: \n");
        printf("\n 3.peekRear: \n");
        printf("\n 4.peekFront: \n");
        printf("\n 5.Display: \n");
        printf("\n 6.Exit: \n");
        
        scanf_s("\n%i", &choice);
        
        switch (choice) {
            case 1:
                scanf_s("%i", &item);
                
                data = (int*)malloc(sizeof(int));
                *data = item;
                
                enqueue(categ, data);
                break;
            case 2:
                dequeue(categ, (void*)&item);
                break;
            case 3:
                peekRear(categ, (void*)&data);
                printf("%i\n", *data);
                break;
            case 4:
                peekFront(categ, (void*)&data);
                printf("%i\n", *data);
                break;
            case 5:
                display(categ);
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
        }
    }
    
    return 0;
}

void display(QUEUE* queue) {
    int* dataPtr;
    
    while (!isEmpty(queue)) {
        dequeue(queue, (void*)&dataPtr);
        printf("%i\t", *dataPtr);
    }
}

