#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 5, 3, 7, 2, 8, 1, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
