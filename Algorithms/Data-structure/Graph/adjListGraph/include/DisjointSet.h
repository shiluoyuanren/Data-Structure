#ifndef _DISJOINTSET_H
#define _DISJOINTSET_H

#include <iostream>

//并查集的定义
class DisjointSet {
   private:
    int* parent;
    int size;

   public:
    DisjointSet(int s = 100);  //参数为并查集的规模
    ~DisjointSet() { delete[] parent; }
    int Find(int x);
    void Union(int root1, int root2);
};

#endif  // _DISJOINTSET_H