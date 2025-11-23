#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;
    char greeting[] = "server ready.";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0){
        std::cerr << "Error: socket unable to be made\n" << std::endl;
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(2121);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        std::cerr << "Error: bind failure.\n" << std::endl;
        return -1;
    }

    if (listen(server_fd, 1) < 0){
        std::cerr << "Error: listening failure." << std::endl;
        return -1;
    }

    std::cout << "server is listening... \n" << "(on port 2121)" << std::endl;

    client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0){
        std::cerr << "Error: client server handshake failed." << std::endl;
        return -1;
    }

    std::cout << "client connection established." << std::endl;

    send(client_fd, greeting, strlen(greeting), 0);

    close(client_fd);
    close(server_fd);

    std::cout << "server closed" << std::endl;
    return 0;
}