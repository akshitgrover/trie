#include "_trie_node.h"

template <typename T>
class trie {
    public:
        trie();
    
    private:
        tnode<T>* root;
        int size;
};

#include "trie.hpp"