#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define STR_SIZE 16

#define CMD_QUIT ".quit"
#define CMD_YES  "yes"
#define CMD_NO   "no"

void usage(char* arg) {
    printf("usage: %s <server_ip> <server_port>\n", arg);
}

int main(int argc, char ** argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;

    if (argc < 3) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("client is staring...\n");

    // 创建UDP套接字
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported ");
        return -1;
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        if (NULL == fgets(buffer, BUFFER_SIZE-1, stdin)) {
            perror("fgets");
            continue;
        }

        // 退出指令
        if (!strncasecmp(buffer, CMD_QUIT, strlen(CMD_QUIT))) {
            char str[STR_SIZE];
            printf("Ensure to exit? yes/[no]\n");
            if (NULL == fgets(str, STR_SIZE-1, stdin)) {
                perror("fgets");
                continue;
            }

            // 去除换行符
            str[strcspn(str, "\n")] = '\0';

            // 如果用户没有输入或按下回车，则默认选择 "yes"
            if (str[0] == '\0') {
                strncpy(str, "no", sizeof(str) - 1);
            }

            if (!strncasecmp(str, CMD_YES, strlen(CMD_YES))) {
                printf("Client is exiting...\n");
                break;
            } 
            else if (!strncasecmp(str, CMD_NO, strlen(CMD_NO))) {
                continue;
            }
        }

        // 发送消息给服务器
        sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));

        // 接收来自服务器的消息
        addr_len = sizeof(serv_addr);
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, &addr_len);
        buffer[n] = '\0';
        printf("Message from server: %s\n", buffer);
    }

    // 关闭套接字
    close(sockfd);
    return 0;
}
