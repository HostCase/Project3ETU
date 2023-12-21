#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int n = 6;
void firsttask(int arra[][n]);
void swapmachine(int arra[][n]);
void showmatrix(int arra[][n]);
void modofmatrix(int arra[][n]);
void sortArranew(int* arr);
void idztransport(int arra[][n]);
int main() {

    cout << "For the normal operation of the program, it is better to expand the console to full screen!!!\n";
    Sleep(1500);
    // const from cin??
    if (n % 2 == 1) {
        return 0;
    }
    int numberoftask;
    int arra[n][n];
    do {
        cout << "Choose task(tips - 8)\n";
        cin >> numberoftask;
        switch (numberoftask) {

        case 1: {
            firsttask(arra);
            break;
        }
        case 2: {
           
            cout << "Choose typeswap from 2 task\n";
            swapmachine(arra);
            
            break;
        }
        case 3: {
            cout << "Sorting\n";
            sortArranew(&arra[0][0]);
            cout << "Completed\n";
            break;
        }
        case 4: {
            modofmatrix(arra);
            break;
        }


        case 5: {
            showmatrix(arra);
            break;
        }
        case 6: {
            cout << "Clearing...";
            Sleep (1500);
            system("cls");
            break;
        }
        case 7: {
            srand(time(0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arra[i][j] = (rand() % 100) + 1;
                }
            }
            cout << "Original Matrix:\n";
            showmatrix(arra);

            cout << "Transpose Process:\n";
            idztransport(arra);

            cout << "Final Transposed Matrix:\n";
            showmatrix(arra);
            break;
        }
        case 8: {
            cout << "\nFirst task(filling) - 1";
            cout << "\nSecond task(swap) - 2";
            cout << "\nThird task(sort)- 3";
            cout << "\nFourth task(math) - 4";
            cout << "\nShow matrix - 5";
            cout << "\nClear console - 6";
            cout << "\nIDZ 9 - 7\n\n\n";
                break;
        }
        }
    }while (numberoftask);
}

void firsttask(int arra[][n]) {

    int k = 0;
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int firsttask = 0;
    cout << "Choose type of filling from first task\n";
    cin >> firsttask;
    switch (firsttask) {
    case 1: {
        system("cls");
        do {
            for (int x = k; x < n - k; x++) {
                arra[k][x] = 1 + rand() % (n * n);
                destCoord.X = x * 10;
                destCoord.Y = k * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[k][x] << '\r';
                Sleep(100);
                cout.flush();

            }
            for (int y = k + 1; y < n - k; y++) {
                arra[y][n - 1 - k] = 1 + rand() % (n * n);
                destCoord.X = (n - 1 - k) * 10;
                destCoord.Y = y * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[y][n - 1 - k] << '\r';
                Sleep(100);
                cout.flush();
            }

            for (int x = n - 2 - k; x >= k; x--) {
                arra[n - 1 - k][x] = 1 + rand() % (n * n);
                destCoord.X = x * 10;
                destCoord.Y = (n - 1 - k) * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[n - 1 - k][x] << '\r';
                Sleep(100);
                cout.flush();
            }


            for (int y = n - 2 - k; y > k; y--) {
                arra[y][k] = 1 + rand() % (n * n);
                destCoord.X = k * 10;
                destCoord.Y = y * 4;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << arra[y][k] << '\r';
                Sleep(100);
                cout.flush();

            }
            k++;
        } while (!(k == n));
        break;
    }
    case 2: {
        system("cls");
        k = 0;
        do {
            for (int i = 0; i < n; i++) {
                if (k % 2 == 0) {
                    for (int y = n - 1; y > -1; y--) {
                        arra[y][i] = 1 + rand() % (n * n);
                        destCoord.X = (i) * 10;
                        destCoord.Y = y * 4;
                        SetConsoleCursorPosition(hStdout, destCoord);
                        cout << arra[y][i] << '\r';
                        Sleep(100);
                        cout.flush();
                    }
                }
                else {
                    for (int y = 0; y < n; y++) {
                        arra[y][i] = 1 + rand() % (n * n);
                        destCoord.X = (i) * 10;
                        destCoord.Y = y * 4;
                        SetConsoleCursorPosition(hStdout, destCoord);
                        cout << arra[y][i] << '\r';
                        Sleep(100);
                        cout.flush();
                    }
                }
                k++;
            }
        } while (!(k == n));
 
        }
    }

    destCoord.X = 0;
    destCoord.Y = 50;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "Task completed, do you want see result?(1-yes,0-no)\n";
    int seeresult = 0;
    cin >> seeresult;
    if (seeresult) {
        showmatrix(arra);
    }
}

void swapmachine(int arra[][n]) {
    int typeswap;
    cout << "Choose type of swap(1,2,3,4)\n";
    cin >> typeswap;
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
    cout << "Task completed, do you want see result?(1-yes,0-no)\n";
    int seeresult = 0;
    cin >> seeresult;
    if (seeresult) {
        showmatrix(arra);
    }
}

void showmatrix(int arra[][n]) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arra[i][j] << " ";
        }
        cout << endl;
    }

}

void modofmatrix(int arra[][n]) {
    int num, type;
    cout << "Choose type. \n 1 - minus\n2 - plus\n3 - *\n4 - /";
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
    cout << "Completed\n";
}

void sortArranew(int* arr) {
    for (int i = 0; i < n * n; i++) {
        for (int j = i + 1; j < n * n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

void idztransport(int arra[][n]) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = arra[i][j];
            arra[i][j] = arra[j][i];
            arra[j][i] = temp;

            // Display the Transpose Process
            cout << "After swapping " << arra[i][j] << " with " << arra[j][i] << ":" << endl;
            Sleep(1300);
            showmatrix(arra);
        }
    }
}