#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096

void error(const char *err) {
    printf("%s: %s (errno: %d)\n", err, strerror(errno), errno);
}

void die(const char *err) {
    error(err);
    exit(0);
}
int main(int argc, char const* argv[])
{
    int listen_fd, conn_fd;
    struct sockaddr_in addr;
    char buff[MAXLINE];
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        die("create socket error");
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8888);

    if (bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        die("bind socket error");
    }

    if (listen(listen_fd, 10) == -1) {
        die("listen socket error");
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        if (conn_fd == -1) {
            error("accept socket error");
            continue;
        }
        size_t n = recv(conn_fd, buff, MAXLINE, 0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        send(conn_fd, buff, n, 0);
        close(conn_fd);
    }
    close(listen_fd);

    return 0;
}
