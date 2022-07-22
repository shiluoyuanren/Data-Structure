#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <iostream>

template <class Temp>
class Queue {
   public:
    virtual ~Queue() {}
    virtual void enQueue(const Temp& value) = 0;
    virtual Temp deQueue() = 0;
    virtual Temp getHead() const = 0;
    virtual bool isEmpty() const = 0;
};

template <class Temp>
class priorityQueue : public Queue<Temp> {
   public:
    priorityQueue(int capacity = 100);
    priorityQueue(const Temp* data, int size);
    ~priorityQueue();
    bool isEmpty() const;
    void enQueue(const Temp& value);
    Temp deQueue();
    Temp getHead() const;

   private:
    int length;
    Temp* elem;
    int volume;

    void doublespace();
    void buildHeap();
    void percolateDown(int hole);
};

template <class Temp>
priorityQueue<Temp>::priorityQueue(int capacity) {
    elem = new Temp[capacity];
    length = 0;
    volume = capacity;
}

template <class Temp>
priorityQueue<Temp>::priorityQueue(const Temp* data, int size)
    : length(size), volume(size + 10) {
    elem = new Temp[volume];
    for (int i = 1; i <= length; ++i)
        elem[i] = data[i - 1];
    buildHeap();
}

template <class Temp>
priorityQueue<Temp>::~priorityQueue() {
    delete[] elem;
}

template <class Temp>
bool priorityQueue<Temp>::isEmpty() const {
    return length == 0;
}

template <class Temp>
void priorityQueue<Temp>::enQueue(const Temp& value) {
    if (length == volume - 1)
        doublespace();
    int hole = ++length;  //向上过滤
    for (; value < elem[hole / 2] && hole > 1; hole /= 2)
        elem[hole] = elem[hole / 2];
    elem[hole] = value;
}

template <class Temp>
Temp priorityQueue<Temp>::deQueue() {
    Temp minitem;
    minitem = elem[1];
    elem[1] = elem[length--];
    percolateDown(1);
    return minitem;
}

template <class Temp>
Temp priorityQueue<Temp>::getHead() const {
    return elem[1];
}

template <class Temp>
void priorityQueue<Temp>::doublespace() {
    Temp* tpl = elem;
    volume *= 2;
    elem = new Temp[volume];
    for (int i = 1; i <= length; ++i)
        elem[i] = tpl[i];
    delete[] tpl;
}

template <class Temp>
void priorityQueue<Temp>::buildHeap() {
    for (int i = length / 2; i > 0; i--)
        percolateDown(i);
}

template <class Temp>
void priorityQueue<Temp>::percolateDown(int hole) {
    int child;
    Temp tpl = elem[hole];  //向下过滤
    for (; hole * 2 <= length; hole = child) {
        child = hole * 2;
        if (child < length && elem[child + 1] < elem[child])
            child++;
        if (tpl > elem[child])
            elem[hole] = elem[child];
        else
            break;
    }
    elem[hole] = tpl;
}

#endif  // _PRIORITYQUEUE_H