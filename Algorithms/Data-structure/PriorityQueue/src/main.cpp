#include <iostream>
#include "priorityQueue.h"

int main() {
    priorityQueue<int> q(2);
    std::cout << q.isEmpty() << std::endl;
    q.enQueue(2);
    q.enQueue(1);
    q.enQueue(3);
    q.enQueue(5);
    q.enQueue(4);
    std::cout << q.isEmpty() << std::endl;
    q.deQueue();
    q.deQueue();
    std::cout << q.getHead() << std::endl;

    int arr[] = {10, 15, 13, 33, 16, 5, 7};
    priorityQueue<int> q1(arr, 7);
    q1.deQueue();
    std::cout << q1.getHead() << std::endl;

    system("pause");
    return 0;
}