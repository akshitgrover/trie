#include <string>

#include "_trie_iterator.h"

template <typename T>
class trie {
  public:
    using iterator = trie_iterator<T>;

    trie();
    void insert(std::string, T);
    bool exist(std::string);
    bool empty();
    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();
  private:
    tnode<T>* root;
    int size;
};

#include "trie.hpp"
