#include "tree.h"

tree* gen_node(int key)
{
    tree* new = (tree*) calloc (1 , sizeof(tree) );
    new->val = key; 
    
    return new ; 
}

void right_insert(tree* p,tree* rt)
{
    p->ri=rt;
    return ;
} 

void left_insert(tree* p,tree* lf)
{

    p->lf=lf;
    return ;
}

int peek_key(tree* t)
{
    return t->val;
}