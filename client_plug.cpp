// Prepared by Kitel Boris in 2021


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

void uncryption(int key, char* line) {
    char buf[128];
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] >= 'A' && line[i] <= 'Z') {
            line[i] = (((line[i] - 'A') - key) % 26) + 'A';
            if (line[i] < 'A')
                line[i] = line[i] + 26;
        } else if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] = (((line[i] - 'a') - key) % 26) + 'a';
            if (line[i] < 'a')
                line[i] = line[i]+26;
        } else if (line[i] >= '0' && line[i] <= '9') {
            line[i] = (((line[i] - '0') - key) % 10) + '0';
            if (line[i] < '0')
                line[i] = line[i]+10;
        }
    }
}

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
