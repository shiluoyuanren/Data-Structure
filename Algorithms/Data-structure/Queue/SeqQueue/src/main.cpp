#include <iostream>
#include "SeqQueue.h"
using namespace std;

int main() {
    SeqQueue<int>* squ = new SeqQueue<int>(2);
    squ->enqueue(1);
    squ->enqueue(2);
    squ->enqueue(3);
    squ->enqueue(4);
    squ->enqueue(5);
    cout << squ->gethead() << endl;
    cout << squ->dequeue() << endl;
    cout << squ->dequeue() << endl;
    cout << squ->dequeue() << endl;
    cout << squ->gethead() << endl;
    cout << squ->isEmpty() << endl;
    system("pause");
    return 0;
}