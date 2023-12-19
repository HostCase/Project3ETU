#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;


int main() {
    // const from cin??
    const int n = 8;
    int arra[n][n];
    int k = 0;
    int value = 1;

    do{
    for (int x = k; x < n - k; x++) {
        arra[k][x] = value;
        cout<<
        value++;
    }


    for (int y = k + 1; y < n - k; y++) {
        arra[y][n - 1 - k] = value;
        value++;
    }


    for (int x = n - 2 - k; x >= k; x--) {
        arra[n - 1 - k][x] = value;
        value++;
    }


    for (int y = n - 2 - k; y > k; y--) {
        arra[y][k] = value;
        value++;
    }
    k++;
    } while (!(k == n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arra[i][j] << " ";
            }
            cout << endl;
        }
}