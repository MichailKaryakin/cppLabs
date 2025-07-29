#include "cstdio"
#include "cstdlib"
#include <iostream>
#include "cstring"

using namespace std;

int user_choice;

typedef struct person { //структура с необходимыми полями
    char surname[20];
    char sex[5];
    int age;
    char city[15];
    char diagnosis[15];
} DataType;

struct node { //реализация связного списка
    DataType data;
    struct node* next;
};

typedef struct node* list;

DataType input_client() { //ввод записи в структуру
    DataType client;
    fflush(stdin);
    puts("surname");
    gets(client.surname);
    fflush(stdin);
    puts("sex");
    gets(client.sex);
    fflush(stdin);
    puts("age");
    scanf("%d", &client.age);
    fflush(stdin);
    puts("city");
    gets(client.city);
    fflush(stdin);
    puts("diagnosis");
    gets(client.diagnosis);
    return client;
}

list new_node(list begin, DataType person) { //функция добавления записи
    list temp = (list) malloc(sizeof(struct node));
    temp->data = person;
    temp->next = begin;
    return temp;
}

list read_file(char* filename) { //считывание файла в список
    FILE* f;
    DataType client;
    list begin = NULL, cur;
    if ((f = fopen(filename, "rb")) == NULL) {
        perror("Error open file");
        getchar();
        return begin;
    }
    if (fread(&client, sizeof(client), 1, f))
        begin = new_node(NULL, client);
    else
        return NULL;
    cur = begin;
    while (fread(&client, sizeof(client), 1, f)) {
        cur->next = new_node(NULL, client);
        cur = cur->next;
    }
    fclose(f);
    return begin;
}

void delete_list(list begin) { //функция удаления списка
    list temp = begin;
    while (temp) {
        begin = temp->next;
        free(temp);
        temp = begin;
    }
}

bool write_file(char* filename, list begin) { //запись списка в файл
    FILE* f;
    if ((f = fopen(filename, "wb")) == NULL) {
        perror("Error create file");
        getchar();
        return false;
    }
    while (begin) {
        if (fwrite(&begin->data, sizeof(DataType), 1, f))
            begin = begin->next;
        else
            return false;
    }
    return true;
}

void print_data(DataType person) { //вывод записи
    printf("surname : %s\nsex : %s\nage : %d\ncity : %s\ndiagnosis : %s\n", person.surname,
           person.sex, person.age, person.city, person.diagnosis);
}

void show(list cur) { //вывод всех записей в виде таблицы
    int k = 0;
    if (cur == NULL) {
        puts("List is empty");
        return;
    }
    puts("|  N |       Surname      |  Sex | Age |      City      |    Diagnosis   |");
    puts("--------------------------------------------------------------------------");
    while (cur) {
        printf("|%3d |%-19s |%5s |%4d |%15s |%15s |\n", ++k, cur->data.surname,
               cur->data.sex, cur->data.age, cur->data.city, cur->data.diagnosis);
        cur = cur->next;
    }
    puts("--------------------------------------------------------------------------");
}

void search(list cur) { //поиск в соответствии с заданием
    if (cur == NULL) {
        puts("List is empty");
        return;
    }
    int user_choice;
    puts("1 - number of nonresidents, 2 - pensionable age");
    cin >> user_choice;
    if (user_choice == 1) {
        char city[20];
        int number_of_nonresidents = 0;
        puts("Name the city");
        fflush(stdin);
        gets(city);
        while (cur) {
            if (strcmp(cur->data.city, city) != 0) {
                ++number_of_nonresidents;
            }
            cur = cur->next;
        }
        printf("number of nonresidents: %d\n", number_of_nonresidents);
    }
    if (user_choice == 2) {
        while (cur) {
            if (strcmp(cur->data.sex, "woman") != 0) {
                if (cur->data.age >= 58) {
                    print_data(cur->data);
                }
            }
            if (strcmp(cur->data.sex, "man") != 0) {
                if (cur->data.age >= 61) {
                    print_data(cur->data);
                }
            }
            cur = cur->next;
        }
    }
}

list delete_node(list begin) { //удаление записи
    struct node* temp;
    if (begin) {
        temp = begin;
        begin = begin->next;
        free(temp);
        puts("Deleted");
    }
    return begin;
}

int main(int argc, char* argv[]) {
    list clients = nullptr; //определение названия файла
    char file[10] = {"file.txt\0"};
    char* filename = argv[1];
    if (filename == NULL) {
        clients = read_file(file);
        filename = file;
    } else {
        clients = read_file(filename);
    }
    char menu;
    do { //меню
        puts("1. Insert");
        puts("2. Show");
        puts("3. Search");
        puts("4. Delete");
        puts("5. Exit");
        fflush(stdin);
        menu = getchar();
        switch (menu) {
            case '1':
                clients = new_node(clients, input_client());
                break;
            case '2':
                show(clients);
                break;
            case '3':
                search(clients);
                break;
            case '4':
                clients = delete_node(clients);
        }
    } while (menu != '5');
    if (write_file(filename, clients)) //вывод сообщения пользователю о результате сохранения файла
        puts("File saved");
    else
        puts("File not saved");
    delete_list(clients); //список удаляется
    return 0;
}

