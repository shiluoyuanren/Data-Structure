#ifndef _ADJLISTGRAPH_H
#define _ADJLISTGRAPH_H

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

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge> {
   public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    ~adjListGraph();
    void insert(const TypeOfVer& x, const TypeOfVer& y, const TypeOfEdge& w);
    void remove(const TypeOfVer& x, const TypeOfVer& y);
    bool exist(const TypeOfVer& x, const TypeOfVer& y) const;

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

    verNode* verList;
    int find(const TypeOfVer& x) const {
        for (int i = 0; i < this->Vers; ++i)
            if (verList[i].ver == x)
                return i;
    }
};

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
        --this->Edges;
    } else {
        while (p->next->end != v)
            p = p->next;
        edgeNode* tpl = p->next;
        p = tpl->next;
        delete tpl;
        --this->Edges;
    }
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