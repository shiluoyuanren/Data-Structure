#include <iostream>
#include "adjListGraph.h"
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    adjListGraph<int, int> g(7, a);
    g.insert(1, 2, 6);
    g.insert(1, 3, 1);
    g.insert(3, 5, 5);
    g.insert(2, 5, 3);
    g.insert(2, 6, 6);
    g.insert(2, 4, 6);
    g.insert(5, 6, 4);
    g.insert(6, 4, 2);
    g.insert(3, 7, 5);
    g.insert(1, 4, 5);
    /*测试有向图改为无向图的正确性
    g.insert(1, 5, 7);
    g.remove(1, 5);*/
    cout << "图的节点数:" << g.numOfVer() << ",边数:" << g.numOfEdge() << endl;
    cout << "\n----------------------------" << endl;
    g.dfs();
    g.bfs();
    cout << "\n----------------------------" << endl;
    g.kruskal();
    g.prim(100);
    cout << "\n---------非加权图-----------" << endl;
    g.unweightedShortDistance(1, 189);
    cout << "\n----------加权图------------" << endl;
    g.dijkstra(1, 235);
    cout << "\n----------拓扑排序----------" << endl;
    g.topSort();

    system("pause");
    return 0;
}