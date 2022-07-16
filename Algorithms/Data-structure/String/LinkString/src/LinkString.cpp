#include "LinkString.h"
#include <algorithm>
#include <iostream>
#include "math.h"

using namespace Ur;

void LinkString::clear() {
    node *p = head, *q;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
}

void LinkString::findPos(int start, int& pos, node*& p) const {
    int count = 0;  //已遍历的字符个数
    p = head;
    while (count < start) {
        if (count + p->size < start) {  // start不在当前节点
            count += p->size;
            p = p->next;
        } else {  // start在当前节点
            pos = start - count;
            return;
        }
    }
}

void LinkString::split(node* p, int pos) {
    node* add = new node(nodesize, p->next);
    p->next = add;
    int i = 0;
    while (pos < p->size)
        add->data[i++] = p->data[pos++];
    add->size = i;
    p->size = pos - i;
}

void LinkString::merge(node* p) {
    node* nextp = p->next;
    if (p->size + nextp->size <= nodesize) {
        for (int i = 0; i < nextp->size; i++)
            p->data[p->size++] = nextp->data[i];
        p->next = nextp->next;
        delete nextp;
    }
}

LinkString::LinkString(const char* s) {
    for (len = 0; s[len] != '\0'; ++len)
        ;
    nodesize = sqrt(len);
    node* p = head = NULL;
    int i = 0;
    while (i < len) {
        if (!p)
            p = head = new node(nodesize);
        else
            p = p->next = new node(nodesize);
        //要注意p->size的范围,可以不等于nodesize
        for (; p->size < nodesize && i < len; ++p->size, ++i)
            p->data[p->size] = s[i];
    }
}

LinkString::LinkString(const LinkString& other) {
    len = other.len;
    nodesize = other.nodesize;
    node* p = head = NULL;
    node* oth = other.head;
    while (oth) {
        if (!p)
            p = head = new node(nodesize);
        else
            p = p->next = new node(nodesize);
        for (; p->size < oth->size; ++p->size)
            p->data[p->size] = oth->data[p->size];
        oth = oth->next;
    }
}

LinkString::~LinkString() {
    clear();
}

int Ur::LinkString::length() const {
    return len;
}

LinkString& LinkString::operator=(const LinkString& other) {
    if (this == &other)
        return *this;
    clear();
    len = other.len;
    nodesize = other.nodesize;
    node* p = head = NULL;
    node* oth = other.head;
    while (oth) {
        if (!p)
            p = head = new node(nodesize);
        else
            p = p->next = new node(nodesize);
        for (; p->size < oth->size; ++p->size)
            p->data[p->size] = oth->data[p->size];
        oth = oth->next;
    }
    return *this;
}

LinkString LinkString::subStr(int start, int num) const {
    LinkString tpl;  //存放取出的子串
    int pos = 0;
    node *p, *add = tpl.head;

    if (start < 0 || start >= len)
        return tpl;  //返回空串

    num = std::min(num, len - start);
    tpl.len = num;
    tpl.nodesize = sqrt(num);

    findPos(start, pos, p);

    int i = 0;
    while (i < tpl.len) {  //复制字串
        if (!add)
            add = tpl.head = new node(tpl.nodesize);
        else
            add = add->next = new node(tpl.nodesize);
        for (; add->size < tpl.nodesize && i < tpl.len; ++i) {
            if (pos == p->size) {
                p = p->next;
                pos = 0;
            }
            add->data[add->size++] = p->data[pos++];
        }
    }

    return tpl;
}

void LinkString::insert(int start, const LinkString& s) {
    node *p, *nextp, *tpl = s.head;
    int pos = 0;
    if (start < 0 || start >= len)
        return;
    findPos(start, pos, p);
    split(p, pos);
    nextp = p->next;
    int i = 0, count = 0;
    while (i < s.len) {
        p = p->next = new node(nodesize);
        for (; p->size < nodesize && i < s.len; ++p->size) {
            if (count == tpl->size) {
                tpl = tpl->next;
                count = 0;
            }
            p->data[p->size] = tpl->data[count++];
            i++;
        }
    }
    len += s.len;
    p->next = nextp;
    merge(p);
}

void LinkString::remove(int start, int num) {
    if (start < 0 || start >= len)
        return;
    num = std::min(num, len - start);
    int pos1 = 0, pos2 = 0;
    node *p1, *p2;
    findPos(start, pos1, p1);
    findPos(start + num, pos2, p2);
    if (p1 == p2) {
        p1->size -= pos2 - pos1;
    } else {
        split(p1, pos1);
        split(p2, pos2);
        node* tpl = p2->next;
        node* nextp = p1->next;
        while (nextp != tpl) {
            p1->next = nextp->next;
            delete nextp;
            nextp = p1->next;
        }
    }
    merge(p1);
    len -= num;
}

LinkString Ur::operator+(const LinkString& s1, const LinkString& s2) {
    char* s = new char[s1.len + s2.len + 1];
    LinkString::node* p;
    int i, count = 0;

    for (p = s1.head; p != NULL; p = p->next)
        for (i = 0; i < p->size; ++i)
            s[count++] = p->data[i];
    for (p = s2.head; p != NULL; p = p->next)
        for (i = 0; i < p->size; ++i)
            s[count++] = p->data[i];

    s[count] = '\0';
    LinkString tpl(s);
    delete[] s;
    return tpl;
}

bool Ur::operator==(const LinkString& s1, const LinkString& s2) {
    LinkString::node* p1 = s1.head;
    LinkString::node* p2 = s2.head;
    if (s1.len != s2.len)
        return false;
    for (; p1 != NULL; p1 = p1->next, p2 = p2->next) {
        for (int i = 0; i < p1->size; ++i)
            if (p1->data[i] != p2->data[i])
                return false;
    }
    return true;
}

bool Ur::operator!=(const LinkString& s1, const LinkString& s2) {
    return !(s1 == s2);
}

bool Ur::operator>(const LinkString& s1, const LinkString& s2) {
    LinkString::node* p1 = s1.head;
    LinkString::node* p2 = s2.head;
    while (p1 && p2) {
        int i = 0, j = 0;
        if (p1->data[i] < p2->data[i])
            return false;
        if (p2->data[i] > p2->data[i])
            return true;
        if (++i == p1->size) {
            i = 0;
            p1 = p1->next;
        }
        if (++j == p2->size) {
            j = 0;
            p2 = p2->next;
        }
    }
    if (p1 && !p2)
        return true;
    else
        return false;
}

bool Ur::operator>=(const LinkString& s1, const LinkString& s2) {
    return (s1 == s2 || s1 > s2);
}

bool Ur::operator<(const LinkString& s1, const LinkString& s2) {
    return !(s1 >= s2);
}

bool Ur::operator<=(const LinkString& s1, const LinkString& s2) {
    return !(s1 > s2);
}

std::ostream& Ur::operator<<(std::ostream& os, const LinkString& s) {
    LinkString::node* p = s.head;
    int i = 0;
    while (p) {
        for (; i < p->size; ++i)
            os << p->data[i];
        p = p->next;
        i = 0;
    }
    return os;
}