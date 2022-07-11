#include <iostream>
#include "SeqString.h"
using namespace std;

int main() {
    SeqString s1("hello");
    SeqString s2("world");
    SeqString s3(s1);
    bool judgment;
    s2 = s1;
    if (s1 == s2)
        judgment = true;
    else
        judgment = false;
    cout << judgment << endl;
    s1.insert(5, " ikun");
    cout << s1 << endl;
    s2 = s1.subStr(0, 90);
    s2.remove(5, 90);
    cout << s2 << endl;
    cout << s1.length() << endl;
    system("pause");
}