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
    node->height = (short) getHeight(node);
}

Node *Avl::rotateRight(Node *&node) {
    Node *left = node->left;
    Node *right = left->right;
    left->right = node;   // put node in child right of child left
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

Node *Avl::addNode(Node *&node,const std::string &word , const std::string &meaning) {
    if (node == nullptr) {
        Node *temp = new Node();
        temp->word = word;
        temp->meaning = meaning;
        return temp;
    } else if (compareStrings(node->word , word) == 1 ) {
        node->left = addNode(node->left, word , meaning);                    /////////////////
    } else {
        node->right = addNode(node->right, word , meaning);                  /////////////////
    }
    return reBalance(node);
}

Node *Avl::deleteNode(Node *&node, const std::string &word) {
    if (node == nullptr) {
        return nullptr;
    } else if (compareStrings(node->word , word) == -1) {
        node->right = deleteNode(node->right, word);               /////////////////
    } else if (compareStrings(node->word , word) == 1) {
        node->left = deleteNode(node->left, word);                 /////////////////
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            node = (node->left == nullptr) ? node->right : node->left;
        } else {
            Node *mostLeftChild = node->right;
            node->word = mostLeftChild->word;
            node->right = deleteNode(node->right, node->word);
        }
    }
    if (node != nullptr) {
        node = reBalance(node);
    }
    return node;
}

Node *Avl::find(Node *&node, const std::string &word) {
    if (node != nullptr) {
        if (compareStrings(node->word , word) == 0)
            return node;
        else if (compareStrings(node->word , word) == -1)
            return find(node->right, word);                      /////////////////
        else
            return find(node->left, word);                       /////////////////
    } else
        return nullptr;
}

Node *Avl::getTree() const {
    return tree;
}

int Avl::compareStrings(const std::string& s1,const std::string&  s2) {
    int compare = s1.compare(s2);
    if (compare > 0){
        return 1;
    }
    else if (compare < 0){
        return -1;
    }
    else if (compare == 1){
        return 0;
    }
}


