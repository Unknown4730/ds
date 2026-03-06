#include <iostream>
using namespace std;

int main() {
    int ch;
    cout << "1.Addition 2.Subtraction 3.Multiplication  4.Transpose  5.Inverse(2x2)\n";
    cin >> ch;

    switch (ch) {

    case 1: { // Addition
        int a[2][2], b[2][2];
        cout << "Enter A and B:\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j] >> b[i][j];

        cout << "Result:\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout << a[i][j] + b[i][j] << " ";
            cout << endl;
        }
        break;
    }

    case 2: { // Subtraction
        int a[2][2], b[2][2];
        cout << "Enter A and B:\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j] >> b[i][j];

        cout << "Result:\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout << a[i][j] - b[i][j] << " ";
            cout << endl;
        }
        break;
    }

    case 3: { // Multiplication
        int a[2][2], b[2][2], c[2][2]={0};
        cout << "Enter A and B:\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j] >> b[i][j];

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c[i][j] += a[i][k] * b[k][j];

        cout << "Result:\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout << c[i][j] << " ";
            cout << endl;
        }
        break;
    }

    case 4: { // Transpose
        int a[2][2];
        cout << "Enter A:\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j];

        cout << "Transpose:\n";
        for(int j=0;j<2;j++){
            for(int i=0;i<2;i++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        break;
    }

    case 5: { // Inverse
        float a[2][2], det;
        cout << "Enter A:\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j];

        det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
        if(det == 0) {
            cout << "Inverse not possible";
            break;
        }

        cout << "Inverse:\n";
        cout <<  a[1][1]/det << " " << -a[0][1]/det << endl;
        cout << -a[1][0]/det << " " <<  a[0][0]/det << endl;
        break;
    }

    default:
        cout << "Invalid choice";
    }

    return 0;
}
