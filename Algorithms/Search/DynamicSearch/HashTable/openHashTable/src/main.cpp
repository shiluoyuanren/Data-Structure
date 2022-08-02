#include <iostream>
#include "openHashTable.h"

int main() {
    system("title openHashTable");

    SET<int, char*> a[] = {{1, (char*)"aaa"},
                           {5, (char*)"bbb"},
                           {7, (char*)"ccc"},
                           {2, (char*)"ddd"}};
    openHashTable<int, char*> table(13);
    for (int i = 0; i < 4; i++)
        table.insert(a[i]);
    SET<int, char*>* p = table.find(7);
    if (p) {
        std::cout << "Find 7 is: ";
        std::cout << p->key << " " << p->other << std::endl;
    } else
        std::cout << "Not found!" << std::endl;
    table.remove(7);
    p = table.find(7);
    if (p) {
        std::cout << "Find 7 is: ";
        std::cout << p->key << " " << p->other << std::endl;
    } else
        std::cout << "Not found!" << std::endl;

    SET<int, char*> x;
    x.key = 30;
    x.other = (char*)"eee";
    table.insert(x);
    p = table.find(x.key);
    if (p) {
        std::cout << "Find 30 is: ";
        std::cout << p->key << " " << p->other << std::endl;
    } else
        std::cout << "Not found!" << std::endl;
    table.remove(x.key);
    p = table.find(x.key);
    if (p) {
        std::cout << "Find 30 is: ";
        std::cout << p->key << " " << p->other << std::endl;
    } else
        std::cout << "Not found!" << std::endl;

    system("pause");
    return 0;
}