#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;

    // 创建UDP套接字
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // 发送消息给服务器
    sendto(sockfd, (const char *)message, strlen(message), 0, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Hello message sent.\n");

    // 接收来自服务器的消息
    addr_len = sizeof(serv_addr);
    int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, &addr_len);
    buffer[n] = '\0';
    printf("Message from server: %s\n", buffer);

    // 关闭套接字
    close(sockfd);
    return 0;
}
