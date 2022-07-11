#include <Algorithm>
#include <iostream>
#include "Array of sum_x.h"
using namespace std;

void NumberSearchFunction(int arr[], int size, int x) {
    int i;
    sort(arr, arr + size);
    for (i = 0; i < size - 1; i++) {
        int low, high, mid;
        low = i + 1;
        high = size - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] + arr[i] == x)
                break;
            else if (arr[mid] + arr[i] > x)
                high = mid - 1;
            else if (arr[mid] + arr[i] < x)
                low = mid + 1;
        }
        if (low <= high) {
            cout << "存在两个数" << arr[i] << "," << arr[mid] << "其和为" << x
                 << endl;
            break;
        }
    }
    if (i == size - 1)
        cout << "不存在两个数其和为" << x << endl;
}