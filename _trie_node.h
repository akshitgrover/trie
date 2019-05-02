#include <vector>

template <typename T>
class tnode {
    public:
        explicit tnode(T v, bool eow = false);
        void addChild(tnode* child, char key);
    private:
        T mapped_value;
        char key;
        bool isEnd;
        std::vector <tnode*> children;
};

template <typename T>
tnode<T>::tnode(T val, bool eow) {
    this->mapped_value = val;
    this-> isEnd = eow;
    std::vector <tnode*> ch(256, nullptr);
    this->children = ch;
}

template <typename T>
void tnode<T>::addChild(tnode* child, char key) {
    this->children[(int)key] = child;
}