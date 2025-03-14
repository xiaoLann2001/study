#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

std::string load_html(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return "<html><body><h1>404 Not Found</h1></body></html>";

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void handle_client(int client_sock) {
    char buffer[1024] = {0};
    read(client_sock, buffer, sizeof(buffer));

    std::cout << "收到请求:\n" << buffer << std::endl;

    std::string content = load_html("index.html");

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: " + std::to_string(content.size()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        content;

    send(client_sock, response.c_str(), response.length(), 0);
    close(client_sock);
}

int main() {
    int server_fd, client_sock;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("创建 socket 失败");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("绑定失败");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("监听失败");
        exit(EXIT_FAILURE);
    }

    std::cout << "Web 服务器运行中，监听端口 " << PORT << "...\n";

    std::vector<std::thread> threads;

    while (true) {
        client_sock = accept(server_fd, (struct sockaddr*)&address, &addr_len);
        if (client_sock < 0) {
            perror("接受连接失败");
            continue;
        }

        std::cout << "新客户端连接: " << inet_ntoa(address.sin_addr) << ":" << ntohs(address.sin_port) << std::endl;

        threads.emplace_back(handle_client, client_sock);
    }

    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    close(server_fd);
    return 0;
}
