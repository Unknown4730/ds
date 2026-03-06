#include <iostream>
using namespace std;

int main() {
    int a[5], i;
    char x;
    int ch;
    int sum, sub, max, min;

    do {
        cout << "\n1. Create array";
        cout << "\n2. Display array";
        cout << "\n3. Sum";
        cout << "\n4. Difference";
        cout << "\n5. Maximum";
        cout << "\n6. Minimum";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter 5 elements:\n";
            for (i = 0; i < 5; i++) {
                cin >> a[i];
            }
            break;

        case 2:
            cout << "Array elements:\n";
            for (i = 0; i < 5; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            break;

        case 3:
            sum = 0;
            for (i = 0; i < 5; i++) {
                sum += a[i];
            }
            cout << "Sum = " << sum << endl;
            break;

        case 4:
            sub = a[0];
            for (i = 1; i < 5; i++) {
                sub -= a[i];
            }
            cout << "Difference = " << sub << endl;
            break;

        case 5:
            max = a[0];
            for (i = 1; i < 5; i++) {
                if (a[i] > max)
                    max = a[i];
            }
            cout << "Maximum = " << max << endl;
            break;

        case 6:
            min = a[0];
            for (i = 1; i < 5; i++) {
                if (a[i] < min)
                    min = a[i];
            }
            cout << "Minimum = " << min << endl;
            break;

        default:
            cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> x;

    } while (x == 'y' || x == 'Y');

    return 0;
}
