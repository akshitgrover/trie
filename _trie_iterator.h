#pragma once

#include <string>
#include <iterator>
#include <iostream>

#include "_trie_node.h"
#include "_trie_util.h"

/*
  Iterator class definition.
*/
template <typename T>
class trie_iterator {
  private:
    tnode<T>* cur_node;
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    // Constructors
    explicit trie_iterator(tnode<T>*);
    trie_iterator();

  protected:
    // Member functions
    tnode<T>* getNode();

  public:
    // Operators
    trie_iterator<T>& operator++ ();
    trie_iterator<T> operator++ (int);
    trie_iterator<T>& operator-- ();
    trie_iterator<T> operator-- (int);
    bool operator== (const trie_iterator<T>&) const;
    bool operator!= (const trie_iterator<T>&) const;
    reference operator* () const;
    pointer operator-> () const;
};

/*
  Function definitions of trie_iterator class member functions.
*/
template <typename T>
trie_iterator<T>::trie_iterator(tnode<T>* root) {
  this->cur_node = root;
}

template <typename T>
trie_iterator<T>::trie_iterator() {
  this->cur_node = nullptr;
}

template <typename T>
trie_iterator<T>& trie_iterator<T>::operator++ () {
  if (this->cur_node == nullptr || this->cur_node->getParentIndex() == 1516) {
    return *this;
  }
  if (this->cur_node->getParentIndex() == -1516) {
    this->cur_node = this->cur_node->getParent();
    return *this;
  }
  tnode<T>* tmp = recur(this->cur_node);
  if (tmp == nullptr) {
    T flag;
    tmp = new tnode<T>(flag, this->cur_node, 1516);
  }
  this->cur_node = tmp;
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
  if (this->cur_node == nullptr || this->cur_node->getParentIndex() == -1516) {
    return *this;
  }
  if (this->cur_node->getParentIndex() == 1516) {
    this->cur_node = this->cur_node->getParent();
    return *this;
  }
  tnode<T>* tmp = rrecur(
    this->cur_node->getParent(),
    this->cur_node->getParentIndex() - 1
  );
  if (tmp == nullptr) {
    T flag;
    tmp = new tnode<T>(flag, this->cur_node, -1516);
  }
  this->cur_node = tmp;
  return *this;
}

template <typename T>
trie_iterator<T> trie_iterator<T>::operator-- (int) {
  trie_iterator<T> t = *this;
  --(*this);
  return t;
}

template <typename T>
bool trie_iterator<T>::operator== (const trie_iterator<T>& t) const {
  if (this->cur_node == nullptr && t.cur_node == nullptr) {
    return true;
  } else if (this->cur_node == nullptr || t.cur_node == nullptr) {
    return false;
  }
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

template <typename T>
typename trie_iterator<T>::reference trie_iterator<T>::operator* () const {
  return this->cur_node->get();
}

template <typename T>
typename trie_iterator<T>::pointer trie_iterator<T>::operator-> () const {
  return &this->cur_node->get();
}

template <typename T>
tnode<T>* trie_iterator<T>::getNode() {
  return this->cur_node;
}
