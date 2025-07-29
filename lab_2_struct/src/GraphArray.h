#pragma once

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "cstring"

using namespace std;

class GraphArray {
    int vertices_num;
    int** adjMatrix;
private:
    void dijkstra(int* dist, int start) { //алгоритм дейкстры
        int i, k;
        for (k = 0; k < this->vertices_num; ++k) {
            dist[k] = 9999;
        }
        dist[start] = 0;

        list<int> elements;
        for (k = 0; k < this->vertices_num; ++k) {
            elements.push_back(k);
        }

        set<int> set;
        while (!elements.empty()) {
            int min = INT_MAX;
            int min_index;
            for (i = 0; i < this->vertices_num; ++i) {
                bool is_in_set = set.find(i) != set.end();
                if (dist[i] < min && !is_in_set) {
                    min = dist[i];
                    min_index = i;
                }
            }
            set.insert(min_index);

            elements.remove(min_index);

            for (i = 0; i < this->vertices_num; ++i) {
                if ((dist[min_index] + adjMatrix[min_index][i]) < dist[i]) {
                    dist[i] = (dist[min_index] + adjMatrix[min_index][i]);
                }
            }
        }
    }

public:
    GraphArray() { //считывание графа из файла в матрицу смежности
        ifstream fin("graph.txt");
        string temp;
        getline(fin, temp);
        int number = 0;
        int order = 1;
        for (char i : temp) {
            number += (i - 48) * order;
            order *= 10;
        }
        this->vertices_num = number;
        number = 0;
        temp.clear();
        adjMatrix = new int* [this->vertices_num];
        for (int i = 0; i < this->vertices_num; ++i) {
            adjMatrix[i] = new int[this->vertices_num];
        } for (int i = 0; i < this->vertices_num; ++i) {
            for (int k = 0; k < this->vertices_num; ++k) {
                adjMatrix[i][k] = 9999;
            }
        }
        while (getline(fin, temp)) {
            int num_of_spaces = 0;
            int first_index, second_index;
            for (char i : temp) {
                if (i == ';') {
                    this->adjMatrix[first_index][second_index] = number;
                    number = 0;
                    break;
                }
                if (i == ' ') {
                    number = 0;
                    ++num_of_spaces;
                    continue;
                }
                number *= 10;
                number += (i - 48);
                if (num_of_spaces == 0) {
                    first_index = number;
                } else if (num_of_spaces == 1) {
                    second_index = number;
                }
            }
            temp.clear();
        }
        fin.close();
    }

    int getVerticesNum() const {
        return this->vertices_num;
    }

    void Search(int* dist, int start) { //запуск поиска по условию задания
        this->dijkstra(dist, start);
    }
};
