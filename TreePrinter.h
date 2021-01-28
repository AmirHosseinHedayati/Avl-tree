#ifndef UNTITLED_TREEPRINTER_H
#define UNTITLED_TREEPRINTER_H

#include "Node.h"
#include <string>

class TreePrinter {
private:
    void printT(const std::string &prefix, const Node *node, bool isLeft);

public:
    void printT(const Node *node);
};

#endif
