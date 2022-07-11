#include <deque>  //优化模型
#include <iostream>
#include <list>  //双链表类型
#include <stack>
#include <vector>  //顺序表类型
using namespace std;

int main() {
    stack<int, deque<int>> s1;  //第二个参数为容器类型,默认为deque
    stack<int, list<int>> s2;   //第二个参数需要标注头文件
    stack<int, vector<int>> s3;
    stack<int> s4;
    int i;
    for (i = 0; i < 10; i++)
        s1.push(i);
    while (!s1.empty()) {  // stack为容器适配器,只有容器才有迭代器
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    for (i = 0; i < 10; i++)
        s2.push(i);
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    for (i = 0; i < 10; i++)
        s3.push(i);
    while (!s3.empty()) {
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl;

    for (i = 0; i < 10; i++)
        s4.push(i);
    while (!s4.empty()) {
        cout << s4.top() << " ";
        s4.pop();
    }
    cout << endl;

    system("pause");
    return 0;
}