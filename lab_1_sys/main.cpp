#include <cstdio>
#include "hidapi.h"
#include <winsock2.h>

#define MAX_STR 255

#include <cstring>

using namespace std;

struct packet {
    short transactionId;
    short protocolId;
    short length;
    char unitId;
    char functionCode;
    char data[22];
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    // Подготовка к работе
    int res;
    unsigned char buf[256];
    wchar_t wStr[MAX_STR];
    hid_device* handle;

    struct hid_device_info* devs, * cur_dev;

    printf("hidapi test/example tool. Compiled with hidapi version %s, runtime version %s.\n", HID_API_VERSION_STR,
           hid_version_str());
    if (hid_version()->major == HID_API_VERSION_MAJOR && hid_version()->minor == HID_API_VERSION_MINOR &&
        hid_version()->patch == HID_API_VERSION_PATCH) {
        printf("Compile-time version matches runtime version of hidapi.\n\n");
    } else {
        printf("Compile-time version is different than runtime version of hidapi.\n]n");
    }

    if (hid_init())
        return -1;

    // Находим все устройства USB HID, печатаем содержимое дескриптора устройства, доступное через драйвер
    devs = hid_enumerate(0x0, 0x0);
    cur_dev = devs;
    while (cur_dev) {
        printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls", cur_dev->vendor_id,
               cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
        printf("\n");
        printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
        printf("  Product:      %ls\n", cur_dev->product_string);
        printf("  Release:      %hx\n", cur_dev->release_number);
        printf("  Interface:    %d\n", cur_dev->interface_number);
        printf("  Usage (page): 0x%hx (0x%hx)\n", cur_dev->usage, cur_dev->usage_page);
        printf("\n");
        cur_dev = cur_dev->next;
    }
    hid_free_enumeration(devs);

    // Открываем девайс, используя VID, PID
    handle = hid_open(0x1234, 0x0001, nullptr);
    if (!handle) {
        printf("unable to open device\n");
        return 0;
    }

    // Читаем строку производителя
    wStr[0] = 0x0000;
    res = hid_get_manufacturer_string(handle, wStr, MAX_STR);
    if (res < 0)
        printf("Unable to read manufacturer string\n");
    printf("Manufacturer String: %ls\n", wStr);

    // Читаем строку продукта
    wStr[0] = 0x0000;
    res = hid_get_product_string(handle, wStr, MAX_STR);
    if (res < 0)
        printf("Unable to read product string\n");
    printf("Product String: %ls\n", wStr);

    // Читаем строку серийного номера
    wStr[0] = 0x0000;
    res = hid_get_serial_number_string(handle, wStr, MAX_STR);
    if (res < 0)
        printf("Unable to read serial number string\n");
    printf("Serial Number String: (%d) %ls", wStr[0], wStr);
    printf("\n");

    // Читаем индексированную строку 1
    wStr[0] = 0x0000;
    res = hid_get_indexed_string(handle, 1, wStr, MAX_STR);
    if (res < 0)
        printf("Unable to read indexed string 1\n");
    printf("Indexed String 1: %ls\n", wStr);

