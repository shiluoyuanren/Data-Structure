#ifndef _BINARY_H
#define _BINARY_H

#include <iostream>
using namespace std;

template <typename Temp>
int Binary_Search(Temp A[], const Temp& index, int p, int r) {
    int q = (p + r) / 2;
    if (p > r)
        return -1;
    if (A[q] == index)
        return q;
    else if (A[q] > index)
        return Binary_Search(A, index, p, q - 1);
    else
        return Binary_Search(A, index, q + 1, r);
}

#endif