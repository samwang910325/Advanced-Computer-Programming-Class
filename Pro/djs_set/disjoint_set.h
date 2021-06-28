typedef struct disjoint_set
{
    int size;
    int key ;
    struct disjoint_set_node *p;
    
}disjoint_set;

disjoint_set* djs_gen(int range);

disjoint_set* djs_make_set(disjoint_set* q);

disjoint_set* djs_find_set(disjoint_set* q);

int djs_Union(disjoint_set* a,disjoint_set *b);   