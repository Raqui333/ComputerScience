#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// lerning socket programming
int main() {
    // AF_LOCAL(local), AF_INET(ipv4), AF_INET6(ipv6)
    // SOCK_STREAM(TCP), SOCK_DGRAM(UDP)
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET; // use ipv4
    address.sin_addr.s_addr = INADDR_ANY; // localhost
    address.sin_port = htons(8080); // port

    // bind server to address
    bind(server_socket, (const sockaddr*)&address, sizeof(address));

    // listen to connections
    if(listen(server_socket, 2) < 0) {
        std::cout << "Error: listen failed\n";
        exit(0);
    }
    std::cout << "Server listening..." << std::endl;

    int socklen = sizeof(address);
    int client_socket = accept(server_socket, (sockaddr*)&address, (socklen_t*)&socklen);
    if (client_socket < 0) {
        std::cout << "Error: Client connection failed...\n";
        exit(0);
    }
    std::cout << "Client connection accepted...\n" << std::endl;

    char buffer[1024] = {0};
    std::string input;

    // chat like send & read test
    while (input != "exit") {
        read(client_socket, buffer, sizeof(buffer));
        std::cout << "\033[1;31m[Client]\033[00m " << buffer << std::endl;

        std::cout << "> ";
        std::getline(std::cin, input);

        std::cout << "\033[1;32m[Me]\033[00m " << input << std::endl;
        send(client_socket, input.c_str(), input.length(), 0);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}
