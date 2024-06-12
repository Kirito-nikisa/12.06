#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 5, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
