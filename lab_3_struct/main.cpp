#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "src/utils.h"

#define N1 10000
#define N2 18000
#define N3 30000
#define N4 60000

using namespace std;

void fill_arrays(int* array1, int* array2, int* array3, int* array4) {
    ifstream fin("test_numbers.txt");
    string temp;
    int symbol_count = 0;
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 32 && symbol_count != N1) {
                array1[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N1) {
            puts("первый массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 32 && symbol_count != N2) {
                array2[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N2) {
            puts("второй массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 32 && symbol_count != N3) {
                array3[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N3) {
            puts("третий массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 32 && symbol_count != N4) {
                array4[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N4) {
            puts("четвёртый массив заполнен");
            break;
        }
        temp.clear();
    }
    fin.close();
}

void array1_sort(const int* array) {
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА ВЫБОРОМ");
    Sleep(2000);
    int temp_array[N1];
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N1);
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА ВСТАВКАМИ");
    Sleep(2000);
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N1);
    puts("СОРТИРОВКА ШЕЛЛА ПЕРВОГО МАССИВА");
    Sleep(2000);
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N1);
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА СЛИЯНИЕМ");
    Sleep(2000);
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, N1);
}

void array2_sort(const int* array) {
    puts("СОРТИРОВКА ВТОРОГО МАССИВА ВЫБОРОМ");
    Sleep(2000);
    int temp_array[N2];
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N2);
    puts("СОРТИРОВКА ВТОРОГО МАССИВА ВСТАВКАМИ");
    Sleep(2000);
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N2);
    puts("СОРТИРОВКА ШЕЛЛА ВТОРОГО МАССИВА");
    Sleep(2000);
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N2);
    puts("СОРТИРОВКА ВТОРОГО МАССИВА СЛИЯНИЕМ");
    Sleep(2000);
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, N2);
}

void array3_sort(const int* array) {
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА ВЫБОРОМ");
    Sleep(2000);
    int temp_array[N3];
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N3);
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА ВСТАВКАМИ");
    Sleep(2000);
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N3);
    puts("СОРТИРОВКА ШЕЛЛА ТРЕТЬЕГО МАССИВА");
    Sleep(2000);
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N3);
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА СЛИЯНИЕМ");
    Sleep(2000);
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, N3);
    Sleep(2000);
}

void array4_sort(const int* array) {
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА ВЫБОРОМ");
    Sleep(2000);
    int temp_array[N4];
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N4);
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА ВСТАВКАМИ");
    Sleep(2000);
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N4);
    puts("СОРТИРОВКА ШЕЛЛА ЧЕТВЁРТОГО МАССИВА");
    Sleep(2000);
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N4);
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА СЛИЯНИЕМ");
    Sleep(2000);
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, N4);
    Sleep(2000);
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int array1[N1], array2[N2], array3[N3], array4[N4];
    fill_arrays(array1, array2, array3, array4);
    bool exit = false, sorted1 = false, sorted2 = false, sorted3 = false, sorted4 = false;
    while (!exit) {
        int user_choice;
        puts ("1 - сортировка N1, 2 - сортировка N2, 3 - сортировка N3, 4 - сортировка N4");
        cin >> user_choice;
        if (user_choice == 1 && !sorted1) {
            array1_sort(array1);
            sorted1 = true;
        } else if (user_choice == 2 && !sorted2) {
            array2_sort(array2);
            sorted2 = true;
        } else if (user_choice == 3 && !sorted3) {
            array3_sort(array3);
            sorted3 = true;
        } else if (user_choice == 4 && !sorted4) {
            array4_sort(array4);
            sorted4 = true;
        }
        if (sorted1 && sorted2 && sorted3 && sorted4) {
            exit = true;
        }
    }
}
