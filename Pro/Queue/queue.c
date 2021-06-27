#include<queue.h>

queue* Queue_Initial(int maxisize)
{
    queue *new = (queue*) malloc(sizeof(queue));
    new->head = 0 ;
    new->size = maxisize;
    new->arr = (int*) calloc (maxisize , sizeof(int));
    new->end = 0;
    return new;  
}

bool Queue_Is_Full(queue* s)
{
    if(s->end > s->size)  return true;
    return false;
}

bool  Queue_Is_Empty(queue* s)
{
    if( s->end == s->head ) 
        return true;
    return false ;
}

int Queue_deque(queue* t)
{
    if(Stack_Is_Empty(t))   return 0;
    (t->head) ++;
    return t->arr[ t->head-1 ] ; 
}

void Queue_enque(int data,queue* t)
{
    if(Stack_Is_Full(t))  return    ;
    t->arr[t->head] = data;
    (t->head) ++;
    return  ;
}
