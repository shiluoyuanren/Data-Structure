#include <iostream>
#include "seqSearch.h"

int main() {
    SET<char, int> set[7];
    for (int i = 1; i < 7; i++) {
        set[i].key = 'a' + i - 1;
        set[i].other = i + 12;
    }
    std::cout << seqSearch(set, 6, 'a') << std::endl;

    system("pause");
    return 0;
}