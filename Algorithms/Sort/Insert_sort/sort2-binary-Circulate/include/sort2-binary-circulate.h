#ifndef _SORT2_H
#define _SORT2_H

#include <iostream>
using namespace std;

template <typename T>
void insert_sort(T arr[], int n) {
    int low, high, place;
    T temp;
    for (int i = 1; i < n; ++i) {
        low = 0, high = i - 1;
        temp = arr[i];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        place = low;

        for (int j = i - 1; j >= place; --j) {
            arr[j + 1] = arr[j];
        }
        arr[place] = temp;
    }
}

#endif