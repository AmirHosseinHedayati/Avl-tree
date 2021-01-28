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

Node *Avl::reBalance(Node *&node) {
    updateHeightNode(node);
    int bal = getBalance(node);
    if (bal > 1) {
        if (getHeight(node->right->right) > getHeight(node->right->left)) {
            node = rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    } else if (bal < -1) {
        if (getHeight(node->left->left) > getHeight(node->left->right))
            node = rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    }
    return node;
}

Node *Avl::addNode(Node *&node, int data) {
    if (node == nullptr) {
        Node *temp = new Node();
        temp->data = data;
        return temp;
    } else if (node->data > data) {
        node->left = addNode(node->left, data);
    } else {
        node->right = addNode(node->right, data);
    }
    return reBalance(node);
}

Node *Avl::deleteNode(Node *&node, int data) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->data < data) {
        node->right = deleteNode(node->right, data);
    } else if (node->data > data) {
        node->left = deleteNode(node->left, data);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            node = (node->left == nullptr) ? node->right : node->left;
        } else {
            Node *mostLeftChild = node->right;
            node->data = mostLeftChild->data;
            node->right = deleteNode(node->right, node->data);
        }
    }
    if (node != nullptr) {
        node = reBalance(node);
    }
    return node;
}

Node *Avl::find(Node *&node, int data) {
    if (node != nullptr) {
        if (node->data == data)
            return node;
        else if (node->data < data)
            return find(node->right, data);
        else
            return find(node->left, data);
    } else
        return nullptr;
}

Node *Avl::getTree() const {
    return tree;
}

