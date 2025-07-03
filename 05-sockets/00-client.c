#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE (256)

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int socket_fd, port, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[2]);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error, no such host\n");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0], (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("connect");
    }

    printf("Please enter the message: ");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    n = write(socket_fd, buffer, strlen(buffer));
    if (n < 0) {
        error("write");
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("read");
    }

    printf("%s\n", buffer);
    close(socket_fd);

    return 0;
}
