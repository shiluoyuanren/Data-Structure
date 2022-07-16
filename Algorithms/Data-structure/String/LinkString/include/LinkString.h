#ifndef _LINKSTRING_H
#define _LINKSTRING_H

#include <iostream>
// using namespace std;

namespace Ur {
class LinkString {
    friend LinkString operator+(const LinkString& s1, const LinkString& s2);
    friend bool operator==(const LinkString& s1, const LinkString& s2);
    friend bool operator!=(const LinkString& s1, const LinkString& s2);
    friend bool operator>(const LinkString& s1, const LinkString& s2);
    friend bool operator>=(const LinkString& s1, const LinkString& s2);
    friend bool operator<(const LinkString& s1, const LinkString& s2);
    friend bool operator<=(const LinkString& s1, const LinkString& s2);
    friend std::ostream& operator<<(std::ostream& os, const Ur::LinkString& s);

    struct node {
        char* data;
        node* next;
        int size;  //节点中的字符数
        node(int le = 1, node* p = NULL) {
            data = new char[le];
            size = 0;
            next = p;
        }
        ~node() {}
    };

    node* head;    //头节点
    int len;       //字符串的长度
    int nodesize;  //节点的存贮容量!=节点数

    void clear();
    void findPos(int start, int& pos, node*& p) const;
    void split(node* p, int pos);
    void merge(node* p);

   public:
    LinkString(const char* s = "");
    LinkString(const LinkString& other);
    ~LinkString();
    int length() const;
    LinkString& operator=(const LinkString& other);
    LinkString subStr(int start, int num) const;
    void insert(int start, const LinkString& s);
    void remove(int start, int num);
};

LinkString operator+(const LinkString& s1, const LinkString& s2);

bool operator==(const LinkString& s1, const LinkString& s2);

bool operator!=(const LinkString& s1, const LinkString& s2);

bool operator>(const LinkString& s1, const LinkString& s2);

bool operator>=(const LinkString& s1, const LinkString& s2);

bool operator<(const LinkString& s1, const LinkString& s2);

bool operator<=(const LinkString& s1, const LinkString& s2);

std::ostream& operator<<(std::ostream& os, const LinkString& s);

}  // namespace Ur

#endif