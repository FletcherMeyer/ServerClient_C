#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6767
#define SERVER_IP "127.0.0.1"

int main(int argc, char const *argv[])
{
    int sockD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr, sizeof(servAddr));

    if (connectStatus == -1) {
        printf("[ERROR]: Could not initiate the socket.");
    } else {
        char strData[255];

        recv(sockD, strData, sizeof(strData), 0);

        printf("Message: %s\n", strData);
    }

    return 0;
}
