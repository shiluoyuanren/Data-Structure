#include <iostream>
#include "SeqStack.h"
using namespace std;

int main() {
    SeqStack<int>* sqk = new SeqStack<int>;
    sqk->push(12);
    cout << sqk->isEmpty() << endl;
    cout << sqk->pop() << endl;
    sqk->push(1);
    sqk->push(2);
    sqk->push(3);
    cout << sqk->pop() << endl;
    cout << sqk->pop() << endl;
    cout << sqk->top() << endl;
    // cout << sqk->isEmpty() << endl;
    system("pause");
    return 0;
}