#include "trie.h"

int c2i(char ch)
{
    return (ch >= '0' && ch <= '9')? ch - '0': ((ch >= 'a' && ch <= 'z')? ch - 'a' + 10: ((ch >= 'A' && ch <= 'Z')? ch - 'A' + 10: -1));
}

trie *trie_new_node()
{
    trie *output = (trie *)calloc(1, sizeof(trie));
    return output;
}

trie *trie_insert(char *str)
{
    trie *cur = trie_root;
    int index;  
    for(int i = 0; str[i]; i++)
    {
        index = c2i(str[i]); 
        if(cur->next[index] == NULL)
            cur->next[index] = trie_new_node();
        cur = cur->next[index];
    }
    cur->exist = true;
    return cur;
}

trie *trie_find(char *str)
{
    trie *cur = trie_root;
    int index;
    for(int i = 0; str[i]; i++)
    {
        index = c2i(str[i]);
        if(cur->next[index] == NULL) return NULL;
        cur=cur->next[index];
    }
    if(!(cur->exist)) return NULL;
    return cur;
}