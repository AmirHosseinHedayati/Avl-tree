#include "TreePrinter.h"
#include <iostream>
using namespace std;

void TreePrinter:: printT(const std::string &prefix, const Node *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "├── " : "└── ");

        std::cout << node->data << std::endl;

        printT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void TreePrinter:: printT(const Node *node) {
    printT("", node, false);
}