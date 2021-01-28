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

void Avl::updateHeightNode(Node *&node) {
    node->height = (short) (max(getHeight(node->left), getHeight(node->right)) + 1);
}

Node *Avl::rotateRight(Node *&node) {
    Node *left = node->left;
    Node *right = left->right;
    left->right = node;
    node->left = right;
    updateHeightNode(node);
    updateHeightNode(left);
    return left;
}