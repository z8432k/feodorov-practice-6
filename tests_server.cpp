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
            execl("build/server.exe", "", argv[1], NULL);
        }
        case -1: {
            perror("fork");
            exit(1);
        }
        default: {
            int status;
            waitpid(-1, &status, 0);
            printf("Exit status: %d\n", status);
        }
    }
    return 0;
}

