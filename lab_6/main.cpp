#include <iostream>
#include <windows.h>
#include "cstdio"
#include "src/String.h"

using namespace std;

static bool isId(char* str) {
    if (*str == '\0') return false;
    if (isdigit(*str)) return false;
    for (int i = 1; *str; str++, i++) {
        if (!(*str == '_' || isalnum(*str))) return false;
    }
    return true;
}

static bool isBin(char* str) {
    for (int i = 0; i < strlen(str); ++i) {
        if ((str[i] - 48) != 0 && (str[i] - 48) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    String* array[6] = {nullptr};
    static int number_of_elements;
    bool exit = false;
    bool called_init = false;
    while (!exit) {
        int user_choice;
        puts("1 - Инициализация, 2 - Тестирование, 3 - Выход\n");
        cin >> user_choice;
        while (cin.fail() == 1 || user_choice > 3) {
            cout << "попробуйте ещё раз\n";
            cin.clear();
            cin.sync();
            cin >> user_choice;
        }
        if (user_choice == 1) {
            bool goUp = false;
            called_init = true;
            static bool called;
            while (!goUp) {
                int user_choice_1;
                puts("1 - Число элементов, 2 - Начальное значение, 3 - Вернуться назад\n");
                cin >> user_choice_1;
                while (cin.fail() == 1 || user_choice_1 > 3) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> user_choice_1;
                }
                if (user_choice_1 == 1 && !called) {
                    puts("Введите число элементов в массиве объектов:\n");
                    cin >> number_of_elements;
                    while (cin.fail() == 1 || number_of_elements > 6) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> number_of_elements;
                    }
                    called = true;
                } else if (user_choice_1 == 1 && called) {
                    puts("число элементов уже задано");
                } else if (user_choice_1 == 2 && called) {
                    int num;
                    bool goUp_1 = false;
                    while (!goUp_1) {
                        puts("введите номер элемента:\n");
                        cin >> num;
                        while (cin.fail() == 1 || num > number_of_elements) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> num;
                        }
                        int user_choice_1_2;
                        puts("выберите тип: 1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка");
                        cin >> user_choice_1_2;
                        while (cin.fail() == 1 || user_choice_1_2 > 3) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> user_choice_1_2;
                        }
                        if (user_choice_1_2 == 1) {
                            char temp_array[100];
                            puts("начальное значение:");
                            fflush(stdin);
                            gets(temp_array);
                            array[num - 1] = new String(temp_array);
                            goUp_1 = true;
                        } else if (user_choice_1_2 == 2) {
                            char temp_array[100];
                            puts("начальное значение:");
                            fflush(stdin);
                            gets(temp_array);
                            while(!isId(temp_array)) {
                                puts("попробуйте снова:");
                                fflush(stdin);
                                gets(temp_array);
                            }
                            array[num - 1] = new StringId(temp_array);
                            goUp_1 = true;
                        } else if (user_choice_1_2 == 3) {
                            char temp_array[100];
                            puts("начальное значение:");
                            fflush(stdin);
                            gets(temp_array);
                            while(!isBin(temp_array)) {
                                puts("попробуйте снова:");
                                fflush(stdin);
                                gets(temp_array);
                            }
                            array[num - 1] = new StringBin(temp_array);
                            goUp_1 = true;
                        }
                    }
                } else if (user_choice_1 == 2 && !called) {
                    puts("задайте число элементов");
                } else if (user_choice_1 == 3) {
                    goUp = true;
                }
            }
        } else if (user_choice == 2 && called_init) {
            bool goUp = false;
            while (!goUp) {
                int user_choice_2;
                puts("1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка, 4 - Задать операнды, 5 - Вернуться назад");
                cin >> user_choice_2;
                while (cin.fail() == 1 || user_choice_2 > 5) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> user_choice_2;
                }
                static bool called;
                int test_num;
                if (user_choice_2 == 1 && called) {
                    bool goUp_1 = false;
                    while (!goUp_1) {
                        int user_choice_2_1;
                        puts("1 - длина строки, 2 - перегрузка оператора \'=\', 3 - вернуться назад");
                        cin >> user_choice_2_1;
                        while (cin.fail() == 1 || user_choice_2_1 > 3) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> user_choice_2_1;
                        }
                        if (user_choice_2_1 == 1) {
                            printf("длина строки: %d\n", array[test_num]->data_length());
                        } else if (user_choice_2_1 == 2) {
                            char test_string[100];
                            fflush(stdin);
                            puts("введите новую строку");
                            *array[test_num] = gets(test_string);
                            puts("результат:");
                            array[test_num]->getData();
                        } else if (user_choice_2_1 == 3) {
                            goUp_1 = true;
                        }
                    }
                } else if (user_choice_2 == 1 && !called) {
                    puts("задайте операнды");
                } else if (user_choice_2 == 2 && called) {
                    bool goUp_2 = false;
                    while (!goUp_2) {
                        int user_choice_2_2;
                        puts("1 - перегрузка оператора \'=\', 2 - первое вхождение символа, 3 - перевод в нижний регистр, 4 - перегрузка оператора \'-\', 5 - вернуться назад");
                        cin >> user_choice_2_2;
                        while (cin.fail() == 1 || user_choice_2_2 > 5) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> user_choice_2_2;
                        }
                        if (user_choice_2_2 == 1) {
                            char test_string[100];
                            fflush(stdin);
                            puts("введите новую строку");
                            gets(test_string);
                            while(!isId(test_string)) {
                                puts("попробуйте снова:");
                                fflush(stdin);
                                gets(test_string);
                            }
                            *array[test_num] = test_string;
                            puts("результат:");
                            array[test_num]->getData();
                        } else if (user_choice_2_2 == 2) {
                            String* virtualCall = array[test_num];
                            auto* childCall = (StringId*) virtualCall;
                            char symbol;
                            puts("введите символ");
                            cin >> symbol;
                            while (cin.fail() == 1) {
                                cout << "попробуйте ещё раз\n";
                                cin.clear();
                                cin.sync();
                                cin >> symbol;
                            }
                            printf("первое вхождение введённого символа: %d\n", childCall->first_occurrence(symbol));
                        } else if (user_choice_2_2 == 3) {
                            String* virtualCall = array[test_num];
                            auto* childCall = (StringId*) virtualCall;
                            childCall->to_low();
                            puts("результат:");
                            childCall->getData();
                        } else if (user_choice_2_2 == 4) {
                            String* virtualCall = array[test_num];
                            auto* childCall = (StringId*) virtualCall;
                            char string[20];
                            puts("введите строку:");
                            fflush(stdin);
                            gets(string);
                            *childCall - string;
                            puts("результат:");
                            childCall->getData();
                        } else if (user_choice_2_2 == 5) {
                            goUp_2 = true;
                        }
                    }
                } else if (user_choice_2 == 2 && !called) {
                    puts("задайте операнды");
                } else if (user_choice_2 == 3 && called) {
                    bool goUp_3 = false;
                    while (!goUp_3) {
                        int user_choice_2_3;
                        puts("1 - перегрузка оператора \'=\', 2 - инвертирование числа, 3 - перегрузка оператора \'-\', 4 - вернуться назад");
                        cin >> user_choice_2_3;
                        while (cin.fail() == 1 || user_choice_2_3 > 4) {
                            cout << "попробуйте ещё раз\n";
                            cin.clear();
                            cin.sync();
                            cin >> user_choice_2_3;
                        }
                        if (user_choice_2_3 == 1) {
                            char test_string[100];
                            fflush(stdin);
                            puts("введите новую строку:");
                            gets(test_string);
                            while(!isBin(test_string)) {
                                puts("попробуйте снова:");
                                fflush(stdin);
                                gets(test_string);
                            }
                            *array[test_num] = test_string;
                            puts("результат:");
                            array[test_num]->getData();
                        } else if (user_choice_2_3 == 2) {
                            String* virtualCall = array[test_num];
                            auto* childCall = (StringBin*) virtualCall;
                            childCall->Inversion();
                            puts("результат:");
                            childCall->getData();
                        } else if (user_choice_2_3 == 3) {
                            String* virtualCall = array[test_num];
                            auto* childCall = (StringBin*) virtualCall;
                            char string[20];
                            puts("введите битовую строку:");
                            fflush(stdin);
                            gets(string);
                            *childCall - string;
                            puts("результат:");
                            childCall->getData();
                        } else if (user_choice_2_3 == 4) {
                            goUp_3 = true;
                        }
                    }
                } else if (user_choice_2 == 3 && !called) {
                    puts("задайте операнды");
                } else if (user_choice_2 == 4) {
                    called = true;
                    puts("введите номер объекта, над которым будет производиться тестирование:");
                    cin >> test_num;
                    while (cin.fail() == 1 || test_num > number_of_elements) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> test_num;
                    }
                    --test_num;
                } else if (user_choice_2 == 5) {
                    goUp = true;
                }
            }
        } else if (user_choice == 2 && !called_init) {
            puts("выполните инициализацию");
        } else if (user_choice == 3) {
            exit = true;
        }
    }
    return 0;
}
