#include <algorithm>
#include <functional>  //必须包含的库
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//用户自定义数据类型
struct node {
    int key;
    string str;
};

bool operator<(const node& s1, const node& s2) {
    return s1.key < s2.key;
}
bool operator>(const node& s1, const node& s2) {
    return s1.key > s2.key;
}

ostream& operator<<(ostream& os, const node& s) {
    os << "(" << s.key << "," << s.str << ") ";
    return os;
}

int main() {
    int i;
    int a[11] = {0, 3, 1, 11, 7, 5, 9, 34, 54, 89, 66};
    vector<int> va(a, a + 11);  //用指针进行初始化

    sort(va.begin(), va.end());
    for (i = 0; i < va.size(); ++i)
        cout << va[i] << " ";
    cout << endl;
    sort(va.begin(), va.end(), greater<int>());
    for (i = 0; i < va.size(); ++i)
        cout << va[i] << " ";
    cout << endl;

    node b[12] = {{5, "aaa"},  {2, "bbb"},  {33, "ccc"}, {5, "ddd"},
                  {33, "eee"}, {6, "fff"},  {5, "ggg"},  {33, "hhh"},
                  {5, "jjj"},  {33, "kkk"}, {6, "lll"},  {5, "ppp"}};
    vector<node> vb(b, b + 12);
    sort(vb.begin(), vb.end());
    for (i = 0; i < vb.size(); ++i)
        cout << vb[i] << " ";
    cout << endl;

    // stable_sort提供稳定排序,sort不能保证稳定性
    stable_sort(vb.begin(), vb.end(), greater<node>());
    for (i = 0; i < vb.size(); ++i)
        cout << vb[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}