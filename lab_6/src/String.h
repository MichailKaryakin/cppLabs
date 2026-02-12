#pragma once

#include <cstring>
#include <iostream>
#include <cctype>
#include <cmath>

class String {
    static int copy_constr_num_of_calls;
protected:
    int length;
    char* data;
public:
    void getData() {
        puts(this->data);
    }

    String() {
        puts("default constructor used");
        this->length = 0;
        this->data = nullptr;
    }

    explicit String(char* str) {
        puts("constructor with string as a parameter used");
        this->length = strlen(str);
        this->data = new char[this->length];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = str[i];
        }
        this->data[this->length] = '\0';
    }

    explicit String(char symbol) {
        puts("constructor with symbol as a parameter used");
        this->length = 1;
        this->data = new char[2];
        this->data[0] = symbol;
        this->data[this->length] = '\0';
    }

    String(const String& obj) {
        printf("copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        this->length = obj.length;
        this->data = new char[obj.length];
        for (int i = 0; i < obj.length; ++i) {
            this->data[i] = obj.data[i];
        }
        this->data[obj.length] = '\0';
    }

    virtual ~String() {
        puts("destructor used");
        delete[] this->data;
    }

    int data_length() const {
        puts("data length method used");
        return this->length;
    }

    virtual String& operator=(char* str) {
        puts("operator \'=\' override");
        this->length = strlen(str);
        this->data = new char[this->length];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = str[i];
        }
        this->data[this->length] = '\0';
        return *this;
    }
};

class StringId : public String {
    static int copy_constr_num_of_calls;
private:
    static bool isId(char* str) {
        if (*str == '\0') return false;
        if (isdigit(*str)) return false;
        for (int i = 1; *str; str++, i++) {
            if (!(*str == '_' || isalnum(*str))) return false;
        }
        return true;
    }

    static void array_shift(char* array, int begin, int end, int shift_count) {
        int i;
        if (shift_count > 0) {
            for (i = end; i >= begin; i--) {
                array[i + shift_count] = array[i];
            }
        }
        if (shift_count < 0) {
            for (i = begin; i <= end; i++) {
                array[i + shift_count] = array[i];
            }
        }
    }

public:
    StringId() : String() {}

    explicit StringId(char* str) : String(str) {
        puts("StringId constructor with string as a parameter used");
        if (!isId(str)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringId(const StringId& obj) : String(obj) {
        printf("StringId copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        if (!isId(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    ~StringId() override = default;

    int first_occurrence(const char symbol) {
        puts("StringId first occurrence method used");
        int i = 0;
        while (this->data[i] != symbol && i < this->length) {
            i++;
        }
        return i + 1;
    }

    void to_low() {
        puts("StringId to low method used");
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = tolower(this->data[i]);
        }
    }

    StringId& operator-(const char* str) {
        puts("StringId operator \'-\' override");
        for (int i = 0; i < this->length; ++i) {
            for (int k = 0; k < strlen(str); ++k) {
                if (this->data[i] == str[k]) {
                    array_shift(this->data, i + 1, this->length - 1, -1);
                    i--;
                    --this->length;
                    this->data[this->length] = '\0';
                    break;
                }
            }
        }
        return *this;
    }

    StringId& operator=(char* str) override {
        puts("StringId operator \'=\' override");
        if (isId(str)) {
            this->length = strlen(str);
            this->data = new char[this->length + 1];
            for (int i = 0; i < this->length; ++i) {
                this->data[i] = str[i];
            }
            this->data[this->length] = '\0';
            return *this;
        } else {
            this->length = 0;
            this->data = nullptr;
            return *this;
        }
    }
};

class StringBin : public String {
    static int copy_constr_num_of_calls;
private:
    static bool isBin(char* str) {
        for (int i = 0; i < strlen(str); ++i) {
            if ((str[i] - 48) != 0 && (str[i] - 48) != 1) {
                return false;
            }
        }
        return true;
    };

    static char* Invert_Bin(char* str) {
        for (int j = 0; j < strlen(str); ++j) {
            if (str[j] == 48) {
                str[j] = 49;
            } else {
                str[j] = 48;
            }
        }
        return str - 1;
    }

    static char* toStraight(char* str) {
        int i = strlen(str) - 1;
        if (str[i] == 48) {
            int k = i;
            while (str[k] != 49 && k != 0) {
                str[k] = 49;
                --k;
            }
            str[k] = 48;
        } else {
            str[i] = 48;
        }
        return Invert_Bin(str + 1);
    }

    static int toDecimal(char* str) {
        int number = 0;
        int order = 0;
        if (str[0] == 49) {
            str = toStraight(str);
        }
        for (int i = strlen(str) - 1; i > 0; --i) {
            number += (str[i] - 48) * (int) pow(2, order);
            ++order;
        }
        if (str[0] == 49) {
            number = -number;
        }
        return number;
    }

    static void Invert_string(char* str) {
        int current_symbol_index = 0;
        int strLength = strlen(str);
        while (current_symbol_index < strLength / 2) {
            char temp = str[current_symbol_index];
            int invertedIndex = strLength - (current_symbol_index + 1);
            str[current_symbol_index] = str[invertedIndex];
            str[invertedIndex] = temp;
            ++current_symbol_index;
        }
    }

    static char* toBin(int number) {
        char* array = new char[100];
        if (number < 0) {
            array[0] = 49;
            number = -number;
        } else {
            array[0] = 48;
        }
        int i = 1;
        while (number > 0) {
            array[i] = number % 2 + 48;
            number /= 2;
            ++i;
        }
        array[i] = '\0';
        Invert_string(array + 1);
        if (array[0] == 49) {
            array = Invert_Bin(array + 1);
            for (int j = i; j > 0; --j) {
                if (array[j] == 48) {
                    array[j] = 49;
                    for (int k = j + 1; k < i; ++k) {
                        array[k] = 48;
                    }
                    return array;
                }
            }
        }
        return array;
    }

public:
    StringBin() : String() {}

    explicit StringBin(char* str) : String(str) {
        puts("StringBin constructor with string as a parameter used");
        if (!isBin(this->data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringBin(const StringBin& obj) : String(obj) {
        printf("copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        if (!isBin(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    ~StringBin() override = default;

    void Inversion() {
        Invert_Bin(this->data);
    }

    StringBin& operator-(char* str) {
        puts("StringBin operator \'-\' override");
        int first_number = toDecimal(this->data);
        int second_number = toDecimal(str);
        char* result = toBin(first_number - second_number);
        this->length = strlen(result);
        this->data = new char[this->length];
        int i;
        for (i = 0; i < this->length; ++i) {
            this->data[i] = result[i];
        }
        this->data[this->length] = '\0';
        return *this;
    }

    StringBin& operator=(char* str) override {
        puts("StringBin operator \'=\' override");
        if (isBin(str)) {
            this->length = strlen(str);
            this->data = new char[this->length];
            for (int i = 0; i < this->length; ++i) {
                this->data[i] = str[i];
            }
            this->data[this->length] = '\0';
            return *this;
        } else {
            this->length = 0;
            this->data = nullptr;
            return *this;
        }
    }
};
