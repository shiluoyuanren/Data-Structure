#include <iostream>
#include "adjListGraph.h"
using namespace std;

int main() {
    adjListGraph<char, int> g(10, "abcdefghij");
    g.insert('a', 'f', 56);
    g.insert('b', 'j', 34);
    g.remove('b', 'j');
    g.insert('e', 'i', 12);
    cout << "图的节点数:" << g.numOfVer() << ",边数:" << g.numOfEdge() << endl;

    system("pause");
    return 0;
}