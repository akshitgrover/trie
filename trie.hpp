#include <string>

#include "_trie_util.h"

template <typename T>
trie<T>::trie(): size(0) {
    T flag;
    root = new tnode<T>(flag);
}

template <typename T>
void trie<T>::insert(std::string key, T val) {
  tnode<T>* node = this->root;
  int ascii;
  sIter(key, it) {
    ascii = (int)*it;
    if (node->getChild(ascii) != nullptr) {
      node = node->getChild(ascii);
    } else {
      T flag;
      tnode<T>* _node = new tnode<T>(flag);
      node->addChild(_node, ascii);
      node = node->getChild(ascii);
    }
  }
  node->update(val);
  node->markEnd();
}
