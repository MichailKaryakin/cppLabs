#include <iostream>
#include <windows.h>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
vector<T> array_sort_even(vector<T> array) {
    vector<T> temp_array;
    for (int i = 0; i < array.size(); i = i + 2) {
        temp_array.push_back(array[i]);
    }
    sort(temp_array.begin(), temp_array.end());
    for (int i = 0, k = 0; k < temp_array.size(); i = i + 2, ++k) {
        array[i] = temp_array[k];
    }
    return array;
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
                vector<long> array;
                bool end_cycle = false;
                int size = 0;
                while (!end_cycle) {
                    long temp;
                    puts("введите элемент:");
                    cin >> temp;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> temp;
                    }
                    array.push_back(temp);
                    ++size;
                    int choice;
                    puts("1 - продолжить, 2 - закончить");
                    cin >> choice;
                    while (cin.fail() == 1 || choice > 2) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> choice;
                    }
                    if (choice == 2) {
                        end_cycle = true;
                    }
                }
                array.resize(size);
                array = array_sort_even(array);
                puts("отсортированный массив:");
                for (long& i : array) {
                    cout << i << " ";
                }
                puts("");
            } else if (user_choice_1 == 2) {
                vector<unsigned char> array;
                bool end_cycle = false;
                int size = 0;
                while (!end_cycle) {
                    unsigned char temp;
                    puts("введите элемент:");
                    cin >> temp;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> temp;
                    }
                    array.push_back(temp);
                    ++size;
                    int choice;
                    puts("1 - продолжить, 2 - закончить");
                    cin >> choice;
                    while (cin.fail() == 1 || choice > 2) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> choice;
                    }
                    if (choice == 2) {
                        end_cycle = true;
                    }
                }
                array.resize(size);
                array = array_sort_even(array);
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
                queue<long> object;
                int user_choice_2_1;
                while (true) {
                    puts("1 - empty, 2 - size, 3 - front, 4 - back, 5 - push, 6 - pop, 7 - emplace, 8 - swap, 9 - главное меню");
                    cin >> user_choice_2_1;
                    while (cin.fail() == 1 || user_choice > 7) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> user_choice_2_1;
                    }
                    if (user_choice_2_1 == 1) {
                        if (object.empty()) {
                            puts("очередь пустая");
                        } else {
                            puts("очередь не пустая");
                        }
                    } else if (user_choice_2_1 == 2) {
                        printf("размер: %d\n", object.size());
                    } else if (user_choice_2_1 == 3) {
                        if (!object.empty())
                            printf("передний элемент: %li\n", object.front());
                        else puts("элементов нет");
                    } else if (user_choice_2_1 == 4) {
                        if (!object.empty())
                            printf("задний элемент: %li\n", object.back());
                        else puts("элементов нет");
                    } else if (user_choice_2_1 == 5) {
                        long temp;
                        puts("введите элемент:");
                        cin >> temp;
                        object.push(temp);
                        printf("задний элемент: %li\n", object.back());
                    } else if (user_choice_2_1 == 6) {
                        printf("передний элемент: %li\n", object.front());
                        puts("передний элемент извлечён");
                        object.pop();
                        if (!object.empty())
                            printf("передний элемент: %li\n", object.front());
                        else puts("был извлечён последний элемент");
                    } else if (user_choice_2_1 == 7) {
                        printf("задний элемент: %li\n", object.back());
                        long temp;
                        puts("введите элемент:");
                        cin >> temp;
                        object.emplace(temp);
                        printf("задний элемент: %li\n", object.back());
                    } else if (user_choice_2_1 == 8) {
                        queue<long> temp_object;
                        puts("создана новая очередь");
                        bool end_cycle = false;
                        while (!end_cycle) {
                            long temp;
                            puts("введите элемент:");
                            cin >> temp;
                            temp_object.push(temp);
                            int choice;
                            puts("1 - продолжить, 2 - закончить");
                            cin >> choice;
                            while (cin.fail() == 1 || choice > 2) {
                                cout << "попробуйте ещё раз\n";
                                cin.clear();
                                cin.sync();
                                cin >> choice;
                            }
                            if (choice == 2) {
                                end_cycle = true;
                            }
                        }
                        puts("новая очередь заполнена");
                        object.swap(temp_object);
                        puts("смена содержимого очередей произведена");
                        while (!object.empty()) {
                            printf("передний элемент исходной очереди: %li\n", object.front());
                            object.pop();
                            puts("передний элемент извлечён");
                        }
                        while (!temp_object.empty()) {
                            printf("передний элемент новой очереди: %li\n", temp_object.front());
                            temp_object.pop();
                            puts("передний элемент извлечён");
                        }
                    } else if (user_choice_2_1 == 9) {
                        break;
                    }
                }
            } else if (user_choice_2 == 2) {
                queue<unsigned char> object;
                int user_choice_2_2;
                while (true) {
                    puts("1 - empty, 2 - size, 3 - front, 4 - back, 5 - push, 6 - pop, 7 - emplace, 8 - swap, 9 - главное меню");
                    cin >> user_choice_2_2;
                    while (cin.fail() == 1 || user_choice > 7) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> user_choice_2_2;
                    }
                    if (user_choice_2_2 == 1) {
                        if (object.empty()) {
                            puts("очередь пустая");
                        } else {
                            puts("очередь не пустая");
                        }
                    } else if (user_choice_2_2 == 2) {
                        printf("размер: %d\n", object.size());
                    } else if (user_choice_2_2 == 3) {
                        if (!object.empty())
                            printf("передний элемент: %c\n", object.front());
                        else puts("элементов нет");
                    } else if (user_choice_2_2 == 4) {
                        if (!object.empty())
                            printf("задний элемент: %c\n", object.back());
                        else puts("элементов нет");
                    } else if (user_choice_2_2 == 5) {
                        unsigned char temp;
                        puts("введите элемент:");
                        cin >> temp;
                        object.push(temp);
                        printf("задний элемент: %c\n", object.back());
                    } else if (user_choice_2_2 == 6) {
                        printf("передний элемент: %c\n", object.front());
                        puts("передний элемент извлечён");
                        object.pop();
                        if (!object.empty())
                            printf("передний элемент: %c\n", object.front());
                        else puts("был извлечён последний элемент");
                    } else if (user_choice_2_2 == 7) {
                        printf("задний элемент: %c\n", object.back());
                        unsigned char temp;
                        puts("введите элемент:");
                        cin >> temp;
                        object.emplace(temp);
                        printf("задний элемент: %c\n", object.back());
                    } else if (user_choice_2_2 == 8) {
                        queue<unsigned char> temp_object;
                        puts("создана новая очередь");
                        bool end_cycle = false;
                        while (!end_cycle) {
                            unsigned char temp;
                            puts("введите элемент:");
                            cin >> temp;
                            temp_object.push(temp);
                            int choice;
                            puts("1 - продолжить, 2 - закончить");
                            cin >> choice;
                            while (cin.fail() == 1 || choice > 2) {
                                cout << "попробуйте ещё раз\n";
                                cin.clear();
                                cin.sync();
                                cin >> choice;
                            }
                            if (choice == 2) {
                                end_cycle = true;
                            }
                        }
                        puts("новая очередь заполнена");
                        object.swap(temp_object);
                        puts("смена содержимого очередей произведена");
                        while (!object.empty()) {
                            printf("передний элемент исходной очереди: %c\n", object.front());
                            object.pop();
                            puts("передний элемент извлечён");
                        }
                        while (!temp_object.empty()) {
                            printf("передний элемент новой очереди: %c\n", temp_object.front());
                            temp_object.pop();
                            puts("передний элемент извлечён");
                        }
                    } else if (user_choice_2_2 == 9) {
                        break;
                    }
                }
            }
        } else if (user_choice == 3) {
            exit = true;
        }
    }
}
