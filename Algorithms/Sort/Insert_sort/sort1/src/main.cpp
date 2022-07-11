#include <iostream>
#include "sort1.h"
using namespace std;

int main() {
    int i;
    float A[5];
    cout << "请输入5个数字: ";
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Insert_Sort(A, 5);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    system("pause");
    return 0;
}