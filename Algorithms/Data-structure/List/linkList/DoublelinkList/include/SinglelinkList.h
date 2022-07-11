#ifndef _SINGLELINKLIST_H
#define _SINGLELINKLIST_H

#include <iostream>
using namespace std;

template <class Temp>
class List {
   public:
    virtual ~List(){};
    virtual void insert(int index, const Temp& value) = 0;
    virtual void remove(const Temp& value) = 0;
    virtual void clear() = 0;
    virtual void travel() const = 0;
    virtual Temp visit(int index) const = 0;
    virtual bool is_empty() const = 0;
    virtual int size() const = 0;
    virtual int search(const Temp& value) const = 0;
};

template <class Temp>
class SinglelinkList : public List<Temp> {
   private:
    struct node {
        Temp data;
        node* next;
        node() : next(NULL) {}
        node(const Temp& value, node* p = NULL) : data(value), next(p) {}
        ~node() {}
    };
    node* head;
    int now_size;

   public:
    SinglelinkList();
    ~SinglelinkList();
    void insert(int index, const Temp& value);
    void remove(const Temp& value);
    void clear();
    void travel() const;
    Temp visit(int index) const;
    bool is_empty() const;
    int size() const;
    int search(const Temp& value) const;
};

template <class Temp>
SinglelinkList<Temp>::SinglelinkList() {
    head = NULL;
    now_size = 0;
}

template <class Temp>
SinglelinkList<Temp>::~SinglelinkList() {
    clear();
}

template <class Temp>
void SinglelinkList<Temp>::insert(int index, const Temp& value) {
    try {
        node* p = new node(value);
        node* cur = head;
        int count;
        if (!cur)
            head = p;
        else {
            if (index <= 0) {
                p->next = head;
                head = p;
            } else {
                for (count = 0; count < min(index, now_size - 1); count++)
                    cur = cur->next;
                p->next = cur->next;
                cur->next = p;
            }
        }
        now_size++;
    } catch (const bad_alloc& e) {
        cerr << "Error!" << endl;
        exit(1);
    }
}

template <class Temp>
void SinglelinkList<Temp>::remove(const Temp& value) {
    node* cur = head;
    if (!cur)
        return;
    else {
        if (cur->data == value) {
            node* tep = head;
            head = head->next;
            delete tep;
            tep = NULL;
        } else {
            while (cur->next && cur->next->data != value)
                cur = cur->next;
            if (!cur->next)
                return;
            node* tep = cur->next;
            cur->next = cur->next->next;
            delete tep;
            tep = NULL;
        }
    }
    now_size--;
}

template <class Temp>
void SinglelinkList<Temp>::clear() {
    node *cur = head, *sub;
    head = NULL;
    while (cur) {
        sub = cur->next;
        delete cur;
        cur = sub;
    }
    now_size = 0;
}

template <class Temp>
void SinglelinkList<Temp>::travel() const {
    node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

template <class Temp>
Temp SinglelinkList<Temp>::visit(int index) const {
    int count;
    node* cur = head;
    if (index <= 0)
        return head->data;
    else {
        for (count = 0; count < min(index, now_size - 1); count++)
            cur = cur->next;
        return cur->data;
    }
}

template <class Temp>
bool SinglelinkList<Temp>::is_empty() const {
    return head == NULL;
}

template <class Temp>
int SinglelinkList<Temp>::size() const {
    return now_size;
}

template <class Temp>
int SinglelinkList<Temp>::search(const Temp& value) const {
    int count = 0;
    node* cur = head;
    while (cur) {
        if (cur->data == value)
            return count;
        count++;
        cur = cur->next;
    }
    return -1;
}

#endif