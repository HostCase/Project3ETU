#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;


int main() {
    // const from cin??
    const int n = 6;
    if (n % 2 == 1) {
        return 0;
    }
    int numberoftask;
    int arra[n][n];
    do {
        cout << "Choose task";
        cin >> numberoftask;
        switch (numberoftask) {

        case 1: {
            int k = 0;
            HANDLE hStdout;
            COORD destCoord;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            int firsttask = 0;
            cout << "Choose type of filling from first task";
            cin >> firsttask;
            switch (firsttask) {
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
                    for (int y = k + 1; y < n - k; y++) {// ��� �����
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
            break;
        }
        case 2: {
            int typeswap = 0;
            cout << "Choose typeswap from 2 task";

            switch (typeswap) {
                //swap first type
            case 1: {
                for (int i = 0; i < (n / 2); i++) {
                    for (int g = 0; g < (n / 2); g++) {
                        swap(arra[i][g], arra[i][g + n / 2]);
                        swap(arra[i][g + n / 2], arra[i + n / 2][g + n / 2]);
                        swap(arra[i + n / 2][g + n / 2], arra[i][g]);
                        swap(arra[i][g], arra[n / 2 + i][g]);
                    }
                }
                break;
            }

                  //swap second type
            case 2: {
                for (int i = 0; i < (n / 2); i++) {
                    for (int g = 0; g < (n / 2); g++) {
                        swap(arra[i][g], arra[i + n / 2][g + n / 2]);
                        swap(arra[i][g + n / 2], arra[i + n / 2][g]);
                    }
                }
                break;
            }
            case 3: {

                for (int i = 0; i < (n / 2); i++) {
                    for (int g = 0; g < (n / 2); g++) {
                        swap(arra[i][g], arra[i + n / 2][g]);
                        swap(arra[i][g + n / 2], arra[i + n / 2][g + n / 2]);
                    }
                }
                break;
            }
            case 4: {
                for (int i = 0; i < (n / 2); i++) {
                    for (int g = 0; g < (n / 2); g++) {
                        swap(arra[i][g], arra[i][g + n / 2]);
                        swap(arra[i + n / 2][g], arra[i + n / 2][g + n / 2]);
                    }
                }
                break;

            }
            }
            break;
        }
        case 3: {
            int(*arr)[n] = arra;
            //����������
            int x;
            for (int k = 0; k < n; k++)
            {
                for (int m = 0; m < n; m++)
                {
                    x = m + 1;
                    for (int i = k; i < n; i++)
                    {
                        for (int j = x; j < n; j++)
                        {
                            if (arr[k][m] > arr[i][j])
                                swap(arr[k][m], arr[i][j]);
                        }
                        x = 0;
                    }
                }
            }
            break;
        }
        case 4: {
            int num, type;
            cout << "Choose type";
            cin >> type;
            cout << "Enter Num";
            cin >> num;
            switch (type)
            {
            case 1: {
                for (int i = 0; i < n; i++) {
                    for (int g = 0; g < n; g++) {
                        arra[i][g] = arra[i][g] - num;

                    }
                }
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                    for (int g = 0; g < n; g++) {
                        arra[i][g] = arra[i][g] + num;

                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < n; i++) {
                    for (int g = 0; g < n; g++) {
                        arra[i][g] = arra[i][g] * num;

                    }
                }
                break;
            }
            case 4: {
                for (int i = 0; i < n; i++) {
                    for (int g = 0; g < n; g++) {
                        arra[i][g] = arra[i][g] / num;

                    }
                }
                break;
            }

            }
        }


        case 5: {
            cout << "\nSECOND\n";
            for (int i = 0; i < n; i++) {  //�����

                for (int j = 0; j < n; j++) {
                    cout << arra[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        }
    }while (numberoftask);
}

