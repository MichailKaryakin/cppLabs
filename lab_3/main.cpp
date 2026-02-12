#include <iostream>
#include "src/Triangle.h"

void waiting_input() {
    puts("введите любой символ, чтобы продолжить");
    fflush(stdin);
    getchar();
}

int main() {
    system("chcp 65001");
    bool exit = false;
    while (!exit) {
        int user_choice;
        puts("1 - конструктор\n2 - конструктор копирования\n3 - длина сторон\n4 - длина медианы\n5 - площадь\n"
             "6 - ввод точки\n7 - возвращение точки\n8 - перегрузка ^\n9 - перегрузка +\n10 - выход");
        std::cin >> user_choice;
        while (std::cin.fail() == 1 || user_choice > 10) {
            std::cout << "попробуйте ещё раз\n";
            std::cin.clear();
            std::cin.sync();
            std::cin >> user_choice;
        }
        Point p1, p2, p3;
        if (user_choice == 1) {
            puts("введите координаты 3 вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте ещё раз\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            for (int i = 0; i < 3; i++) {
                triangle->output_point(i + 1);
            }
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 2) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle2 = new Triangle(p1, p2, p3);
            auto* triangle = new Triangle(*triangle2);
            for (int i = 0; i < 3; i++) {
                triangle->output_point(i + 1);
            }
            delete triangle;
            delete triangle2;
            waiting_input();
            continue;
        } else if (user_choice == 3) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            TriangleSidesLen sidesLen = triangle->sides_len();
            for (double i: sidesLen.len) {
                printf("длина стороны: %lf\n", i);
            }
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 4) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            Triangle triangle(p1, p2, p3);
            double median_len = triangle.median_len();
            printf("%lf\n", median_len);
            waiting_input();
            continue;
        } else if (user_choice == 5) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            double area = triangle->area();
            printf("площадь: %lf\n", area);
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 6) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            for (int i = 0; i < 3; i++) {
                triangle->output_point(i + 1);
            }
            for (int i = 0; i < 3; i++) {
                triangle->input_point(i + 1);
            }
            for (int i = 0; i < 3; i++) {
                triangle->output_point(i + 1);
            }
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 7) {
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            Point points[3];
            for (int i = 0; i < 3; i++) {
                points[i] = triangle->return_point(i + 1);
            }
            for (auto& point: points) {
                printf("x координата:%d y координата:%d\n", point.x, point.y);
            }
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 8) {
            puts("введите координаты трёх вершин для первого треугольника");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            puts("введите координаты трёх вершин");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle2 = new Triangle(p1, p2, p3);
            bool sim = *triangle ^ *triangle2;
            if (sim) {
                puts("треугольники подобны");
            } else {
                puts("треугольники не подобны");
            }
            delete triangle2;
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 9) {
            puts("введите координаты трёх вершин для первого треугольника");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle = new Triangle(p1, p2, p3);
            puts("введите координаты трёх вершин для первого треугольника");
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            while (std::cin.fail() == 1) {
                std::cout << "попробуйте снова\n";
                std::cin.clear();
                std::cin.sync();
                std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
            auto* triangle2 = new Triangle(p1, p2, p3);
            double sum = *triangle + *triangle2;
            printf("сумма площадей: %lf\n", sum);
            delete triangle2;
            delete triangle;
            waiting_input();
            continue;
        } else if (user_choice == 10) {
            exit = true;
        }
    }
    return 0;
}
