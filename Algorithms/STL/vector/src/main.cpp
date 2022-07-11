#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << v.size() << endl;  // size为现有元素个数
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout << v.capacity() << endl;  // capacity为此时数组的容量,二倍扩充
    vector<int>::iterator p;
    // const_iterator为修饰,vector<int>::为域名,所有vector迭代器一样
    for (p = v.begin(); p != v.end(); p++) {
        (*p)++;
        cout << *p << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}