#ifndef UNTITLED_AVL_H
#define UNTITLED_AVL_H

#include "Node.h"

class Avl {

private:
    Node *tree;

    int getHeight(Node *tree);

    void updateHeightNode(Node *&n);

    Node *rotateRight(Node *&node);

    Node *rotateLeft(Node *&node);

    int getBalance(Node *&node);

    Node *reBalance(Node *&node);

    Node *addNode(Node *&node, int data);

    Node *deleteNode(Node *&node, int data);

    Node *find(Node *&node, int data);

public:
    int getHeight();

    void reBalance() {
        tree = reBalance(tree);
    }

    void addNode(int data) {
        tree = addNode(tree, data);
    }

    Node *getTree() const;
};


#endif //UNTITLED_AVL_H
