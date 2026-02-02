#include <iostream>
using namespace std;

int main() {
    int *arr1 = nullptr;
    int *arr2 = nullptr;
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Create array one(5 elements)\n";
        cout << "2. Create array two(5 elements)\n";
        cout << "3. Display array one\n";
        cout << "4. Display array two\n";
        cout << "5. Add all elements of array one\n";
        cout << "6. Add all elements of array two\n";
        cout << "7. Compare two arrays\n";
        cout << "8. Add both arrays\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr1 = new int[5];
                cout << "Enter 5 elements for array one:\n";
                for (int i = 0; i < 5; i++) {
                    cin >> arr1[i];
                }
                break;

            case 2:
                arr2 = new int[5];
                cout << "Enter 5 elements for array two:\n";
                for (int i = 0; i < 5; i++) {
                    cin >> arr2[i];
                }
                break;

            case 3:
                if (arr1 == nullptr) {
                    cout << "Array one not created yet!\n";
                } else {
                    cout << "Array one elements are:\n";
                    for (int i = 0; i < 5; i++) {
                        cout << arr1[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 4:
                if (arr2 == nullptr) {
                    cout << "Array two not created yet!\n";
                } else {
                    cout << "Array two elements are:\n";
                    for (int i = 0; i < 5; i++) {
                        cout << arr2[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5:
                if (arr1 == nullptr) {
                    cout << "Array one not created yet!\n";
                } else {
                    int sum1 = 0;
                    for (int i = 0; i < 5; i++) {
                        sum1 += arr1[i];
                    }
                    cout << "Sum of elements in array one: " << sum1 << endl;
                }
                break;

            case 6:
                if (arr2 == nullptr) {
                    cout << "Array two not created yet!\n";
                } else {
                    int sum2 = 0;
                    for (int i = 0; i < 5; i++) {
                        sum2 += arr2[i];
                    }
                    cout << "Sum of elements in array two: " << sum2 << endl;
                }
                break;

            case 7:
                if (arr1 == nullptr || arr2 == nullptr) {
                    cout << "Both arrays must be created first!\n";
                } else {
                    bool equal = true;
                    for (int i = 0; i < 5; i++) {
                        if (arr1[i] != arr2[i]) {
                            equal = false;
                            break;
                        }
                    }
                    if (equal) {
                        cout << "Both arrays are equal\n";
                    } else {
                        cout << "Arrays are not equal\n";
                    }
                }
                break;

            case 8:
                if (arr1 == nullptr || arr2 == nullptr) {
                    cout << "Both arrays must be created first!\n";
                } else {
                    int *arr3 = new int[5];
                    cout << "Sum of both arrays:\n";
                    for (int i = 0; i < 5; i++) {
                        arr3[i] = arr1[i] + arr2[i];
                        cout << arr3[i] << " ";
                    }
                    cout << endl;
                    delete[] arr3;
                }
                break;

            case 9:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    delete[] arr1;
    delete[] arr2;

    return 0;
}