    // Подготовка сокета
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr)); // Каждый байт заполняется 0
    sockAddr.sin_family = PF_INET; // Использовать IPv4-адрес
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Определенный IP-адрес
    sockAddr.sin_port = htons(502); // Порт

    bind(servSock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));
    listen(servSock, 20);

    SOCKADDR clientAddr;
    int nSize;
    char szBuffer[30] = {0};
    SOCKET clientSock;

    while (true) {
        // Получение информации с сокета
        nSize = sizeof(SOCKADDR);
        clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);
        recv(clientSock, szBuffer, 30, 0);

        // Подготовка буфера для команд
        memset(buf, 0x00, sizeof(buf));
        short length;
        memcpy(&length, szBuffer + 4, 2);
        memcpy(buf, szBuffer + 8, length);

        // Исполнение команды, сообщение на клиент
        if (szBuffer[7] == 'G') {
            // Кнопки
            res = hid_get_feature_report(handle, buf, sizeof(buf));
            if (res < 0) {
                printf("Unable to get a feature report.\n");
                printf("%ls", hid_error(handle));

                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 5;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'e';
                Packet.data[1] = 'r';
                Packet.data[2] = 'r';
                Packet.data[3] = 'o';
                Packet.data[4] = 'r';
                Packet.data[5] = '\0';

                send(clientSock, (char*) &Packet, 30, 0);
            } else {
                printf("Feature Report\n   ");
                printf("%2d\n", buf[1]);

                // Сообщение на клиент
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 1;
                Packet.unitId = 0;
                Packet.functionCode = 71;
                memcpy((char*) &Packet + 8, buf + 1, 1);
                Packet.data[1] = '\0';

                send(clientSock, (char*) &Packet, 30, 0);
            }
        } else if (szBuffer[7] == 'H') {
            // Элемент
            res = hid_get_feature_report(handle, buf, sizeof(buf));
            if (res < 0) {
                printf("Unable to get a feature report.\n");
                printf("%ls", hid_error(handle));

                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 5;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'e';
                Packet.data[1] = 'r';
                Packet.data[2] = 'r';
                Packet.data[3] = 'o';
                Packet.data[4] = 'r';
                Packet.data[5] = '\0';

                send(clientSock, (char*) &Packet, 30, 0);
            } else {
                printf("Feature Report\n   ");
                short value;
                memcpy(&value, buf + 1, 2);
                printf("%hu", value);

                // Сообщение на клиент
                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 2;
                Packet.unitId = 0;
                Packet.functionCode = 72;
                memcpy((char*) &Packet + 8, &value, 2);
                Packet.data[2] = '\0';

                send(clientSock, (char*) &Packet, 30, 0);
            }
        } else if (szBuffer[7] == 'I') {
            // Лампочки
            res = hid_send_feature_report(handle, buf, 7);
            if (res == -1) {
                printf("hid_write error.\n");

                packet Packet{};
                Packet.transactionId = 0;
                Packet.protocolId = 0;
                Packet.length = 5;
                Packet.unitId = 0;
                Packet.functionCode = 01;
                Packet.data[0] = 'e';
                Packet.data[1] = 'r';
                Packet.data[2] = 'r';
                Packet.data[3] = 'o';
                Packet.data[4] = 'r';
                Packet.data[5] = '\0';

                send(clientSock, (char*) &Packet, 30, 0);
            }

            // Сообщение на клиент
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 4;
            Packet.unitId = 0;
            Packet.functionCode = 73;
            Packet.data[0] = 'd';
            Packet.data[1] = 'o';
            Packet.data[2] = 'n';
            Packet.data[3] = 'e';
            Packet.data[4] = '\0';

            send(clientSock, (char*) &Packet, 30, 0);
        } else if (szBuffer[7] == 'J') {
            // Сообщение на клиент
            packet Packet{};
            Packet.transactionId = 0;
            Packet.protocolId = 0;
            Packet.length = 4;
            Packet.unitId = 0;
            Packet.functionCode = 74;
            Packet.data[0] = 'd';
            Packet.data[1] = 'o';
            Packet.data[2] = 'n';
            Packet.data[3] = 'e';
            Packet.data[4] = '\0';

            // Пиксели
            for (int i = 1; i < 2; i++) { // По x
                for (int j = 1; j < 2; j++) { // По y
                    buf[1] = i;
                    buf[2] = j;
                    res = hid_send_feature_report(handle, buf, 4);
                    if (res == -1) {
                        printf("hid_write error.\n");

                        Packet.functionCode = 01;
                        Packet.data[0] = 'e';
                        Packet.data[1] = 'r';
                        Packet.data[2] = 'r';
                        Packet.data[3] = 'o';
                        Packet.data[4] = 'r';
                        Packet.data[5] = '\0';

                        break;
                    }
                }
            }

            send(clientSock, (char*) &Packet, 30, 0);
        } else {
            // Сообщение об ошибке
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

            send(clientSock, (char*) &Packet, 30, 0);
        }
    }

    // Закрываем сокет
    closesocket(clientSock);
    closesocket(servSock);

    // Прекращаем использование DLL
    WSACleanup();

    return 0;
}
