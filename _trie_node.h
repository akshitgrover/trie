#include <string>
#include <vector>

template <typename T>
class tnode {
  public:
    explicit tnode(T v, tnode<T>* p, int ascii, bool eow = false);
    void addChild(tnode* child, int key);
    std::string getKey();
    tnode<T>* getChild(int key);
    T& get();
    void update(T val);
    void markEnd(std::string);
    bool isEnd();
    tnode<T>* getParent();
    int getParentIndex();
  private:
    T mapped_value;
    int p_index;
    bool isEndOfWord;
    tnode<T>* parent;
    std::vector <tnode<T>*> children;
    std::string key;
};

template <typename T>
tnode<T>::tnode(T val, tnode<T>* p, int ascii, bool eow) {
  this->mapped_value = val;
  this-> isEndOfWord = eow;
  this->p_index = ascii;
  this-> key = "";
  this->parent = p;
  this->children = *(new std::vector <tnode<T>*>(128, nullptr));
}

template <typename T>
void tnode<T>::addChild(tnode* child, int key) {
  this->children[(int)key] = child;
}

template <typename T>
std::string tnode<T>::getKey() {
  return this->key;
}

template <typename T>
tnode<T>* tnode<T>::getChild(int key) {
  return this->children[(int)key];
}

template <typename T>
T& tnode<T>::get() {
  return this->mapped_value;
}

template <typename T>
void tnode<T>::update(T val) {
  this->mapped_value = val;
}

template <typename T>
void tnode<T>::markEnd(std::string key) {
  this->key = key;
  this->isEndOfWord = true;
}

template <typename T>
bool tnode<T>::isEnd() {
  return this->isEndOfWord;
}

template <typename T>
tnode<T>* tnode<T>::getParent() {
  return this->parent;
}

template <typename T>
int tnode<T>::getParentIndex() {
  return this->p_index;
}
