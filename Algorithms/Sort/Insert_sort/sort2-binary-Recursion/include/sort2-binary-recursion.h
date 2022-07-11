#ifndef _SORT2_H
#define _SORT2_H

#include <iostream>
using namespace std;

template <typename Temp>
int Binary_Search(Temp A[], const Temp& index, int p, int r) {
    int q = (p + r) / 2;
    if (p > r)
        return p;
    if (A[q] >= index)
        return Binary_Search(A, index, p, q - 1);
    else
        return Binary_Search(A, index, q + 1, r);
}

template <typename Temp>
void Insert_Sort(Temp A[], int p, int r) {
    int Alength = r - p + 1;
    int i, j, k;
    Temp key;
    for (j = 1; j < Alength; j++) {
        i = j - 1;
        key = A[j];
        k = Binary_Search(A, key, 0, i);
        for (i = j - 1; i >= k; i--)
            A[i + 1] = A[i];
        A[k] = key;
    }
}

#endif