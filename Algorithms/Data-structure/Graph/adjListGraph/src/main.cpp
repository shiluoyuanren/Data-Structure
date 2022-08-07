#include <iostream>
#include "adjListGraph.h"
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    adjListGraph<int, int> g(7, a);
    g.insert(5, 6, 10);
    g.insert(5, 7, 10);
    g.insert(7, 6, 10);
    g.insert(6, 2, 10);
    g.insert(7, 4, 10);
    g.insert(2, 4, 10);
    g.insert(2, 3, 10);
    g.insert(4, 3, 10);
    g.insert(4, 1, 10);
    g.insert(3, 1, 10);
    g.insert(1, 2, 10);
    cout << "图的节点数:" << g.numOfVer() << ",边数:" << g.numOfEdge() << endl;
    g.dfs();
    g.bfs();

    system("pause");
    return 0;
}