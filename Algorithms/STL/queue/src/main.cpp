#include <deque>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main() {
    queue<int, list<int>> q1;
    for (int i = 0; i < 10; i++)
        q1.push(i);
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    queue<int> q2;  // queue<int,deque<int>>
    for (int i = 0; i < 10; i++)
        q2.push(i);
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}