#ifndef _SORT1_H
#define _SORT1_H

#include <iostream>
using namespace std;

template <typename Temp>
void Merge(Temp A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[p + k] = L[i];
            i++;
        } else {
            A[p + k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[p + k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[p + k] = R[j];
        j++;
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