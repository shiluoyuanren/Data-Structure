#include <iostream>
#include "adjMatrixGraph.h"
using namespace std;

int main() {
    adjMatrixGraph<char, int> g(10, "abcdefghij", -2);
    g.insert('a', 'f', 56);
    g.insert('b', 'j', 34);
    g.remove('b', 'j');
    cout << "图的节点数:" << g.numOfVer() << ",边数:" << g.numOfEdge() << endl;

    system("pause");
    return 0;
}