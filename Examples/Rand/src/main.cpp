#include <stdlib.h>
#include <time.h>
#include <iostream>
#define random(x) rand() % x
using namespace std;

int main() {
    int i;
    srand(time(NULL));
    //将time(NULL)作为srand的参数,time以秒为单位,只需执行一次
    // srand()函数用来设置rand()函数的种子
    for (i = 0; i < 10; ++i) {
        cout << rand() % 26 + 100;                 //可以设置范围
        cout << "\t" << random(26) + 100 << endl;  //可以用宏替换
    }

    system("pause");
    return 0;
}