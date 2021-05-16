// This code is not protected by any copyright as far as I know
// It is based on misc public sources on the Internet
// Prepared by Mark Polyak in 2020

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

void encryption(int key, char* line) {
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] >= 'A' && line[i] <= 'Z')
            line[i] = (((line[i] - 'A') + key) % 26) + 'A';
        else if (line[i] >= 'a' && line[i] <= 'z')
            line[i] = (((line[i] - 'a') + key) % 26) + 'a';
        else if (line[i] >= '0' && line[i] <= '9')
            line[i] = (((line[i] - '0') + key) % 10) + '0';
    }
}


int main() {
    int sock;
    struct sockaddr_in addr;
    struct sockaddr_in addr_out;

    int SenderAddrSize = sizeof (addr_out);
    char buf[128];
    int bytes_read;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 0;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = inet_addr("192.168.56.101");

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 0;
    }
    while (1) {
        int pos_num = 0;
        bytes_read = recvfrom(sock, buf, 128, 0,
        (struct sockaddr *)&addr_out,
        reinterpret_cast<socklen_t*>(&SenderAddrSize));
        buf[bytes_read] = '\0';
        printf("%s%s\n", "server input line -", buf);
        for (int i = 0; i < bytes_read; i++)
            if (buf[i] == '$')
                pos_num = i + 1;
        int kol_num = bytes_read-pos_num;
        int const kSizeN = kol_num;
        char number[kSizeN];
        for (int i = 0, j = pos_num; i < kol_num; i++, j++)
            number[i] = buf[j];
        int n = std::atoi(number);
        buf[pos_num-1] = '\0';
        encryption(n, buf);
        sendto(sock, buf, 128, 0, (struct sockaddr *)&addr_out, SenderAddrSize);
        printf("server output line - %s\n", buf);
    }
    return 0;
}
