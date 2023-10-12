#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

// lerning socket programming
int main() {
    // AF_LOCAL(local), AF_INET(ipv4), AF_INET6(ipv6)
    // SOCK_STREAM(TCP), SOCK_DGRAM(UDP)
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET; // use ipv4
    address.sin_port = htons(8080); // port

    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr); // convert ipv4 to binary

    if(connect(client_socket, (const sockaddr*)&address, sizeof(address)) < 0) {
        std::cout << "Error: connect to server failed..." << std::endl;
        exit(0);
    }
    std::cout << "Connected to server sucessfuly...\n" << std::endl;

    char buffer[1024] = {0};
    std::string input;

    // chat like read & send test
    while (input != "exit") {
        std::cout << "> ";
        std::getline(std::cin, input);

        std::cout << "\033[1;32m[Me]\033[00m " << input << std::endl;
        send(client_socket, input.c_str(), input.length(), 0);

        read(client_socket, buffer, sizeof(buffer));
        std::cout << "\033[1;31m[Server]\033[00m " << buffer << std::endl;
    }

    close(client_socket);

    return 0;
}
