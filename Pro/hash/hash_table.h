typedef struct n
{
    int val;
    int key;
    struct n* next;
} node; 

typedef struct
{
    int size;
    node **arr;
} table; 
table* table_gen(int table_size);

void insert(table* t,int key,int val);

int peek(table* t,int key);