#include <iostream>
#include <windows.h>
#include "src/Queue.h"

#define array_size 4

using namespace std;

template<class T>
void array_sort_even(T* array) {
    T* temp_array = new T[array_size / 2];
    for (int i = 0, k = 0; i < array_size; i = i + 2, ++k) {
        temp_array[k] = array[i];
    }
    for (int i = 0; i < array_size / 2; ++i) {
        for (int k = 0; k < (array_size / 2) - 1; ++k) {
            if (temp_array[k] > temp_array[k + 1]) {
                T temp = temp_array[k];
                temp_array[k] = temp_array[k + 1];
                temp_array[k + 1] = temp;
            }
        }
    }
    for (int i = 0, k = 0; i < array_size; i = i + 2, ++k) {
        array[i] = temp_array[k];
    }
    delete[] temp_array;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int user_choice;
    bool exit = false;
    while (!exit) {
        puts("1 - шаблон функции, 2 - шаблон класса, 3 - выход");
        cin >> user_choice;
        while (cin.fail() == 1 || user_choice > 3) {
            cout << "попробуйте ещё раз\n";
            cin.clear();
            cin.sync();
            cin >> user_choice;
        }
        if (user_choice == 1) {
            int user_choice_1;
            puts("1 - long, 2 - unsigned char");
            cin >> user_choice_1;
            while (cin.fail() == 1 || user_choice > 2) {
                cout << "попробуйте ещё раз\n";
                cin.clear();
                cin.sync();
                cin >> user_choice_1;
            }
            if (user_choice_1 == 1) {
                long array[array_size];
                puts("наполните массив:");
                for (long& i : array) {
                    cin >> i;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> i;
                    }
                }
                array_sort_even(array);
                puts("отсортированный массив:");
                for (long& i : array) {
                    cout << i << " ";
                }
                puts("");
            } else if (user_choice_1 == 2) {
                unsigned char array[array_size];
                puts("наполните массив:");
                for (unsigned char& i : array) {
                    cin >> i;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> i;
                    }
                }
                array_sort_even(array);
                puts("отсортированный массив:");
                for (unsigned char& i : array) {
                    cout << i << " ";
                }
                puts("");
            }
        } else if (user_choice == 2) {
            int user_choice_2;
            puts("1 - long, 2 - unsigned char");
            cin >> user_choice_2;
            while (cin.fail() == 1 || user_choice > 2) {
                cout << "попробуйте ещё раз\n";
                cin.clear();
                cin.sync();
                cin >> user_choice_2;
            }
            if (user_choice_2 == 1) {
                Queue<long> object(array_size);
                int user_choice_2_1;
                while (true) {
                    puts("1 - Empty, 2 - Full, 3 - Front, 4 - EnQueue, 5 - DeQueue, 6 - главное меню");
                    cin >> user_choice_2_1;
                    while (cin.fail() == 1 || user_choice > 6) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> user_choice_2_1;
                    }
                    if (user_choice_2_1 == 1) {
                        if (object.Empty()) {
                            puts("очередь пустая");
                        } else {
                            puts("очередь не пустая");
                        }
                    } else if (user_choice_2_1 == 2) {
                        if (object.Full()) {
                            puts("очередь полная");
                        } else {
                            puts("очередь не полная");
                        }
                    } else if (user_choice_2_1 == 3) {
                        printf("передний элемент: %li\n", object.Front());
                    } else if (user_choice_2_1 == 4) {
                        int num_of_elements;
                        puts("введите количество элементов:");
                        cin >> num_of_elements;
                        while (cin.fail() == 1) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> num_of_elements;
                        }
                        for (int i = 0; i < num_of_elements; ++i) {
                            long temp;
                            puts("введите элемент:");
                            cin >> temp;
                            while (cin.fail() == 1) {
                                cout << "попробуйте ещё раз\n";
                                cin.clear();
                                cin.sync();
                                cin >> temp;
                            }
                            if (object.EnQueue(temp)) {
                                puts("элемент добавлен в очередь");
                            } else {
                                puts("очередь заполнена");
                            }
                        }
                    } else if (user_choice_2_1 == 5) {
                        int num_of_elements;
                        puts("введите количество элементов:");
                        cin >> num_of_elements;
                        while (cin.fail() == 1) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> num_of_elements;
                        }
                        for (int i = 0; i < num_of_elements; ++i) {
                            printf("извлечённый элемент: %li\n", object.DeQueue());
                        }
                    } else if (user_choice_2_1 == 6) {
                        break;
                    }
                }
            } else if (user_choice_2 == 2) {
                Queue<unsigned char> object(array_size);
                int user_choice_2_2;
                while (true) {
                    puts("1 - Empty, 2 - Full, 3 - Front, 4 - EnQueue, 5 - DeQueue, 6 - Выход");
                    cin >> user_choice_2_2;
                    while (cin.fail() == 1 || user_choice > 6) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> user_choice_2_2;
                    }
                    if (user_choice_2_2 == 1) {
                        if (object.Empty()) {
                            puts("очередь пустая");
                        } else {
                            puts("очередь не пустая");
                        }
                    } else if (user_choice_2_2 == 2) {
                        if (object.Full()) {
                            puts("очередь полная");
                        } else {
                            puts("очередь не полная");
                        }
                    } else if (user_choice_2_2 == 3) {
                        printf("передний элемент: %c\n", object.Front());
                    } else if (user_choice_2_2 == 4) {
                        int num_of_elements;
                        puts("введите количество элементов:");
                        cin >> num_of_elements;
                        while (cin.fail() == 1) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> num_of_elements;
                        }
                        for (int i = 0; i < num_of_elements; ++i) {
                            unsigned char temp;
                            puts("введите элемент:");
                            cin >> temp;
                            while (cin.fail() == 1) {
                                cout << "попробуйте ещё раз\n";
                                cin.clear();
                                cin.sync();
                                cin >> temp;
                            }
                            if (object.EnQueue(temp)) {
                                puts("элемент добавлен в очередь");
                            } else {
                                puts("очередь заполнена");
                            }
                        }
                    } else if (user_choice_2_2 == 5) {
                        int num_of_elements;
                        puts("введите количество элементов:");
                        cin >> num_of_elements;
                        while (cin.fail() == 1) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> num_of_elements;
                        }
                        for (int i = 0; i < num_of_elements; ++i) {
                            printf("извлечённый элемент: %c\n", object.DeQueue());
                        }
                    } else if (user_choice_2_2 == 6) {
                        break;
                    }
                }
            }
        } else if (user_choice == 3) {
            exit = true;
        }
    }
}
