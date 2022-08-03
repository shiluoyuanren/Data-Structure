#ifndef _HEAPSORT_H
#define _HEAPSORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size) {
    int i;
    SET<KEY, OTHER> tpl;

    //创建初始的堆
    for (i = size / 2 - 1; i >= 0; --i)
        percolateDown(a, i, size);

    //执行n-1次deQueue
    for (i = size - 1; i > 0; --i) {
        // delete a[0];
        tpl = a[0];
        a[0] = a[i];
        a[i] = tpl;
        percolateDown(a, 0, i);
    }
}

template <class KEY, class OTHER>
void percolateDown(SET<KEY, OTHER> a[], int hole, int size) {
    SET<KEY, OTHER> tpl = a[hole];
    int max;
    for (; hole * 2 + 1 < size; hole = max) {
        //寻找最大子节点
        max = hole * 2 + 1;
        if (hole * 2 + 2 < size && a[max].key < a[max + 1].key)
            max += 1;

        //开始比较,注意转移的是空节点,相当于只交换一次
        if (tpl.key < a[max].key)
            a[hole] = a[max];
        else
            break;
    }
    a[hole] = tpl;
}

#endif  // _HEAPSORT_H