/* A simple server in the internet domain using TCP. The port number is passed as an argument. */
/* Code adapted from https://www.linuxhowtos.org/C_C++/socket.htm. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE (256)

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int socket_fd, new_socket_fd, port;
    socklen_t client_length;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("socket");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    port = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("bind");
    }

    listen(socket_fd, 5);
    client_length = sizeof(client_addr);
    new_socket_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &client_length);
    if (new_socket_fd < 0) {
        error("accept");
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(new_socket_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("read");
    }

    printf("Here is the message: %s\n", buffer);
    n = write(new_socket_fd, "I got your message", 18);
    if (n < 0) {
        error("write");
    }

    close(new_socket_fd);
    close(socket_fd);

    return 0;
}
