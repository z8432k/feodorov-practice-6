// Copyright [2021] <Kitel Boris>


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("invalid input data!\n");
        return 1;
    }

    unsigned int port = 0;
    std::stringstream PortPars(argv[1]);
    PortPars >> port;

    if (PortPars.fail()) {
        printf("Invalid port parser: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (port < 49152 || port > 65535) {
        printf("Invalid port value: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int sock;
    struct sockaddr_in addr;

    char msg[1024] = "abczxc1290";
    char recvbuf[1024];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    unsigned int SizeAddr = sizeof(addr);

    int sentbytes = sendto(sock, msg, 1024, 0,
    (struct sockaddr *)&addr, SizeAddr);

    int recvbytes = recvfrom(sock, recvbuf, 1024, 0,
     (struct sockaddr *)&addr, &SizeAddr);

    printf("%s\n", recvbuf);

    if (sentbytes < 0 || recvbytes < 0) {
        printf("Connection error\n");
        exit(1);
    }

    return 0;
}
