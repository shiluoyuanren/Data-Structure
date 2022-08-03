#ifndef _SHELLSORT_H
#define _SHELLSORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
void shellSort(SET<KEY, OTHER> a[], int size) {
    int i, j;
    int step;  // step为希尔增量
    SET<KEY, OTHER> tpl;
    //对相距step的元素序列采用直接插入排序
    for (step = size / 2; step > 0; step /= 2) {
        for (i = step; i < size; ++i) {
            tpl = a[i];
            for (j = i - step; j >= 0 && tpl.key < a[j].key; j -= step)
                a[j + step] = a[j];
            a[j + step] = tpl;
        }
    }
}

#endif  // _SHELLSORT_H