#ifndef _OPENHASHTABLE_H
#define _OPENHASHTABLE_H

#include <iostream>

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

template <class KEY, class OTHER>
class openHashTable : public dynamicSearchTable<KEY, OTHER> {
   private:
    struct node {
        SET<KEY, OTHER> data;
        node* next;

        node(const SET<KEY, OTHER>& x, node* p = NULL) : data(x), next(p) {}
    };

    node** array;
    int size;
    int (*key)(const KEY& value);
    static int defaultKey(const KEY& value) { return value; }

   public:
    openHashTable(int length = 101, int (*f)(const KEY& value) = defaultKey);
    ~openHashTable();
    SET<KEY, OTHER>* find(const KEY& value) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);
};

template <class KEY, class OTHER>
openHashTable<KEY, OTHER>::openHashTable(int length,
                                         int (*f)(const KEY& value)) {
    size = length;
    key = f;
    array = new node*[size];
    for (int i = 0; i < size; i++)
        array[i] = NULL;
}

template <class KEY, class OTHER>
openHashTable<KEY, OTHER>::~openHashTable() {
    for (int i = 0; i < size; ++i) {
        node *cur = array[i], *p;
        while (cur) {
            p = cur->next;
            delete cur;
            cur = p;
        }
    }
    delete[] array;
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* openHashTable<KEY, OTHER>::find(const KEY& value) const {
    int pos = key(value) % size;
    node* cur = array[pos];
    while (cur) {
        if (cur->data.key == value)
            return (SET<KEY, OTHER>*)cur;
        cur = cur->next;
    }
    return NULL;
}

template <class KEY, class OTHER>
void openHashTable<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    int pos = key(x.key) % size;
    array[pos] = new node(x, array[pos]);
}

template <class KEY, class OTHER>
void openHashTable<KEY, OTHER>::remove(const KEY& value) {
    int pos = key(value) % size;
    node* cur = array[pos];
    if (array[pos] == NULL)
        return;  // pos处无元素
    if (array[pos]->next == NULL && array[pos]->data.key == value) {
        delete array[pos];  // pos处只有一个元素且此元素就是待删除元素
        array[pos] = NULL;
        return;
    }
    while (cur) {  //一般情况
        if (cur->next && cur->next->data.key == value) {
            node* tpl = cur->next;
            cur->next = tpl->next;
            delete tpl;
            tpl = NULL;
        }
        cur = cur->next;
    }
}

#endif  // _OPENHASHTABLE_H