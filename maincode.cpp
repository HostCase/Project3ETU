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
       destCoord.X = x*10;
       destCoord.Y = k*4;
       SetConsoleCursorPosition(hStdout, destCoord);
       cout << arra[k][x] << '\r';
       cout.flush();
       Sleep(300);

    }
    Sleep(5000);
    for (int y = k + 1; y < n - k; y++) {// ÒÓÒ ÇÐÀÄÀ
        arra[y][n - 1 - k] = 1 + rand() % (n * n);
        destCoord.X = (n-1)*10;
        destCoord.Y = y*4;
        SetConsoleCursorPosition(hStdout, destCoord);
        cout << arra[y][n-1-k] << '\r';
        cout.flush();
        Sleep(300);
    }
    Sleep(2000);

    for (int x = n - 2 - k; x >= k; x--) {
        arra[n - 1 - k][x] = 1 + rand() % (n * n);
        destCoord.X = x * 10;
        destCoord.Y = (n-1-k) * 4;
        SetConsoleCursorPosition(hStdout, destCoord);
        cout << arra[n - 1 - k][x] << '\r';
        cout.flush();
        Sleep(300);
    }
    Sleep(2000);

    for (int y = n - 2 - k; y > k; y--) {
        arra[y][k] = 1 + rand() % (n * n);
        destCoord.X = k * 10;
        destCoord.Y = y * 4;
        SetConsoleCursorPosition(hStdout, destCoord);
        cout << arra[y][k] << '\r';
        cout.flush();
        Sleep(300);

    }
    Sleep(2000);
    k++;
    } while (!(k == n));
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arra[i][j] << " ";
            }
            cout << endl;
        }
}