#pragma once

#include <cstdlib>
#include <cstdio>

#define MAXLENGTH 10
typedef int DataType;

class Deque {
private:
    int left, right;
    DataType data[MAXLENGTH]{};
public:
    Deque() {
        this->left = 0;
        this->right = MAXLENGTH - 1;
    }

    bool Empty() const {
        return (this->right + 1) % MAXLENGTH == this->left;
    }

    bool Full() const {
        return (this->right + 2) % MAXLENGTH == this->left;
    }

    int ReadRight() {
        return this->data[this->right];
    }

    int InRight(DataType x) {
        if (Full()) return 0;
        this->right = (this->right + 1) % MAXLENGTH;
        this->data[this->right] = x;
        return 1;
    }

    int InLeft(DataType x) {
        if (Full()) return 0;
        this->left = this->left ? this->left - 1 : MAXLENGTH - 1;
        this->data[this->left] = x;
        return 1;
    }

    DataType OutRight() {
        int temp = this->right;
        this->right = this->right ? this->right - 1 : MAXLENGTH - 1;
        return this->data[temp];
    }
};