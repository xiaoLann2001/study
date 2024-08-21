#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUF_SIZE];
    struct sockaddr_in servaddr;

    // 创建套接字
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed." << std::endl;
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // 填写服务器信息
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // 发送数据到服务器
    std::string message = "Hello from client";
    sendto(sockfd, message.c_str(), message.size(), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Hello message sent." << std::endl;

    int n, len;
    n = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);
    buffer[n] = '\0';
    std::cout << "Server : " << buffer << std::endl;

    // 关闭套接字
    close(sockfd);
    return 0;
}
