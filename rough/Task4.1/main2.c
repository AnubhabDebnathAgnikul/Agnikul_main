#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int pipefd[2];
    int number;
    pid_t child_pid;

    if (pipe(pipefd) == -1) 
    {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid == -1) 
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (child_pid == 0) 
    {
        // Child process
        close(pipefd[1]); // Close write 

        while (read(pipefd[0], &number, sizeof(number)) > 0) 
        {
            printf("Child process received number: %d\n", number);
        }

        close(pipefd[0]); // Close read 
    } 
    else 
    {
        // Parent process
        close(pipefd[0]); // Close read

        for (number = 0; number <= 10; number++) 
        {
            write(pipefd[1], &number, sizeof(number));
        }

        close(pipefd[1]); // Close write 
    }

    return 0;
}
