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

//对vector用法的一些测试
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int i;
//     vector<int>* q = new vector<int>;
//     !!!此时必须申请一个数组的空间,否则无法用push_back等函数
//     for (i = 0; i < 5; ++i) {
//         q->push_back(i);
//         cout << q->at(i) << " "; at()函数用来访问元素,list不可以用
//     }
//     cout << endl;
//     delete q;   !!!注意此时不是delete[] q

//     system("pause");
//     return 0;
// }