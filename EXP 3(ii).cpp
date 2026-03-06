#include <iostream>
using namespace std;

int main()
{
    int n, ch;
    int a[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1 Selection Sort\n2 Insertion Sort\n3 Bubble Sort\nEnter choice: ";
    cin >> ch;

    if(ch == 1)
    {
        for(int i = 0; i < n - 1; i++)
        {
            int min = i;
            for(int j = i + 1; j < n; j++)
            {
                if(a[j] < a[min])
                    min = j;
            }
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    else if(ch == 2)
    {
        for(int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;

            while(j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    else if(ch == 3)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    else
    {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
