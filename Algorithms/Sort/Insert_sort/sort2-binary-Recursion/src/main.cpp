#include <iostream>
#include "sort2-binary-recursion.h"
using namespace std;

int main() {
    int A[5];
    cout << "请输入5个数字: ";
    int i;
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Insert_Sort(A, 0, 4);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}