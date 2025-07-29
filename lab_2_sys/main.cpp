#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <winsock2.h>

using namespace std;

struct packet {
    short transactionId;
    short protocolId;
    short length;
    char unitId;
    char functionCode;
    char data[22];
};

int main() {
    int user_choice = 0;
    puts("1 - check connection, 2 - hello name, 3 - sum of two numbers, 4 - board");
    cin >> user_choice;

    if (user_choice == 1) {
        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // массив пакета протокола
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 1;
        Packet.unitId = 0;
        Packet.functionCode = 65;
        Packet.data[0] = 'c';
        Packet.data[1] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 8);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 2) {
        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // массив пакета протокола
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 7;
        Packet.unitId = 0;
        Packet.functionCode = 67;
        Packet.data[0] = 'M';
        Packet.data[1] = 'i';
        Packet.data[2] = 'c';
        Packet.data[3] = 'h';
        Packet.data[4] = 'a';
        Packet.data[5] = 'i';
        Packet.data[6] = 'l';
        Packet.data[7] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 8);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 3) {
        // получение чисел от пользователя
        int firstNumber;
        int secondNumber;
        cout << "enter two numbers: " << endl;
        cin >> firstNumber >> secondNumber;

        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // пакет протокола
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 2;
        Packet.unitId = 0;
        Packet.functionCode = 69;
        Packet.data[0] = firstNumber;
        Packet.data[1] = secondNumber;
        Packet.data[2] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        if (szBuffer[7] == 'E') {
            printf("Message from server: %d\n", *(szBuffer + 8));
        } else {
            printf("Message from server: %s\n", szBuffer + 8);
        }

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 4) {
        int user_choice_1 = 0;
        puts("1 - buttons, 2 - movable element, 3 - lights, 4 - pixels");
        cin >> user_choice_1;

        if (user_choice_1 == 1) {
            // начало работы
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);

            // настройка сокета
            SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
            sockaddr_in sockAddr{};
            memset(&sockAddr, 0, sizeof(sockAddr));
            sockAddr.sin_family = PF_INET;
            sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            sockAddr.sin_port = htons(502);
            connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

            // буфер приёма
            char szBuffer[30] = {0};

            // пакет протокола
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 1;
            Packet.unitId = 0;
            Packet.functionCode = 71;
            Packet.data[0] = 0x01;
            Packet.data[1] = '\0';

            // отправка на сервер и получение ответа
            send(sock, (char*) &Packet, 30, 0);
            recv(sock, szBuffer, 30, 0);

            // вывод сообщения с сервера
            if (szBuffer[7] == 'G') {
                printf("Message from server: %d\n", *(szBuffer + 8));
            } else {
                printf("Message from server: %s\n", szBuffer + 8);
            }

            // закрытие сокета
            closesocket(sock);

            // завершение работы
            WSACleanup();
            system("pause");
            return 0;
        }

        if (user_choice_1 == 2) {
            // начало работы
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);

            // настройка сокета
            SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
            sockaddr_in sockAddr{};
            memset(&sockAddr, 0, sizeof(sockAddr));
            sockAddr.sin_family = PF_INET;
            sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            sockAddr.sin_port = htons(502);
            connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

            // буфер приёма
            char szBuffer[30] = {0};

            // пакет протокола
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 1;
            Packet.unitId = 0;
            Packet.functionCode = 72;
            Packet.data[0] = 0x03;
            Packet.data[1] = '\0';

            // отправка на сервер и получение ответа
            send(sock, (char*) &Packet, 30, 0);
            recv(sock, szBuffer, 30, 0);

            // вывод сообщения с сервера
            if (szBuffer[7] == 'H') {
                short result;
                memcpy(&result, szBuffer + 8, 2);
                printf("Message from server: %hu\n", result);
            } else {
                printf("Message from server: %s\n", szBuffer + 8);
            }

            // закрытие сокета
            closesocket(sock);

            // завершение работы
            WSACleanup();
            system("pause");
            return 0;
        }

        if (user_choice_1 == 3) {
            // начало работы
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);

            // настройка сокета
            SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
            sockaddr_in sockAddr{};
            memset(&sockAddr, 0, sizeof(sockAddr));
            sockAddr.sin_family = PF_INET;
            sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            sockAddr.sin_port = htons(502);
            connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

            // буфер приёма
            char szBuffer[30] = {0};

            // пакет протокола
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 7;
            Packet.unitId = 0;
            Packet.functionCode = 73;
            Packet.data[0] = 0x02;
            // выбор цвета пользователем
            short red = 0;
            short green = 0;
            short blue = 0;
            puts("enter rgb codes");
            cin >> red >> green >> blue;
            memcpy((char*)&Packet + 9, &red, 2);
            memcpy((char*)&Packet + 11, &green, 2);
            memcpy((char*)&Packet + 13, &blue, 2);
            Packet.data[7] = '\0';

            // отправка на сервер и получение ответа
            send(sock, (char*) &Packet, 30, 0);
            recv(sock, szBuffer, 30, 0);

            // вывод сообщения с сервера
            printf("Message from server: %s\n", szBuffer + 8);

            // закрытие сокета
            closesocket(sock);

            // завершение работы
            WSACleanup();
            system("pause");
            return 0;
        }

        if (user_choice_1 == 4) {
            // начало работы
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);

            // настройка сокета
            SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
            sockaddr_in sockAddr{};
            memset(&sockAddr, 0, sizeof(sockAddr));
            sockAddr.sin_family = PF_INET;
            sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            sockAddr.sin_port = htons(502);
            connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

            // буфер приёма
            char szBuffer[30] = {0};

            // пакет протокола
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 4;
            Packet.unitId = 0;
            Packet.functionCode = 74;
            Packet.data[0] = 0x04;
            Packet.data[1] = 0;
            Packet.data[2] = 0;
            // выбор цвета пользователем
            int color = 0;
            puts("pick the color");
            cin >> color;
            Packet.data[3] = color;
            Packet.data[4] = '\0';

            printf("Message from server: %s\n", "done");

            // отправка на сервер и получение ответа
            send(sock, (char*) &Packet, 30, 0);
            recv(sock, szBuffer, 30, 0);

            // вывод сообщения с сервера
            printf("Message from server: %s\n", szBuffer + 8);

            // закрытие сокета
            closesocket(sock);

            // завершение работы
            WSACleanup();
            system("pause");
            return 0;
        }
    }
}
