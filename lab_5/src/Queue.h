#pragma once

#include <iostream>
#include <cstdlib>

template <class T>
class Queue {
    int front, rear;
    int maxlength;
    T* data;
public:
    explicit Queue(int n) : maxlength(n) {
        puts("constructor used");
        data = new T[maxlength];
        front = 0;
        rear = maxlength - 1;
    }

    ~Queue() {
        puts("destructor used");
        delete[] data;
    }

    bool Empty() {
        puts("empty method used");
        return (rear + 1) % maxlength == front;
    }

    bool Full() {
        puts("full method used");
        return (rear + 2) % maxlength == front;
    }

    T Front() {
        puts("front method used");
        return data[front];
    }

    bool EnQueue(T x) {
        puts("enqueue method used");
        if (Full()) return false;
        rear = (rear + 1) % maxlength;
        data[rear] = x;
        return true;
    }

    T DeQueue() {
        puts("dequeue method used");
        int temp = front;
        front = (front + 1) % maxlength;
        return data[temp];
    }
};

