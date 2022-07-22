#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "cmp.h"

int main() {
    std::priority_queue<int, std::vector<int>,std::greater<int>> q1;
    // less表示大顶堆
    // greater表示小顶堆
    // cmp为重写的仿函数(并非函数,而是类或结构体)
    q1.push(12);
    q1.push(3);
    q1.push(5);
    q1.push(13);
    q1.push(8);
    q1.push(10);
    for (int i = 1; i < 7; ++i) {
        std::cout << q1.top() << " ";
        q1.pop();
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
