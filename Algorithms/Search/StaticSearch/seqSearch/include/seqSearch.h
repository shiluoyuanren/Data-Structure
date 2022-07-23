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
    for (i = size; data[i].key != value; --i)
        ;
    return i;
}

#endif  // _SEQSEARCH_H