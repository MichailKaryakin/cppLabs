#include "cstdlib"
#include "cmath"
#include "ctime"
#include "utils.h"
#include "iostream"

using namespace std;

void choicesSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++) {
        ++compare_count;
        int temp; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++) {
            ++compare_count;
            if (array[repeat_counter] < array[element_counter]) {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
            ++basic_operations;
        }
        ++compare_count;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество выделенной дополнительной памяти = " << sizeof(int) << " байт" << "\n";
}

void insertionSort(int* array, int length) {
    clock_t start = clock();
    long long compare_count = 0;
    long long basic_operations = 0;
    int temp, j, i;
    for (i = 1; i < length; i++) {
        ++compare_count;
        temp = array[i];
        for (j = i; j >= 0 && temp > array[j - 1]; j--) {/* находим место вставки, попутно сдвигая элементы */
            ++compare_count;
            ++basic_operations;
            array[j] = array[j - 1];
        }
        ++compare_count;
        ++basic_operations;
        array[j] = temp;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество выделенной дополнительной памяти = " << sizeof(int) * 3 << " байт" << "\n";
}

void shellSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    const int num_of_gaps = (int) ((log(length) / log(3)) - 1);
    int i, m;
    int current_gap, temp, replace_index;
    int gaps[num_of_gaps];
    gaps[num_of_gaps] = 1;
    for (m = num_of_gaps - 1; m >= 0; m--) {
        ++compare_count;
        gaps[m] = gaps[m + 1] * 3 + 1;
    }
    ++compare_count;
    for (m = 0; m < num_of_gaps; m++) /*последовательно перебираем все расстояния*/
    {
        ++compare_count;
        current_gap = gaps[m];
        for (i = current_gap; i < length; i++) /*до конца цикла метод вставки с учетом шага gaps[m]*/
        {
            ++compare_count;
            temp = array[i];
            replace_index = i - current_gap;
            while (replace_index >= 0 && temp > array[replace_index]) {
                ++basic_operations;
                ++compare_count;
                array[replace_index + current_gap] = array[replace_index];
                replace_index -= current_gap;
            }
            ++basic_operations;
            ++compare_count;
            array[replace_index + current_gap] = temp;
        }
        ++compare_count;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество дополнительно выделенной памяти = "
         << sizeof(const int) * 1 + sizeof(int) * 5 + sizeof(int) * num_of_gaps << " байт" << "\n";
}

void mergeSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    int step = 1;  // шаг разбиения последовательности
    int* temp = (int*) malloc(length * sizeof(int)); // дополнительный массив
    while (step < length)  // пока шаг меньше длины массива
    {
        ++compare_count;
        int index = 0;    // индекс результирующего массива
        int l = 0;      // левая граница участка
        int m = l + step;  // середина участка
        int r = l + step * 2;  // правая граница участка
        do {
            ++compare_count;
            m = m < length ? m : length;  // сортируемый участок не выходит за границы последовательности
            ++compare_count;
            r = r < length ? r : length;
            ++compare_count;
            int i1 = l, i2 = m; // индексы сравниваемых элементов
            for (; i1 < m && i2 < r;) // пока i1 не дошёл до середины и i2 не дошёл до конца
            {
                compare_count += 2;
                if (array[i1] < array[i2]) {
                    temp[index++] = array[i1++];
                } // заполняем участок результирующей последовательности
                else {
                    temp[index++] = array[i2++];
                }
                ++basic_operations;
            }
            compare_count += 2;
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m) temp[index++] = array[i1++]; // заносим оставшиеся элементы сортируемых участков
            while (i2 < r) temp[index++] = array[i2++]; // в результирующий массив
            l += step * 2; // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        } while (l < length); // пока левая граница сортируемого участка - в пределах последоватльности
        for (int i = 0; i < length; i++) {// переносим сформированный массив обратно в a
            ++compare_count;
            array[i] = temp[i];
        }
        ++compare_count;
        step *= 2; // увеличиваем в 2 раза шаг разбиения
    }
    ++compare_count;
    free(temp);
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество дополнительно выделенной памяти = "
         << sizeof(int) * length + sizeof(int*) * 5 + sizeof(int) * 2 << " байт"
         << "\n";
}


