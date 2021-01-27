#include "Avl.h"
#include <stdexcept>

using namespace std;

int Avl::getHeight(Node *tree) {
    if (tree == nullptr){
        return 0;
    }
    else{
        return 1 + max(getHeight(tree->left), getHeight(tree->right));
    }
}

int Avl::getHeight() {
    return getHeight(tree);
}