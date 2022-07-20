#include <iostream>
#include "BinaryTree.h"

int main() {
    binaryTree<char> b1;
    b1.createTree('@');
    b1.preOrder();
    b1.midOrder();
    b1.postOrder();
    b1.levelOrder();
    std::cout << "\n" << std::endl;
    printTree(b1, '@');
    b1.delLeft('L');
    b1.delRight('C');
    b1.delLeft('C');
    std::cout << std::endl;
    printTree(b1, '@');
    b1.clear();
    b1.levelOrder();
    std::cout << "\n" << std::endl;
    system("pause");
    return 0;
}