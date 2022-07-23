#ifndef _BINARYSEARCH_H
#define _BINARYSEARCH_H

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY& value) {
    int i;
    int low, mid, high;
    low = 1, high = size;
    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid].key == value)
            return mid;
        else if (data[mid].key < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

#endif  // _BINARYSEARCH_H