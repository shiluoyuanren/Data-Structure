#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    l.push_back(2);
    l.push_front(3);
    list<int>::const_iterator p;
    for (p = l.begin(); p != l.end(); p++)
        cout << *p << " ";
    l.pop_back();
    cout << endl << l.size() << endl;
    system("pause");
    return 0;
}