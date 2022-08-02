#ifndef _SIMPLEINSERTSORT_H
#define _SIMPLEINSERTSORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
void simpleInsertSort(SET<KEY, OTHER> a[], int size) {
    int i, j;
    SET<KEY, OTHER> tpl;
    for (i = 1; i < size; ++i) {
        tpl = a[i];
        for (j = i - 1; j >= 0 && tpl.key < a[j].key; --j)
            a[j + 1] = a[j];
        a[j + 1] = tpl;
    }
}

#endif  // _SIMPLEINSERTSORT_H