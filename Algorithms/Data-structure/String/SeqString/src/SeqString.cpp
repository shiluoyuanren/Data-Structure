#include "SeqString.h"
#include <iostream>
using namespace std;

SeqString::SeqString(const char* s) {
    for (len = 0; s[len] != '\0'; ++len)
        ;
    data = new char[len + 1];
    for (len = 0; s[len] != '\0'; ++len)
        data[len] = s[len];
    data[len] = '\0';
}

SeqString::SeqString(const SeqString& other) {
    data = new char[other.len + 1];
    len = other.len;
    for (len = 0; other.data[len] != '\0'; ++len)
        data[len] = other.data[len];
    data[len] = '\0';
}

SeqString::~SeqString() {
    delete[] data;
}

int SeqString::length() const {
    return len;
}

SeqString& SeqString::operator=(const SeqString& other) {
    if (this == &other)
        return *this;
    delete[] data;
    data = new char[other.len + 1];
    for (len = 0; other.data[len] != '\0'; ++len)
        data[len] = other.data[len];
    data[len] = '\0';
    return *this;
}

SeqString SeqString::subStr(int start, int num) const {
    SeqString tpl;
    if (start < 0 || start > len - 1) {
        tpl.data = new char[1];
        data[0] = '\0';
        tpl.len = 0;
    } else {
        int end = min(len - 1, start + num - 1);
        tpl.data = new char[end - start + 2];
        int i;
        for (i = 0; i <= end - start; ++i)
            tpl.data[i] = data[start + i];
        tpl.data[i] = '\0';
        tpl.len = end - start + 1;
    }
    return tpl;
}

void SeqString::insert(int start, const SeqString& s) {
    if (start < 0 || start > len)
        return;
    SeqString tpl;
    tpl.len = len + s.len;
    tpl.data = new char[tpl.len + 1];
    int i;
    for (i = 0; i < start; ++i)
        tpl.data[i] = data[i];
    for (i = 0; i < s.len; ++i)
        tpl.data[start + i] = s.data[i];
    for (i = 0; i < len - start; ++i)
        tpl.data[start + s.len + i] = data[start + i];
    tpl.data[tpl.len] = '\0';
    delete[] data;
    *this = tpl;
}

void SeqString::remove(int start, int num) {
    if (start < 0 || start > len)
        return;
    int end = min(start + num, len - 1);
    len -= end - start + 1;
    data[len] = '\0';
}

int SeqString::find(const SeqString& s) const {
    int* p = new int[s.len];
    int i, j;

    //生成失效函数
    p[0] = -1;
    for (i = 1; i < s.len; ++i) {
        j = i - 1;
        while (j >= 0 && s.data[p[j] + 1] != s.data[i])
            j = p[j];
        if (j < 0)
            p[i] = -1;
        else
            p[i] = p[j] + 1;
    }

    //查找
    i = j = 0;
    while (i < len && j < s.len) {
        if (data[i] == s.data[j]) {
            j++;
            i++;
        } else if (j == 0)
            i++;
        else
            j = p[j - 1] + 1;
    }
    delete[] p;
    if (j == s.len)
        return i - j;
    else
        return -1;
}

SeqString operator+(const SeqString& s1, const SeqString& s2) {
    SeqString tpl;
    tpl.len = s1.len + s2.len;
    tpl.data = new char[tpl.len + 1];
    int i;
    for (i = 0; i < s1.len; i++)
        tpl.data[i] = s1.data[i];
    for (i = 0; i < s2.len; i++)
        tpl.data[i + s1.len] = s2.data[i];
    tpl.data[tpl.len] = '\0';
    return tpl;
}

bool operator==(const SeqString& s1, const SeqString& s2) {
    int i;
    if (s1.len != s2.len)
        return false;
    for (i = 0; i < s1.len; i++)
        if (s1.data[i] != s2.data[i])
            return false;
    return true;
}

bool operator!=(const SeqString& s1, const SeqString& s2) {
    return !(s1 == s2);
}

bool operator>(const SeqString& s1, const SeqString& s2) {
    int i;
    for (i = 0; i < s1.len; i++) {
        if (s1.data[i] > s2.data[i])
            return true;
        else if (s2.data[i] < s1.data[i])
            return false;
    }
    return false;
}

bool operator>=(const SeqString& s1, const SeqString& s2) {
    int i;
    for (i = 0; i < s1.len; i++)
        if (s1.data[i] > s2.data[i] || s1.data[i] == s2.data[i])
            return true;
        else
            return false;
}

bool operator<(const SeqString& s1, const SeqString& s2) {
    return !(s1 >= s2);
}

bool operator<=(const SeqString& s1, const SeqString& s2) {
    return !(s1 > s2);
}

ostream& operator<<(ostream& os, const SeqString& s) {
    os << s.data;
    return os;
}