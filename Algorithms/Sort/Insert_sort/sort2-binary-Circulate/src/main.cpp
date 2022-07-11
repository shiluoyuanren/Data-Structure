#include <iostream>
#include "sort2-binary-circulate.h"
using namespace std;

int main() {
    int arr[9] = {3, 5, 1, 2, 7, 9, 45, 14, 8};
    insert_sort(arr, 9);
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}