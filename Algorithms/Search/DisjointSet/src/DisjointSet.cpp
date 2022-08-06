#include "DisjointSet.h"
#include <iostream>

DisjointSet::DisjointSet(int s) {
    size = s;
    parent = new int[size];
    for (int i = 0; i < size; ++i)
        parent[i] = -1;
    //此时每个元素都为一个集合
}

int DisjointSet::Find(int x) {
    if (parent[x] >= 0)
        return parent[x] = Find(parent[x]);
    //路径压缩
    else
        return x;
}

void DisjointSet::Union(int root1, int root2) {
    root1 = Find(root1);
    root2 = Find(root2);
    if (root1 == root2)
        return;
    //按规模并
    else if (parent[root1] < parent[root2]) {
        parent[root1] += parent[root2];
        parent[root2] = root1;
    } else {
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
}