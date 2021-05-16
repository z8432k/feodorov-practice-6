// This code is not protected by any copyright as far as I know
// It is based on misc public sources on the Internet, including MSDN
// Prepared by Mark Polyak in 2020

#include <stdio.h>
#include <winsock2.h>
#include <string>

bool check_num(char* line){
	for(int i=0;i<strlen(line);i++)
		if(line[i]<'0'||line[i]>'9')
			return false;
	return true;
}
	
void uncryption(int key, char* line){
	char buf[128];
	for(int i=0;i<strlen(line);i++){
		if (line[i] >= 'A' && line[i] <= 'Z')
        {
            line[i] = (((line[i] - 'A') - key) % 26) + 'A';
			if(line[i] < 'A')
				line[i]=line[i]+26;
        }
        else if (line[i] >= 'a' && line[i] <= 'z')
        {
            line[i] = (((line[i] - 'a') - key) % 26) + 'a';
			if(line[i] < 'a')
				line[i]=line[i]+26;
        }
 	else if (line[i] >= '0' && line[i] <= '9')
        {
            line[i] = (((line[i] - '0') - key) % 10) + '0';
			if(line[i] < '0')
				line[i]=line[i]+10;
        }
	}

}

int main(int argc, char* argv[]) {
	
    int key;
	char check_line[128];
	//std::string line;
    if (argc == 5 && check_num(argv[2])&& check_num(argv[3])) {
        key = std::stoi(argv[3]);
    }
    else {
        printf("invalid input data!\n");
        return 1;
    }
	char address_input[16];
	strcpy(address_input,argv[1]);
	int a = std::stoi(std::string(argv[2]));
	
    // Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if ( iResult != NO_ERROR )
        printf("Error at WSAStartup()\n");

    // Create a socket.
    SOCKET m_socket;
    m_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if ( m_socket == INVALID_SOCKET ) {
        printf("Error at socket(): %ld\n", WSAGetLastError() );
        WSACleanup();
        return 1;
    }

    // Connect to a server.
    struct sockaddr_in addr;

	addr.sin_family = AF_INET;
    addr.sin_port = htons(short(a));
    addr.sin_addr.s_addr = inet_addr(address_input);

	char sendbuf[128];
	char recvbuf[128] = "";
	strcpy(sendbuf,argv[4]);
	strcpy(check_line,argv[4]);
	int size = strlen(sendbuf);
	sendbuf[size] = '$';
	size++;
	for(int i=0;i<sizeof(argv[3]);i++,size++)
		sendbuf[size]=argv[3][i];
	sendbuf[size] = '\0';
	
    sendto(m_socket, sendbuf, strlen(sendbuf), 0,(struct sockaddr *)&addr, sizeof(addr));
	
	printf("client output line - %s\n", sendbuf);
	
	recv(m_socket, recvbuf, 128, 0);
    printf("client input line - %s\n", recvbuf);
	uncryption(key,recvbuf);
	printf("uncryption line - %s\n", recvbuf);
	closesocket(m_socket);
   
    return 0;
}
