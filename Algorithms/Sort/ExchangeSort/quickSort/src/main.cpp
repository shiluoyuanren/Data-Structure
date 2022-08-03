#include <iostream>
#include <string>
#include "quickSort.h"
using namespace std;

int main() {
    SET<int, string> s[] = {{3, "aaa"}, {7, "bbb"}, {1, "ccc"},
                            {9, "ddd"}, {4, "eee"}, {8, "fff"},
                            {6, "ggg"}, {2, "hhh"}, {5, "iii"}};
    quickSort(s, 9);
    for (int i = 0; i < 9; ++i)
        cout << s[i].key << " " << s[i].other << endl;

    system("pause");
    return 0;
}