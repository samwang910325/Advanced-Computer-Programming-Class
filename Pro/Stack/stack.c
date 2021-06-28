#include  "stack.h"

stack* Stack_Initial(int maxisize)
{
    stack *new = (stack*) malloc(sizeof(stack));
    new->size = maxisize ;
    new->arr = (int*) calloc (maxisize , sizeof(int));
    new->index = 0;
    return new;  
}

bool Stack_Is_Full(stack* s)
{
    if( s->size >= s->index )
        return false;
    return true;
}

bool Stack_Is_Empty(stack* s)
{
    if( s->index > 0 ) 
        return false;
    return true;
}

void Stack_Push(int data , stack* t)
{
    if(Stack_Is_Full(t))   return;
    t->arr[ t->index ] = data;
    (t->index)++;
}

int Stack_Pop(stack* t)
{
    if(Stack_Is_Empty(t))  return -1;
    --(t->index) ;
    return t->arr[ t->index ];
} 

