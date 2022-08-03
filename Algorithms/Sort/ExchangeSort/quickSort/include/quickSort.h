#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

//快速排序的包裹函数
template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int size) {
    quickSort(a, 0, size - 1);
}

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int low, int high) {
    int mid;
    if (low >= high)  //待分段的元素只有1个或0个,递归终止
        return;
    mid = divide(a, low, high);
    quickSort(a, low, mid - 1);   //排序左一半
    quickSort(a, mid + 1, high);  //排序右一半
}

//划分函数
template <class KEY, class OTHER>
int divide(SET<KEY, OTHER> a[], int low, int high) {
    SET<KEY, OTHER> k = a[low];
    while (low < high) {
        while (a[high].key > k.key && low < high)
            high--;
        if (low < high)  //注意此时要判断low与high是否重叠
            a[low++] = a[high];
        while (a[low].key <= k.key && low < high)
            low++;
        if (low < high)
            a[high--] = a[low];
    }
    a[low] = k;
    return low;
}

#endif  //_QUICKSORT_H