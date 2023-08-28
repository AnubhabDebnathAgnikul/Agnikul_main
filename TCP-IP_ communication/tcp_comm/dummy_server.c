#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 1234
// #define MESSAGE "Hello, client! it's server"
#define MAX 100
#define BUFFER_SIZE 1024
#define TIMEOUT_SEC 10
#define TIMEOUT_SEC 10
#define TIMEOUT_USEC 100000

int server()
{
    int socket_fd, new_client;
    struct sockaddr_in address; // Structure describing an Internet socket address

    // create a socket
    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd==-1)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to specified address and port
    if(bind(socket_fd,(struct sockaddr *)&address, sizeof(address))==-1)
    {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    //listening to incoming connection
    if(listen(socket_fd,2)==-1)
    {
        perror("listening failure");
        exit(EXIT_FAILURE);
    }

    // accept new client connection
    new_client = accept(socket_fd,(struct sockaddr *)&address,(socklen_t *)(sizeof(address)));
    if(new_client==-1)
    {        
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }
    
    char message[100];
    while(1)
    {
        printf("enter something");
        fgets(message,sizeof(message),stdin);
        send(new_client, message, strlen(message), 0);
    }
    close(socket_fd);
    close(new_client);
    
    return 0;

}

int client()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET,INADDR_ANY, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    fd_set readfds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = TIMEOUT_USEC;

    // Wait for data to be received with timeout
    int select_status = select(sock + 1, &readfds, NULL, NULL, &timeout);
    if (select_status == -1) {
        perror("Error in select");
        exit(EXIT_FAILURE);
    } else if (select_status == 0) {
        printf("Timeout error: No data received within the specified timeout\n");
        exit(EXIT_FAILURE);
    }

    while(buffer!="stop")
    {
        // Data is available, receive the message from the server
        valread = read(sock, buffer, BUFFER_SIZE);
        if(valread=='\0')
        {
            break;
        }
        printf("Received message from server: %s\n", buffer);
        memset(buffer,0,BUFFER_SIZE);
    }

    
    close(sock);

    return 0;

}

int main()
{
    server();
    sleep(1);
    client();
}