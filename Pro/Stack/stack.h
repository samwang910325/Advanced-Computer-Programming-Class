typedef struct
{
    int size;
    int* arr;
    int index;
} stack;

stack* Stack_Initial(int maxisize);

bool Stack_Is_Full(stack* s);

bool Stack_Is_Empty(stack* s);

void Stack_Push(int data , stack* t);

int Stack_Pop(stack* t);