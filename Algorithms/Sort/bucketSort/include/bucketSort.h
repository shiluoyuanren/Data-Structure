#ifndef _BUCKETSORT_H
#define _BUCKETSORT_H

#include <iostream>
#include <vector>
using std::vector;

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class OTHER>
void bucketSort(SET<int, OTHER> a[], int size) {
    int len = maxbit(a, size);
    int i, j, k, m;
    int base = 1;
    vector<SET<int, OTHER>>* bucket[10];
    //每一个口袋都保存一个动态数组
    for (i = 0; i < len; ++i) {
        m = 0;
        for (j = 0; j < 10; ++j) {
            //为每一个指针赋予行使数组的权利
            bucket[j] = new vector<SET<int, OTHER>>;
        }
        //找到每一个元素所在的口袋
        for (j = 0; j < size; ++j) {
            k = (a[j].key / base) % 10;
            bucket[k]->push_back(a[j]);
        }
        //按照口袋的顺序依次倒出
        for (j = 0; j < 10; j++) {
            k = 0;  //每一个口袋内元素数量的计数器
            while (k < bucket[j]->size())
                a[m++] = bucket[j]->at(k++);  //重构a[]数组
        }
        base *= 10;
    }
}

template <class OTHER>  //求最大位数
int maxbit(SET<int, OTHER> a[], int size) {
    int max = 0, len;
    int i;
    for (i = 0; i < size; i++)
        if (a[i].key > max)
            max = a[i].key;
    if (max == 0)
        len = 0;
    else
        for (len = 0; max != 0; ++len)
            max /= 10;
    return len;
}

#endif  // _BUCKETSORT_H