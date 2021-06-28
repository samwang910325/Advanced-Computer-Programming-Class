
#include "disjoint_set.h"

disjoint_set* djs_gen(int range)
{
    disjoint_set* new = (disjoint_set*) malloc(sizeof(disjoint_set));
    
    new->size = 1;
    new->key = 0;
    new->p = &new;
    return new ;
}

disjoint_set* djs_make_set(disjoint_set* q)
{
    q->size = 1;
    q->key = 0;
    q->p = q;
    return q ;
}

disjoint_set* djs_find_set(disjoint_set* q)
{
    if(q->p    ==   q) return q->p;
    q->p = djs_find_set(q->p);
    return q->p ;
}

int djs_Union(disjoint_set* a,disjoint_set *b) 
{
    disjoint_set* h0 = djs_find_set(a);
    disjoint_set* h1 = djs_find_set(b);
    if( h1 == h0) return 0 ; 
    if( h0->size > h1->size ) 
    {
        h0->size += h1->size;
        h1->p = h0 ;
    }
    else   
    {
        h1->size += h0->size;
        h0->p = h1 ;
    }
    return 1 ;
}
