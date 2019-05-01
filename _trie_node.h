#include <vector>

template <typename T>
class tnode {
    public:
        tnode();
    private:
        T mapped_value;
        char key;
        bool isEnd;
        vector <char> children;
};