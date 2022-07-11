#ifndef _DOUBLELINKLIST_H
#define _DOUBLELINKLIST_H

#include <iostream>
using namespace std;

template <class Temp>
class List {
   public:
    virtual ~List(){};
    virtual void insert(int index, const Temp& value) = 0;
    virtual void remove(const Temp& value) = 0;
    virtual void travel() const = 0;
    virtual void clear() = 0;
    virtual bool is_empty() const = 0;
    virtual Temp visit(int index) const = 0;
    virtual int search(const Temp& value) const = 0;
    virtual int size() const = 0;
};

template <class Temp>
class DoublelinkList : public List<Temp> {
   private:
    struct node {
        Temp data;
        node* next;
        node* prev;
        node() : next(NULL), prev(NULL) {}
        node(const Temp& value, node* p = NULL, node* q = NULL)
            : data(value), next(p), prev(q) {}
        ~node() {}
    };
    int now_size;
    node* head;
    node* address(int index) const;

   public:
    DoublelinkList();
    ~DoublelinkList();
    void insert(int index, const Temp& value);
    void remove(const Temp& value);
    void travel() const;
    void clear();
    bool is_empty() const;
    Temp visit(int index) const;
    int search(const Temp& value) const;
    int size() const;
};

template <class Temp>
class DoublelinkList<Temp>::node* DoublelinkList<Temp>::address(
    int index) const {
    node* cur = head;
    while (index-- > 0)
        cur = cur->next;
    return cur;
}

template <class Temp>
DoublelinkList<Temp>::DoublelinkList() {
    now_size = 0;
    head = NULL;
}

template <class Temp>
DoublelinkList<Temp>::~DoublelinkList() {
    clear();
}

template <class Temp>
void DoublelinkList<Temp>::insert(int index, const Temp& value) {
    if (index < 0)
        index = 0;
    if (index > now_size - 1 && now_size) {
        index = now_size - 1;
        node* cur = address(index);
        node* add = new node(value, NULL, cur);
        cur->next = add;
    } else {
        if (!head)
            head = new node(value);
        else {
            node* cur = address(index);
            if (!index) {
                cur->prev = new node(value, cur);
                head = cur->prev;
            } else {
                node* add = new node(value, cur, cur->prev);
                cur->prev->next = add;
                cur->prev = add;
            }
        }
    }
    now_size++;
}

template <class Temp>
void DoublelinkList<Temp>::remove(const Temp& value) {
    node* cur = head;
    while (cur) {
        if (cur->data == value) {
            if (now_size == 1)
                head = NULL;
            else {
                if (!cur->next)
                    cur->prev->next = NULL;
                else if (!cur->prev) {
                    head = cur->next;
                    cur->next->prev = NULL;
                } else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            delete cur;
            cur = NULL;
            now_size--;
            return;
        }
        cur = cur->next;
    }
}

template <class Temp>
void DoublelinkList<Temp>::travel() const {
    node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

template <class Temp>
void DoublelinkList<Temp>::clear() {
    node *p = head, *q;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    now_size = 0;
    head = NULL;
}

template <class Temp>
bool DoublelinkList<Temp>::is_empty() const {
    return now_size == 0;
}

template <class Temp>
Temp DoublelinkList<Temp>::visit(int index) const {
    node* cur = address(index);
    return cur->data;
}

template <class Temp>
int DoublelinkList<Temp>::search(const Temp& value) const {
    node* cur = head;
    int count = 0;
    while (cur) {
        if (cur->data == value)
            return count;
        count++;
        cur = cur->next;
    }
    return -1;
}

template <class Temp>
int DoublelinkList<Temp>::size() const {
    return now_size;
}

#endif