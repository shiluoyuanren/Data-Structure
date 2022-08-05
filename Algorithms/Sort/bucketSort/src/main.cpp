#include <iostream>
#include <string>
#include "bucketSort.h"
using namespace std;

int main() {
    SET<int, string> s[] = {{30, "aaa"}, {7, "bbb"}, {1, "ccc"},
                            {9, "ddd"}, {41, "eee"}, {228, "fff"},
                            {6, "ggg"}, {2, "hhh"}, {15, "iii"}};
    bucketSort(s, 9);
    for (int i = 0; i < 9; ++i)
        cout << s[i].key << " " << s[i].other << endl;

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