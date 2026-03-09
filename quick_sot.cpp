#include <iostream>
#include <algorithm>   // for std::swap

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[high]);

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main() {
    int n;
    std::cout << " Enter no of elements";
    std::cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

}
