typedef struct
{
    int size;
    int head;
    int* arr;
    int end;
} queue;

queue* Queue_Initial(int maxisize);

bool Queue_Is_Full(queue* s);

bool  Queue_Is_Empty(queue* s);

int Queue_deque(queue* t);

void Queue_enque(int data,queue* t);