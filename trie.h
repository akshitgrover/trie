#include <string>

#include "_trie_node.h"

template <typename T>
class trie {
  public:
    trie();
    void insert(std::string, T);
  private:
    tnode<T>* root;
    int size;
};

#include "trie.hpp"
