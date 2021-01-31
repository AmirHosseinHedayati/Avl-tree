#include <iostream>
#include "Avl.h"
#include "TreePrinter.h"

int main() {
    auto tp = new TreePrinter();
    Avl *avl = new Avl();
    avl->addNode("a" ,"1" );
    avl->addNode("b" , "2");
    avl->addNode("c" , "3");
    avl->addNode("d" , "4");
    avl->addNode("e" , "5");
    avl->addNode("e" , "6");
    avl->addNode("f" , "7");
    avl->addNode("g" , "8");
    avl->addNode("h" , "9");
    avl->addNode("i" , "10");

    tp->printT(avl->getTree());
  
    return 0;
}
