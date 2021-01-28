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

    Node *addNode(Node *&node, const std::string &word , const std::string &meaning);

    Node *deleteNode(Node *&node, const std::string &word );

    Node *find(Node *&node, const std::string &word);

    int compareStrings(const std::string& s1,const std::string&  s2);

public:
    int getHeight();

    void reBalance() {
        tree = reBalance(tree);
    }

    void addNode(const std::string &word ,const std::string &meaning) {
        tree = addNode(tree, word , meaning);
    }

    Node *getTree() const;

    void deleteNode(const std::string &word) {
        tree = deleteNode(tree, word);
    }

    Node *find(const std::string &word) {
        return find(tree, word);
    }
};


#endif //UNTITLED_AVL_H
