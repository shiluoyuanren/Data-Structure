#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
void bubbleSort(SET<KEY, OTHER> a[], int size) {
    SET<KEY, OTHER> tpl;
    int i, j;
    bool flag = true;  //记录一趟起泡过程中是否发生过交换

    for (i = 1; i < size && flag; ++i) {  // size-1次起泡
        flag = false;
        for (j = 0; j < size - i; ++j)  //第i次起泡
            if (a[j].key > a[j + 1].key) {
                tpl = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tpl;
                flag = true;
            }
    }
}

#endif  // _BUBBLESORT_H