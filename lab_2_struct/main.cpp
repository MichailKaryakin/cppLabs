#include <iostream>
#include <windows.h>
#include "src/GraphList.h"
#include "src/GraphArray.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int user_choice;
    cout << "1 - список смежности, 2 - матрица смежности" << "\n";
    cin >> user_choice;
    if (user_choice == 1) {
        GraphList graph;
        int n = graph.getVerticesNum();
        int dist[n];

        int cityNum = 0;
        for (int i = 0; i < n; i++) {
            graph.Search(dist, i);
            bool check = true;
            for (int j : dist) {
                if (j > 100) {
                    check = false;
                    break;
                }
            }
            if (check) {
                printf("from city %d there is a path less than 100 km to any other city\n", i);
                ++cityNum;
            }
        }
        if (cityNum == 0) {
            puts("there is no such city");
        }
    } else if (user_choice == 2) {
        GraphArray graph;
        int n = graph.getVerticesNum();
        int dist[n];

        int cityNum = 0;
        for (int i = 0; i < n; i++) {
            graph.Search(dist, i);
            bool check = true;
            for (int j : dist) {
                if (j > 100) {
                    check = false;
                    break;
                }
            }
            if (check) {
                printf("from city %d there is a path less than 100 km to any other city\n", i);
                ++cityNum;
            }
        }
        if (cityNum == 0) {
            puts("there is no such city");
        }
    }
}
