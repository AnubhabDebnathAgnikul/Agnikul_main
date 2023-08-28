#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.c"
#include "client.c"

#include "declaration.h"

#define MESSAGE "Hello, client!"

int main()
{
    pid_t pid = fork();

    if(pid==0)
    {
        client_function();
    }
    else
    {
        server_function();
    }
}
