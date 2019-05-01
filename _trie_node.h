#include <vector>

template <typename T>
class tnode {
    public:
        explicit tnode(T v, char keu, bool eow = false);
    private:
        T mapped_value;
        char key;
        bool isEnd;
        std::vector <tnode*> children;
};

template <typename T>
tnode<T>::tnode(T val, char key, bool eow) {
    this->mapped_value = val;
    this->key = key;
    this-> isEnd = eow;
    std::vector <tnode*> ch(256);
    this->children = ch;
}