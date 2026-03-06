#include <iostream>
using namespace std;

int main()
{
    int n, ch, key;
    int arr[100];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1 Linear Search\n2 Binary Search\nEnter choice: ";
    cin >> ch;

    cout << "Enter element to search: ";
    cin >> key;

    switch(ch)
    {
        case 1:
        {
            int flag = 0;
            for(int i = 0; i < n; i++)
            {
                if(arr[i] == key)
                {
                    cout << "Element found at position " << i;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                cout << "Element not found";
            break;
        }

        case 2:
        {
            int low = 0, high = n - 1, mid, flag = 0;

            while(low <= high)
            {
                mid = (low + high) / 2;

                if(arr[mid] == key)
                {
                    cout << "Element found at position " << mid;
                    flag = 1;
                    break;
                }
                else if(arr[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            if(flag == 0)
                cout << "Element not found";
            break;
        }

        default:
            cout << "Invalid choice";
    }

    return 0;
}
