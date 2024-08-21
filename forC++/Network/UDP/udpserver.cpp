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
    struct sockaddr_in servaddr, cliaddr;

    // 创建套接字
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed." << std::endl;
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // 填写服务器信息
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // 绑定套接字到地址
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Bind failed." << std::endl;
        close(sockfd);
        return EXIT_FAILURE;
    }

    int len, n;
    len = sizeof(cliaddr);

    // 等待接收数据
    n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cliaddr, (socklen_t*)&len);
    buffer[n] = '\0';
    std::cout << "Client : " << buffer << std::endl;

    // 回复客户端
    std::string message = "Hello from server";
    sendto(sockfd, message.c_str(), message.size(), 0, (const struct sockaddr *)&cliaddr, len);
    std::cout << "Hello message sent." << std::endl;

    // 关闭套接字
    close(sockfd);
    return 0;
}
