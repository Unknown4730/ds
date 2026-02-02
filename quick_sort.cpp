#include <iostream>

void quickSort(int* arr, int low, int high) {
 if (low >= high) return;

 int pivot = arr[high];
 int i = low -1;

 for (int j = low; j < high; j++) {
 if (arr[j] <= pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }

 int temp = arr[i +1];
 arr[i +1] = arr[high];
 arr[high] = temp;

 int p = i +1;
 quickSort(arr, low, p -1);
 quickSort(arr, p +1, high);
}

int main() {
 int n;
 std::cout << "Enter the number of elements: ";
 std::cin >> n;

 int* arr = new int[n];

 std::cout << "Enter " << n << " elements:\n";
 for (int i =0; i < n; i++) {
 std::cin >> arr[i];
 }

 quickSort(arr,0, n -1);

 std::cout << "Sorted array:\n";
 for (int i =0; i < n; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;

 delete[] arr;
 return 0;
}