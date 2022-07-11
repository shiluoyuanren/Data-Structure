#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <iostream>
#define LE 10
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
class SeqStack : public Stack<Temp> {
   private:
    Temp* data;
    int now_size;
    int max_size;
    void doublespace();

   public:
    SeqStack(int size = LE);
    ~SeqStack();
    void push(const Temp& value);
    Temp pop();
    Temp top() const;
    bool isEmpty() const;
};

template <class Temp>
void SeqStack<Temp>::doublespace() {
    Temp* tpl = data;
    max_size *= 2;
    data = new Temp[max_size];
    for (int i = 0; i < now_size; ++i)
        data[i] = tpl[i];
    delete[] tpl;
    tpl = NULL;
}

template <class Temp>
SeqStack<Temp>::SeqStack(int size) {
    data = new Temp[size];
    now_size = 0;
    max_size = size;
}

template <class Temp>
SeqStack<Temp>::~SeqStack() {
    delete[] data;
}

template <class Temp>
void SeqStack<Temp>::push(const Temp& value) {
    if (now_size == max_size)
        doublespace();
    data[now_size++] = value;
}

template <class Temp>
Temp SeqStack<Temp>::pop() {
    return data[--now_size];
}

template <class Temp>
Temp SeqStack<Temp>::top() const {
    return data[now_size - 1];
}

template <class Temp>
bool SeqStack<Temp>::isEmpty() const {
    return now_size == 0;
}

#endif