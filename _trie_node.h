#include <vector>

template <typename T>
class tnode {
  public:
    explicit tnode(T v, tnode<T>* p, int ascii, bool eow = false);
    void addChild(tnode* child, char key);
    tnode<T>* getChild(char key);
    T get();
    void update(T val);
    void markEnd();
    bool isEnd();
  private:
    T mapped_value;
    int p_index;
    bool isEndOfWord;
    tnode<T>* parent;
    std::vector <tnode<T>*> children;
};

template <typename T>
tnode<T>::tnode(T val, tnode<T>* p, int ascii, bool eow) {
  this->mapped_value = val;
  this-> isEndOfWord = eow;
  this->p_index = ascii;
  this->parent = p;
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
T tnode<T>::get() {
  return this->mapped_value;
}

template <typename T>
void tnode<T>::update(T val) {
  this->mapped_value = val;
}

template <typename T>
void tnode<T>::markEnd() {
  this->isEndOfWord = true;
}

template <typename T>
bool tnode<T>::isEnd() {
  return this->isEndOfWord;
}
