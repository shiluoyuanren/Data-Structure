#ifndef _VIOLENT_H
#define _VIOLENT_H

#include <iostream>
using namespace std;

template <typename T>
T MaxAddSub(T array[], int n) {
    int i, j;
    T max_sum = array[0];
    for (i = 0; i < n; i++) {
        T sum = array[i];
        T max_sum_every = sum;
        for (j = i + 1; j < n; j++) {
            sum += array[j];
            if (sum >= max_sum_every)
                max_sum_every = sum;
        }
        if (max_sum_every > max_sum)
            max_sum = max_sum_every;
    }
    return max_sum;
}

#endif