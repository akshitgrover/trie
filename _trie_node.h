#include <vector>

template <typename T>
class tnode {
  public:
    explicit tnode(T v, bool eow = false);
    void addChild(tnode* child, char key);
    tnode<T>* getChild(char key);
    T getVal();
  private:
    T mapped_value;
    bool isEnd;
    std::vector <tnode*> children;
};

template <typename T>
tnode<T>::tnode(T val, bool eow) {
  this->mapped_value = val;
  this-> isEnd = eow;
  this->children = *(new std::vector <tnode<T>*>(256, nullptr));
}

template <typename T>
void tnode<T>::addChild(tnode* child, char key) {
  this->children[(int)key] = child;
}

template <typename T>
tnode<T>* tnode<T>::getChild(char key) {
  return this->children[(int)key];
}

template <typename T>
T tnode<T>::getVal() {
  return this->mapped_value;
}
