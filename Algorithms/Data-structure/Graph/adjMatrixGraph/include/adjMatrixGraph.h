#ifndef _ADJMATRIXGRAPH_H
#define _ADJMATRIXGRAPH_H

#include <iostream>

template <class TypeOfVer, class TypeOfEdge>
class graph {
   public:
    virtual ~graph() {}
    virtual void insert(const TypeOfVer& x,
                        const TypeOfVer& y,
                        const TypeOfEdge& w) = 0;
    virtual void remove(const TypeOfVer& x, const TypeOfVer& y) = 0;
    virtual bool exist(const TypeOfVer& x, const TypeOfVer& y) const = 0;
    int numOfVer() const { return Vers; }
    int numOfEdge() const { return Edges; }

   protected:
    int Vers, Edges;
};

//邻接矩阵表示法
template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge> {
   public:
    adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
    ~adjMatrixGraph();
    void insert(const TypeOfVer& x, const TypeOfVer& y, const TypeOfEdge& w);
    void remove(const TypeOfVer& x, const TypeOfVer& y);
    bool exist(const TypeOfVer& x, const TypeOfVer& y) const;

   private:
    TypeOfEdge** edge;  //存放邻接矩阵
    TypeOfVer* ver;     //存放节点值
    TypeOfEdge noEdge;  //邻接矩阵中的oo的表示值
    int find(const TypeOfVer& v) const {
        for (int i = 0; i < this->Vers; ++i)
            if (ver[i] == v)
                return i;
    }
};

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(
    int vSize,
    const TypeOfVer d[],
    const TypeOfEdge noEdgeFlag) {
    int i, j;
    noEdge = noEdgeFlag;
    this->Vers = vSize;
    this->Edges = 0;

    //存放节点的数组的初始化
    ver = new TypeOfVer[this->Vers];
    for (i = 0; i < this->Vers; ++i)
        ver[i] = d[i];

    //邻接矩阵的初始化
    edge = new TypeOfEdge*[this->Vers];
    for (i = 0; i < this->Vers; ++i) {
        edge[i] = new TypeOfEdge[this->Vers];
        for (j = 0; j < this->Vers; ++j)
            edge[i][j] = noEdge;
        edge[i][i] = 0;
    }
}

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph() {
    delete[] ver;
    for (int i = 0; i < this->Vers; ++i)
        delete[] edge[i];
    delete[] edge;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(const TypeOfVer& x,
                                                   const TypeOfVer& y,
                                                   const TypeOfEdge& w) {
    int u = find(x), v = find(y);
    if (edge[u][v] == noEdge) {
        edge[u][v] = w;
        ++this->Edges;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(const TypeOfVer& x,
                                                   const TypeOfVer& y) {
    int u = find(x), v = find(y);
    if (edge[u][v] != noEdge && edge[u][v] != 0) {
        edge[u][v] = noEdge;
        --this->Edges;
    }
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(const TypeOfVer& x,
                                                  const TypeOfVer& y) const {
    int u = find(x), v = find(y);
    return edge[u][v] != noEdge;
}

#endif  // _ADJMATRIXGRAPH_H