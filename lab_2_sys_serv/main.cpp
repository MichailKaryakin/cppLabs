#include <winsock2.h>
#include <iostream>

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
    puts("1 - check connection, 2 - hello name, 3 - sum of two numbers");
    cin >> user_choice;
    if (user_choice == 1) {
        // Инициализируем DLL
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создаем сокет
        SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Привязываем сокет
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr)); // Каждый байт заполняется 0
        sockAddr.sin_family = PF_INET; // Использовать IPv4-адрес
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Определенный IP-адрес
        sockAddr.sin_port = htons(502); // Порт
        bind(servSock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // Входим в состояние мониторинга
        listen(servSock, 20);

        // Подготовка полей
        SOCKADDR clientAddr;
        int nSize;
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            recv(clientSock, szBuffer, 30, 0);

            if (szBuffer[7] == 'A') {
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 20;
                Packet.unitId = 0;
                Packet.functionCode = 65;
                Packet.data[0] = 'c';
                Packet.data[1] = 'o';
                Packet.data[2] = 'n';
                Packet.data[3] = 'n';
                Packet.data[4] = 'e';
                Packet.data[5] = 'c';
                Packet.data[6] = 't';
                Packet.data[7] = 'i';
                Packet.data[8] = 'o';
                Packet.data[9] = 'n';
                Packet.data[10] = ' ';
                Packet.data[11] = 'c';
                Packet.data[12] = 'o';
                Packet.data[13] = 'm';
                Packet.data[14] = 'p';
                Packet.data[15] = 'l';
                Packet.data[16] = 'e';
                Packet.data[17] = 't';
                Packet.data[18] = 'e';
                Packet.data[19] = 'd';
                Packet.data[20] = '\0';

                send(clientSock, (char*)&Packet, 30, 0);
            } else {
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 12;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'i';
                Packet.data[1] = 'n';
                Packet.data[2] = 'v';
                Packet.data[3] = 'a';
                Packet.data[4] = 'l';
                Packet.data[5] = 'i';
                Packet.data[6] = 'd';
                Packet.data[7] = ' ';
                Packet.data[8] = 'c';
                Packet.data[9] = 'o';
                Packet.data[10] = 'd';
                Packet.data[11] = 'e';
                Packet.data[12] = '\0';

                send(clientSock, (char*)&Packet, 30, 0);
            }
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }

    if (user_choice == 2) {
        // Инициализируем DLL
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создаем сокет
        SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Привязываем сокет
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr)); // Каждый байт заполняется 0
        sockAddr.sin_family = PF_INET; // Использовать IPv4-адрес
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Определенный IP-адрес
        sockAddr.sin_port = htons(502); // Порт
        bind(servSock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // Входим в состояние мониторинга
        listen(servSock, 20);

        // Подготовка полей
        SOCKADDR clientAddr;
        int nSize;
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            recv(clientSock, szBuffer, 30, 0);

            if (szBuffer[7] == 'C') {
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                short length;
                memcpy(&length, szBuffer + 4, 2);
                Packet.length = 7 + length;
                Packet.unitId = 0;
                Packet.functionCode = 67;
                Packet.data[0] = 'H';
                Packet.data[1] = 'e';
                Packet.data[2] = 'l';
                Packet.data[3] = 'l';
                Packet.data[4] = 'o';
                Packet.data[5] = ',';
                Packet.data[6] = ' ';
                memcpy((char*)&Packet + 15, szBuffer + 8, length);
                Packet.data[7 + length] = '\0';

                send(clientSock, (char*)&Packet, 30, 0);
            } else {
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 12;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'i';
                Packet.data[1] = 'n';
                Packet.data[2] = 'v';
                Packet.data[3] = 'a';
                Packet.data[4] = 'l';
                Packet.data[5] = 'i';
                Packet.data[6] = 'd';
                Packet.data[7] = ' ';
                Packet.data[8] = 'c';
                Packet.data[9] = 'o';
                Packet.data[10] = 'd';
                Packet.data[11] = 'e';
                Packet.data[12] = '\0';

                send(clientSock, (char*)&Packet, 30, 0);
            }
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }

    if (user_choice == 3) {
        // Инициализируем DLL
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создаем сокет
        SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Привязываем сокет
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr)); // Каждый байт заполняется 0
        sockAddr.sin_family = PF_INET; // Использовать IPv4-адрес
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Определенный IP-адрес
        sockAddr.sin_port = htons(502); // Порт
        bind(servSock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // Входим в состояние мониторинга
        listen(servSock, 20);

        // Подготовка полей
        SOCKADDR clientAddr;
        int nSize;
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            recv(clientSock, szBuffer, 30, 0);

            if (szBuffer[7] == 'E') {
                char firstNumber = szBuffer[8];
                char secondNumber = szBuffer[9];
                char sum = firstNumber + secondNumber;

                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 1;
                Packet.unitId = 0;
                Packet.functionCode = 69;
                Packet.data[0] = sum;

                send(clientSock, (char*)&Packet, 30, 0);
            } else {
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 12;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'i';
                Packet.data[1] = 'n';
                Packet.data[2] = 'v';
                Packet.data[3] = 'a';
                Packet.data[4] = 'l';
                Packet.data[5] = 'i';
                Packet.data[6] = 'd';
                Packet.data[7] = ' ';
                Packet.data[8] = 'c';
                Packet.data[9] = 'o';
                Packet.data[10] = 'd';
                Packet.data[11] = 'e';
                Packet.data[12] = '\0';

                send(clientSock, (char*)&Packet, 30, 0);
            }
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }
}
