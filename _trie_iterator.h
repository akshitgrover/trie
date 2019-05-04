#include <string>
#include <iterator>
#include <iostream>

#include "_trie_node.h"
#include "_trie_util.h"

template <typename T>
class trie_iterator {
  private:
    tnode<T>* cur_node;
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = std::pair<std::string, T>;
    using pointer = value_type*;
    using reference = value_type&;

    // Constructors
    explicit trie_iterator(tnode<T>*);

    // Operators
    trie_iterator<T>& operator++ ();
    trie_iterator<T> operator++ (int);
};

template <typename T>
trie_iterator<T>::trie_iterator(tnode<T>* root) {
  this->cur_node = root;
}

template <typename T>
trie_iterator<T>& trie_iterator<T>::operator++ () {
  if (this->cur_node == nullptr) {
    return *this;
  }
  this->cur_node = recur(this->cur_node);
  return *this;
}

template <typename T>
trie_iterator<T> trie_iterator<T>::operator++ (int) {
  trie_iterator<T> t = *this;
  ++(*this);
  return t;
}
