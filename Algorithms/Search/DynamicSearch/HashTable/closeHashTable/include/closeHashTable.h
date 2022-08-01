#ifndef _CLOSEHASHTABLE_H
#define _CLOSEHASHTABLE_H

#include <iostream>

//基于线性探测法的闭散列表
template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class dynamicSearchTable {
   public:
    virtual ~dynamicSearchTable() {}
    virtual SET<KEY, OTHER>* find(const KEY& value) const = 0;
    virtual void insert(const SET<KEY, OTHER>& x) = 0;
    virtual void remove(const KEY& value) = 0;
};

//除留余数法
template <class KEY, class OTHER>
class closeHashTable : public dynamicSearchTable<KEY, OTHER> {
   private:
    struct node {
        SET<KEY, OTHER> data;
        int state;  //节点的状态 0--empty  1--active  2--deleted

        node() : state(0) {}
    };

    node* array;
    int size;  //数组容量
    //此处key为一个指针
    int (*key)(const KEY& x);  //函数指针,指向一个可转换key的函数
    static int defaultKey(const int& value) { return value; }  //默认转换函数

   public:
    closeHashTable(int length = 101, int (*f)(const KEY& value) = defaultKey);
    ~closeHashTable() { delete[] array; }
    SET<KEY, OTHER>* find(const KEY& value) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);
};

template <class KEY, class OTHER>
closeHashTable<KEY, OTHER>::closeHashTable(int length,
                                           int (*f)(const KEY& value)) {
    size = length;
    array = new node[size];
    key = f;
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* closeHashTable<KEY, OTHER>::find(const KEY& value) const {
    int initPos, pos;
    // initPos为初始位置,pos为实际位置
    initPos = pos = key(value) % size;
    do {
        if (array[pos].state == 0)
            return NULL;
        if (array[pos].state == 1 && array[pos].data.key == value)
            return (SET<KEY, OTHER>*)&array[pos];
        pos = (pos + 1) % size;
    } while (pos != initPos);
    return NULL;
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    int initPos, pos;
    initPos = pos = key(x.key) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::remove(const KEY& value) {
    int initPos, pos;
    initPos = pos = key(value) % size;
    do {
        if (array[pos].state == 0)
            return;
        if (array[pos].state == 1 && array[pos].data.key == value) {
            array[pos].state = 2;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

#endif  // _CLOSEHASHTABLE_H