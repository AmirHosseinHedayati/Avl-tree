#ifndef UNTITLED_AVL_H
#define UNTITLED_AVL_H

#include "Node.h"

class Avl {

private:
    Node *tree;

    int getHeight(Node *tree);

    void updateHeightNode(Node *&n);

    Node *rotateRight(Node *&node);

public:
    int getHeight();
};


#endif //UNTITLED_AVL_H
