#include <string>
#include <iterator>

#include "_trie_node.h"

template <typename T>
class trie_iterator {
  private:
    tnode<T>* root;
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = std::pair<std::string, T>;
    using pointer = value_type*;
    using reference = value_type&;

    // Constructors
    explicit trie_iterator(tnode<T>*);
};

template <typename T>
trie_iterator<T>::trie_iterator(tnode<T>* root) {
  this->root = root;
}
