#ifndef _DIVIDE_H
#define _DIVIDE_H

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
T MaxAddSub(T arr[], int from, int to) {
    if (from == to)
        return arr[from];

    int mid = (from + to) / 2;
    T value1 = MaxAddSub(arr, from, mid);
    T value2 = MaxAddSub(arr, mid + 1, to);

    T value_left = arr[mid];
    T new1 = arr[mid];
    for (int left = mid - 1; left >= from; --left) {
        new1 += arr[left];
        value_left = max(value_left, new1);
    }

    T value_right = arr[mid + 1];
    T new2 = arr[mid + 1];
    for (int right = mid + 2; right <= to; ++right) {
        new2 += arr[right];
        value_right = max(value_right, new2);
    }
    T value3 = value_left + value_right;
    return max(value1, max(value2, value3));
}

#endif