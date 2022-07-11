#ifndef _SORT2_H
#define _SORT2_H

#include <iostream>
using namespace std;
#define oo 10000

template <typename Temp>
void Merge(Temp A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    int i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    L[n1] = oo;
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    R[n2] = oo;
    i = j = k = 0;
    while (k < r - p + 1) {
        if (L[i] <= R[j]) {
            A[p + k] = L[i];
            i++;
        } else {
            A[p + k] = R[j];
            j++;
        }
        k++;
    }
}

template <typename Temp>
void Merge_Sort(Temp A[], int p, int r) {
    int q = (p + r) / 2;
    if (p >= r)
        return;
    Merge_Sort(A, p, q);
    Merge_Sort(A, q + 1, r);
    Merge(A, p, q, r);
}

#endif