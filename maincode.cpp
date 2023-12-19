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
    int needcal = 0;
    switch (needcal) {
    case 1: {
        do {
            for (int x = k; x < n - k; x++) {
                arra[k][x] = 1 + rand() % (n * n);
                destCoord.X = x * 10;
                destCoord.Y = k * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[k][x] << '\r';
                cout.flush();
                Sleep(300);

            }
            for (int y = k + 1; y < n - k; y++) {// ÒÓÒ ÇÐÀÄÀ
                arra[y][n - 1 - k] = 1 + rand() % (n * n);
                destCoord.X = (n - 1 - k) * 10;
                destCoord.Y = y * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[y][n - 1 - k] << '\r';
                cout.flush();
                Sleep(300);
            }

            for (int x = n - 2 - k; x >= k; x--) {
                arra[n - 1 - k][x] = 1 + rand() % (n * n);
                destCoord.X = x * 10;
                destCoord.Y = (n - 1 - k) * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[n - 1 - k][x] << '\r';
                cout.flush();
                Sleep(300);
            }


            for (int y = n - 2 - k; y > k; y--) {
                arra[y][k] = 1 + rand() % (n * n);
                destCoord.X = k * 10;
                destCoord.Y = y * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[y][k] << '\r';
                cout.flush();
                Sleep(300);

            }
            k++;
        } while (!(k == n));
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arra[i][j] << " ";
            }

            cout << endl;
        }
        break;
    }
    case 2: {
        int arrasecond[n][n];
        k = 0;
        do {
            for (int i = 0; i < n; i++) {
                if (k % 2 == 0) {
                    for (int y = n - 1; y > -1; y--) {
                        arrasecond[y][i] = 1 + rand() % (n * n);
                        destCoord.X = (i) * 10;
                        destCoord.Y = y * 4;
                        SetConsoleCursorPosition(hStdout, destCoord);
                        cout << arrasecond[y][i] << '\r';
                        cout.flush();
                    }
                }
                else {
                    for (int y = 0; y < n; y++) {
                        arrasecond[y][i] = 1 + rand() % (n * n);
                        destCoord.X = (i) * 10;
                        destCoord.Y = y * 4;
                        SetConsoleCursorPosition(hStdout, destCoord);
                        cout << arrasecond[y][i] << '\r';
                        cout.flush();
                    }
                }
                k++;
            }
        } while (!(k == n));
        cout << "\n\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arrasecond[i][j] << " ";
            }

            cout << endl;
        }
        break;
    }
    }



    int arratest[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arratest[i][j] = i + j * 100;
        }
    }
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << arratest[i][j] << " ";
        }
        cout << "\n";
    }
    int typeswap = 0;

    switch (typeswap) {
        //swap first type
    case 1: {
        for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arratest[i][g], arratest[i][g + n / 2]);
                swap(arratest[i][g + n / 2], arratest[i + n / 2][g + n / 2]);
                swap(arratest[i + n / 2][g + n / 2], arratest[i][g]);
                swap(arratest[i][g], arratest[n / 2 + i][g]);
            }
        }
        break;
    }

          //swap second type
    case 2: {
        for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arratest[i][g], arratest[i + n / 2][g + n / 2]);
                swap(arratest[i][g + n / 2], arratest[i + n / 2][g]);
            }
        }
        break;
    }
    case 3: {

        for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arratest[i][g], arratest[i + n / 2][g]);
                swap(arratest[i][g + n / 2], arratest[i + n / 2][g + n / 2]);
            }
        }
        break;
    }
    case 4: {
        for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arratest[i][g], arratest[i][g + n / 2]);
                swap(arratest[i + n / 2][g], arratest[i + n / 2][g + n / 2]);
            }
        }
        break;

    }
    }



    for (int i = 0; i < n*n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n ; j++) {
                
                if (k != (n - 1)) {
                    if ((j != (n - 2))||(j!=(n-2))) {
                        if (arratest[k][j] > arratest[k][j + 1]) {
                            swap(arratest[k][j], arratest[k][j + 1]);
                        }
                    }

                    if (j == (n - 1)) {
                        if (arratest[k][j] > arratest[k + 1][0]) {
                            swap(arratest[k][j], arratest[k + 1][0]);
                            cout << "TEST TEST " << arratest[k][j] << "      " << arratest[k + 1][0];
                        }
                    }
                }
                if (arratest[k][j] > arratest[k][j + 1]) {
                    swap(arratest[k][j], arratest[k][j + 1]);
                }
            }
        }
    }



    cout << "\nSECOND\n";
    for (int i = 0; i < n; i++) {  //ÂÛÂÎÄ

        for (int j = 0; j < n; j++) {
            cout << arratest[i][j] << " ";
        }
        cout << "\n";
    }





}
