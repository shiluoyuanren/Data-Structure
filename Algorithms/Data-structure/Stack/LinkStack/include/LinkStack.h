#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#include <iostream>
using namespace std;

template <class Temp>
class Stack {
   public:
    virtual ~Stack(){};
    virtual void push(const Temp& value) = 0;
    virtual Temp pop() = 0;
    virtual Temp top() const = 0;
    virtual bool isEmpty() const = 0;
};

template <class Temp>
class LinkStack : public Stack<Temp> {
   private:
    struct node {
        Temp data;
        node* next;
        node() : next(NULL) {}
        node(const Temp& value, node* p = NULL) : data(value), next(p) {}
        ~node() {}
    };
    node* head;

   public:
    LinkStack();
    ~LinkStack();
    void push(const Temp& value);
    Temp pop();
    Temp top() const;
    bool isEmpty() const;
};

template <class Temp>
LinkStack<Temp>::LinkStack() {
    head = NULL;
}

template <class Temp>
LinkStack<Temp>::~LinkStack() {
    node *cur = head, *add;
    while (cur) {
        add = cur->next;
        delete cur;
        cur = add;
    }
    head = NULL;
}

template <class Temp>
void LinkStack<Temp>::push(const Temp& value) {
    head = new node(value, head);
}

template <class Temp>
Temp LinkStack<Temp>::pop() {
    Temp tpl_value = head->data;
    node* tpl = head;
    head = head->next;
    delete tpl;
    tpl = NULL;
    return tpl_value;
}

template <class Temp>
Temp LinkStack<Temp>::top() const {
    return head->data;
}

template <class Temp>
bool LinkStack<Temp>::isEmpty() const {
    return head == NULL;
}

#endif