#ifndef _ADJLISTGRAPH_H
#define _ADJLISTGRAPH_H

#include <iostream>
#include <queue>
#include "DisjointSet.h"

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

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge> {
   public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    ~adjListGraph();
    void insert(const TypeOfVer& x, const TypeOfVer& y, const TypeOfEdge& w);
    void remove(const TypeOfVer& x, const TypeOfVer& y);
    bool exist(const TypeOfVer& x, const TypeOfVer& y) const;
    void dfs() const;  //深度优先搜索
    void bfs() const;  //广度优先搜索
    //求加权无向连通图的最小生成树
    void kruskal() const;                       // Kruskal算法
    void prim(const TypeOfEdge& noEdge) const;  // Prim算法
    //单源最短路径
    //非加权图的最短路径
    void unweightedShortDistance(const TypeOfVer& start,
                                 const TypeOfEdge& noEdge) const;
    //加权图的最短路径
    void dijkstra(const TypeOfVer& start, const TypeOfEdge& noEdge) const;

   private:
    struct edgeNode {
        int end;
        TypeOfEdge weight;
        edgeNode* next;

        edgeNode(int e, const TypeOfEdge& w, edgeNode* p = NULL)
            : end(e), weight(w), next(p) {}
    };

    struct verNode {
        TypeOfVer ver;
        edgeNode* head;

        verNode() : head(NULL) {}
    };

    //边的类型
    struct edge {
        int beg, end;
        TypeOfEdge w;
        bool operator>(const edge& rp) const { return w > rp.w; }
    };

    verNode* verList;
    int find(const TypeOfVer& x) const {
        for (int i = 0; i < this->Vers; ++i)
            if (verList[i].ver == x)
                return i;
    }
    void dfs(int start, bool visited[]) const;
    void printPath(int start, int end, int prev[]) const;
};

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dijkstra(
    const TypeOfVer& start,
    const TypeOfEdge& noEdge) const {
    TypeOfEdge* distance = new TypeOfEdge[this->Vers];
    int* prev = new int[this->Vers];
    bool* known = new bool[this->Vers];
    int i, u, sNo, j;
    TypeOfEdge min;
    edgeNode* p;

    //初始化
    for (i = 0; i < this->Vers; ++i) {
        distance[i] = noEdge;
        known[i] = false;
    }

    sNo = find(start);
    distance[sNo] = 0;
    prev[sNo] = sNo;
    for (i = 0; i < this->Vers; ++i) {
        min = noEdge;
        //寻找具有最短距离的节点
        for (j = 0; j < this->Vers; ++j)
            if (known[j] == false && distance[j] < min) {
                u = j;
                min = distance[j];
            }
        known[u] = true;  //将u放入S
        p = verList[u].head;
        while (p) {  //更新u的邻接点距离
            if (known[p->end] == false &&
                distance[u] + p->weight < distance[p->end]) {
                distance[p->end] = distance[u] + p->weight;
                prev[p->end] = u;
            }
            p = p->next;
        }
    }

    for (i = 0; i < this->Vers; ++i) {
        std::cout << "从" << start << "到" << verList[i].ver << "的最短路径为:";
        printPath(sNo, i, prev);
        std::cout << " 长度为:" << distance[i] << std::endl;
    }
    delete[] distance;
    delete[] prev;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::unweightedShortDistance(
    //实质就是广度优先搜索
    const TypeOfVer& start,
    const TypeOfEdge& noEdge) const {
    TypeOfEdge* distance = new TypeOfEdge[this->Vers];
    int* prev = new int[this->Vers];
    int u, i, sNo;
    edgeNode* p;
    std::queue<int> q;

    //初始化
    for (i = 0; i < this->Vers; ++i)
        distance[i] = noEdge;

    //寻找起始节点的编号
    sNo = find(start);

    //寻找最短路径
    distance[sNo] = 0;
    prev[sNo] = sNo;
    q.push(sNo);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        p = verList[u].head;
        while (p) {
            if (distance[p->end] == noEdge) {
                distance[p->end] = distance[u] + 1;
                prev[p->end] = u;
                q.push(p->end);
            }
            p = p->next;
        }
    }

    //输出最短路径
    for (i = 0; i < this->Vers; ++i) {
        std::cout << "从" << start << "到" << verList[i].ver
                  << "的最短路径为:" << std::endl;
        printPath(sNo, i, prev);
        std::cout << std::endl;
    }
    delete[] distance;
    delete[] prev;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::printPath(int start,
                                                    int end,
                                                    int prev[]) const {
    if (start == end) {
        std::cout << verList[start].ver;
        return;
    }
    printPath(start, prev[end], prev);
    std::cout << "->" << verList[end].ver;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::prim(const TypeOfEdge& noEdge) const {
    int i, j, start;
    TypeOfEdge min;
    //保存节点是否在生成树中
    bool* flag = new bool[this->Vers];
    //到节点i的边的最小权值
    TypeOfEdge* lowCost = new TypeOfEdge[this->Vers];
    //从哪一个节点到节点i的权值是lowCost[i]
    int* startNode = new int[this->Vers];

    for (i = 0; i < this->Vers; ++i) {
        flag[i] = false;
        lowCost[i] = noEdge;
    }

    start = 0;  // 0作为第一个加入生成树的节点
    std::cout << "此图的最小生成树(Prim)为:\n";
    for (i = 1; i < this->Vers; ++i) {
        edgeNode* p = verList[start].head;
        while (p) {
            if (flag[p->end] == false && p->weight < lowCost[p->end]) {
                lowCost[p->end] = p->weight;
                startNode[p->end] = start;
            }
            p = p->next;
        }
        flag[start] = true;
        min = noEdge;
        for (j = 0; j < this->Vers; ++j)
            if (lowCost[j] < min) {
                min = lowCost[j];
                start = j;
            }
        std::cout << "(" << verList[startNode[start]].ver << ","
                  << verList[start].ver << ") ";
        lowCost[start] = noEdge;  //边的权值设为无穷大,表示不考虑这个节点
    }
    std::cout << std::endl;
    delete[] flag;
    delete[] lowCost;
    delete[] startNode;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::kruskal() const {
    DisjointSet d(this->Vers);
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> q;
    int i;
    edgeNode* p;
    edge e;

    //将所有的边入队,注意不可重复
    for (i = 0; i < this->Vers; ++i)
        for (p = verList[i].head; p != NULL; p = p->next)
            if (i < p->end) {
                e.beg = i;
                e.end = p->end;
                e.w = p->weight;
                q.push(e);
            }

    std::cout << "此图的最小生成树(Kruskal)为:\n";
    for (i = 1; i < this->Vers;) {
        e = q.top();
        q.pop();
        if (d.Find(e.beg) != d.Find(e.end)) {
            std::cout << "(" << verList[e.beg].ver << "," << verList[e.end].ver
                      << ") ";
            d.Union(e.beg, e.end);
            ++i;
        }
    }
    std::cout << std::endl;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const {
    int i;
    std::queue<int> q;  //保存当前访问节点
    bool* visited = new bool[this->Vers];

    for (i = 0; i < this->Vers; ++i)
        visited[i] = false;

    std::cout << "当前图的广度优先遍历序列为:\n";
    for (i = 0; i < this->Vers; ++i) {
        if (visited[i] == true)
            continue;
        q.push(i);
        while (!q.empty()) {
            int tpl = q.front();
            if (visited[tpl] == false) {
                std::cout << verList[tpl].ver << " ";
                visited[tpl] = true;
            }
            q.pop();
            edgeNode* p = verList[tpl].head;
            while (p) {
                if (visited[p->end] == false)
                    q.push(p->end);
                p = p->next;
            }
        }
        std::cout << std::endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const {
    int i;
    bool* visited = new bool[this->Vers];

    for (i = 0; i < this->Vers; ++i)
        visited[i] = false;

    std::cout << "当前图的深度优先遍历序列为:\n";
    for (i = 0; i < this->Vers; ++i) {
        if (visited[i] == true)
            continue;
        dfs(i, visited);  //深度搜索当前的节点
        std::cout << std::endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const {
    edgeNode* p = verList[start].head;

    std::cout << verList[start].ver << " ";
    visited[start] = true;

    while (p) {
        if (visited[p->end] == false)
            dfs(p->end, visited);
        p = p->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize,
                                                  const TypeOfVer d[]) {
    this->Vers = vSize;
    this->Edges = 0;

    verList = new verNode[this->Vers];
    for (int i = 0; i < this->Vers; ++i)
        verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
    edgeNode *p, *q;
    for (int i = 0; i < this->Vers; ++i) {
        p = verList[i].head;
        while (p) {
            q = p->next;
            delete p;
            p = q;
        }
    }
    delete[] verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(const TypeOfVer& x,
                                                 const TypeOfVer& y,
                                                 const TypeOfEdge& w) {
    int u = find(x), v = find(y);
    if (!exist(x, y)) {
        verList[u].head = new edgeNode(v, w, verList[u].head);
        //无向图添加此项
        verList[v].head = new edgeNode(u, w, verList[v].head);
        ++this->Edges;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(const TypeOfVer& x,
                                                 const TypeOfVer& y) {
    int u = find(x), v = find(y);
    if (!exist(x, y)) {
        return;
    }
    //此时x,y必有边
    edgeNode* p = verList[u].head;
    if (p->end == v) {
        verList[u].head = p->next;
        delete p;
    } else {
        while (p->next->end != v)
            p = p->next;
        edgeNode* tpl = p->next;
        p = tpl->next;
        delete tpl;
    }
    //无向图添加此项
    edgeNode* q = verList[v].head;
    if (q->end == u) {
        verList[v].head = q->next;
        delete q;
    } else {
        while (q->next->end != u)
            q = q->next;
        edgeNode* tpl = q->next;
        q = tpl->next;
        delete tpl;
    }
    --this->Edges;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(const TypeOfVer& x,
                                                const TypeOfVer& y) const {
    int u = find(x), v = find(y);
    edgeNode* p = verList[u].head;
    while (p) {
        if (p->end == v)
            return true;
        p = p->next;
    }
    return false;
}

#endif  // _ADJLISTGRAPH_H