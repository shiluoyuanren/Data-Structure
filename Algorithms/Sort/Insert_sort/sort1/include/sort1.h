#ifndef _SORT1_H
#define _SORT1_H

#include <iostream>
using namespace std;

template <typename Temp>
void Insert_Sort(Temp A[], int n) {
    int i, j;
    Temp key;
    int Alength = n;
    for (j = 1; j < Alength; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

#endif