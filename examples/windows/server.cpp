// This code is not protected by any copyright as far as I know
// It is based on misc public sources on the Internet, including MSDN
// Prepared by Mark Polyak in 2020

#include <stdio.h>
#include <winsock2.h>

int main() {
    // Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if ( iResult != NO_ERROR )
        printf("Error at WSAStartup()\n");

    // Create a socket.
    SOCKET m_socket;
    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if ( m_socket == INVALID_SOCKET ) {
        printf("Error at socket(): %ld\n", WSAGetLastError() );
        WSACleanup();
        return 1;
    }

    // Bind the socket.
    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(27015);

    if ( bind(
            m_socket,
            reinterpret_cast<SOCKADDR*> &service,
            sizeof(service) )
    == SOCKET_ERROR) {
        printf("bind() failed.\n");
        closesocket(m_socket);
        return 1;
    }

    // Listen on the socket.
    if ( listen( m_socket, 1 ) == SOCKET_ERROR )
        printf("Error listening on socket.\n");

    // Accept connections.
    SOCKET AcceptSocket;

    printf("Waiting for a client to connect...\n");
    while (1) {
        AcceptSocket = SOCKET_ERROR;
        while ( AcceptSocket == SOCKET_ERROR ) {
            AcceptSocket = accept(m_socket, NULL, NULL);
        }
        printf("Client Connected.\n");
        m_socket = AcceptSocket;
        break;
    }

    // Send and receive data.
    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[32] = "Server: Sending Data.";
    char recvbuf[32] = "";

    bytesRecv = recv(m_socket, recvbuf, 32, 0);
    printf("Bytes Recv: %ld\n", bytesRecv);

    bytesSent = send(m_socket, sendbuf, strlen(sendbuf), 0);
    printf("Bytes Sent: %ld\n", bytesSent);

    return 0;
}
