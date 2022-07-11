#include <iostream>
#include "LinkQueue.h"
using namespace std;

int main() {
    LinkQueue<int>* lqu = new LinkQueue<int>;
    lqu->enqueue(1);
    lqu->enqueue(2);
    lqu->enqueue(3);
    lqu->enqueue(4);
    lqu->enqueue(5);
    cout << lqu->gethead() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->isEmpty() << endl;
    cout << lqu->gethead() << endl;
    system("pause");
    return 0;
}