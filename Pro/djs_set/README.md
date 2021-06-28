# Structure -- Disjoint Set

## You should include  "stdio.h","stdlib.h",and "djs_set.h" 

## The code contains the following funtion
  
 
    disjoint_set* djs_gen(void);
    
    You should call djs_gen when you want to create a set.This function will return a pointer to you.

    disjoint_set* djs_make_set(int v,disjoint_set* q);
    
    When you call this function with input q,v, it will make a set with the key v, and return the pointer.

    disjoint_set* djs_find_set(disjoint_set* q);
    
    You can enter the set, then it will return a pointer. You could assume that given different pointer , but in the same set will return the same node.

    int djs_Union(disjoint_set* a,disjoint_set *b);   
    
    When you want to Union , then call this function with two set, then it will return 1 after two sets is unioned.If it return 0 , that means the two set are in the same set. 


