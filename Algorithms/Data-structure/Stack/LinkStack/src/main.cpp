#include <iostream>
#include "LinkStack.h"
using namespace std;

int main() {
    LinkStack<int>* lsk = new LinkStack<int>;
    lsk->push(1);
    cout << lsk->top() << endl;
    cout << lsk->isEmpty() << endl;
    lsk->push(2);
    lsk->push(3);
    lsk->push(4);
    cout << lsk->pop() << endl;
    system("pause");
    return 0;
}