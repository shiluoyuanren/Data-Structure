#include <iostream>
#include <string>
#include "AATree.h"

int main() {
    SET<int, char*> a[] = {{10, (char*)"aaa"},   {8, (char*)"bbb"},
                           {21, (char*)"ccc"},   {87, (char*)"ddd"},
                           {56, (char*)"eee"},   {4, (char*)"fff"},
                           {11, (char*)"ggg"},   {3, (char*)"hhh"},
                           {22, (char*)"iiiii"}, {7, (char*)"jjj"}};
    AATree<int, char*> tree;
    SET<int, char*> x;
    SET<int, char*>* p;

    for (int i = 0; i < 10; i++)
        tree.insert(a[i]);

    p = tree.find(8);
    if (p)
        std::cout << "Find 8 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;
    tree.remove(8);
    p = tree.find(8);
    if (p)
        std::cout << "Find 8 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;
    p = tree.find(21);
    if (p)
        std::cout << "Find 21 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;
    tree.remove(21);
    p = tree.find(21);
    if (p)
        std::cout << "Find 21 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;

    x.key = 30;
    x.other = (char*)"xyz";
    tree.insert(x);
    p = tree.find(30);
    if (p)
        std::cout << "Find 30 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;
    tree.remove(30);
    p = tree.find(30);
    if (p)
        std::cout << "Find 30 is " << p->key << " " << p->other << std::endl
                  << std::endl;
    else
        std::cout << "Not found" << std::endl << std::endl;

    system("pause");
    return 0;
}