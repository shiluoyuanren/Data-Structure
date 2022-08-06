#include <iostream>
#include "DisjointSet.h"
using namespace std;

int main() {
    DisjointSet s(20);
    s.Union(0, 1);
    s.Union(1, 2);
    s.Union(3, 4);
    s.Union(4, 5);
    s.Union(1, 5);
    cout << s.Find(0) << endl;
    cout << s.Find(0) << endl;
    cout << s.Find(5) << endl;

    system("pause");
    return 0;
}