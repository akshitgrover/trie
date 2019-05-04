#pragma once

#include <vector>
#include <string>

#define sIter(c, it)\
for (std::string::iterator it = c.begin(); it != c.end(); it++)

template <typename T>
tnode<T>* recur(tnode<T>* n, int offset = 0) {
  if (n == nullptr) {
    std::cout << "Null Received" << std::endl;
    return nullptr;
  }
  tnode<T>* it = nullptr;
  for (int i = offset; i < 128; i++) {
    it = n->getChild(i);
    if (it == nullptr) {
      if (i == 127) {
        if (n->getParent() == nullptr) {
          std::cout << "Exhausted" << std::endl;
          return nullptr;
        }
        return recur(n->getParent(), n->getParentIndex() + 1);
      }
      continue;
    }
    if (it->isEnd()) {
      return it;
    }
    return recur(it, 0);
  }
}
