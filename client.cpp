#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const std::string server_ip =  "127.0.0.1";
const int port = 2121;
const int buffer_size = 1024;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[buffer_size] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        std::cerr << "Error: socket creation failure" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Error: invalid address" << std::endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Error: connection failed. is server on " << server_ip << ":" << port << "?" << std::endl;
        return -1;
    }

    std::cout << "connected to server on " << server_ip << ":" << port << "." << std::endl;

    ssize_t bytes_read = read(sock, buffer, buffer_size - 1);
    if (bytes_read > 0) {
        std::cout << "server response: " << buffer;
    } else if (bytes_read == 0){
        std::cout << "server closed connection" << std::endl;
    } else {
        std::cerr << "Error reading from server" << std::endl;
    }

    close(sock);

    return 0;
}