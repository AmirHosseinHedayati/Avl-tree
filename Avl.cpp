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

Node *Avl::rotateLeft(Node *&node) {
    Node *right = node->right;
    Node *left = right->left;
    right->left = node;
    node->right = left;
    updateHeightNode(node);
    updateHeightNode(right);
    return right;
}

int Avl::getBalance(Node *&n) {
    return (n == nullptr) ? 0 : getHeight(n->right) - getHeight(n->left);

}