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
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    if (!cin || size < 1 || size > 100) {
        cout << "Invalid size. Please enter a value between 1 and 100." << endl;
        return 1;
    }

    int arr[100];

    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index " << result;
    } else {
        cout << "Element not found";
    }

    return 0;
}
