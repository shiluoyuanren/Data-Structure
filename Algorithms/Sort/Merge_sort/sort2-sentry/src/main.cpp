#include <iostream>
#include "sort2-sentry.h"
using namespace std;

int main() {
    int A[5];
    int i;
    cout << "请输入5个数字: ";
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Merge_Sort(A, 0, 4);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
    system("pause");
}