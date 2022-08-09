#include <iostream>
#include "adjMatrixGraph.h"
using namespace std;

int main() {
    int a[] = {0, 1, 2};
    adjMatrixGraph<int, int> g(3, a, 255);
    g.insert(0, 2, 5);
    g.insert(0, 1, 8);
    g.insert(2, 1, 2);
    g.insert(2, 0, 6);
    g.insert(1, 0, 3);
    g.floyd();

    system("pause");
    return 0;
}