typedef struct trie
{
    struct trie *next[36];
    bool exist;
}trie;


trie *trie_new_node();

trie *trie_insert(char *str);

trie *trie_find(char *str);