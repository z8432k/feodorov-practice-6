// Copyright [2021] Kitel Boris

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>


int main(int argc, char** argv) {
    pid_t process_id;
    switch (process_id = fork()) {
        case 0: {
            execl("build/client_plug.exe", "", argv[1], NULL);
        }
        case -1: {
            perror("fork");
            exit(1);
        }
        default: {
            int status;
            waitpid(process_id, &status, 0);
            printf("Exit status: %d\n", status);
        }
    }
    return 0;
}

