#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MESSAGE "Hello, client!"

int main() 
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) 
    {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept a new client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) 
    {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    // Send the message to the client
    send(new_socket, MESSAGE, strlen(MESSAGE), 0);
    printf("Message sent to the client: %s\n", MESSAGE);

    close(new_socket);
    close(server_fd);

    return 0;
}
