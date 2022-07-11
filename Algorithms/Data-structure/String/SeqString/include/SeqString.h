#ifndef _SEQSTRING_H
#define _SEQSTRING_H

#include <iostream>
using namespace std;

class SeqString {
    friend SeqString operator+(const SeqString& s1, const SeqString& s2);
    friend bool operator==(const SeqString& s1, const SeqString& s2);
    friend bool operator!=(const SeqString& s1, const SeqString& s2);
    friend bool operator>(const SeqString& s1, const SeqString& s2);
    friend bool operator>=(const SeqString& s1, const SeqString& s2);
    friend bool operator<(const SeqString& s1, const SeqString& s2);
    friend bool operator<=(const SeqString& s1, const SeqString& s2);
    friend ostream& operator<<(ostream& os, const SeqString& s);

    char* data;
    int len;

   public:
    SeqString(const char* s = "");
    SeqString(const SeqString& other);
    ~SeqString();
    int length() const;
    SeqString& operator=(const SeqString& other);
    SeqString subStr(int start, int num) const;
    void insert(int start, const SeqString& s);
    void remove(int start, int num);
};

#endif