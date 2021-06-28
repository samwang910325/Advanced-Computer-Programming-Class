#include "hash_table.h"

table* table_gen(int table_size)
{
    table* n = (table*) calloc( 1, sizeof(table));
    n->size = table_size;
    n->arr  = (node**) calloc(n->size , sizeof(node* ));
    return n;
}

void insert(table* t,int key,int val)
{
    int hash_value= key % t->size ; 
    node* start=t->arr[hash_value];
    node* current=start ;
    while(current->next != NULL )
    {
        current = current->next; 
    }
    node* new = (node*) calloc(1,sizeof(node));
    current->next = new;
    new->val=val;
    new->key=key;
    return  ;
}

int peek(table* t,int key)
{
    int hash_value= key % t->size ; 
    node* start=t->arr[hash_value];
    node* current=start ;
    while(current != NULL )
    {
        if(current->key==key) break;
        current = current->next; 
    }
    if(current==NULL) return -1;
    else              return current->val;
}
