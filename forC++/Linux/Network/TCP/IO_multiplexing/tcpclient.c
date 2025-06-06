#include "net.h"

void usage(char* arg) {
    printf("Usage: %s <server_ip> <server_port>\n", arg);
}

int main(int argc, char ** argv) {
    int sock_fd = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};

    fd_set rset;
    int maxfd;
    struct timeval tout;

    if (argc < 3) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Client is staring...\n");

    // 创建套接字
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return -1;
    }

    // 填充服务器地址和端口号
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported ");
        return -1;
    }

    // 连接服务器
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sock_fd);
        return -1;
    }

    while (1)
    {
        // 将读集合清零
        FD_ZERO(&rset);

        // 将标准输入和socket加入读集合
        FD_SET(0, &rset);
        FD_SET(sock_fd, &rset);

        // 阻塞等待直到读集合的fd有数据，退出时更新读集合为有数据的读集合
        maxfd = sock_fd;
        tout.tv_sec = 5;    // 每次需要重新设置
        tout.tv_usec = 0;
        select(maxfd + 1, &rset, NULL, NULL, &tout);

        // 处理标准输入数据
        if (FD_ISSET(0, &rset)) {
            printf("Stdin have data\n");
            // 读标准输入，末尾有'\n'
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

            // 发送数据到服务器
            write(sock_fd, buffer, strlen(buffer));
        }

        // 处理socket数据
        if (FD_ISSET(sock_fd, &rset)) {
            printf("Socket have data\n");
            // 读取服务器发送的数据
            int ret = -1;
            do {
                ret = read(sock_fd, buffer, BUFFER_SIZE-1);
            } while (ret < 0 && EINTR == errno);
            if (ret < 0) {
                perror("Read from server");
                break;
            }
            if (0 == ret) {
                perror("Server is disconnected. Exiting...");
                break;  // 对方已关闭连接
            }
            printf("Message from server: %s\n", buffer);
        }
    }
    
    // 关闭套接字
    close(sock_fd);
    return 0;
}
