#pragma once

#include <cstdio>
#include <algorithm>
#include "Point.h"

struct TriangleSidesLen {
    double len[3];
};

class Triangle {
private:
    Point vertexes[3]{};
public:
    Triangle(Point p1, Point p2, Point p3) {
        puts("конструктор был использован");
        this->vertexes[0] = p1;
        this->vertexes[1] = p2;
        this->vertexes[2] = p3;
    }

    Triangle(const Triangle &obj) {
        puts("конструктор копирования был использован");
        this->vertexes[0] = obj.vertexes[0];
        this->vertexes[1] = obj.vertexes[1];
        this->vertexes[2] = obj.vertexes[2];
    }

    ~Triangle() {
        puts("деструктор был использован");
    }

    TriangleSidesLen sides_len() {
        puts("длина сторон метод использован");
        TriangleSidesLen sidesLen{};
        sidesLen.len[0] = this->vertexes[0].len(this->vertexes[1]);
        sidesLen.len[1] = this->vertexes[0].len(this->vertexes[2]);
        sidesLen.len[2] = this->vertexes[1].len(this->vertexes[2]);
        std::sort(std::begin(sidesLen.len), std::end(sidesLen.len));
        return sidesLen;
    }

    double median_len() {
        puts("длина медианы метод использован");
        TriangleSidesLen sidesLen = sides_len();
        return (0.5 * sqrt(pow(2 * sidesLen.len[1], 2) + pow(2 * sidesLen.len[2], 2) - pow(sidesLen.len[0], 2)));
    }

    double area() {
        puts("площадь метод использован");
        TriangleSidesLen sidesLen = this->sides_len();
        double halfP = (sidesLen.len[0] + sidesLen.len[1] + sidesLen.len[2]) / 2;
        return (sqrt(halfP * (halfP - sidesLen.len[0]) * (halfP - sidesLen.len[1]) * (halfP - sidesLen.len[2])));
    }

    void input_point(int num_of_point) {
        puts("ввод точки метод использован");
        puts("введите x координату");
        std::cin >> this->vertexes[num_of_point - 1].x;
        while (std::cin.fail() == 1) {
            std::cout << "try again\n";
            std::cin.clear();
            std::cin.sync();
            std::cin >> this->vertexes[num_of_point - 1].x;
        }
        puts("введите y координату");
        std::cin >> this->vertexes[num_of_point - 1].y;
        while (std::cin.fail() == 1) {
            std::cout << "try again\n";
            std::cin.clear();
            std::cin.sync();
            std::cin >> this->vertexes[num_of_point - 1].y;
        }
    }

    void output_point(int num_of_point) {
        puts("вывод точки метод использован");
        puts("x координата: ");
        printf("%d\n", this->vertexes[num_of_point - 1].x);
        puts("y координата: ");
        printf("%d\n", this->vertexes[num_of_point - 1].y);
    }

    Point return_point(int num_of_point) {
        puts("возвращение точки метод использован");
        return this->vertexes[num_of_point - 1];
    }

    bool operator^(Triangle t2) {
        puts("перегрузка оператора ^");
        TriangleSidesLen sidesLen = this->sides_len();
        TriangleSidesLen t2Sides = t2.sides_len();
        bool sim = (sidesLen.len[0] / t2Sides.len[0] == sidesLen.len[1] / t2Sides.len[1] ==
                    sidesLen.len[2] / t2Sides.len[2]);
        return sim;
    }

    double operator+(Triangle t2) {
        puts("перегрузка оператора +");
        double area1 = this->area();
        double area2 = t2.area();
        return (area1 + area2);
    }
};
