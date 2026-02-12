#pragma once

#include "node.h"
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include "cstring"

using namespace std;

class GraphList {
    int vertices_num;
    list <node>* adjList;
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

            list<node>::iterator it;
            for (it = this->adjList[min_index].begin(); it != this->adjList[min_index].end(); ++it) {
                if ((dist[min_index] + (it->cost)) < dist[it->dest]) {
                    dist[it->dest] = (dist[min_index] + (it->cost));
                }
            }
        }
    }

    void addEdge(int source, int dest, int cost) { //добавление новой вершины в список
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        adjList[source].push_back(newNode);
    }

public:
    GraphList() { //считывание графа из файла
        ifstream fin("graphadj.txt");
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
        this->adjList = new list<node>[this->vertices_num];
        int first_index = 0;
        while (getline(fin, temp)) {
            int num_of_spaces = 0;
            int second_index;
            for (char i : temp) {
                if (i == '-') {
                    ++first_index;
                    break;
                }
                if (i == ';') {
                    this->addEdge(first_index, second_index, number); //добавление вершины в список
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
