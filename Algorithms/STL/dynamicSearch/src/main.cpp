// STL中的动态查找表称为关联容器,最基本的是set和map
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    // set是一个排序后的容器,元素不允许重复,仅能包含关键字一个字段
    set<int> s;
    int a[21] = {0, 4,  7, 10, 2, 9, 8,  12, 13, 17,
                 3, 18, 1, 15, 5, 6, 11, 20, 19};
    set<int>::const_iterator p;
    //关联容器也是容器,也有迭代器
    for (int i = 0; i < 21; ++i)
        s.insert(a[i]);
    cout << "the content of s: ";
    for (p = s.begin(); p != s.end(); p++)
        cout << *p << " ";

    cout << "\nfind(18):" << *(s.find(18)) << endl;

    s.erase(17);
    cout << "after erase(17),the content of s: ";
    for (p = s.begin(); p != s.end(); p++)
        cout << *p << " ";
    cout << endl << endl;

    // map<关键字,值>,类型为类模板pair(必须显示指出),关键字必须唯一,值不需要
    map<string, string> m;
    string name[6] = {"钱一", "孙二", "张三", "李四", "王五", "赵六"};
    string addr[6] = {"上海", "南京", "杭州", "南京", "南京", "杭州"};
    map<string, string>::const_iterator q;
    for (int i = 0; i < 6; i++)
        m.insert(pair<string, string>(name[i], addr[i]));
    cout << "the content of m:" << endl;
    for (q = m.begin(); q != m.end(); ++q)
        cout << q->first << " " << q->second << endl;

    q = m.find("张三");
    cout << "\nfind(\"张三\"): " << q->first << " " << q->second << endl;

    m.erase("张三");
    cout << "after erase(\"张三\"),the content of m:" << endl;
    for (q = m.begin(); q != m.end(); ++q)
        cout << q->first << " " << q->second << endl;
    cout << endl;

    system("pause");
    return 0;
}