#ifndef _SEQSEARCH_H
#define _SEQSEARCH_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY& value) {
    data[0].key = value;
    int i;
    for (i = size; data[i].key > value; --i)
        ;
    if (data[i].key == value && i != 0)
        return i;
    else
        return 0;
}

#endif  // _SEQSEARCH_H