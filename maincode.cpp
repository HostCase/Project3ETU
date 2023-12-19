#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
    // const from cin??
    const int n = 6;
    if (n % 2 == 1) {
        return 0;
    }
    
    int arra[n][n];
    int k = 0;
    int value = 1;
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    do{
    for (int x = k; x < n - k; x++) {
       arra[k][x] = 1 + rand() % (n * n);
       destCoord.X = x * 4;
       destCoord.Y = k * 2; 
       SetConsoleCursorPosition(hStdout, destCoord);
       cout << arra[k][x] << "    ";
       cout.flush();
    }
    Sleep(3000);

    for (int y = k + 1; y < n - k; y++) {
        arra[y][n - 1 - k] = 1 + rand() % (n * n);

    }


    for (int x = n - 2 - k; x >= k; x--) {
        arra[n - 1 - k][x] = 1 + rand() % (n * n);
        value++;
    }


    for (int y = n - 2 - k; y > k; y--) {
        arra[y][k] = 1 + rand() % (n * n);
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