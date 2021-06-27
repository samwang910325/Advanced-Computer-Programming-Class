# Structure -- Queue

## You should include "stdbool.h","stdio.h","stdlib.h",and "queue.h"  

## The code contains the following funtion

    queue* Queue_Initial(int maxisize);
    You should call Queue_Initial when you want to create the queue.Your input should be the " maximum operation " you would do. Then this function will return a pointer to you.
    
    
    
    bool Queue_Is_Full(queue* s);
    You can use this function to check if the queue is full.If it returns true,that means the queue is filled with data.
    
    
    
    bool  Queue_Is_Empty(queue* s);
    You can use this function to check if the queue is empty.If it returns true,that means the queue has nothing.



    int Queue_deque(queue* t);
    You can use this function to pop the item.



    void Queue_enque(int data,queue* t);
    You can use this item to push a data with integer type. 
