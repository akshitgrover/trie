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
    trie_iterator<T>& operator-- ();
    bool operator== (const trie_iterator<T>&) const;
    bool operator!= (const trie_iterator<T>&) const;
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

template <typename T>
trie_iterator<T>& trie_iterator<T>::operator-- () {
  if (this->cur_node == nullptr) {
    return *this;
  }
  this->cur_node = rrecur(
    this->cur_node->getParent(),
    this->cur_node->getParentIndex() - 1
  );
  return *this;
}

template <typename T>
bool trie_iterator<T>::operator== (const trie_iterator<T>& t) const {
  if (this->cur_node->getParentIndex() == t.cur_node->getParentIndex()
  && this->cur_node->getParent() == t.cur_node->getParent()) {
    return true;
  }
  return false;
}

template <typename T>
bool trie_iterator<T>::operator!= (const trie_iterator<T>& t) const {
  return !(*this == t);
}
