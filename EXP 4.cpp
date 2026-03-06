#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// Merge Sort helpers
void merge(int a[], int l, int m, int r) {
    int i = l, j = m+1, k = 0;
    int temp[100];

    while(i <= m && j <= r) {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}


int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


void display(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n, choice;
    int a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    do {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                bubbleSort(a, n);
                cout << "After Bubble Sort: ";
                display(a, n);
                break;

            case 2:
                insertionSort(a, n);
                cout << "After Insertion Sort: ";
                display(a, n);
                break;

            case 3:
                mergeSort(a, 0, n-1);
                cout << "After Merge Sort: ";
                display(a, n);
                break;

            case 4:
                quickSort(a, 0, n-1);
                cout << "After Quick Sort: ";
                display(a, n);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
