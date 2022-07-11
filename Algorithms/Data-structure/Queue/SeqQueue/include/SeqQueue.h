#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H

#include <iostream>
#define LE 10
using namespace std;

template <class Temp>
class Queue {
   public:
    virtual ~Queue(){};
    virtual void enqueue(const Temp& value) = 0;
    virtual Temp dequeue() = 0;
    virtual bool isEmpty() const = 0;
    virtual Temp gethead() const = 0;
};

template <class Temp>
class SeqQueue : public Queue<Temp> {
   private:
    Temp* data;
    int front;
    int rear;
    int maxsize;
    void doublespace();

   public:
    SeqQueue(int size = LE);
    ~SeqQueue();
    void enqueue(const Temp& value);
    Temp dequeue();
    Temp gethead() const;
    bool isEmpty() const;
};

template <class Temp>
void SeqQueue<Temp>::doublespace() {
    Temp* tpl = data;
    data = new Temp[maxsize * 2];
    for (int i = 0; i < maxsize; i++)
        data[i] = tpl[(front + i) % maxsize];
    delete[] tpl;
    front = 0;
    rear = maxsize - 1;
    maxsize *= 2;
}

template <class Temp>
SeqQueue<Temp>::SeqQueue(int size) {
    data = new Temp[size];
    maxsize = size;
    front = 0;
    rear = -1;
}

template <class Temp>
SeqQueue<Temp>::~SeqQueue() {
    delete[] data;
}

template <class Temp>
void SeqQueue<Temp>::enqueue(const Temp& value) {
    if (front == (rear + 1) % maxsize && rear != -1)
        doublespace();
    rear = (rear + 1) % maxsize;
    data[rear] = value;
}

template <class Temp>
Temp SeqQueue<Temp>::dequeue() {
    int tpl = front;
    front = (front + 1) % maxsize;
    return data[tpl];
}

template <class Temp>
Temp SeqQueue<Temp>::gethead() const {
    return data[front];
}

template <class Temp>
bool SeqQueue<Temp>::isEmpty() const {
    return rear == -1;
}

#endif