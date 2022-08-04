#ifndef _MERGESORT_H
#define _MERGESORT_H

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

//归并函数的包裹函数
template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int size) {
    mergeSort(a, 0, size - 1);
}

template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int left, int right) {
    int mid = (left + right) / 2;
    if (left >= right)
        return;
    mergeSort(a, left, mid);       //排序左一半
    mergeSort(a, mid + 1, right);  //排序右一半
    merge(a, left, mid, right);    //排序后归并
}

template <class KEY, class OTHER>
void merge(SET<KEY, OTHER> a[], int left, int mid, int right) {
    // tpl为临时数组
    SET<KEY, OTHER>* tpl = new SET<KEY, OTHER>[right - left + 1];
    int i, j, k;
    i = left;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= right) {
        if (a[i].key < a[j].key)
            tpl[k++] = a[i++];
        else
            tpl[k++] = a[j++];
    }

    while (i <= mid)
        tpl[k++] = a[i++];
    while (j <= right)
        tpl[k++] = a[j++];

    for (i = left, k = 0; i <= right;)
        a[i++] = tpl[k++];
    delete[] tpl;
}

#endif  // _MERGESORT_H