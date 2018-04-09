/*===== createQueue =====*/
#include "Header.h"

int main(){
    int choice,*item;
    QUEUE* categ;
    categ  = createQueue();
    
    while(1){
        printf("\n 1.Enqueue: \n");
        printf("\n 2.Dequeue: \n");
        printf("3.Display: \n");
        printf("\n 4.Exit: \n");
        
        scanf("%i",&choice);
        
        switch (choice) {
            case 1:
                scanf("%i", item);
                enqueue(categ, item);
                break;
            case 2:
                dequeue(categ, item);
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
