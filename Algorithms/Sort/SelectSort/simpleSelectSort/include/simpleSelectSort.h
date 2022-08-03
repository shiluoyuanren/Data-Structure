#ifndef _SIMPLESELECTSORT_H
#define _SIMPLESELECTSORT_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
void simpleSelectSort(SET<KEY, OTHER> a[], int size) {
    int i, j, min;
    SET<KEY, OTHER> tpl;
    for (i = 0; i < size - 1; ++i) {
        min = i;
        for (j = i + 1; j < size; ++j)
            if (a[j].key < a[min].key)
                min = j;
        tpl = a[i];
        a[i] = a[min];
        a[min] = tpl;
    }
}

#endif  // _SIMPLESELECTSORT_H