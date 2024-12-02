#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);
    char *message = "Hello from server";

    printf("server is staring...\n");

    // 创建UDP套接字
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 允许绑定地址快速重用
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    // 绑定IP和端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int n = -1;
        char addr[INET_ADDRSTRLEN];
        // 接收来自客户端的数据
        bzero(buffer, BUFFER_SIZE);
        if ((n = recvfrom(server_fd, (char *)buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("recvfrom");
            continue;
        }
        buffer[n] = '\0';
        if (NULL == inet_ntop(AF_INET, (void *)&client_addr.sin_addr, addr, sizeof(client_addr))) {
            perror("inet_ntop");
            continue;
        }
        printf("Message from client(%s : %d): %s\n", addr, ntohs(client_addr.sin_port), buffer);

        // 发送消息给客户端
        sendto(server_fd, (const char *)message, strlen(message), 0, (const struct sockaddr *)&client_addr, addr_len);
    }

    // 关闭套接字
    close(server_fd);
    return 0;
}
