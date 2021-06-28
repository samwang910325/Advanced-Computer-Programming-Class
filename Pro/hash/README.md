# Structure -- Queue

## You should include  "stdio.h","stdlib.h",and "hash_table.h"  

## The code contains the following funtion

    table* table_gen(int table_size)
    You should call table_gen while you want to create the hash table.
    
    void insert(table* t,int key,int val);
    When you want to insert an item with value val , then you can call insert to insert the item with val and key in the table t.
    
    int peek(table* t,int key);
    You can call the function when you want to get the value with key key(int::),then the function will return the val in table t.If the key can't be matched, then it will return -1.
    
