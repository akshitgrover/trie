#include <string>

#include "_trie_util.h"

template <typename T>
trie<T>::trie(): size(0) {
    T flag;
    root = new tnode<T>(flag, nullptr);
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
      tnode<T>* _node = new tnode<T>(flag, node);
      node->addChild(_node, ascii);
      node = node->getChild(ascii);
    }
  }
  node->update(val);
  node->markEnd();
}

template <typename T>
bool trie<T>::exist(std::string key) {
  int ascii;
  bool res = true;
  tnode<T>* node = this->root;
  sIter(key, it) {
    ascii = (int)*it;
    if (node->getChild(ascii) == nullptr) {
      res = false;
      break;
    } else {
      node = node->getChild(ascii);
    }
  }
  if (!node->isEnd()) {
    res = false;
  }
  return res;
}
