#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int a[] = {2, 4, 8, 10, 12, 13, 15, 16, 19, 20};
    std::vector<int> v;
    std::vector<int>::const_iterator itr;

    int i = 0;
    for (i = 0; i < 11; ++i)
        v.push_back(a[i]);

    std::cout << std::binary_search(v.begin(), v.end(), 20) << std::endl;

    itr = std::find(v.begin(), v.end(), 20);
    std::cout << *itr << std::endl;

    system("pause");
    return 0;
}