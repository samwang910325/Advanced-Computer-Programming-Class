typedef struct  tree
{
    int val;
    struct tree* ri;
    struct tree* lf;
} tree;

tree* gen_node(int key);

void right_insert(tree* p,tree* rt);

void left_insert(tree* p,tree* lf);

int peek_key(tree* t);