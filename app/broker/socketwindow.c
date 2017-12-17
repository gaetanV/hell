#include <winsock2.h>
#pragma comment(lib, "./libws2_32.a")

static void initSocket()
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);

}

static void endSocket()
{
    WSACleanup();
}
