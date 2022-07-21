#ifndef _HFTREE_H
#define _HFTREE_H

#include <iostream>
#include <string>

template <class Temp>
class hfTree {
    struct node {
        Temp data;
        int weight;
        int parent, left, right;
        ~node() {}
    };

    node* elem;
    int length;

   public:
    struct hfCode {
        Temp data;
        std::string code;
    };

    hfTree(const Temp* x, const int* w, int size);
    void getCode(hfCode result[]);
    ~hfTree() { delete[] elem; };
};

template <class Temp>
hfTree<Temp>::hfTree(const Temp* x, const int* w, int size) {
    length = 2 * size;
    elem = new node[length];
    int i;

    for (i = size; i < length; ++i) {
        elem[i].data = x[i - size];
        elem[i].weight = w[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }

    for (i = size - 1; i > 0; i--) {
        int min1, min2;  // min1最小权重,min2次小权重
        int x, y = 0;    // x最小下标,y次小下标
        min1 = min2 = 10000;
        for (int j = i + 1; j < length; j++) {
            if (elem[j].parent == 0)
                if (elem[j].weight < min1) {
                    min2 = min1;
                    min1 = elem[j].weight;
                    y = x;
                    x = j;
                } else if (elem[j].weight < min2) {
                    min2 = elem[j].weight;
                    y = j;
                }
        }
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = elem[y].parent = i;
        elem[i].weight = min1 + min2;
    }
}

template <class Temp>
void hfTree<Temp>::getCode(hfCode result[]) {
    int p, s;
    int i;
    int size = length / 2;
    for (i = size; i < length; ++i) {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while (p) {
            if (elem[p].left == s)
                result[i - size].code = '0' + result[i - size].code;
            else
                result[i - size].code = '1' + result[i - size].code;
            s = p;
            p = elem[s].parent;
        }
    }
}

#endif /* _HFTREE_H */